// TileSetVProgressBar.h
#pragma once
#include <Arduino.h>

namespace evab
{
    class TilesetVProgressbar
    {
        public:
        static const uint8_t* GetTile(unsigned char blockType, unsigned char fillNumber);
    };

    class TilesetHProgressbar
    {
        public:
        static const uint8_t* GetTile(unsigned char blockType, unsigned char fillNumber);
    };

    class TilesetVScrollbar
    {
        public:
        static const uint8_t* GetTile(unsigned char blockType, unsigned char fillNumber);
    };

    class TilesetHScrollbar
    {
        public:
        static const uint8_t* GetTile(unsigned char blockType, unsigned char fillNumber);
    };

};
