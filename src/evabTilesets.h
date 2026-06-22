#pragma once
#include <Arduino.h>
namespace evab
{

    class TilesetOnOff
    {
    public:
        static const uint8_t *GetTile(unsigned char aIndex);
        static constexpr unsigned char Count = 2;
    };

    class TilesetRainbowmeter
    {
    public:
        static const uint8_t *GetTile(unsigned char aIndex);
        static constexpr unsigned char Count = 7;
    };

    class TilesetRoundmeter
    {
    public:
        static const uint8_t *GetTile(unsigned char aIndex);
        static constexpr unsigned char Count = 9;
    };

    class TilesetFan
    {
    public:
        static const uint8_t *GetTile(unsigned char aIndex);
        static constexpr unsigned char Count = 3;
    };

    class TilesetHorizontalProgressBar1x1
    {
    public:
        static const uint8_t *GetTile(unsigned char aIndex);
        static constexpr unsigned char Count = 5;
    };

    class TilesetBattery
    {
    public:
        static const uint8_t *GetTile(unsigned char aIndex);
        static constexpr unsigned char Count = 7;
    };

    class TilesetLamp
    {
    public:
        static const uint8_t *GetTile(unsigned char aIndex);
        static constexpr unsigned char Count = 6;
    };

    class TilesetProgress
    {
    public:
        static const uint8_t *GetTile(unsigned char aIndex);
        static constexpr unsigned char Count = 9;
    };

    class TilesetSpeaker
    {
    public:
        static const uint8_t *GetTile(unsigned char aIndex);
        static constexpr unsigned char Count = 4;
    };

    class TilesetSignal
    {
    public:
        static const uint8_t *GetTile(unsigned char aIndex);
        static constexpr unsigned char Count = 4;
    };

}