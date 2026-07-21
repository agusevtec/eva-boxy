

# Struct evab::HorizontalTextPolicy



[**ClassList**](annotated.md) **>** [**evab**](namespaceevab.md) **>** [**HorizontalTextPolicy**](structevab_1_1_horizontal_text_policy.md)



_Policy for horizontal text-based stretch bars._ 

* `#include <evabInputTextStretchBar.h>`







































## Public Static Functions

| Type | Name |
| ---: | :--- |
|  unsigned short | [**CalculateResolution**](#function-calculateresolution) ([**Coor**](structevab_1_1_coor.md) aSize) <br>_Calculates resolution (number of possible positions)._  |
|  unsigned short | [**CalculateTotalBlocks**](#function-calculatetotalblocks) ([**Coor**](structevab_1_1_coor.md) aSize) <br>_Calculates total number of blocks._  |
|  [**Coor**](structevab_1_1_coor.md) | [**GetTilePosition**](#function-gettileposition) ([**Coor**](structevab_1_1_coor.md) aPos, [**Coor**](structevab_1_1_coor.md) aSize, unsigned char index, unsigned char total) <br>_Gets position of a block._  |


























## Public Static Functions Documentation




### function CalculateResolution 

_Calculates resolution (number of possible positions)._ 
```C++
static inline unsigned short evab::HorizontalTextPolicy::CalculateResolution (
    Coor aSize
) 
```





**Parameters:**


* `aSize` Size of the element 



**Returns:**

Resolution value 





        

<hr>



### function CalculateTotalBlocks 

_Calculates total number of blocks._ 
```C++
static inline unsigned short evab::HorizontalTextPolicy::CalculateTotalBlocks (
    Coor aSize
) 
```





**Parameters:**


* `aSize` Size of the element 



**Returns:**

Total number of blocks 





        

<hr>



### function GetTilePosition 

_Gets position of a block._ 
```C++
static inline Coor evab::HorizontalTextPolicy::GetTilePosition (
    Coor aPos,
    Coor aSize,
    unsigned char index,
    unsigned char total
) 
```





**Parameters:**


* `aPos` Base position 
* `aSize` Size of the element 
* `index` Block index 
* `total` Total number of blocks 



**Returns:**

Position of the block 





        

<hr>

------------------------------
The documentation for this class was generated from the following file `src/evabInputTextStretchBar.h`

