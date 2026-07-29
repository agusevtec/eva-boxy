

# Class evab::InputButtonPicto



[**ClassList**](annotated.md) **>** [**evab**](namespaceevab.md) **>** [**InputButtonPicto**](classevab_1_1_input_button_picto.md)



_Pictogram button element._ [More...](#detailed-description)

* `#include <evabInputButtonPicto.h>`



Inherits the following classes: [evab::ElementBase](classevab_1_1_element_base.md)






















































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**InputButtonPicto**](#function-inputbuttonpicto) (const unsigned char \* aaPictogram) <br>_Constructor for_ [_**InputButtonPicto**_](classevab_1_1_input_button_picto.md) _._ |


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
| virtual void | [**drawer**](#function-drawer) ([**Screen**](classevab_1_1_screen.md) \* aScreen, [**Coor**](structevab_1_1_coor.md) aPos, [**Coor**](structevab_1_1_coor.md) aSize, unsigned char aIsFocused) override<br>_Draws the button element._  |


## Protected Functions inherited from evab::ElementBase

See [evab::ElementBase](classevab_1_1_element_base.md)

| Type | Name |
| ---: | :--- |
| virtual void | [**drawer**](classevab_1_1_element_base.md#function-drawer) ([**Screen**](classevab_1_1_screen.md) \* aScreen, [**Coor**](structevab_1_1_coor.md) aPos, [**Coor**](structevab_1_1_coor.md) aSize, unsigned char aIsFocused) = 0<br>_Pure virtual method for drawing the element._  |
| virtual void | [**hider**](classevab_1_1_element_base.md#function-hider) () <br>_Virtual method for hiding the element._  |






## Detailed Description


Displays a button with a pictogram enclosed in parentheses. 


    
## Public Functions Documentation




### function InputButtonPicto 

_Constructor for_ [_**InputButtonPicto**_](classevab_1_1_input_button_picto.md) _._
```C++
evab::InputButtonPicto::InputButtonPicto (
    const unsigned char * aaPictogram
) 
```





**Parameters:**


* `aaPictogram` Pointer to pictogram data 




        

<hr>
## Protected Functions Documentation




### function drawer 

_Draws the button element._ 
```C++
virtual void evab::InputButtonPicto::drawer (
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
The documentation for this class was generated from the following file `src/evabInputButtonPicto.h`

