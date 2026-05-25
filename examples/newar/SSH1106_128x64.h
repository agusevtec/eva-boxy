// SSH1106_128x64.h
#pragma once

#include "Coor.h"
#include "Font2Tile8x8.h"
#include "Tile64PagedScreenBase.h"


class SSH1106_128x64 : public Tile64PagedScreenBase<Font2Tile8x8>
{
public:
    SSH1106_128x64();
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
