

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
| virtual bool | [**Key**](#function-key) (Keys aKey) override<br>_Handles key events by forwarding to focused child._  |


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
|  void | [**focusChild**](#function-focuschild) ([**ElementBase**](classevab_1_1_element_base.md) \* aChild) <br>_Sets the focused child element._  |


## Protected Functions inherited from evab::ElementBase

See [evab::ElementBase](classevab_1_1_element_base.md)

| Type | Name |
| ---: | :--- |
| virtual void | [**drawer**](classevab_1_1_element_base.md#function-drawer) ([**Screen**](classevab_1_1_screen.md) \* aScreen, [**Coor**](structevab_1_1_coor.md) aPos, [**Coor**](structevab_1_1_coor.md) aSize, unsigned char aIsFocused) = 0<br>_Pure virtual method for drawing the element._  |
| virtual void | [**hider**](classevab_1_1_element_base.md#function-hider) () <br>_Virtual method for hiding the element._  |






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



### function Key 

_Handles key events by forwarding to focused child._ 
```C++
virtual bool evab::CompositeBase::Key (
    Keys aKey
) override
```





**Parameters:**


* `aKey` Key code to process 



**Returns:**

true if the key was handled, false otherwise 





        
Implements [*evab::ElementBase::Key*](classevab_1_1_element_base.md#function-key)


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

