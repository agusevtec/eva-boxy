

# Class evab::Font8Compact



[**ClassList**](annotated.md) **>** [**evab**](namespaceevab.md) **>** [**Font8Compact**](classevab_1_1_font8_compact.md)



_8x8 compact font implementation_ [More...](#detailed-description)

* `#include <evabFont8Compact.h>`



Inherits the following classes: [evab::IFont](classevab_1_1_i_font.md)






















































## Public Functions

| Type | Name |
| ---: | :--- |
| virtual unsigned char | [**GetVerticalSlice**](#function-getverticalslice) (char aCharcode, unsigned char aSliceColumn) override const<br>_Gets a vertical slice of a character._  |


## Public Functions inherited from evab::IFont

See [evab::IFont](classevab_1_1_i_font.md)

| Type | Name |
| ---: | :--- |
| virtual unsigned char | [**GetVerticalSlice**](classevab_1_1_i_font.md#function-getverticalslice) (char aCharcode, unsigned char col) const = 0<br>_Gets a vertical slice (column) of a character._  |






















































## Detailed Description


Provides a compact 8x8 pixel font that saves memory by storing only 5 columns per character. 


    
## Public Functions Documentation




### function GetVerticalSlice 

_Gets a vertical slice of a character._ 
```C++
virtual unsigned char evab::Font8Compact::GetVerticalSlice (
    char aCharcode,
    unsigned char aSliceColumn
) override const
```





**Parameters:**


* `aCharcode` ASCII character code (32-126) 
* `aSliceColumn` Column index (0-7) 



**Returns:**

unsigned char Bitmap data for the specified column 





        
Implements [*evab::IFont::GetVerticalSlice*](classevab_1_1_i_font.md#function-getverticalslice)


<hr>

------------------------------
The documentation for this class was generated from the following file `src/evabFont8Compact.h`

