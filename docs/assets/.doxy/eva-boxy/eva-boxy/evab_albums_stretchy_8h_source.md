

# File evabAlbumsStretchy.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**evabAlbumsStretchy.h**](evab_albums_stretchy_8h.md)

[Go to the documentation of this file](evab_albums_stretchy_8h.md)


```C++
#pragma once

namespace evab
{
    class AlbumStretchyVerticalProgressBar
    {
        public:
        static const unsigned char* GetTile(unsigned char blockType, unsigned char fillNumber);
    };

    class AlbumStretchyHorizontalProgressBar
    {
        public:
        static const unsigned char* GetTile(unsigned char blockType, unsigned char fillNumber);
    };

    class AlbumStretchyVerticalScrollBar
    {
        public:
        static const unsigned char* GetTile(unsigned char blockType, unsigned char fillNumber);
    };

    class AlbumStretchyHorizontalScrollBar
    {
        public:
        static const unsigned char* GetTile(unsigned char blockType, unsigned char fillNumber);
    };

};
```


