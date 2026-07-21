

# Class evab::CompositeBase



[**ClassList**](annotated.md) **>** [**evab**](namespaceevab.md) **>** [**CompositeBase**](classevab_1_1_composite_base.md)



_Abstract base class for composite elements that can manage child focus._ [More...](#detailed-description)

* `#include <evabCompositeBase.h>`



Inherits the following classes: [evab::ElementBase](classevab_1_1_element_base.md)






















































## Public Functions

| Type | Name |
| ---: | :--- |
|  bool | [**IsFocused**](#function-isfocused) ([**ElementBase**](classevab_1_1_element_base.md) \* aChild) <br>_Checks if a child is currently focused._  |
| virtual void | [**hider**](#function-hider) () = 0<br>_Pure virtual method to hide all children._  |
| virtual bool | [**onResidualKey**](#function-onresidualkey) (Keys aKey) <br>_Handles residual keys when no child handles the event._  |


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
|  void | [**focusChild**](#function-focuschild) ([**ElementBase**](classevab_1_1_element_base.md) \* aChild) <br>_Sets the focused child element._  |








## Detailed Description


Provides focus management and key event routing for container elements. 


    
## Public Functions Documentation




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



### function hider 

_Pure virtual method to hide all children._ 
```C++
virtual void evab::CompositeBase::hider () = 0
```



Implements [*evab::ElementBase::hider*](classevab_1_1_element_base.md#function-hider)


<hr>



### function onResidualKey 

_Handles residual keys when no child handles the event._ 
```C++
virtual bool evab::CompositeBase::onResidualKey (
    Keys aKey
) 
```



Override this to implement custom key handling in composites.




**Parameters:**


* `aKey` Key code to process 



**Returns:**

true if the key was handled, false otherwise 





        

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

