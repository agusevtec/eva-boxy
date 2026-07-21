

# Class evab::InputButton



[**ClassList**](annotated.md) **>** [**evab**](namespaceevab.md) **>** [**InputButton**](classevab_1_1_input_button.md)



_Button input element._ [More...](#detailed-description)

* `#include <evabInputButton.h>`



Inherits the following classes: [evab::ElementBase](classevab_1_1_element_base.md)






















































## Public Functions

| Type | Name |
| ---: | :--- |
|  void | [**Increment**](#function-increment) (signed char delta) <br>_Placeholder increment method (does nothing)._  |
|   | [**InputButton**](#function-inputbutton) (const \_\_FlashStringHelper \* aName) <br>_Constructor for_ [_**InputButton**_](classevab_1_1_input_button.md) _._ |


## Public Functions inherited from evab::ElementBase

See [evab::ElementBase](classevab_1_1_element_base.md)

| Type | Name |
| ---: | :--- |
|  void | [**Draw**](classevab_1_1_element_base.md#function-draw) ([**IScreen**](classevab_1_1_i_screen.md) \* aScreen, [**Coor**](structevab_1_1_coor.md) aPos, [**Coor**](structevab_1_1_coor.md) aSize, unsigned char aIsFocused) <br>_Draws the element on the specified screen._  |
|  void | [**Hide**](classevab_1_1_element_base.md#function-hide) () <br>_Hides the element from view._  |
|  bool | [**IsHidden**](classevab_1_1_element_base.md#function-ishidden) () <br>_Checks if the element is hidden._  |
| virtual bool | [**Key**](classevab_1_1_element_base.md#function-key) (Keys aKey) <br>_Handles key events for the element._  |
|  void | [**Redraw**](classevab_1_1_element_base.md#function-redraw) () <br>_Redraws the element on the current screen._  |














































## Protected Functions

| Type | Name |
| ---: | :--- |
| virtual void | [**drawer**](#function-drawer) ([**IScreen**](classevab_1_1_i_screen.md) \* aScreen, [**Coor**](structevab_1_1_coor.md) aPos, [**Coor**](structevab_1_1_coor.md) aSize, unsigned char aIsFocused) override<br>_Draws the button element._  |








## Detailed Description


Displays a button with a label enclosed in parentheses. The Increment method is a placeholder that does nothing. 


    
## Public Functions Documentation




### function Increment 

_Placeholder increment method (does nothing)._ 
```C++
void evab::InputButton::Increment (
    signed char delta
) 
```





**Parameters:**


* `delta` Unused parameter 




        

<hr>



### function InputButton 

_Constructor for_ [_**InputButton**_](classevab_1_1_input_button.md) _._
```C++
evab::InputButton::InputButton (
    const __FlashStringHelper * aName
) 
```





**Parameters:**


* `aName` Flash string for button label 




        

<hr>
## Protected Functions Documentation




### function drawer 

_Draws the button element._ 
```C++
virtual void evab::InputButton::drawer (
    IScreen * aScreen,
    Coor aPos,
    Coor aSize,
    unsigned char aIsFocused
) override
```





**Parameters:**


* `aScreen` Screen to draw on 
* `aPos` Position on screen 
* `aSize` Size of the element 
* `aIsFocused` Focus state (1 = focused, 0 = not focused) 




        
Implements [*evab::ElementBase::drawer*](classevab_1_1_element_base.md#function-drawer)


<hr>

------------------------------
The documentation for this class was generated from the following file `src/evabInputButton.h`

