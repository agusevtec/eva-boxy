#pragma once

#include <evabWindowAlgorithms.h>
#include <evabElementBase.h>

namespace evab
{
  /**
   * @brief List box element with configurable windowing algorithm
   * 
   * Displays a scrollable list of items with navigation support.
   * 
   * @tparam TWindowAlgorithm Windowing algorithm for navigation (Flip/Scroll)
   */
  template <class TWindowAlgorithm>
  class ListBox : public ElementBase, public TWindowAlgorithm
  {
  private:
    ElementBase **mItems = nullptr;  ///< Array of item pointers
    unsigned char mItemHeight = 1;    ///< Height of each item

  public:
    /**
     * @brief Sets the list of items to display
     * 
     * @param aItems Array of element pointers
     * @param aCount Number of items
     * @return Reference to this list box
     */
    ListBox<TWindowAlgorithm> &SetItems(ElementBase *aItems[], int aCount)
    {
      mItems = aItems;
      TWindowAlgorithm::setCount(aCount);
      if (aCount)
        Select(0);
      Redraw();
      return *this;
    }

    /**
     * @brief Sets the height of each item
     * 
     * @param aItemHeight Height in tiles
     * @return Reference to this list box
     */
    ListBox<TWindowAlgorithm> &SetItemHeight(unsigned char aItemHeight)
    {
      mItemHeight = aItemHeight;
      Redraw();
      return *this;
    }

    /**
     * @brief Selects an item by index
     * 
     * @param aIndex Index to select
     */
    void Select(signed char aIndex) override
    {
      TWindowAlgorithm::Select(aIndex);
      Redraw();
    }

    /**
     * @brief Gets an item by index
     * 
     * @param aIndex Index of the item
     * @return Pointer to the item, or nullptr if invalid
     */
    ElementBase *GetItem(unsigned char aIndex)
    {
      if (aIndex < TWindowAlgorithm::Count())
        return mItems[aIndex];
      return nullptr;
    }

    /**
     * @brief Increments the selection by a delta
     * 
     * @param delta Amount to increment (positive or negative)
     */
    void Increment(signed char delta)
    {
      Select(Selected() + delta);
    }

    /**
     * @brief Handles key events, forwarding to selected item
     * 
     * @param aKey Key code to process
     * @return true if the key was handled
     */
    bool Key(Keys aKey) override
    {
      signed char selected = TWindowAlgorithm::Selected();
      if (selected == -1)
        return false;

      if (mItems[selected]->Key(aKey))
        return true;

      return false;
    }

  protected:
    /**
     * @brief Draws the list box
     * 
     * @param aScreen Screen to draw on
     * @param aPos Position on screen
     * @param aSize Size of the element
     * @param aIsFocused Focus state (1 = focused, 0 = not focused)
     */
    void drawer(IScreen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override
    {
      TWindowAlgorithm::resizeWindow(aSize.Y / mItemHeight);
      unsigned char visibleElementsCount = 0;
      signed char selected = TWindowAlgorithm::Selected();
      hider();
      for (int i = 0; i < TWindowAlgorithm::Count(); i++)
      {
        int offset = TWindowAlgorithm::indexInWindow(i) * mItemHeight;
        if (offset >= 0)
        {
          mItems[i]->Draw(aScreen, {aPos.X, aPos.Y + offset}, {aSize.X, mItemHeight}, aIsFocused && (i == selected));
          visibleElementsCount++;
        }
      }
      aScreen->Clear({aPos.X, aPos.Y + visibleElementsCount * mItemHeight}, {aSize.X, aSize.Y - visibleElementsCount * mItemHeight});
    }

    /**
     * @brief Hides all items
     */
    void hider() override
    {
      for (int i = 0; i < TWindowAlgorithm::Count(); i++)
        mItems[i]->Hide();
    }
  };

  // Convenience typedefs for common list box types
  using ScrollListbox = ListBox<ScrollWindowAlgorithm>;  ///< Scrollable list box
  using FlipListbox = ListBox<FlipWindowAlgorithm>;      ///< Flip-based list box
}
