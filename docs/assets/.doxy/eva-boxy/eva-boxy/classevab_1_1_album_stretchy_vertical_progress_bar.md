

# Class evab::AlbumStretchyVerticalProgressBar



[**ClassList**](annotated.md) **>** [**evab**](namespaceevab.md) **>** [**AlbumStretchyVerticalProgressBar**](classevab_1_1_album_stretchy_vertical_progress_bar.md)



_Vertical progress bar pictogram set._ 

* `#include <evabAlbumsStretchy.h>`







































## Public Static Functions

| Type | Name |
| ---: | :--- |
|  const unsigned char \* | [**GetTile**](#function-gettile) (unsigned char blockType, unsigned char fillNumber) <br>_Gets pictogram for vertical progress bar._  |


























## Public Static Functions Documentation




### function GetTile 

_Gets pictogram for vertical progress bar._ 
```C++
static const unsigned char * evab::AlbumStretchyVerticalProgressBar::GetTile (
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

