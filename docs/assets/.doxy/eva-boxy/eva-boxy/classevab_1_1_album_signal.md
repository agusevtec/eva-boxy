

# Class evab::AlbumSignal



[**ClassList**](annotated.md) **>** [**evab**](namespaceevab.md) **>** [**AlbumSignal**](classevab_1_1_album_signal.md)



_Signal pictogram set (4 states)._ 

* `#include <evabAlbums.h>`























## Public Static Attributes

| Type | Name |
| ---: | :--- |
|  unsigned char | [**Count**](#variable-count)   = `4`<br>_Number of pictograms._  |
















## Public Static Functions

| Type | Name |
| ---: | :--- |
|  const unsigned char \* | [**GetTile**](#function-gettile) (unsigned char aIndex) <br>_Gets pictogram by index._  |


























## Public Static Attributes Documentation




### variable Count 

_Number of pictograms._ 
```C++
unsigned char evab::AlbumSignal::Count;
```




<hr>
## Public Static Functions Documentation




### function GetTile 

_Gets pictogram by index._ 
```C++
static const unsigned char * evab::AlbumSignal::GetTile (
    unsigned char aIndex
) 
```





**Parameters:**


* `aIndex` Index (0-3) 



**Returns:**

Pointer to pictogram data 





        

<hr>

------------------------------
The documentation for this class was generated from the following file `src/evabAlbums.h`

