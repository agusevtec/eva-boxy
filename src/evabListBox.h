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
    unsigned char mItemHeight;  ///< Height of each item
    ElementBase **mItems; ///< Array of item pointers

  public:
    ListBox(unsigned char aItemHeight)
        : mItemHeight(max(1, aItemHeight)), mItems(nullptr), TWindowAlgorithm(0)
    {
    }

    template <int N>
    ListBox(unsigned char aItemHeight, ElementBase *(&aItems)[N])
        : mItemHeight(max(1, aItemHeight)), mItems(aItems), TWindowAlgorithm(N)
    {
    }

    /**
     * @brief Sets the list of items to display
     *
     * @param aItems Array of element pointers
     * @return Reference to this list box
     */
    template <int N>
    void SetItems(ElementBase *(&aItems)[N])
    {
      mItems = aItems;
      TWindowAlgorithm::setCount(N);
      redraw();
    }

    void SetItemsPtr(ElementBase *aItems[], unsigned char aSize)
    {
      mItems = aItems;
      TWindowAlgorithm::setCount(aSize);
      redraw();
    }

    /**
     * @brief Sets the height of each item
     *
     * @param aItemHeight Height in tiles
     * @return Reference to this list box
     */
    void SetItemHeight(unsigned char aItemHeight)
    {
      mItemHeight = aItemHeight;
      redraw();
    }

    /**
     * @brief Selects an item by index
     *
     * @param aIndex Index to select
     */
    void Select(unsigned char aIndex) override
    {
      TWindowAlgorithm::Select(aIndex);
      redraw();
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
    bool OnKey(Keys aKey) override
    {
      if (!mItems)
        return false;

      signed char selected = TWindowAlgorithm::Selected();
      if (selected == -1)
        return false;

      ElementBase *item = mItems[selected];
      if (!item)
        return false;

      return item->OnKey(aKey);
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
    void drawer(Screen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override
    {
      TWindowAlgorithm::setWindowSize(aSize.Y / mItemHeight);
      unsigned char visibleElementsCount = 0;
      signed char selected = TWindowAlgorithm::Selected();
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
    void freezer() override
    {
      for (int i = 0; i < TWindowAlgorithm::Count(); i++)
        mItems[i]->Freeze();
    }
  };

  // Convenience typedefs for common list box types
  using ScrollListbox = ListBox<ScrollWindowAlgorithm>; ///< Scrollable list box
  using FlipListbox = ListBox<FlipWindowAlgorithm>;     ///< Flip-based list box
}
