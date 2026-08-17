

# Class evab::InputButton



[**ClassList**](annotated.md) **>** [**evab**](namespaceevab.md) **>** [**InputButton**](classevab_1_1_input_button.md)



_Button input element (label in RAM)._ [More...](#detailed-description)

* `#include <evabInputButton.h>`



Inherits the following classes: [evab::ElementBase](classevab_1_1_element_base.md)






















































## Public Functions

| Type | Name |
| ---: | :--- |
|  const char \* | [**GetName**](#function-getname) () const<br>_Gets the current label text._  |
|   | [**InputButton**](#function-inputbutton) (const char \* aText="") <br>_Constructs a_ [_**InputButton**_](classevab_1_1_input_button.md) _with a RAM string._ |
|  void | [**SetName**](#function-setname) (const char \* aText) <br>_Sets new label text and redraws._  |


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
| virtual void | [**drawer**](#function-drawer) ([**Screen**](classevab_1_1_screen.md) \* aScreen, [**Coor**](structevab_1_1_coor.md) aPos, [**Coor**](structevab_1_1_coor.md) aSize, unsigned char aIsFocused) override<br>_Pure virtual method for drawing the element._  |


## Protected Functions inherited from evab::ElementBase

See [evab::ElementBase](classevab_1_1_element_base.md)

| Type | Name |
| ---: | :--- |
| virtual void | [**drawer**](classevab_1_1_element_base.md#function-drawer) ([**Screen**](classevab_1_1_screen.md) \* aScreen, [**Coor**](structevab_1_1_coor.md) aPos, [**Coor**](structevab_1_1_coor.md) aSize, unsigned char aIsFocused) = 0<br>_Pure virtual method for drawing the element._  |
| virtual void | [**freezer**](classevab_1_1_element_base.md#function-freezer) () <br>_Virtual method for freezing the element._  |
|  bool | [**isFrozen**](classevab_1_1_element_base.md#function-isfrozen) () <br>_Checks if the element is currently freezed._  |
|  void | [**redraw**](classevab_1_1_element_base.md#function-redraw) () <br>_Redraws the element on the current screen._  |






## Detailed Description


Displays a button with a label enclosed in parentheses. The Increment method is a placeholder that does nothing. 


    
## Public Functions Documentation




### function GetName 

_Gets the current label text._ 
```C++
const char * evab::InputButton::GetName () const
```




<hr>



### function InputButton 

_Constructs a_ [_**InputButton**_](classevab_1_1_input_button.md) _with a RAM string._
```C++
evab::InputButton::InputButton (
    const char * aText=""
) 
```





**Parameters:**


* `aText` Label text (const char\*) 




        

<hr>



### function SetName 

_Sets new label text and redraws._ 
```C++
void evab::InputButton::SetName (
    const char * aText
) 
```




<hr>
## Protected Functions Documentation




### function drawer 

_Pure virtual method for drawing the element._ 
```C++
virtual void evab::InputButton::drawer (
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
The documentation for this class was generated from the following file `src/evabInputButton.h`

