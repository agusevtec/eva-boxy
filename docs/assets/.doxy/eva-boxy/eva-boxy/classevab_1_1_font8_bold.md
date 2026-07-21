

# Class evab::Font8Bold



[**ClassList**](annotated.md) **>** [**evab**](namespaceevab.md) **>** [**Font8Bold**](classevab_1_1_font8_bold.md)



_8x8 bold font implementation_ [More...](#detailed-description)

* `#include <evabFont8Bold.h>`



Inherits the following classes: [evab::IFont](classevab_1_1_i_font.md)






















































## Public Functions

| Type | Name |
| ---: | :--- |
| virtual unsigned char | [**GetVerticalSlice**](#function-getverticalslice) (char aCharcode, unsigned char col) override const<br>_Gets a vertical slice of a character._  |


## Public Functions inherited from evab::IFont

See [evab::IFont](classevab_1_1_i_font.md)

| Type | Name |
| ---: | :--- |
| virtual unsigned char | [**GetVerticalSlice**](classevab_1_1_i_font.md#function-getverticalslice) (char aCharcode, unsigned char col) const = 0<br>_Gets a vertical slice (column) of a character._  |






















































## Detailed Description


Provides a bold 8x8 pixel font for display systems. 


    
## Public Functions Documentation




### function GetVerticalSlice 

_Gets a vertical slice of a character._ 
```C++
virtual unsigned char evab::Font8Bold::GetVerticalSlice (
    char aCharcode,
    unsigned char col
) override const
```





**Parameters:**


* `aCharcode` ASCII character code (32-126) 
* `col` Column index (0-7) 



**Returns:**

unsigned char Bitmap data for the specified column 





        
Implements [*evab::IFont::GetVerticalSlice*](classevab_1_1_i_font.md#function-getverticalslice)


<hr>

------------------------------
The documentation for this class was generated from the following file `src/evabFont8Bold.h`

