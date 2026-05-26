// SSH1106_128x64.h
#pragma once

#include "Coor.h"
#include "Font8Thin.h"
#include "Font8Compact.h"
#include "Font8Bold.h"
#include "Page8ScreenBase.h"


class SSH1106Screen : public Page8ScreenBase<Font8Thin>
{
public:
    SSH1106Screen();
    void clearDisplay();

protected:
    void DrawVerticalSlice(Coor aPosition, unsigned char aSliceColumn, unsigned char aSlice) override;
    void ClearTile(Coor aPosition) override;
    Coor Size() override;

private:
    void sendCommand(unsigned char cmd);
    void sendData(unsigned char data);
    void setPage(unsigned char page);
    void setColumn(unsigned char col);

    uint8_t _address;
};
