

# File evabTilesets.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**evabTilesets.h**](evab_tilesets_8h.md)

[Go to the documentation of this file](evab_tilesets_8h.md)


```C++
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

    class TileSetBattery
    {
    public:
        static const uint8_t *GetTile(unsigned char aIndex);
        static constexpr unsigned char Count = 7;
    };

    class TileSetLamp
    {
    public:
        static const uint8_t *GetTile(unsigned char aIndex);
        static constexpr unsigned char Count = 6;
    };

    class TileSetProgress
    {
    public:
        static const uint8_t *GetTile(unsigned char aIndex);
        static constexpr unsigned char Count = 9;
    };

    class TileSetSpeaker
    {
    public:
        static const uint8_t *GetTile(unsigned char aIndex);
        static constexpr unsigned char Count = 4;
    };

    class TileSetSignal
    {
    public:
        static const uint8_t *GetTile(unsigned char aIndex);
        static constexpr unsigned char Count = 4;
    };

}
```


