

# Class evab::IFont



[**ClassList**](annotated.md) **>** [**evab**](namespaceevab.md) **>** [**IFont**](classevab_1_1_i_font.md)



_Abstract interface for font providers._ [More...](#detailed-description)

* `#include <evabIFont.h>`





Inherited by the following classes: [evab::Font8Bold](classevab_1_1_font8_bold.md),  [evab::Font8Compact](classevab_1_1_font8_compact.md),  [evab::Font8Narrow](classevab_1_1_font8_narrow.md)
































## Public Functions

| Type | Name |
| ---: | :--- |
| virtual unsigned char | [**GetVerticalSlice**](#function-getverticalslice) (char aCharcode, unsigned char col) const = 0<br>_Gets a vertical slice (column) of a character._  |




























## Detailed Description


Defines the contract for font implementations that can provide vertical slices of character bitmaps. 


    
## Public Functions Documentation




### function GetVerticalSlice 

_Gets a vertical slice (column) of a character._ 
```C++
virtual unsigned char evab::IFont::GetVerticalSlice (
    char aCharcode,
    unsigned char col
) const = 0
```





**Parameters:**


* `aCharcode` ASCII character code 
* `col` Column index 



**Returns:**

unsigned char Bitmap data for the specified column 





        

<hr>

------------------------------
The documentation for this class was generated from the following file `src/evabIFont.h`

