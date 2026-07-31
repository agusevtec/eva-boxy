

# File evabAlbums.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**evabAlbums.h**](evab_albums_8h.md)

[Go to the documentation of this file](evab_albums_8h.md)


```C++
#pragma once
namespace evab
{

    class AlbumOnOff
    {
    public:
        static const unsigned char *GetTile(unsigned char aIndex);
        static constexpr unsigned char Count = 2; 
    };

    class AlbumRainbowmeter
    {
    public:
        static const unsigned char *GetTile(unsigned char aIndex);
        static constexpr unsigned char Count = 7; 
    };

    class AlbumFan
    {
    public:
        static const unsigned char *GetTile(unsigned char aIndex);
        static constexpr unsigned char Count = 3; 
    };

    class AlbumBattery
    {
    public:
        static const unsigned char *GetTile(unsigned char aIndex);
        static constexpr unsigned char Count = 7; 
    };

    class AlbumLamp
    {
    public:
        static const unsigned char *GetTile(unsigned char aIndex);
        static constexpr unsigned char Count = 6; 
    };

    class AlbumProgress
    {
    public:
        static const unsigned char *GetTile(unsigned char aIndex);
        static constexpr unsigned char Count = 9; 
    };

    class AlbumSpeaker
    {
    public:
        static const unsigned char *GetTile(unsigned char aIndex);
        static constexpr unsigned char Count = 4; 
    };

    class AlbumSignal
    {
    public:
        static const unsigned char *GetTile(unsigned char aIndex);
        static constexpr unsigned char Count = 4; 
    };

    class AlbumRoundmeter
    {
    public:
        static const unsigned char *GetTile(unsigned char aIndex);
        static constexpr unsigned char Count = 13;
    };

}
```


