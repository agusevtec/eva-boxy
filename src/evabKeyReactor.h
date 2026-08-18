#pragma once

#include <evaHandler.h>

namespace evab
{
  /**
   * @brief Decorator that triggers events when values change via increment/decrement
   *
   * Similar to KeyModifier but additionally sends event notifications
   * when the value changes through increment/decrement operations.
   *
   * @tparam T Base element type (must have Increment(signed char) and Selected() methods)
   * @tparam kDec Key code for decrement
   * @tparam kInc Key code for increment
   */
  template <class T, unsigned char kDec, unsigned char kInc>
  class KeyReactor : public T
  {
  public:

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
    bool OnKey(Keys aKey) override
    {
      if (T::OnKey(aKey))
        return true;

      if (aKey == kDec)
        T::Increment(-1);
      else if (aKey == kInc)
        T::Increment(+1);
      else
        return false;

      if (mListener)
        mListener->invoke((void *)this, {0, 0});
      return true;
    }

  private:
    eva::IHandler *mListener = nullptr; ///< Event listener for value change events
  };

}
