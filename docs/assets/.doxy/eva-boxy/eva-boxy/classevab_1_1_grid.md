

# Class evab::Grid



[**ClassList**](annotated.md) **>** [**evab**](namespaceevab.md) **>** [**Grid**](classevab_1_1_grid.md)



_Layout manager for grid-based UI arrangement._ [More...](#detailed-description)

* `#include <evabGrid.h>`





































## Public Functions

| Type | Name |
| ---: | :--- |
|  void | [**Blank**](#function-blank) ([**Screen**](classevab_1_1_screen.md) \* aScreen) <br>_Clears the current cell area._  |
|  void | [**Draw**](#function-draw) ([**Screen**](classevab_1_1_screen.md) \* aScreen, [**ElementBase**](classevab_1_1_element_base.md) \* aElement, unsigned char aIsFocused=0) <br>_Draws an element in the current cell._  |
|  [**Coor**](structevab_1_1_coor.md) | [**GetPos**](#function-getpos) () const<br>_Gets the current position._  |
|  [**Coor**](structevab_1_1_coor.md) | [**GetSize**](#function-getsize) () const<br>_Gets the current size._  |
|   | [**Grid**](#function-grid) ([**Coor**](structevab_1_1_coor.md) aPos, [**Coor**](structevab_1_1_coor.md) aSize) <br>_Constructs a_ [_**Grid**_](classevab_1_1_grid.md) _for a specific area._ |
|  [**Grid**](classevab_1_1_grid.md#function-grid) & | [**Rest**](#function-rest) () <br>_Returns the remaining space from current position._  |
|  [**Grid**](classevab_1_1_grid.md#function-grid) | [**SliceCol**](#function-slicecol) (unsigned char aWidth=0) <br>_Creates a new_ [_**Grid**_](classevab_1_1_grid.md) _for the next column._ |
|  [**Grid**](classevab_1_1_grid.md#function-grid) | [**SliceRow**](#function-slicerow) (unsigned char aHeight=0) <br>_Creates a new_ [_**Grid**_](classevab_1_1_grid.md) _for the next row._ |




























## Detailed Description


[**Grid**](classevab_1_1_grid.md) provides a fluent interface for organizing UI elements in a grid. Each [**SliceRow()**](classevab_1_1_grid.md#function-slicerow)/SliceCol() returns a new [**Grid**](classevab_1_1_grid.md) representing the cell.



```C++
Grid mesh({0,0}, {16,8});
mesh.SliceRow(2).Draw(screen, element1);
mesh.SliceRow(2).SliceCol(2).Draw(screen, element2);
mesh.SliceRow(2).SliceCol(2).Clean(screen);
mesh.Rest().Clean(screen);
```
 


    
## Public Functions Documentation




### function Blank 

_Clears the current cell area._ 
```C++
void evab::Grid::Blank (
    Screen * aScreen
) 
```





**Parameters:**


* `aScreen` [**Screen**](classevab_1_1_screen.md) to draw on 




        

<hr>



### function Draw 

_Draws an element in the current cell._ 
```C++
void evab::Grid::Draw (
    Screen * aScreen,
    ElementBase * aElement,
    unsigned char aIsFocused=0
) 
```





**Parameters:**


* `aScreen` [**Screen**](classevab_1_1_screen.md) to draw on 
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
    Coor aPos,
    Coor aSize
) 
```





**Parameters:**


* `aPos` Position on screen 
* `aSize` Size of the mesh area 




        

<hr>



### function Rest 

_Returns the remaining space from current position._ 
```C++
Grid & evab::Grid::Rest () 
```





**Returns:**

[**Grid**](classevab_1_1_grid.md) New mesh representing the remaining space 





        

<hr>



### function SliceCol 

_Creates a new_ [_**Grid**_](classevab_1_1_grid.md) _for the next column._
```C++
Grid evab::Grid::SliceCol (
    unsigned char aWidth=0
) 
```





**Parameters:**


* `aWidth` Width of the column (0 = use remaining width) 



**Returns:**

[**Grid**](classevab_1_1_grid.md) New mesh representing the column 





        

<hr>



### function SliceRow 

_Creates a new_ [_**Grid**_](classevab_1_1_grid.md) _for the next row._
```C++
Grid evab::Grid::SliceRow (
    unsigned char aHeight=0
) 
```





**Parameters:**


* `aHeight` Height of the row (0 = use remaining height) 



**Returns:**

[**Grid**](classevab_1_1_grid.md) New mesh representing the row 





        

<hr>

------------------------------
The documentation for this class was generated from the following file `src/evabGrid.h`

