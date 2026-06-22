// TileSetVProgressBar.h
#pragma once
#include <Arduino.h>

namespace evab
{
    class TilesetVerticalProgressBar
    {
        public:
        static const uint8_t* GetTile(unsigned char blockType, unsigned char fillNumber);
    };

    class TilesetHorizontalProgressBar
    {
        public:
        static const uint8_t* GetTile(unsigned char blockType, unsigned char fillNumber);
    };

    class TilesetVerticalScrollBar
    {
        public:
        static const uint8_t* GetTile(unsigned char blockType, unsigned char fillNumber);
    };

    class TilesetHorizontalScrollBar
    {
        public:
        static const uint8_t* GetTile(unsigned char blockType, unsigned char fillNumber);
    };

};
