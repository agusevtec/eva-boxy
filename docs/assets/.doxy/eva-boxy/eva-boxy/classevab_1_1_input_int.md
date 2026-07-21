

# Class evab::InputInt



[**ClassList**](annotated.md) **>** [**evab**](namespaceevab.md) **>** [**InputInt**](classevab_1_1_input_int.md)



_Integer input element._ [More...](#detailed-description)

* `#include <evabInputInt.h>`



Inherits the following classes: [evab::ElementBase](classevab_1_1_element_base.md)






















































## Public Functions

| Type | Name |
| ---: | :--- |
|  int | [**GetValue**](#function-getvalue) () const<br>_Gets the current integer value._  |
|  void | [**Increment**](#function-increment) (signed char delta) <br>_Increments the value by a delta._  |
|   | [**InputInt**](#function-inputint) (int aValue=0) <br>_Constructor for_ [_**InputInt**_](classevab_1_1_input_int.md) _._ |
|  void | [**SetValue**](#function-setvalue) (int aValue) <br>_Sets the integer value and redraws._  |


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
| virtual void | [**drawer**](#function-drawer) ([**IScreen**](classevab_1_1_i_screen.md) \* aScreen, [**Coor**](structevab_1_1_coor.md) aPos, [**Coor**](structevab_1_1_coor.md) aSize, unsigned char aIsFocused) override<br>_Draws the integer value centered on screen._  |








## Detailed Description


Displays and manages an integer value. 


    
## Public Functions Documentation




### function GetValue 

_Gets the current integer value._ 
```C++
int evab::InputInt::GetValue () const
```





**Returns:**

Current integer value 





        

<hr>



### function Increment 

_Increments the value by a delta._ 
```C++
void evab::InputInt::Increment (
    signed char delta
) 
```





**Parameters:**


* `delta` Amount to add (positive or negative) 




        

<hr>



### function InputInt 

_Constructor for_ [_**InputInt**_](classevab_1_1_input_int.md) _._
```C++
evab::InputInt::InputInt (
    int aValue=0
) 
```





**Parameters:**


* `aValue` Initial integer value (default 0) 




        

<hr>



### function SetValue 

_Sets the integer value and redraws._ 
```C++
void evab::InputInt::SetValue (
    int aValue
) 
```





**Parameters:**


* `aValue` New integer value 




        

<hr>
## Protected Functions Documentation




### function drawer 

_Draws the integer value centered on screen._ 
```C++
virtual void evab::InputInt::drawer (
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
The documentation for this class was generated from the following file `src/evabInputInt.h`

