#pragma once

#include <evabScreenPage8Base.h>
#include <evabIFont.h>

namespace evab
{

    class ScreenKS0108 : public ScreenPage8Base
    {
    public:
        ScreenKS0108(const IFont *aFont,
                     uint8_t aRS, uint8_t aRW, uint8_t aE,
                     uint8_t aCS1, uint8_t aCS2,
                     uint8_t aDB0, uint8_t aDB1, uint8_t aDB2, uint8_t aDB3,
                     uint8_t aDB4, uint8_t aDB5, uint8_t aDB6, uint8_t aDB7,
                     uint8_t aLED = 255);
        ~ScreenKS0108();

        void SetBacklight(uint8_t aState);
        void clearDisplay();
        Coor Size() override;
        unsigned short Serialize(const Coor &aPos, const Coor &aSize, bool isFocused);
        void Deserialize(unsigned short aSerialized, Coor &aPos, Coor &aSize, bool &isFocused);

    protected:
        void DrawVerticalSlice(Coor aPosition, unsigned char aSliceColumn, unsigned char aSlice) override;
        void ClearTile(Coor aPosition, unsigned char aColor) override;

    private:
        void sendCommand(uint8_t aCmd, uint8_t aChip);
        void sendData(uint8_t aData, uint8_t aChip);
        void setChip(uint8_t aChip);
        void setPage(uint8_t aPage);
        void setColumn(uint8_t aCol);
        void initDisplay();

        void writeByte(uint8_t aByte);
        void pulseE();

        uint8_t mRSPin;
        uint8_t mRWPin;
        uint8_t mEPin;
        uint8_t mCS1Pin;
        uint8_t mCS2Pin;
        uint8_t mDataPins[8];
        uint8_t mLEDPin;
        uint8_t mCurrentChip;
    };

}