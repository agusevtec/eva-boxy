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
   * @tparam KEYS OnKey codes to catch (variadic template parameters)
   */
  template <class T, Keys... KEYS>
  class KeyCatcher : public T
  {
  public:

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
    bool OnKey(Keys aKey) override
    {
      if (T::OnKey(aKey))
        return true;

      if ((... || (aKey == KEYS)))
      {
        if (mListener)
        {
          mListener->invoke(this, {0, (int)aKey});
          return true;
        }
      }
      return false;
    }

  private:
    eva::IHandler *mListener = nullptr; ///< Event listener for caught key events
  };

}
