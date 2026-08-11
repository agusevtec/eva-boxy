

# Class evab::StretchBar

**template &lt;typename TCharset, typename TOrientationTextPolicy&gt;**



[**ClassList**](annotated.md) **>** [**evab**](namespaceevab.md) **>** [**StretchBar**](classevab_1_1_stretch_bar.md)



_Text-based stretch bar element._ [More...](#detailed-description)

* `#include <evabStretchBar.h>`



Inherits the following classes: [evab::ElementBase](classevab_1_1_element_base.md)






















































## Public Functions

| Type | Name |
| ---: | :--- |
|  unsigned char | [**GetPercent**](#function-getpercent) () <br> |
|  void | [**Increment**](#function-increment) (signed char delta) <br>_Increments the value by a delta._  |
|  void | [**SetPercent**](#function-setpercent) (unsigned char aPercent) <br>_Sets the value and redraws._  |
|   | [**StretchBar**](#function-stretchbar) (unsigned char aValue=0, unsigned char aStep=0) <br>_Constructor for_ [_**StretchBar**_](classevab_1_1_stretch_bar.md) _._ |


## Public Functions inherited from evab::ElementBase

See [evab::ElementBase](classevab_1_1_element_base.md)

| Type | Name |
| ---: | :--- |
|  void | [**Draw**](classevab_1_1_element_base.md#function-draw) ([**Screen**](classevab_1_1_screen.md) \* aScreen, [**Coor**](structevab_1_1_coor.md) aPos, [**Coor**](structevab_1_1_coor.md) aSize, unsigned char aIsFocused) <br>_Draws the element on the specified screen._  |
|  void | [**Freeze**](classevab_1_1_element_base.md#function-freeze) () <br>_Make element insensitive to redraw method._  |
| virtual bool | [**OnKey**](classevab_1_1_element_base.md#function-onkey) (Keys aKey) <br>_Handles key events for the element._  |














































## Protected Functions

| Type | Name |
| ---: | :--- |
| virtual void | [**drawer**](#function-drawer) ([**Screen**](classevab_1_1_screen.md) \* aScreen, [**Coor**](structevab_1_1_coor.md) aPos, [**Coor**](structevab_1_1_coor.md) aSize, unsigned char aIsFocused) override<br>_Draws the text stretch bar on screen._  |


## Protected Functions inherited from evab::ElementBase

See [evab::ElementBase](classevab_1_1_element_base.md)

| Type | Name |
| ---: | :--- |
| virtual void | [**drawer**](classevab_1_1_element_base.md#function-drawer) ([**Screen**](classevab_1_1_screen.md) \* aScreen, [**Coor**](structevab_1_1_coor.md) aPos, [**Coor**](structevab_1_1_coor.md) aSize, unsigned char aIsFocused) = 0<br>_Pure virtual method for drawing the element._  |
| virtual void | [**freezer**](classevab_1_1_element_base.md#function-freezer) () <br>_Virtual method for freezing the element._  |
|  bool | [**isFrozen**](classevab_1_1_element_base.md#function-isfrozen) () <br>_Checks if the element is currently freezed._  |
|  void | [**redraw**](classevab_1_1_element_base.md#function-redraw) () <br>_Redraws the element on the current screen._  |






## Detailed Description


Displays a progress/scroll bar using characters instead of pictograms.




**Template parameters:**


* `TCharset` Character set class providing GetChar method 
* `TOrientationTextPolicy` Policy for orientation (vertical/horizontal) 




    
## Public Functions Documentation




### function GetPercent 

```C++
inline unsigned char evab::StretchBar::GetPercent () 
```




<hr>



### function Increment 

_Increments the value by a delta._ 
```C++
inline void evab::StretchBar::Increment (
    signed char delta
) 
```





**Parameters:**


* `delta` Amount to add (positive or negative) 




        

<hr>



### function SetPercent 

_Sets the value and redraws._ 
```C++
inline void evab::StretchBar::SetPercent (
    unsigned char aPercent
) 
```





**Parameters:**


* `aValue` New value (0-100) 




        

<hr>



### function StretchBar 

_Constructor for_ [_**StretchBar**_](classevab_1_1_stretch_bar.md) _._
```C++
inline evab::StretchBar::StretchBar (
    unsigned char aValue=0,
    unsigned char aStep=0
) 
```





**Parameters:**


* `aValue` Initial percent value (0-100) 
* `aStep` Increment step (0 = auto-calculate from resolution) 




        

<hr>
## Protected Functions Documentation




### function drawer 

_Draws the text stretch bar on screen._ 
```C++
inline virtual void evab::StretchBar::drawer (
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




        
Implements [*evab::ElementBase::drawer*](classevab_1_1_element_base.md#function-drawer)


<hr>

------------------------------
The documentation for this class was generated from the following file `src/evabStretchBar.h`

