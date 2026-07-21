#pragma once

#include <evabElementBase.h>

namespace evab
{
  /**
   * @brief Structure defining a single item in a layout pane
   */
  struct LayoutPaneItem
  {
    ElementBase *Element;  ///< Pointer to the element
    Coor Position;          ///< Position of the item
    Coor Size;              ///< Size of the item
  };

  /**
   * @brief Dynamic layout pane for arranging items in a grid
   * 
   * Uses a numeric layout definition to determine the grid structure.
   * Each digit represents the number of items in that row.
   * Currently in development (debug version).
   */
  class LayoutPane: public ElementBase
  {
  public:
    // LayoutPane(CompositeBase *aContainer);
      /**
       * @brief Sets up the layout pane with items
       * 
       * @param aLayout Layout configuration (digits represent items per row)
       * @param aItems Array of layout items
       * @param aCount Number of items
       */
      void SetItems(unsigned short aLayout, LayoutPaneItem aItems[], unsigned char  aCount);

  private:
    /**
     * @brief Handles key events for navigation
     * 
     * @param aKey Key code to process
     * @return true if the key was handled
     */
    bool Key(Keys aKey) override;
    
    /**
     * @brief Draws the layout pane
     * 
     * @param aScreen Screen to draw on
     * @param aPos Position on screen
     * @param aSize Size of the element
     * @param aIsFocused Focus state (1 = focused, 0 = not focused)
     */
    void drawer(IScreen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override;
    
    /**
     * @brief Hides all items in the layout
     */
    void hider() override;
    
    /**
     * @brief Calculates number of digits in a number
     * 
     * @param n Number to analyze
     * @return Number of digits
     */
    static int digits(unsigned short n);
    
    /**
     * @brief Gets a tile count from a number
     * 
     * @param n Number to extract from
     * @param row Row index
     * @return Digit value at the specified position
     */
    static int getTileCount(unsigned short n, unsigned char row);

  private:
    LayoutPaneItem *mItems = nullptr;  ///< Array of layout items
    int mCount = 0;                    ///< Number of items
    int mFocused = -1;                 ///< Currently focused item index
    unsigned short number;             ///< Layout configuration
  };
}
