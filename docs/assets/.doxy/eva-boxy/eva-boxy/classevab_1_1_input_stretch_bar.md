

# Class evab::InputStretchBar

**template &lt;typename TPictoset, typename OrientationPictoPolicy&gt;**



[**ClassList**](annotated.md) **>** [**evab**](namespaceevab.md) **>** [**InputStretchBar**](classevab_1_1_input_stretch_bar.md)



_Stretch bar input element with pictogram support._ [More...](#detailed-description)

* `#include <evabInputStretchBar.h>`



Inherits the following classes: [evab::ElementBase](classevab_1_1_element_base.md)






















































## Public Functions

| Type | Name |
| ---: | :--- |
|  void | [**Increment**](#function-increment) (signed char delta) <br>_Increments the value by a delta._  |
|   | [**InputStretchBar**](#function-inputstretchbar) (unsigned char aValue=0) <br>_Constructor for_ [_**InputStretchBar**_](classevab_1_1_input_stretch_bar.md) _._ |
|  void | [**SetValue**](#function-setvalue) (unsigned char aValue) <br>_Sets the value and redraws._  |


## Public Functions inherited from evab::ElementBase

See [evab::ElementBase](classevab_1_1_element_base.md)

| Type | Name |
| ---: | :--- |
|  void | [**Draw**](classevab_1_1_element_base.md#function-draw) ([**Screen**](classevab_1_1_screen.md) \* aScreen, [**Coor**](structevab_1_1_coor.md) aPos, [**Coor**](structevab_1_1_coor.md) aSize, unsigned char aIsFocused) <br>_Draws the element on the specified screen._  |
|  void | [**Hide**](classevab_1_1_element_base.md#function-hide) () <br>_Hides the element from view._  |
|  bool | [**IsHidden**](classevab_1_1_element_base.md#function-ishidden) () <br>_Checks if the element is hidden._  |
| virtual bool | [**Key**](classevab_1_1_element_base.md#function-key) (Keys aKey) <br>_Handles key events for the element._  |
|  void | [**Redraw**](classevab_1_1_element_base.md#function-redraw) () <br>_Redraws the element on the current screen._  |














































## Protected Functions

| Type | Name |
| ---: | :--- |
| virtual void | [**drawer**](#function-drawer) ([**Screen**](classevab_1_1_screen.md) \* aScreen, [**Coor**](structevab_1_1_coor.md) aPos, [**Coor**](structevab_1_1_coor.md) aSize, unsigned char aIsFocused) override<br>_Draws the stretch bar on screen._  |


## Protected Functions inherited from evab::ElementBase

See [evab::ElementBase](classevab_1_1_element_base.md)

| Type | Name |
| ---: | :--- |
| virtual void | [**drawer**](classevab_1_1_element_base.md#function-drawer) ([**Screen**](classevab_1_1_screen.md) \* aScreen, [**Coor**](structevab_1_1_coor.md) aPos, [**Coor**](structevab_1_1_coor.md) aSize, unsigned char aIsFocused) = 0<br>_Pure virtual method for drawing the element._  |
| virtual void | [**hider**](classevab_1_1_element_base.md#function-hider) () <br>_Virtual method for hiding the element._  |






## Detailed Description


Displays a progress/scroll bar using pictograms with variable fill levels.




**Template parameters:**


* `TPictoset` Pictoset class providing pictogram data 
* `OrientationPictoPolicy` Policy for orientation (vertical/horizontal) 




    
## Public Functions Documentation




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
    unsigned char aValue=0
) 
```





**Parameters:**


* `aValue` Initial value (0-100) 




        

<hr>



### function SetValue 

_Sets the value and redraws._ 
```C++
inline void evab::InputStretchBar::SetValue (
    unsigned char aValue
) 
```





**Parameters:**


* `aValue` New value (0-100) 




        

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

