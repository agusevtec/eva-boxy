

# Class evab::CompositeBase



[**ClassList**](annotated.md) **>** [**evab**](namespaceevab.md) **>** [**CompositeBase**](classevab_1_1_composite_base.md)



_Abstract base class for composite elements that can manage child focus._ [More...](#detailed-description)

* `#include <evabCompositeBase.h>`



Inherits the following classes: [evab::ElementBase](classevab_1_1_element_base.md)






















































## Public Functions

| Type | Name |
| ---: | :--- |
|  [**ElementBase**](classevab_1_1_element_base.md) \* | [**GetFocused**](#function-getfocused) () const<br>_Gets the current (focused) child._  |
|  bool | [**IsFocused**](#function-isfocused) ([**ElementBase**](classevab_1_1_element_base.md) \* aChild) <br>_Checks if a child is currently focused._  |
| virtual bool | [**OnKey**](#function-onkey) (Keys aKey) override<br>_Handles key events by forwarding to focused child._  |


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
|  void | [**focusChild**](#function-focuschild) ([**ElementBase**](classevab_1_1_element_base.md) \* aChild) <br>_Sets the focused child element._  |


## Protected Functions inherited from evab::ElementBase

See [evab::ElementBase](classevab_1_1_element_base.md)

| Type | Name |
| ---: | :--- |
| virtual void | [**drawer**](classevab_1_1_element_base.md#function-drawer) ([**Screen**](classevab_1_1_screen.md) \* aScreen, [**Coor**](structevab_1_1_coor.md) aPos, [**Coor**](structevab_1_1_coor.md) aSize, unsigned char aIsFocused) = 0<br>_Pure virtual method for drawing the element._  |
| virtual void | [**freezer**](classevab_1_1_element_base.md#function-freezer) () <br>_Virtual method for freezing the element._  |
|  bool | [**isFrozen**](classevab_1_1_element_base.md#function-isfrozen) () <br>_Checks if the element is currently freezed._  |
|  void | [**redraw**](classevab_1_1_element_base.md#function-redraw) () <br>_Redraws the element on the current screen._  |






## Detailed Description


Provides focus management and key event routing for container elements. 


    
## Public Functions Documentation




### function GetFocused 

_Gets the current (focused) child._ 
```C++
ElementBase * evab::CompositeBase::GetFocused () const
```





**Returns:**

Pointer to current child, or nullptr if none 





        

<hr>



### function IsFocused 

_Checks if a child is currently focused._ 
```C++
bool evab::CompositeBase::IsFocused (
    ElementBase * aChild
) 
```





**Parameters:**


* `aChild` Child element to check 



**Returns:**

true if the child is focused 





        

<hr>



### function OnKey 

_Handles key events by forwarding to focused child._ 
```C++
virtual bool evab::CompositeBase::OnKey (
    Keys aKey
) override
```





**Parameters:**


* `aKey` OnKey code to process 



**Returns:**

true if the key was handled, false otherwise 





        
Implements [*evab::ElementBase::OnKey*](classevab_1_1_element_base.md#function-onkey)


<hr>
## Protected Functions Documentation




### function focusChild 

_Sets the focused child element._ 
```C++
void evab::CompositeBase::focusChild (
    ElementBase * aChild
) 
```





**Parameters:**


* `aChild` Child element to focus 




        

<hr>

------------------------------
The documentation for this class was generated from the following file `src/evabCompositeBase.h`

