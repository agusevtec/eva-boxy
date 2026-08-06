

# Struct evab::LeftAlign



[**ClassList**](annotated.md) **>** [**evab**](namespaceevab.md) **>** [**LeftAlign**](structevab_1_1_left_align.md)



_Left alignment strategy._ 

* `#include <evabTextAlign.h>`







































## Public Static Functions

| Type | Name |
| ---: | :--- |
|  unsigned char | [**Offset**](#function-offset) ([**Coor**](structevab_1_1_coor.md) aSize, unsigned char textLen) <br>_Calculates offset for left alignment._  |


























## Public Static Functions Documentation




### function Offset 

_Calculates offset for left alignment._ 
```C++
static unsigned char evab::LeftAlign::Offset (
    Coor aSize,
    unsigned char textLen
) 
```





**Parameters:**


* `aSize` Available area size 
* `textLen` Text length in characters 



**Returns:**

Always 0 (left alignment) 





        

<hr>

------------------------------
The documentation for this class was generated from the following file `src/evabTextAlign.h`

