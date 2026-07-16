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
        unsigned short Serialize(const Coor &aPos, const Coor &aSize, bool isFocused);
        void Deserialize(unsigned short aSerialized, Coor &aPos, Coor &aSize, bool &isFocused);

    protected:
        void DrawSymbol(Coor aPosition, Coor aSize, char aCharcode, unsigned char aColor) override;

    private:
        char mBuffer[128];
    };

}