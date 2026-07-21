#pragma once

#include <evaHandler.h>

namespace evab
{

  /**
   * @brief Decorator that catches specified key events and forwards them to a listener.
   * 
   * This class wraps any element and intercepts key presses matching the specified keys.
   * When a matching key is pressed, it invokes the listener with an event callback.
   * 
   * @tparam T Base element type to decorate
   * @tparam KEYS Key codes to catch (variadic template parameters)
   */
  template <class T, Keys... KEYS>
  class KeyCatcher : public T
  {
  public:
    /**
     * @brief Event types for KeyCatcher notifications
     */
    enum EventType
    {
      EVENT_CATCH_KEY = 1,  ///< Event triggered when a caught key is pressed
    };

    /**
     * @brief Constructor for KeyCatcher
     * 
     * @param aListener Pointer to the event listener
     * @param args Arguments forwarded to the base element constructor
     */
    template <typename... Args>
    KeyCatcher(eva::IHandler *aListener, Args &&...args)
        : T(args...), mListener(aListener)
    {
    }

    /**
     * @brief Handles key events, catching specified keys
     * 
     * @param aKey The key code to process
     * @return true if the key was handled, false otherwise
     */
    bool Key(Keys aKey) override
    {
      if (T::Key(aKey))
        return true;

      if ((... || (aKey == KEYS)))
      {
        if (mListener)
        {
          mListener->invoke(this, {EVENT_CATCH_KEY, (int)aKey});
          return true;
        }
      }
      return false;
    }

  private:
    eva::IHandler *mListener = nullptr;  ///< Event listener for caught key events
  };

  /**
   * @brief Decorator that modifies values using increment/decrement keys
   * 
   * This class wraps any element and adds behavior for increment and decrement keys.
   * It calls the underlying element's Increment() method with +/- 1.
   * 
   * @tparam T Base element type (must have Increment(signed char) method)
   * @tparam kDec Key code for decrement
   * @tparam kInc Key code for increment
   */
  template <class T, unsigned char kDec, unsigned char kInc>
  class KeyModifier : public T
  {
  public:
    /**
     * @brief Constructor for KeyModifier
     * 
     * @param args Arguments forwarded to the base element constructor
     */
    template <typename... Args>
    KeyModifier(Args &&...args)
        : T(args...)
    {
    }

    /**
     * @brief Handles key events for increment/decrement
     * 
     * @param aKey The key code to process
     * @return true if the key was handled, false otherwise
     */
    bool Key(Keys aKey) override
    {
      if (T::Key(aKey))
        return true;

      if (aKey == kDec)
        T::Increment(-1);
      else if (aKey == kInc)
        T::Increment(+1);
      else
        return false;

      return true;
    }
  };

  /**
   * @brief Decorator that triggers events when values change via increment/decrement
   * 
   * Similar to KeyModifier but additionally sends event notifications
   * when the value changes through increment/decrement operations.
   * 
   * @tparam T Base element type (must have Increment(signed char) and GetValue() methods)
   * @tparam kDec Key code for decrement
   * @tparam kInc Key code for increment
   */
  template <class T, unsigned char kDec, unsigned char kInc>
  class KeyReactor : public T
  {
  public:
    /**
     * @brief Event types for KeyReactor notifications
     */
    enum EventType
    {
      EVENT_VALUE_CHANGED = 1,  ///< Event triggered when value changes
    };

    /**
     * @brief Constructor for KeyReactor
     * 
     * @param aListener Pointer to the event listener
     * @param args Arguments forwarded to the base element constructor
     */
    template <typename... Args>
    KeyReactor(eva::IHandler *aListener, Args &&...args)
        : T(args...), mListener(aListener)
    {
    }

    /**
     * @brief Handles key events, triggers event on value change
     * 
     * @param aKey The key code to process
     * @return true if the key was handled, false otherwise
     */
    bool Key(Keys aKey) override
    {
      if (T::Key(aKey))
        return true;

      if (aKey == kDec)
        T::Increment(-1);
      else if (aKey == kInc)
        T::Increment(+1);
      else
        return false;

      if (mListener)
        mListener->invoke(this, {EVENT_VALUE_CHANGED, (int)T::GetValue()});
      return true;
    }

  private:
    eva::IHandler *mListener = nullptr;  ///< Event listener for value change events
  };

}
