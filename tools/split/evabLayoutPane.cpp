#include "evabLayoutPane.h"

namespace evab
{

  // LayoutPane::LayoutPane(CompositeBase *aContainer) : CompositeBase(aContainer)
  // {
  // }

  /**
   * @brief Sets up the layout pane with items
   * 
   * @param aLayout Layout configuration
   * @param aItems Array of layout items
   * @param aCount Number of items
   */
  void LayoutPane::SetItems(unsigned short aLayout, LayoutPaneItem aItems[], unsigned char  aCount)
  {
    number = aLayout;
    mItems = aItems;
    mCount = aCount;
    if (mCount > 0)
      mFocused = 0;

  }

  /**
   * @brief Handles key events for navigation
   * 
   * @param aKey Key code to process
   * @return true if the key was handled
   */
  bool LayoutPane::Key(Keys aKey)
  {
    if (mCount == 0)
      return false;
    if (aKey == KEY_MENU)
    {
      mFocused = (mFocused + 1) % mCount;
      return true;
    }
    if (aKey == KEY_MENU)
    {
      mFocused = (mFocused - 1 + mCount) % mCount;
      return true;
    }
    return false;
  }

  /**
   * @brief Hides all items in the layout
   */
  void LayoutPane::hider()
  {
    for (int i = 0; i < mCount; i++)
      mItems[i].Element->Hide();
  }

  /**
   * @brief Calculates number of digits in a number
   * 
   * @param n Number to analyze
   * @return Number of digits
   */
  int LayoutPane::digits(unsigned short n)
  {
    return n < 10 ? 1 : 1 + digits(n / 10);
  }

  /**
   * @brief Gets a tile count from a number
   * 
   * @param n Number to extract from
   * @param row Row index
   * @return Digit value at the specified position
   */
  int LayoutPane::getTileCount(unsigned short n, unsigned char row)
  {
    unsigned char index = digits(n) - row - 1;
    for (int i = 0; i < index; i++)
      n /= 10;
    return n % 10;
  }

  /**
   * @brief Draws the layout pane
   * 
   * @param aScreen Screen to draw on
   * @param aPos Position on screen
   * @param aSize Size of the element
   * @param aIsFocused Focus state (1 = focused, 0 = not focused)
   */
  void LayoutPane::drawer(IScreen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused)
  {
    unsigned char rows = digits(number);
    unsigned char rowH = aSize.Y / rows, y = 0;
    unsigned char i = 0;

    for (unsigned char r = 0; r < rows; r++)
    {
      unsigned char cols = getTileCount(number, r);
      unsigned char colW = aSize.X / cols, x = 0;

      for (unsigned char c = 0; c < cols; c++)
      {
        // Placeholder for debugging: displays "X" to visualize grid layout
        aScreen->TextLeft({x,y}, {colW, rowH}, "X", 0);
        //mItems[i].Element->Draw(aScreen, mItems[i].Position, mItems[i].Size, aIsFocused && (i == mFocused));
        x += colW;
      }
      y += rowH;
    }

  }
}
