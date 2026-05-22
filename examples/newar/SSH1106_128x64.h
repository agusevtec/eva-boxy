// SSH1106_128x64.h
#pragma once

#include "Coor.h"
#include "Tile64PagedScreenBase.h"

class SSH1106_128x64 : public Tile64PagedScreenBase {
public:
    SSH1106_128x64();
    void clearDisplay();
    
protected:
    void DrawVerticalSlice(Coor aPosition, unsigned char aColumn, unsigned char aSlice) override;
    Coor Size() override;
private:
    void sendCommand(unsigned char cmd);
    void sendData(unsigned char data);
    void setPage(unsigned char page);
    void setColumn(unsigned char col);
    
    uint8_t _address;
};

