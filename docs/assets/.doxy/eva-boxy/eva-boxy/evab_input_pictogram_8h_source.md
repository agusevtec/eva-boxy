

# File evabInputPictogram.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**evabInputPictogram.h**](evab_input_pictogram_8h.md)

[Go to the documentation of this file](evab_input_pictogram_8h.md)


```C++
#include "evabElementBase.h"
#pragma once

namespace evab
{

    template <class TPictoset>
    class InputPictogram : public ElementBase
    {
    public:
        InputPictogram(int aValue = 0)
        {
            mValue = constrain(aValue, 0, TPictoset::Count - 1);
        }
        
        void SetValue(int aValue)
        {
            mValue = constrain(aValue, 0, TPictoset::Count - 1);
            Redraw();
        }
        
        signed char GetValue() const
        {
            return mValue;
        }

        void SetValuePercent(int aValue)
        {
            SetValue(map(aValue, 0, 100, 0, TPictoset::Count - 1));
        }

        signed char GetValuePercent() const
        {
            return map(mValue, 0, TPictoset::Count - 1, 0, 100);
        }

        void Increment(signed char delta)
        {
            SetValue(mValue + delta);
        }

    protected:
        void drawer(IScreen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override
        {
            aScreen->Picto(aPos, TPictoset::GetTile(mValue), aIsFocused);
        }

    private:
        signed char mValue;  
    };

}
```


