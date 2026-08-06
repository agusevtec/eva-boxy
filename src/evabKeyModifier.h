#pragma once

#include <evaHandler.h>

namespace evab
{

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

      return true;
    }
  };

}
