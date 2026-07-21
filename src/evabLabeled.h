#pragma once

#include <evabIScreen.h>
#include <evabCoor.h>

namespace evab
{

  /**
   * @brief Decorator that adds a label to any element
   * 
   * Wraps an element and adds a text label either to the left
   * (single line) or above (multi-line).
   * 
   * @tparam T Element type to label
   */
  template <class T>
  class Labeled : public T
  {
  public:
    /**
     * @brief Constructor for Labeled with C-string label
     * 
     * @param aName Label text (C-string)
     * @param args Arguments forwarded to the base element constructor
     */
    template<typename... Args>
    Labeled(const char *aName, Args&&... args) 
      : T(args...), mName(aName)
    {
    }

  private:
    /**
     * @brief Draws the labeled element
     * 
     * @param aScreen Screen to draw on
     * @param aPos Position on screen
     * @param aSize Size of the element
     * @param aIsFocused Focus state (1 = focused, 0 = not focused)
     */
    void drawer(IScreen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override
    {
      if (aSize.Y == 1)
      {
        unsigned char labelWidth = 2 * aSize.X / 3;
        unsigned char inputWidth = aSize.X - labelWidth;
        
        aScreen->TextLeft(aPos, {labelWidth, 1}, mName, aIsFocused);
        T::drawer(aScreen, {aPos.X + labelWidth, aPos.Y}, {inputWidth, 1}, aIsFocused);
      }
      else
      {
        aScreen->TextLeft(aPos, {aSize.X, 1}, mName, aIsFocused);
        T::drawer(aScreen, {aPos.X, aPos.Y + 1}, {aSize.X, aSize.Y - 1}, aIsFocused);
      }
    }

  private:
    const char *mName;  ///< Label text (C-string)
  };

  /**
   * @brief Decorator that adds a Flash string label to any element
   * 
   * Wraps an element and adds a Flash string label either to the left
   * (single line) or above (multi-line).
   * 
   * @tparam T Element type to label
   */
  template <class T>
  class LabeledF : public T
  {
  public:
    /**
     * @brief Constructor for LabeledF with Flash string label
     * 
     * @param aName Label text (Flash string, PROGMEM)
     * @param args Arguments forwarded to the base element constructor
     */
    template<typename... Args>
    LabeledF(const __FlashStringHelper *aName, Args&&... args) 
      : T(args...), mName(aName)
    {
    }

  private:
    /**
     * @brief Draws the labeled element
     * 
     * @param aScreen Screen to draw on
     * @param aPos Position on screen
     * @param aSize Size of the element
     * @param aIsFocused Focus state (1 = focused, 0 = not focused)
     */
    void drawer(IScreen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override
    {
      if (aSize.Y == 1)
      {
        unsigned char labelWidth = 2 * aSize.X / 3;
        unsigned char inputWidth = aSize.X - labelWidth;
        
        aScreen->TextLeft(aPos, {labelWidth, 1}, mName, aIsFocused);
        T::drawer(aScreen, {aPos.X + labelWidth, aPos.Y}, {inputWidth, 1}, aIsFocused);
      }
      else
      {
        aScreen->TextLeft(aPos, {aSize.X, 1}, mName, aIsFocused);
        T::drawer(aScreen, {aPos.X, aPos.Y + 1}, {aSize.X, aSize.Y - 1}, aIsFocused);
      }
    }

  private:
    const __FlashStringHelper *mName;  ///< Label text (Flash string)
  };

}
