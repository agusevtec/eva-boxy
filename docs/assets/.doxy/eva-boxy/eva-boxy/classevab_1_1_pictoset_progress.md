

# Class evab::PictosetProgress



[**ClassList**](annotated.md) **>** [**evab**](namespaceevab.md) **>** [**PictosetProgress**](classevab_1_1_pictoset_progress.md)



_Progress pictogram set (9 states)._ 

* `#include <evabPictosets.h>`























## Public Static Attributes

| Type | Name |
| ---: | :--- |
|  unsigned char | [**Count**](#variable-count)   = `9`<br>_Number of pictograms._  |
















## Public Static Functions

| Type | Name |
| ---: | :--- |
|  const unsigned char \* | [**GetTile**](#function-gettile) (unsigned char aIndex) <br>_Gets pictogram by index._  |


























## Public Static Attributes Documentation




### variable Count 

_Number of pictograms._ 
```C++
unsigned char evab::PictosetProgress::Count;
```




<hr>
## Public Static Functions Documentation




### function GetTile 

_Gets pictogram by index._ 
```C++
static const unsigned char * evab::PictosetProgress::GetTile (
    unsigned char aIndex
) 
```





**Parameters:**


* `aIndex` Index (0-8) 



**Returns:**

Pointer to pictogram data 





        

<hr>

------------------------------
The documentation for this class was generated from the following file `src/evabPictosets.h`

