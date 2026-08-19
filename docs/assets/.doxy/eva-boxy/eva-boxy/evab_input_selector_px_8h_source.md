

# File evabInputSelectorPx.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**evabInputSelectorPx.h**](evab_input_selector_px_8h.md)

[Go to the documentation of this file](evab_input_selector_px_8h.md)


```C++
#pragma once

#include <evabElementBase.h>

namespace evab
{

    template <class TAlbum>
    class InputSelectorPx : public ElementBase
    {
    public:
        InputSelectorPx(int aValue = 0)
        {
            mValue = constrain(aValue, 0, TAlbum::Count - 1);
        }

        void Select(int aValue)
        {
            aValue = constrain(aValue, 0, TAlbum::Count - 1);
            if (mValue == aValue)
                return;
            mValue = aValue;
            redraw();
        }

        signed char Selected() const
        {
            return mValue;
        }

        void Increment(signed char aSteps)
        {
            Select(mValue + aSteps);
        }

        unsigned char Count() const
        {
            return TAlbum::Count;
        }

    protected:
        void drawer(Screen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override
        {
            aScreen->Clear(aPos, aSize, aIsFocused);
            aScreen->Picto(aPos, TAlbum::GetTile(mValue), aIsFocused);
        }

    private:
        signed char mValue; 
    };

}
```


