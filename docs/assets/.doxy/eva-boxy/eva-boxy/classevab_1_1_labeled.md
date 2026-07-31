

# Class evab::Labeled

**template &lt;class T, typename TAlign, typename TText&gt;**



[**ClassList**](annotated.md) **>** [**evab**](namespaceevab.md) **>** [**Labeled**](classevab_1_1_labeled.md)



_Decorator that adds a label to any element with alignment._ [More...](#detailed-description)

* `#include <evabLabeled.h>`



Inherits the following classes: T


































## Public Functions

| Type | Name |
| ---: | :--- |
|  TText | [**GetLabel**](#function-getlabel) () const<br>_Gets current label text._  |
|   | [**Labeled**](#function-labeled) (TText aName, Args &&... args) <br>_Constructor for_ [_**Labeled**_](classevab_1_1_labeled.md) _._ |
|  void | [**SetLabel**](#function-setlabel) (TText aName) <br>_Sets new label text and redraws._  |
























## Protected Functions

| Type | Name |
| ---: | :--- |
|  void | [**drawer**](#function-drawer) ([**Screen**](classevab_1_1_screen.md) \* aScreen, [**Coor**](structevab_1_1_coor.md) aPos, [**Coor**](structevab_1_1_coor.md) aSize, unsigned char aIsFocused) override<br>_Draws the labeled element._  |
|  void | [**freezer**](#function-freezer) () override<br> |




## Detailed Description


Wraps an element and adds a text label either to the left (single line) or above (multi-line).




**Template parameters:**


* `T` Element type to label 
* `TAlign` Alignment strategy for label ([**LeftAlign**](structevab_1_1_left_align.md), [**CenterAlign**](structevab_1_1_center_align.md), [**RightAlign**](structevab_1_1_right_align.md)) 
* `TText` Text type (const char\*, \_\_FlashStringHelper\*) 




    
## Public Functions Documentation




### function GetLabel 

_Gets current label text._ 
```C++
inline TText evab::Labeled::GetLabel () const
```





**Returns:**

Current label text 





        

<hr>



### function Labeled 

_Constructor for_ [_**Labeled**_](classevab_1_1_labeled.md) _._
```C++
template<typename... Args>
inline evab::Labeled::Labeled (
    TText aName,
    Args &&... args
) 
```





**Parameters:**


* `aName` Label text 
* `args` Arguments forwarded to the base element constructor 




        

<hr>



### function SetLabel 

_Sets new label text and redraws._ 
```C++
inline void evab::Labeled::SetLabel (
    TText aName
) 
```





**Parameters:**


* `aName` New label text 




        

<hr>
## Protected Functions Documentation




### function drawer 

_Draws the labeled element._ 
```C++
inline void evab::Labeled::drawer (
    Screen * aScreen,
    Coor aPos,
    Coor aSize,
    unsigned char aIsFocused
) override
```





**Parameters:**


* `aScreen` [**Screen**](classevab_1_1_screen.md) to draw on 
* `aPos` Position on screen 
* `aSize` Size of the element 
* `aIsFocused` Focus state (1 = focused, 0 = not focused) 




        

<hr>



### function freezer 

```C++
inline void evab::Labeled::freezer () override
```




<hr>

------------------------------
The documentation for this class was generated from the following file `src/evabLabeled.h`

