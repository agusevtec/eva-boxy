#pragma once

#include <evabScreen.h>
#include <evabCoor.h>
#include <evabTextAlign.h>

namespace evab
{
  /**
   * @brief Decorator that adds a label to any element with alignment
   *
   * Wraps an element and adds a text label either to the left
   * (single line) or above (multi-line).
   *
   * @tparam T Element type to label
   * @tparam TAlign Alignment strategy for label (LeftAlign, CenterAlign, RightAlign)
   * @tparam TText Text type (const char*, __FlashStringHelper*)
   */
  template <class T, typename TAlign, typename TText>
  class Labeled : public T
  {
  public:
    /**
     * @brief Constructor for Labeled
     *
     * @param aName Label text
     * @param args Arguments forwarded to the base element constructor
     */
    template <typename... Args>
    Labeled(TText aName, Args &&...args)
        : T(args...), mName(aName)
    {
    }

    /**
     * @brief Sets new label text and redraws
     *
     * @param aName New label text
     */
    void SetLabel(TText aName)
    {
      mName = aName;
      redraw();
    }

    /**
     * @brief Gets current label text
     *
     * @return Current label text
     */
    TText GetLabel() const
    {
      return mName;
    }

  protected:
    /**
     * @brief Draws the labeled element
     *
     * @param aScreen Screen to draw on
     * @param aPos Position on screen
     * @param aSize Size of the element
     * @param aIsFocused Focus state (1 = focused, 0 = not focused)
     */
    void drawer(Screen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override
    {
      if (aSize.Y == 1)
      {
        unsigned char labelWidth = 2 * aSize.X / 3;
        unsigned char inputWidth = aSize.X - labelWidth;
        aScreen->Text<TAlign>(aPos, {labelWidth, 1}, mName, aIsFocused);
        T::drawer(aScreen, {aPos.X + labelWidth, aPos.Y}, {inputWidth, 1}, aIsFocused);
      }
      else
      {
        unsigned char labelWidth = 2 * aSize.X / 3;
        unsigned char inputWidth = aSize.X - labelWidth;
        aScreen->Text<TAlign>(aPos, {labelWidth, 1}, mName, aIsFocused);
        aScreen->Clear({aPos.X, aPos.Y + 1}, {labelWidth, aSize.Y - 1}, aIsFocused);
        T::drawer(aScreen, {aPos.X + labelWidth, aPos.Y}, {inputWidth, aSize.Y}, aIsFocused);
      }
    }

  private:
    TText mName; ///< Label text
  };

  // ============================================================
  // Convenience aliases for const char* labels
  // ============================================================

  template <class T>
  using LabeledLeft = Labeled<T, LeftAlign, const char *>;

  template <class T>
  using LabeledCenter = Labeled<T, CenterAlign, const char *>;

  template <class T>
  using LabeledRight = Labeled<T, RightAlign, const char *>;

  // ============================================================
  // Convenience aliases for Flash string labels
  // ============================================================

  template <class T>
  using LabeledLeftF = Labeled<T, LeftAlign, const __FlashStringHelper *>;

  template <class T>
  using LabeledCenterF = Labeled<T, CenterAlign, const __FlashStringHelper *>;

  template <class T>
  using LabeledRightF = Labeled<T, RightAlign, const __FlashStringHelper *>;

}