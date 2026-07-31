

# Class evab::AlbumFan



[**ClassList**](annotated.md) **>** [**evab**](namespaceevab.md) **>** [**AlbumFan**](classevab_1_1_album_fan.md)



_Fan pictogram set (3 states)._ 

* `#include <evabAlbums.h>`























## Public Static Attributes

| Type | Name |
| ---: | :--- |
|  unsigned char | [**Count**](#variable-count)   = `3`<br>_Number of pictograms._  |
















## Public Static Functions

| Type | Name |
| ---: | :--- |
|  const unsigned char \* | [**GetTile**](#function-gettile) (unsigned char aIndex) <br>_Gets pictogram by index._  |


























## Public Static Attributes Documentation




### variable Count 

_Number of pictograms._ 
```C++
unsigned char evab::AlbumFan::Count;
```




<hr>
## Public Static Functions Documentation




### function GetTile 

_Gets pictogram by index._ 
```C++
static const unsigned char * evab::AlbumFan::GetTile (
    unsigned char aIndex
) 
```





**Parameters:**


* `aIndex` Index (0-2) 



**Returns:**

Pointer to pictogram data 





        

<hr>

------------------------------
The documentation for this class was generated from the following file `src/evabAlbums.h`

