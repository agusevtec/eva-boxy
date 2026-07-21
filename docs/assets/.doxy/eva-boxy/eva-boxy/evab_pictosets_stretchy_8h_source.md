

# File evabPictosetsStretchy.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**evabPictosetsStretchy.h**](evab_pictosets_stretchy_8h.md)

[Go to the documentation of this file](evab_pictosets_stretchy_8h.md)


```C++
#pragma once

namespace evab
{
    class PictosetVerticalProgressBar
    {
        public:
        static const unsigned char* GetTile(unsigned char blockType, unsigned char fillNumber);
    };

    class PictosetHorizontalProgressBar
    {
        public:
        static const unsigned char* GetTile(unsigned char blockType, unsigned char fillNumber);
    };

    class PictosetVerticalScrollBar
    {
        public:
        static const unsigned char* GetTile(unsigned char blockType, unsigned char fillNumber);
    };

    class PictosetHorizontalScrollBar
    {
        public:
        static const unsigned char* GetTile(unsigned char blockType, unsigned char fillNumber);
    };

};
```


