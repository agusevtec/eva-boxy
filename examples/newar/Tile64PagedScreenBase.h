#pragma once
#include "TileScreenBase.h"

class Tile64PagedScreenBase : public TileScreenBase {
protected:
    static const uint8_t kCharmap[][5] PROGMEM;
    uint32_t upscale(uint8_t x, uint8_t scale) ;
    uint8_t getSymbolSlice(char charIndex, unsigned char i);

public:
    virtual void DrawSymbol(Coor aPosition, Coor aSize, char aSymbol, unsigned char aColor) override;
    //virtual void Picto(Coor aPosition, Coor aSize, uint8_t aPictoIndex, unsigned char aColor) override;
    virtual void DrawVerticalSlice(Coor aPosition, unsigned char aColumn, unsigned char aSlice) = 0;
};