

# Struct evab::HorizontalTilesetPolicy



[**ClassList**](annotated.md) **>** [**evab**](namespaceevab.md) **>** [**HorizontalTilesetPolicy**](structevab_1_1_horizontal_tileset_policy.md)



_Policy for horizontal orientation of stretch bars._ 

* `#include <evabStretchBarPx.h>`







































## Public Static Functions

| Type | Name |
| ---: | :--- |
|  unsigned short | [**CalculateResolution**](#function-calculateresolution) ([**Coor**](structevab_1_1_coor.md) aSize) <br>_Calculates resolution (number of possible positions)._  |
|  unsigned short | [**CalculateTotalBlocks**](#function-calculatetotalblocks) ([**Coor**](structevab_1_1_coor.md) aSize) <br>_Calculates total number of blocks._  |
|  [**Coor**](structevab_1_1_coor.md) | [**GetRestPosition**](#function-getrestposition) ([**Coor**](structevab_1_1_coor.md) aPos, [**Coor**](structevab_1_1_coor.md) aSize) <br> |
|  [**Coor**](structevab_1_1_coor.md) | [**GetRestSize**](#function-getrestsize) ([**Coor**](structevab_1_1_coor.md) aPos, [**Coor**](structevab_1_1_coor.md) aSize) <br> |
|  [**Coor**](structevab_1_1_coor.md) | [**GetTilePosition**](#function-gettileposition) ([**Coor**](structevab_1_1_coor.md) aPos, [**Coor**](structevab_1_1_coor.md) aSize, unsigned char index, unsigned char total) <br>_Gets position of a block._  |


























## Public Static Functions Documentation




### function CalculateResolution 

_Calculates resolution (number of possible positions)._ 
```C++
static inline unsigned short evab::HorizontalTilesetPolicy::CalculateResolution (
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
static inline unsigned short evab::HorizontalTilesetPolicy::CalculateTotalBlocks (
    Coor aSize
) 
```





**Parameters:**


* `aSize` Size of the element 



**Returns:**

Total number of blocks 





        

<hr>



### function GetRestPosition 

```C++
static inline Coor evab::HorizontalTilesetPolicy::GetRestPosition (
    Coor aPos,
    Coor aSize
) 
```




<hr>



### function GetRestSize 

```C++
static inline Coor evab::HorizontalTilesetPolicy::GetRestSize (
    Coor aPos,
    Coor aSize
) 
```




<hr>



### function GetTilePosition 

_Gets position of a block._ 
```C++
static inline Coor evab::HorizontalTilesetPolicy::GetTilePosition (
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
The documentation for this class was generated from the following file `src/evabStretchBarPx.h`

