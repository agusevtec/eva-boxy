#pragma once

#include <evabElementBase.h>

namespace evab
{
    class ProgressBar : public ElementBase
    {
    public:
        ProgressBar(unsigned char aValue);
        void SetValue(unsigned char aValue);
        unsigned char Resolution();

    private:
        void drawer(IScreen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override;


    private:
        unsigned char mValue;
    };
}

 //       const unsigned char *getPicto(unsigned char blockNumber, unsigned char blockFillNumber);