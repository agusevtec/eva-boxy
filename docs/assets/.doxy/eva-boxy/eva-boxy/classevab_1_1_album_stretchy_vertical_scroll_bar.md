

# Class evab::AlbumStretchyVerticalScrollBar



[**ClassList**](annotated.md) **>** [**evab**](namespaceevab.md) **>** [**AlbumStretchyVerticalScrollBar**](classevab_1_1_album_stretchy_vertical_scroll_bar.md)



_Vertical scroll bar pictogram set._ 

* `#include <evabAlbumsStretchy.h>`







































## Public Static Functions

| Type | Name |
| ---: | :--- |
|  const unsigned char \* | [**GetTile**](#function-gettile) (unsigned char blockType, unsigned char fillNumber) <br>_Gets pictogram for vertical scroll bar._  |


























## Public Static Functions Documentation




### function GetTile 

_Gets pictogram for vertical scroll bar._ 
```C++
static const unsigned char * evab::AlbumStretchyVerticalScrollBar::GetTile (
    unsigned char blockType,
    unsigned char fillNumber
) 
```





**Parameters:**


* `blockType` Block type (1=start, 2=middle, 3=end) 
* `fillNumber` Fill level (0-4) 



**Returns:**

Pointer to pictogram data 





        

<hr>

------------------------------
The documentation for this class was generated from the following file `src/evabAlbumsStretchy.h`

