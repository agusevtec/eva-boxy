

# Class evab::TextLabel

**template &lt;typename T, typename TAlign&gt;**



[**ClassList**](annotated.md) **>** [**evab**](namespaceevab.md) **>** [**TextLabel**](classevab_1_1_text_label.md)



_Text label widget with alignment._ [More...](#detailed-description)

* `#include <evabTextLabel.h>`



Inherits the following classes: [evab::ElementBase](classevab_1_1_element_base.md)






















































## Public Functions

| Type | Name |
| ---: | :--- |
|  T | [**GetText**](#function-gettext) () const<br>_Gets current text._  |
|  void | [**SetText**](#function-settext) (T aText) <br>_Sets new text and redraws._  |
|   | [**TextLabel**](#function-textlabel) (T aText) <br>_Constructor with text._  |


## Public Functions inherited from evab::ElementBase

See [evab::ElementBase](classevab_1_1_element_base.md)

| Type | Name |
| ---: | :--- |
|  void | [**Draw**](classevab_1_1_element_base.md#function-draw) ([**Screen**](classevab_1_1_screen.md) \* aScreen, [**Coor**](structevab_1_1_coor.md) aPos, [**Coor**](structevab_1_1_coor.md) aSize, unsigned char aIsFocused) <br>_Draws the element on the specified screen._  |
|  void | [**Hide**](classevab_1_1_element_base.md#function-mute) () <br>_Hides the element from view._  |
|  bool | [**IsHidden**](classevab_1_1_element_base.md#function-ishidden) () <br>_Checks if the element is hidden._  |
| virtual bool | [**Key**](classevab_1_1_element_base.md#function-key) (Keys aKey) <br>_Handles key events for the element._  |
|  void | [**Redraw**](classevab_1_1_element_base.md#function-redraw) () <br>_Redraws the element on the current screen._  |














































## Protected Functions

| Type | Name |
| ---: | :--- |
| virtual void | [**drawer**](#function-drawer) ([**Screen**](classevab_1_1_screen.md) \* aScreen, [**Coor**](structevab_1_1_coor.md) aPos, [**Coor**](structevab_1_1_coor.md) aSize, unsigned char aIsFocused) override<br>_Draws the label with alignment._  |
| virtual void | [**hider**](#function-hider) () override<br>_Virtual method for muting the element._  |


## Protected Functions inherited from evab::ElementBase

See [evab::ElementBase](classevab_1_1_element_base.md)

| Type | Name |
| ---: | :--- |
| virtual void | [**drawer**](classevab_1_1_element_base.md#function-drawer) ([**Screen**](classevab_1_1_screen.md) \* aScreen, [**Coor**](structevab_1_1_coor.md) aPos, [**Coor**](structevab_1_1_coor.md) aSize, unsigned char aIsFocused) = 0<br>_Pure virtual method for drawing the element._  |
| virtual void | [**hider**](classevab_1_1_element_base.md#function-hider) () <br>_Virtual method for muting the element._  |






## Detailed Description




**Template parameters:**


* `T` Text type (char\*, const char\*, \_\_FlashStringHelper\*) 
* `TAlign` Alignment strategy ([**LeftAlign**](structevab_1_1_left_align.md), [**CenterAlign**](structevab_1_1_center_align.md), [**RightAlign**](structevab_1_1_right_align.md)) 




    
## Public Functions Documentation




### function GetText 

_Gets current text._ 
```C++
inline T evab::TextLabel::GetText () const
```





**Returns:**

Current text 





        

<hr>



### function SetText 

_Sets new text and redraws._ 
```C++
inline void evab::TextLabel::SetText (
    T aText
) 
```





**Parameters:**


* `aText` New text 




        

<hr>



### function TextLabel 

_Constructor with text._ 
```C++
inline explicit evab::TextLabel::TextLabel (
    T aText
) 
```





**Parameters:**


* `aText` Text to display 




        

<hr>
## Protected Functions Documentation




### function drawer 

_Draws the label with alignment._ 
```C++
inline virtual void evab::TextLabel::drawer (
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



### function hider 

_Virtual method for muting the element._ 
```C++
inline virtual void evab::TextLabel::hider () override
```



Override to implement custom muting behavior. 


        
Implements [*evab::ElementBase::hider*](classevab_1_1_element_base.md#function-hider)


<hr>

------------------------------
The documentation for this class was generated from the following file `src/evabTextLabel.h`

