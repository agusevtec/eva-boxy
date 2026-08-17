

# Class evab::Grid



[**ClassList**](annotated.md) **>** [**evab**](namespaceevab.md) **>** [**Grid**](classevab_1_1_grid.md)



_Layout manager for rest-based UI arrangement._ [More...](#detailed-description)

* `#include <evabGrid.h>`





































## Public Functions

| Type | Name |
| ---: | :--- |
|  void | [**Clear**](#function-clear) (unsigned char aIsFocused=0) <br>_Clears the current cell area._  |
|  [**Grid**](classevab_1_1_grid.md#function-grid) | [**CutCol**](#function-cutcol) (unsigned char aWidth=0) <br>_Creates a new_ [_**Grid**_](classevab_1_1_grid.md) _for the next column._ |
|  [**Grid**](classevab_1_1_grid.md#function-grid) | [**CutRow**](#function-cutrow) (unsigned char aHeight=0) <br>_Creates a new_ [_**Grid**_](classevab_1_1_grid.md) _for the next row._ |
|  void | [**Draw**](#function-draw) ([**ElementBase**](classevab_1_1_element_base.md) & aElement, unsigned char aIsFocused=0) <br>_Draws an element in the current cell._  |
|  [**Coor**](structevab_1_1_coor.md) | [**GetPos**](#function-getpos) () const<br>_Gets the current position._  |
|  [**Coor**](structevab_1_1_coor.md) | [**GetSize**](#function-getsize) () const<br>_Gets the current size._  |
|   | [**Grid**](#function-grid) ([**Screen**](classevab_1_1_screen.md) \* aScreen, [**Coor**](structevab_1_1_coor.md) aPos, [**Coor**](structevab_1_1_coor.md) aSize, unsigned char aIsFocused) <br>_Constructs a_ [_**Grid**_](classevab_1_1_grid.md) _for a specific area._ |
|  void | [**Picto**](#function-picto) (const unsigned char \* aPictogram, unsigned char aIsFocused=0) <br>_Draws a pictogram in the current cell._  |
|  void | [**Text**](#function-text) (TText aText, unsigned char aIsFocused=0) <br>_Draws text with specified alignment._  |
|  void | [**TextCenter**](#function-textcenter) (T aText, unsigned char aIsFocused=0) <br>_Draws center-aligned text._  |
|  void | [**TextLeft**](#function-textleft) (T aText, unsigned char aIsFocused=0) <br>_Draws left-aligned text._  |
|  void | [**TextRight**](#function-textright) (T aText, unsigned char aIsFocused=0) <br>_Draws right-aligned text._  |




























## Detailed Description


[**Grid**](classevab_1_1_grid.md) provides a fluent interface for organizing UI elements in a rest. Each [**CutRow()**](classevab_1_1_grid.md#function-cutrow)/CutCol() returns a new [**Grid**](classevab_1_1_grid.md) representing the cell.



```C++
Grid rest({0,0}, {16,8});
rest.CutRow(2).Draw(element1);
rest.CutRow(2).CutCol(2).Draw(element2);
rest.CutRow(2).CutCol(2).Clear();
rest.Clear();
```
 


    
## Public Functions Documentation




### function Clear 

_Clears the current cell area._ 
```C++
void evab::Grid::Clear (
    unsigned char aIsFocused=0
) 
```




<hr>



### function CutCol 

_Creates a new_ [_**Grid**_](classevab_1_1_grid.md) _for the next column._
```C++
Grid evab::Grid::CutCol (
    unsigned char aWidth=0
) 
```





**Parameters:**


* `aWidth` Width of the column (0 = use remaining width) 



**Returns:**

[**Grid**](classevab_1_1_grid.md) New rest representing the column 





        

<hr>



### function CutRow 

_Creates a new_ [_**Grid**_](classevab_1_1_grid.md) _for the next row._
```C++
Grid evab::Grid::CutRow (
    unsigned char aHeight=0
) 
```





**Parameters:**


* `aHeight` Height of the row (0 = use remaining height) 



**Returns:**

[**Grid**](classevab_1_1_grid.md) New rest representing the row 





        

<hr>



### function Draw 

_Draws an element in the current cell._ 
```C++
void evab::Grid::Draw (
    ElementBase & aElement,
    unsigned char aIsFocused=0
) 
```





**Parameters:**


* `aElement` Element to draw 
* `aIsFocused` Focus state (1 = focused, 0 = not focused) 




        

<hr>



### function GetPos 

_Gets the current position._ 
```C++
inline Coor evab::Grid::GetPos () const
```





**Returns:**

[**Coor**](structevab_1_1_coor.md) Current position 





        

<hr>



### function GetSize 

_Gets the current size._ 
```C++
Coor evab::Grid::GetSize () const
```





**Returns:**

[**Coor**](structevab_1_1_coor.md) Current size (clamped to non-negative values) 





        

<hr>



### function Grid 

_Constructs a_ [_**Grid**_](classevab_1_1_grid.md) _for a specific area._
```C++
evab::Grid::Grid (
    Screen * aScreen,
    Coor aPos,
    Coor aSize,
    unsigned char aIsFocused
) 
```





**Parameters:**


* `aScreen` [**Screen**](classevab_1_1_screen.md) to draw on 
* `aPos` Position on screen 
* `aSize` Size of the rest area 




        

<hr>



### function Picto 

_Draws a pictogram in the current cell._ 
```C++
void evab::Grid::Picto (
    const unsigned char * aPictogram,
    unsigned char aIsFocused=0
) 
```





**Parameters:**


* `aPictogram` Pictogram data 
* `aIsFocused` Color/inversion flag 




        

<hr>



### function Text 

_Draws text with specified alignment._ 
```C++
template<typename TAlign, typename TText>
inline void evab::Grid::Text (
    TText aText,
    unsigned char aIsFocused=0
) 
```





**Template parameters:**


* `TAlign` Alignment strategy ([**LeftAlign**](structevab_1_1_left_align.md), [**CenterAlign**](structevab_1_1_center_align.md), [**RightAlign**](structevab_1_1_right_align.md)) 
* `TText` Text type 



**Parameters:**


* `aText` Text to draw 
* `aIsFocused` Color/inversion flag 




        

<hr>



### function TextCenter 

_Draws center-aligned text._ 
```C++
template<typename T>
inline void evab::Grid::TextCenter (
    T aText,
    unsigned char aIsFocused=0
) 
```




<hr>



### function TextLeft 

_Draws left-aligned text._ 
```C++
template<typename T>
inline void evab::Grid::TextLeft (
    T aText,
    unsigned char aIsFocused=0
) 
```




<hr>



### function TextRight 

_Draws right-aligned text._ 
```C++
template<typename T>
inline void evab::Grid::TextRight (
    T aText,
    unsigned char aIsFocused=0
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `src/evabGrid.h`

