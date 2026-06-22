#include "evabElementBase.h"
#pragma once

namespace evab
{

    template <class TTileSet>
    class InputPictogram : public ElementBase
    {
    public:
        InputPictogram(int aValue = 0)
        {
            SetValue(aValue);
        }
        signed char SetValue(int aValue)
        {
            mValue = constrain(aValue, 0, TTileSet::Count - 1);
        }
        signed char GetValue() const
        {
            return mValue;
        }

        void SetValuePercent(int aValue)
        {
            SetValue(map(mValue, 0, 100, 0, TTileSet::Count - 1));
        }

        signed char GetValuePercent() const
        {
            return map(mValue, 0, TTileSet::Count - 1, 0, 100);
        }

        void Increment(signed char delta)
        {
            SetValue(mValue + delta);
        }

    protected:
        void drawer(IScreen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override
        {
            aScreen->Picto(aPos, TTileSet::GetTile(mValue), aIsFocused);
        }

    private:
        signed char mValue;
    };

}