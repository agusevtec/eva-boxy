

# File evabPictosets.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**evabPictosets.h**](evab_pictosets_8h.md)

[Go to the documentation of this file](evab_pictosets_8h.md)


```C++
#pragma once
namespace evab
{

    class PictosetOnOff
    {
    public:
        static const unsigned char *GetTile(unsigned char aIndex);
        static constexpr unsigned char Count = 2;  
    };

    class PictosetRainbowmeter
    {
    public:
        static const unsigned char *GetTile(unsigned char aIndex);
        static constexpr unsigned char Count = 7;  
    };

    class PictosetRoundmeter
    {
    public:
        static const unsigned char *GetTile(unsigned char aIndex);
        static constexpr unsigned char Count = 9;  
    };

    class PictosetFan
    {
    public:
        static const unsigned char *GetTile(unsigned char aIndex);
        static constexpr unsigned char Count = 3;  
    };

    
    class PictosetBattery
    {
    public:
        static const unsigned char *GetTile(unsigned char aIndex);
        static constexpr unsigned char Count = 7;  
    };

    class PictosetLamp
    {
    public:
        static const unsigned char *GetTile(unsigned char aIndex);
        static constexpr unsigned char Count = 6;  
    };

    class PictosetProgress
    {
    public:
        static const unsigned char *GetTile(unsigned char aIndex);
        static constexpr unsigned char Count = 9;  
    };

    class PictosetSpeaker
    {
    public:
        static const unsigned char *GetTile(unsigned char aIndex);
        static constexpr unsigned char Count = 4;  
    };

    class PictosetSignal
    {
    public:
        static const unsigned char *GetTile(unsigned char aIndex);
        static constexpr unsigned char Count = 4;  
    };

}
```


