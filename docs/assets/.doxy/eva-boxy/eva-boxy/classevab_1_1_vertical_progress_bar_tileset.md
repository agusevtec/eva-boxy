

# Class evab::VerticalProgressBarTileset



[**ClassList**](annotated.md) **>** [**evab**](namespaceevab.md) **>** [**VerticalProgressBarTileset**](classevab_1_1_vertical_progress_bar_tileset.md)



_Vertical progress bar pictogram set._ 

* `#include <evabStretchBarPxResources.h>`







































## Public Static Functions

| Type | Name |
| ---: | :--- |
|  const unsigned char \* | [**GetTile**](#function-gettile) (unsigned char blockType, unsigned char fillNumber) <br>_Gets pictogram for vertical progress bar._  |


























## Public Static Functions Documentation




### function GetTile 

_Gets pictogram for vertical progress bar._ 
```C++
static const unsigned char * evab::VerticalProgressBarTileset::GetTile (
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

