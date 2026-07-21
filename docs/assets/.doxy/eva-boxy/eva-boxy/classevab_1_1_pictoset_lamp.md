

# Class evab::PictosetLamp



[**ClassList**](annotated.md) **>** [**evab**](namespaceevab.md) **>** [**PictosetLamp**](classevab_1_1_pictoset_lamp.md)



_Lamp pictogram set (6 states)._ 

* `#include <evabPictosets.h>`























## Public Static Attributes

| Type | Name |
| ---: | :--- |
|  unsigned char | [**Count**](#variable-count)   = `6`<br>_Number of pictograms._  |
















## Public Static Functions

| Type | Name |
| ---: | :--- |
|  const unsigned char \* | [**GetTile**](#function-gettile) (unsigned char aIndex) <br>_Gets pictogram by index._  |


























## Public Static Attributes Documentation




### variable Count 

_Number of pictograms._ 
```C++
unsigned char evab::PictosetLamp::Count;
```




<hr>
## Public Static Functions Documentation




### function GetTile 

_Gets pictogram by index._ 
```C++
static const unsigned char * evab::PictosetLamp::GetTile (
    unsigned char aIndex
) 
```





**Parameters:**


* `aIndex` Index (0-5) 



**Returns:**

Pointer to pictogram data 





        

<hr>

------------------------------
The documentation for this class was generated from the following file `src/evabPictosets.h`

