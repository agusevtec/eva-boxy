

# Class evab::InputStretchBar

**template &lt;typename TAlbumStretchy, typename OrientationAlbumPolicy&gt;**



[**ClassList**](annotated.md) **>** [**evab**](namespaceevab.md) **>** [**InputStretchBar**](classevab_1_1_input_stretch_bar.md)



_Stretch bar input element with Albumgram support._ [More...](#detailed-description)

* `#include <evabInputStretchBar.h>`



Inherits the following classes: [evab::ElementBase](classevab_1_1_element_base.md)






















































## Public Functions

| Type | Name |
| ---: | :--- |
|  unsigned char | [**GetPercent**](#function-getpercent) () <br> |
|  void | [**Increment**](#function-increment) (signed char delta) <br>_Increments the value by a delta._  |
|   | [**InputStretchBar**](#function-inputstretchbar) (unsigned char aValue=0, unsigned char aStep=0) <br>_Constructor for_ [_**InputStretchBar**_](classevab_1_1_input_stretch_bar.md) _._ |
|  void | [**SetPercent**](#function-setpercent) (unsigned char aPercent) <br>_Sets the value and redraws._  |


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
| virtual void | [**drawer**](#function-drawer) ([**Screen**](classevab_1_1_screen.md) \* aScreen, [**Coor**](structevab_1_1_coor.md) aPos, [**Coor**](structevab_1_1_coor.md) aSize, unsigned char aIsFocused) override<br>_Draws the stretch bar on screen._  |


## Protected Functions inherited from evab::ElementBase

See [evab::ElementBase](classevab_1_1_element_base.md)

| Type | Name |
| ---: | :--- |
| virtual void | [**drawer**](classevab_1_1_element_base.md#function-drawer) ([**Screen**](classevab_1_1_screen.md) \* aScreen, [**Coor**](structevab_1_1_coor.md) aPos, [**Coor**](structevab_1_1_coor.md) aSize, unsigned char aIsFocused) = 0<br>_Pure virtual method for drawing the element._  |
| virtual void | [**freezer**](classevab_1_1_element_base.md#function-freezer) () <br>_Virtual method for freezing the element._  |
|  bool | [**isFrozen**](classevab_1_1_element_base.md#function-isfrozen) () <br>_Checks if the element is currently freezed._  |
|  void | [**redraw**](classevab_1_1_element_base.md#function-redraw) () <br>_Redraws the element on the current screen._  |






## Detailed Description


Displays a progress/scroll bar using Albumgrams with variable fill levels.




**Template parameters:**


* `TAlbumStretchy` Album class providing Albumgram data 
* `OrientationAlbumPolicy` Policy for orientation (vertical/horizontal) 




    
## Public Functions Documentation




### function GetPercent 

```C++
inline unsigned char evab::InputStretchBar::GetPercent () 
```




<hr>



### function Increment 

_Increments the value by a delta._ 
```C++
inline void evab::InputStretchBar::Increment (
    signed char delta
) 
```





**Parameters:**


* `delta` Amount to add (positive or negative) 




        

<hr>



### function InputStretchBar 

_Constructor for_ [_**InputStretchBar**_](classevab_1_1_input_stretch_bar.md) _._
```C++
inline evab::InputStretchBar::InputStretchBar (
    unsigned char aValue=0,
    unsigned char aStep=0
) 
```





**Parameters:**


* `aValue` Initial percent value (0-100) 
* `aStep` Increment step (0 = auto-calculate from resolution) 




        

<hr>



### function SetPercent 

_Sets the value and redraws._ 
```C++
inline void evab::InputStretchBar::SetPercent (
    unsigned char aPercent
) 
```





**Parameters:**


* `aPercent` New value (0-100) 




        

<hr>
## Protected Functions Documentation




### function drawer 

_Draws the stretch bar on screen._ 
```C++
inline virtual void evab::InputStretchBar::drawer (
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
The documentation for this class was generated from the following file `src/evabInputStretchBar.h`

