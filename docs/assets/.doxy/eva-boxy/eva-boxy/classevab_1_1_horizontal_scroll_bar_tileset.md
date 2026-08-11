

# Class evab::HorizontalScrollBarTileset



[**ClassList**](annotated.md) **>** [**evab**](namespaceevab.md) **>** [**HorizontalScrollBarTileset**](classevab_1_1_horizontal_scroll_bar_tileset.md)



_Horizontal scroll bar pictogram set._ 

* `#include <evabStretchBarPxResources.h>`







































## Public Static Functions

| Type | Name |
| ---: | :--- |
|  const unsigned char \* | [**GetTile**](#function-gettile) (unsigned char blockType, unsigned char fillNumber) <br>_Gets pictogram for horizontal scroll bar._  |


























## Public Static Functions Documentation




### function GetTile 

_Gets pictogram for horizontal scroll bar._ 
```C++
static const unsigned char * evab::HorizontalScrollBarTileset::GetTile (
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

