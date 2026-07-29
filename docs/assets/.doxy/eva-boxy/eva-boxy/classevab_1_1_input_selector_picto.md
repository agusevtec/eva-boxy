

# Class evab::InputSelectorPicto

**template &lt;class TAlbum&gt;**



[**ClassList**](annotated.md) **>** [**evab**](namespaceevab.md) **>** [**InputSelectorPicto**](classevab_1_1_input_selector_picto.md)



_Pictogram-based input element._ [More...](#detailed-description)

* `#include <evabInputSelectorPicto.h>`



Inherits the following classes: [evab::ElementBase](classevab_1_1_element_base.md)






















































## Public Functions

| Type | Name |
| ---: | :--- |
|  signed char | [**GetValue**](#function-getvalue) () const<br>_Gets the current pictogram index._  |
|  signed char | [**GetValuePercent**](#function-getvaluepercent) () const<br>_Gets value as percentage._  |
|  void | [**Increment**](#function-increment) (signed char delta) <br>_Increments the pictogram index._  |
|   | [**InputSelectorPicto**](#function-inputselectorpicto) (int aValue=0) <br>_Constructor for InputPictogram._  |
|  void | [**SetValue**](#function-setvalue) (int aValue) <br>_Sets the pictogram index and redraws._  |
|  void | [**SetValuePercent**](#function-setvaluepercent) (int aValue) <br>_Sets value as percentage (0-100)._  |


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
| virtual void | [**drawer**](#function-drawer) ([**Screen**](classevab_1_1_screen.md) \* aScreen, [**Coor**](structevab_1_1_coor.md) aPos, [**Coor**](structevab_1_1_coor.md) aSize, unsigned char aIsFocused) override<br>_Draws the pictogram on screen._  |


## Protected Functions inherited from evab::ElementBase

See [evab::ElementBase](classevab_1_1_element_base.md)

| Type | Name |
| ---: | :--- |
| virtual void | [**drawer**](classevab_1_1_element_base.md#function-drawer) ([**Screen**](classevab_1_1_screen.md) \* aScreen, [**Coor**](structevab_1_1_coor.md) aPos, [**Coor**](structevab_1_1_coor.md) aSize, unsigned char aIsFocused) = 0<br>_Pure virtual method for drawing the element._  |
| virtual void | [**hider**](classevab_1_1_element_base.md#function-hider) () <br>_Virtual method for hiding the element._  |






## Detailed Description


Displays a pictogram from a pictoset and manages its index value.




**Template parameters:**


* `TAlbum` Album class providing pictogram data and count 




    
## Public Functions Documentation




### function GetValue 

_Gets the current pictogram index._ 
```C++
inline signed char evab::InputSelectorPicto::GetValue () const
```





**Returns:**

Current pictogram index 





        

<hr>



### function GetValuePercent 

_Gets value as percentage._ 
```C++
inline signed char evab::InputSelectorPicto::GetValuePercent () const
```





**Returns:**

Percentage value (0-100) 





        

<hr>



### function Increment 

_Increments the pictogram index._ 
```C++
inline void evab::InputSelectorPicto::Increment (
    signed char delta
) 
```





**Parameters:**


* `delta` Amount to increment (positive or negative) 




        

<hr>



### function InputSelectorPicto 

_Constructor for InputPictogram._ 
```C++
inline evab::InputSelectorPicto::InputSelectorPicto (
    int aValue=0
) 
```





**Parameters:**


* `aValue` Initial pictogram index (0 to TAlbum::Count - 1) 




        

<hr>



### function SetValue 

_Sets the pictogram index and redraws._ 
```C++
inline void evab::InputSelectorPicto::SetValue (
    int aValue
) 
```





**Parameters:**


* `aValue` New pictogram index 




        

<hr>



### function SetValuePercent 

_Sets value as percentage (0-100)._ 
```C++
inline void evab::InputSelectorPicto::SetValuePercent (
    int aValue
) 
```



Maps percentage to pictogram index range.




**Parameters:**


* `aValue` Percentage value (0-100) 




        

<hr>
## Protected Functions Documentation




### function drawer 

_Draws the pictogram on screen._ 
```C++
inline virtual void evab::InputSelectorPicto::drawer (
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
The documentation for this class was generated from the following file `src/evabInputSelectorPicto.h`

