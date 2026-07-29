

# Class evab::ElementBase



[**ClassList**](annotated.md) **>** [**evab**](namespaceevab.md) **>** [**ElementBase**](classevab_1_1_element_base.md)



_Abstract base class for all UI elements._ [More...](#detailed-description)

* `#include <evabElementBase.h>`





Inherited by the following classes: [evab::InputStretchBar](classevab_1_1_input_stretch_bar.md),  [evab::InputStretchBar](classevab_1_1_input_stretch_bar.md),  [evab::InputStretchBar](classevab_1_1_input_stretch_bar.md),  [evab::InputStretchBar](classevab_1_1_input_stretch_bar.md),  [evab::InputTextStretchBar](classevab_1_1_input_text_stretch_bar.md),  [evab::InputTextStretchBar](classevab_1_1_input_text_stretch_bar.md),  [evab::InputTextStretchBar](classevab_1_1_input_text_stretch_bar.md),  [evab::InputTextStretchBar](classevab_1_1_input_text_stretch_bar.md),  [evab::ListBox](classevab_1_1_list_box.md),  [evab::ListBox](classevab_1_1_list_box.md),  [evab::TextLabel](classevab_1_1_text_label.md),  [evab::TextLabel](classevab_1_1_text_label.md),  [evab::TextLabel](classevab_1_1_text_label.md),  [evab::TextLabel](classevab_1_1_text_label.md),  [evab::TextLabel](classevab_1_1_text_label.md),  [evab::TextLabel](classevab_1_1_text_label.md),  [evab::TextLabel](classevab_1_1_text_label.md),  [evab::TextLabel](classevab_1_1_text_label.md),  [evab::TextLabel](classevab_1_1_text_label.md),  [evab::CompositeBase](classevab_1_1_composite_base.md),  [evab::InputAnimation](classevab_1_1_input_animation.md),  [evab::InputButton](classevab_1_1_input_button.md),  [evab::InputButtonPicto](classevab_1_1_input_button_picto.md),  [evab::InputFloat](classevab_1_1_input_float.md),  [evab::InputInt](classevab_1_1_input_int.md),  [evab::InputSelectorPicto](classevab_1_1_input_selector_picto.md),  [evab::InputStretchBar](classevab_1_1_input_stretch_bar.md),  [evab::InputTextStretchBar](classevab_1_1_input_text_stretch_bar.md),  [evab::LayoutBase](classevab_1_1_layout_base.md),  [evab::ListBox](classevab_1_1_list_box.md),  [evab::TextLabel](classevab_1_1_text_label.md)
































## Public Functions

| Type | Name |
| ---: | :--- |
|  void | [**Draw**](#function-draw) ([**Screen**](classevab_1_1_screen.md) \* aScreen, [**Coor**](structevab_1_1_coor.md) aPos, [**Coor**](structevab_1_1_coor.md) aSize, unsigned char aIsFocused) <br>_Draws the element on the specified screen._  |
|  void | [**Hide**](#function-hide) () <br>_Hides the element from view._  |
|  bool | [**IsHidden**](#function-ishidden) () <br>_Checks if the element is hidden._  |
| virtual bool | [**Key**](#function-key) (Keys aKey) <br>_Handles key events for the element._  |
|  void | [**Redraw**](#function-redraw) () <br>_Redraws the element on the current screen._  |
























## Protected Functions

| Type | Name |
| ---: | :--- |
| virtual void | [**drawer**](#function-drawer) ([**Screen**](classevab_1_1_screen.md) \* aScreen, [**Coor**](structevab_1_1_coor.md) aPos, [**Coor**](structevab_1_1_coor.md) aSize, unsigned char aIsFocused) = 0<br>_Pure virtual method for drawing the element._  |
| virtual void | [**hider**](#function-hider) () <br>_Virtual method for hiding the element._  |




## Detailed Description


Provides the core functionality for rendering, state management, and key event handling for visual elements. 


    
## Public Functions Documentation




### function Draw 

_Draws the element on the specified screen._ 
```C++
void evab::ElementBase::Draw (
    Screen * aScreen,
    Coor aPos,
    Coor aSize,
    unsigned char aIsFocused
) 
```





**Parameters:**


* `aScreen` [**Screen**](classevab_1_1_screen.md) to draw on 
* `aPos` Position on screen 
* `aSize` Size of the element 
* `aIsFocused` Focus state (1 = focused, 0 = not focused) 




        

<hr>



### function Hide 

_Hides the element from view._ 
```C++
void evab::ElementBase::Hide () 
```




<hr>



### function IsHidden 

_Checks if the element is hidden._ 
```C++
bool evab::ElementBase::IsHidden () 
```





**Returns:**

true if hidden, false otherwise 





        

<hr>



### function Key 

_Handles key events for the element._ 
```C++
virtual bool evab::ElementBase::Key (
    Keys aKey
) 
```



Override to implement custom key handling.




**Parameters:**


* `aKey` Key code to process 



**Returns:**

true if the key was handled, false otherwise 





        

<hr>



### function Redraw 

_Redraws the element on the current screen._ 
```C++
void evab::ElementBase::Redraw () 
```




<hr>
## Protected Functions Documentation




### function drawer 

_Pure virtual method for drawing the element._ 
```C++
virtual void evab::ElementBase::drawer (
    Screen * aScreen,
    Coor aPos,
    Coor aSize,
    unsigned char aIsFocused
) = 0
```





**Parameters:**


* `aScreen` [**Screen**](classevab_1_1_screen.md) to draw on 
* `aPos` Position on screen 
* `aSize` Size of the element 
* `aIsFocused` Focus state (1 = focused, 0 = not focused) 




        

<hr>



### function hider 

_Virtual method for hiding the element._ 
```C++
inline virtual void evab::ElementBase::hider () 
```



Override to implement custom hiding behavior. 


        

<hr>

------------------------------
The documentation for this class was generated from the following file `src/evabElementBase.h`

