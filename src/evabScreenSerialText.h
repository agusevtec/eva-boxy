#pragma once

#include <evabScreenBase.h>

namespace evab
{

    class ScreenSerialText : public ScreenBase
    {
    public:
        ScreenSerialText();
        
        void clear();
        void printToSerial();
        
        Coor Size() override;

    protected:
        void DrawSymbol(Coor aPosition, Coor aSize, char aCharcode, unsigned char aColor) override;

    private:
        char mBuffer[128];
    };

}