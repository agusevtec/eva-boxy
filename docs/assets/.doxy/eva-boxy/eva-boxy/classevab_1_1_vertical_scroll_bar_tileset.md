

# Class evab::VerticalScrollBarTileset



[**ClassList**](annotated.md) **>** [**evab**](namespaceevab.md) **>** [**VerticalScrollBarTileset**](classevab_1_1_vertical_scroll_bar_tileset.md)



_Vertical scroll bar pictogram set._ 

* `#include <evabStretchBarPxResources.h>`







































## Public Static Functions

| Type | Name |
| ---: | :--- |
|  const unsigned char \* | [**GetTile**](#function-gettile) (unsigned char blockType, unsigned char fillNumber) <br>_Gets pictogram for vertical scroll bar._  |


























## Public Static Functions Documentation




### function GetTile 

_Gets pictogram for vertical scroll bar._ 
```C++
static const unsigned char * evab::VerticalScrollBarTileset::GetTile (
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
The documentation for this class was generated from the following file `src/evabStretchBarPxResources.h`

