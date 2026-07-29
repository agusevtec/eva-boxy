

# File evabAlbumsStretchy.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**evabAlbumsStretchy.h**](evab_pictosets_stretchy_8h.md)

[Go to the documentation of this file](evab_pictosets_stretchy_8h.md)


```C++
#pragma once

namespace evab
{
    class AlbumVerticalProgressBar
    {
        public:
        static const unsigned char* GetTile(unsigned char blockType, unsigned char fillNumber);
    };

    class AlbumHorizontalProgressBar
    {
        public:
        static const unsigned char* GetTile(unsigned char blockType, unsigned char fillNumber);
    };

    class AlbumVerticalScrollBar
    {
        public:
        static const unsigned char* GetTile(unsigned char blockType, unsigned char fillNumber);
    };

    class AlbumHorizontalScrollBar
    {
        public:
        static const unsigned char* GetTile(unsigned char blockType, unsigned char fillNumber);
    };

};
```


