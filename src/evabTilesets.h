#pragma once
#include <Arduino.h>

class TilesetOnoff
{
public:
    static const uint8_t* GetTile(unsigned char aIndex);
    static constexpr unsigned char Count = 2;
};


class TilesetRainbowmeter
{
public:
    static const uint8_t* GetTile(unsigned char aIndex);
    static constexpr unsigned char Count = 7;
};

class TilesetRoundmeter
{
public:
    static const uint8_t* GetTile(unsigned char aIndex);
    static constexpr unsigned char Count = 9;
};

class TilesetFan
{
public:
    static const uint8_t* GetTile(unsigned char aIndex);
    static constexpr unsigned char Count = 3;
};

class TilesetH_progress1
{
public:
    static const uint8_t* GetTile(unsigned char aIndex);
    static constexpr unsigned char Count = 5;
};

class TilesetV_progress1
{
public:
    static const uint8_t* GetTile(unsigned char aIndex);
    static constexpr unsigned char Count = 5;
};

class TilesetH_scroll1
{
public:
    static const uint8_t* GetTile(unsigned char aIndex);
    static constexpr unsigned char Count = 5;
};

class TilesetV_scroll1
{
public:
    static const uint8_t* GetTile(unsigned char aIndex);
    static constexpr unsigned char Count = 5;
};

