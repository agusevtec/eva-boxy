

# Class evab::BoxyRest



[**ClassList**](annotated.md) **>** [**evab**](namespaceevab.md) **>** [**BoxyRest**](classevab_1_1_boxy_rest.md)



_Layout manager for rest-based UI arrangement._ [More...](#detailed-description)

* `#include <evabGrid.h>`





































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**BoxyRest**](#function-boxyrest) ([**Screen**](classevab_1_1_screen.md) \* aScreen, [**Coor**](structevab_1_1_coor.md) aPos, [**Coor**](structevab_1_1_coor.md) aSize, unsigned char aIsFocused) <br>_Constructs a_ [_**BoxyRest**_](classevab_1_1_boxy_rest.md) _for a specific area._ |
|  void | [**Clear**](#function-clear) (unsigned char aIsFocused=0) <br>_Clears the current cell area._  |
|  [**BoxyRest**](classevab_1_1_boxy_rest.md#function-boxyrest) | [**CutCol**](#function-cutcol) (unsigned char aWidth=0) <br>_Creates a new_ [_**BoxyRest**_](classevab_1_1_boxy_rest.md) _for the next column._ |
|  [**BoxyRest**](classevab_1_1_boxy_rest.md#function-boxyrest) | [**CutRow**](#function-cutrow) (unsigned char aHeight=0) <br>_Creates a new_ [_**BoxyRest**_](classevab_1_1_boxy_rest.md) _for the next row._ |
|  void | [**Draw**](#function-draw) ([**ElementBase**](classevab_1_1_element_base.md) & aElement, unsigned char aIsFocused=0) <br>_Draws an element in the current cell._  |
|  [**Coor**](structevab_1_1_coor.md) | [**GetPos**](#function-getpos) () const<br>_Gets the current position._  |
|  [**Coor**](structevab_1_1_coor.md) | [**GetSize**](#function-getsize) () const<br>_Gets the current size._  |
|  void | [**Picto**](#function-picto) (const unsigned char \* aPictogram, unsigned char aIsFocused=0) <br>_Draws a pictogram in the current cell._  |
|  [**BoxyRest**](classevab_1_1_boxy_rest.md#function-boxyrest) & | [**Rest**](#function-rest) () <br>_Returns the remaining space from current position._  |
|  void | [**Text**](#function-text) (TText aText, unsigned char aIsFocused=0) <br>_Draws text with specified alignment._  |
|  void | [**TextCenter**](#function-textcenter) (T aText, unsigned char aIsFocused=0) <br>_Draws center-aligned text._  |
|  void | [**TextLeft**](#function-textleft) (T aText, unsigned char aIsFocused=0) <br>_Draws left-aligned text._  |
|  void | [**TextRight**](#function-textright) (T aText, unsigned char aIsFocused=0) <br>_Draws right-aligned text._  |




























## Detailed Description


[**BoxyRest**](classevab_1_1_boxy_rest.md) provides a fluent interface for organizing UI elements in a rest. Each [**CutRow()**](classevab_1_1_boxy_rest.md#function-cutrow)/CutCol() returns a new [**BoxyRest**](classevab_1_1_boxy_rest.md) representing the cell.



```C++
BoxyRest rest({0,0}, {16,8});
rest.CutRow(2).Draw(element1);
rest.CutRow(2).CutCol(2).Draw(element2);
rest.CutRow(2).CutCol(2).Clear();
rest.Clear();
```
 


    
## Public Functions Documentation




### function BoxyRest 

_Constructs a_ [_**BoxyRest**_](classevab_1_1_boxy_rest.md) _for a specific area._
```C++
evab::BoxyRest::BoxyRest (
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



### function Clear 

_Clears the current cell area._ 
```C++
void evab::BoxyRest::Clear (
    unsigned char aIsFocused=0
) 
```




<hr>



### function CutCol 

_Creates a new_ [_**BoxyRest**_](classevab_1_1_boxy_rest.md) _for the next column._
```C++
BoxyRest evab::BoxyRest::CutCol (
    unsigned char aWidth=0
) 
```





**Parameters:**


* `aWidth` Width of the column (0 = use remaining width) 



**Returns:**

[**BoxyRest**](classevab_1_1_boxy_rest.md) New rest representing the column 





        

<hr>



### function CutRow 

_Creates a new_ [_**BoxyRest**_](classevab_1_1_boxy_rest.md) _for the next row._
```C++
BoxyRest evab::BoxyRest::CutRow (
    unsigned char aHeight=0
) 
```





**Parameters:**


* `aHeight` Height of the row (0 = use remaining height) 



**Returns:**

[**BoxyRest**](classevab_1_1_boxy_rest.md) New rest representing the row 





        

<hr>



### function Draw 

_Draws an element in the current cell._ 
```C++
void evab::BoxyRest::Draw (
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
inline Coor evab::BoxyRest::GetPos () const
```





**Returns:**

[**Coor**](structevab_1_1_coor.md) Current position 





        

<hr>



### function GetSize 

_Gets the current size._ 
```C++
Coor evab::BoxyRest::GetSize () const
```





**Returns:**

[**Coor**](structevab_1_1_coor.md) Current size (clamped to non-negative values) 





        

<hr>



### function Picto 

_Draws a pictogram in the current cell._ 
```C++
void evab::BoxyRest::Picto (
    const unsigned char * aPictogram,
    unsigned char aIsFocused=0
) 
```





**Parameters:**


* `aPictogram` Pictogram data 
* `aIsFocused` Color/inversion flag 




        

<hr>



### function Rest 

_Returns the remaining space from current position._ 
```C++
BoxyRest & evab::BoxyRest::Rest () 
```





**Returns:**

[**BoxyRest**](classevab_1_1_boxy_rest.md)& Reference to this rest 





        

<hr>



### function Text 

_Draws text with specified alignment._ 
```C++
template<typename TAlign, typename TText>
inline void evab::BoxyRest::Text (
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
inline void evab::BoxyRest::TextCenter (
    T aText,
    unsigned char aIsFocused=0
) 
```




<hr>



### function TextLeft 

_Draws left-aligned text._ 
```C++
template<typename T>
inline void evab::BoxyRest::TextLeft (
    T aText,
    unsigned char aIsFocused=0
) 
```




<hr>



### function TextRight 

_Draws right-aligned text._ 
```C++
template<typename T>
inline void evab::BoxyRest::TextRight (
    T aText,
    unsigned char aIsFocused=0
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `src/evabGrid.h`

