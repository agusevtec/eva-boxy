#pragma once

#include <evabElementBase.h>

namespace evab
{

  /**
   * @brief Pictogram button element
   *
   * Displays a button with a pictogram enclosed in parentheses.
   */
  class InputButtonPicto : public ElementBase
  {
  public:
    /**
     * @brief Constructor for InputButtonPicto
     *
     * @param aPictoData Pointer to pictogram data
     */
    InputButtonPicto(const unsigned char *aPictoData);

  protected:
    /**
     * @brief Draws the button element
     *
     * @param aScreen Screen to draw on
     * @param aPos Position on screen
     * @param aSize Size of the element
     * @param aIsFocused Focus state (1 = focused, 0 = not focused)
     */
    void drawer(IScreen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override;

  private:
    const unsigned char *mPictoData; ///< Pictogram data
  };

}