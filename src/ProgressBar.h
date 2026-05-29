#pragma once

#include <evabElementBase.h>

namespace evab
{
    class ProgressBar : public ElementBase
    {
    public:
        ProgressBar(unsigned char aValue);
        void SetValue(unsigned char aValue);

    private:
        void drawer(IScreen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override;
        const unsigned char *getPicto(unsigned char blockNumber, unsigned char blockFillNumber);

    private:
        unsigned char mValue;
    };
}