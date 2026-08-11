#pragma once

#include <evabElementBase.h>

namespace evab
{

  /**
   * @brief Pictogram button element
   *
   * Displays a button with a pictogram.
   */
  class InputButtonPx : public ElementBase
  {
  public:
    /**
     * @brief Constructor for InputButtonPx
     *
     * @param aPictogram Pointer to pictogram data
     */
    InputButtonPx(const unsigned char *aPictogram);

  protected:
    /**
     * @brief Draws the button element
     *
     * @param aScreen Screen to draw on
     * @param aPos Position on screen
     * @param aSize Size of the element
     * @param aIsFocused Focus state (1 = focused, 0 = not focused)
     */
    void drawer(Screen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override;

  private:
    const unsigned char *mPictogram; ///< Pictogram data
  };

}