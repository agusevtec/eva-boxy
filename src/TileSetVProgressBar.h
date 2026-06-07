// TileSetVProgressBar.h
#pragma once


namespace evab
{
    class TileSetVProgressBar
    {
        static constexpr unsigned char FILL_STEPS = 4;
        static const uint8_t* GetTile(unsigned char blockType, unsigned char fillNumber);
    };
};
