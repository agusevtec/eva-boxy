#include "evabLayoutPane.h"

namespace evab
{

  // LayoutPane::LayoutPane(CompositeBase *aContainer) : CompositeBase(aContainer)
  // {
  // }

  void LayoutPane::SetItems(LayoutPaneItem aItems[], int aCount)
  {
    mItems = aItems;
    mCount = aCount;
    if (mCount > 0)
    {
      mFocused = 0;
      focusChild(mItems[0].Element);
    }
  }

  bool LayoutPane::onResidualKey(Keys aKey)
  {
    if (mCount == 0)
      return false;
    if (aKey == 'l')
    {
      mFocused = (mFocused + 1) % mCount;
      focusChild(mItems[mFocused].Element);
      return true;
    }
    if (aKey == 'r')
    {
      mFocused = (mFocused - 1 + mCount) % mCount;
      focusChild(mItems[mFocused].Element);
      return true;
    }
    return false;
  }

  void LayoutPane::hider()
  {
    for (int i = 0; i < mCount; i++)
      mItems[i].Element->Hide();
  }

  void LayoutPane::drawer(IScreen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused)
  {
    for (int i = 0; i < mCount; i++)
      mItems[i].Element->Draw(aScreen, mItems[i].Position, mItems[i].Size, aIsFocused && (i == mFocused));
  }
}
