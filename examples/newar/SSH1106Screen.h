// SSH1106_128x64.h
#pragma once

#include "Coor.h"
#include "Font8Standart.h"
#include "Page8ScreenBase.h"


class SSH1106Screen : public Page8ScreenBase<Font8Standart>
{
public:
    SSH1106Screen();
    void clearDisplay();

protected:
    void DrawVerticalSlice(Coor aPosition, unsigned char aColumn, unsigned char aSlice) override;
    void ClearTile(Coor aPosition) override;
    Coor Size() override;

private:
    void sendCommand(unsigned char cmd);
    void sendData(unsigned char data);
    void setPage(unsigned char page);
    void setColumn(unsigned char col);

    uint8_t _address;
};
