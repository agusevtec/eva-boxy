

# Class evab::InputSelectorAlbum

**template &lt;class TAlbum&gt;**



[**ClassList**](annotated.md) **>** [**evab**](namespaceevab.md) **>** [**InputSelectorAlbum**](classevab_1_1_input_selector_album.md)



_Pictogram-based input element._ [More...](#detailed-description)

* `#include <evabInputSelectorAlbum.h>`



Inherits the following classes: [evab::ElementBase](classevab_1_1_element_base.md)






















































## Public Functions

| Type | Name |
| ---: | :--- |
|  unsigned char | [**Count**](#function-count) () const<br> |
|  void | [**Increment**](#function-increment) (signed char aSteps) <br>_Increments the pictogram index._  |
|   | [**InputSelectorAlbum**](#function-inputselectoralbum) (int aValue=0) <br>_Constructor for InputPictogram._  |
|  void | [**Select**](#function-select) (int aValue) <br>_Sets the pictogram index and redraws._  |
|  signed char | [**Selected**](#function-selected) () const<br>_Gets the current pictogram index._  |


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
| virtual void | [**drawer**](#function-drawer) ([**Screen**](classevab_1_1_screen.md) \* aScreen, [**Coor**](structevab_1_1_coor.md) aPos, [**Coor**](structevab_1_1_coor.md) aSize, unsigned char aIsFocused) override<br>_Draws the pictogram on screen._  |


## Protected Functions inherited from evab::ElementBase

See [evab::ElementBase](classevab_1_1_element_base.md)

| Type | Name |
| ---: | :--- |
| virtual void | [**drawer**](classevab_1_1_element_base.md#function-drawer) ([**Screen**](classevab_1_1_screen.md) \* aScreen, [**Coor**](structevab_1_1_coor.md) aPos, [**Coor**](structevab_1_1_coor.md) aSize, unsigned char aIsFocused) = 0<br>_Pure virtual method for drawing the element._  |
| virtual void | [**freezer**](classevab_1_1_element_base.md#function-freezer) () <br>_Virtual method for freezing the element._  |
|  bool | [**isFrozen**](classevab_1_1_element_base.md#function-isfrozen) () <br>_Checks if the element is currently freezed._  |
|  void | [**redraw**](classevab_1_1_element_base.md#function-redraw) () <br>_Redraws the element on the current screen._  |






## Detailed Description


Displays a pictogram from a pictoset and manages its index value.




**Template parameters:**


* `TAlbum` Album class providing pictogram data and count 




    
## Public Functions Documentation




### function Count 

```C++
inline unsigned char evab::InputSelectorAlbum::Count () const
```




<hr>



### function Increment 

_Increments the pictogram index._ 
```C++
inline void evab::InputSelectorAlbum::Increment (
    signed char aSteps
) 
```





**Parameters:**


* `aSteps` Amount to increment (positive or negative) 




        

<hr>



### function InputSelectorAlbum 

_Constructor for InputPictogram._ 
```C++
inline evab::InputSelectorAlbum::InputSelectorAlbum (
    int aValue=0
) 
```





**Parameters:**


* `aValue` Initial pictogram index (0 to TAlbum::Count - 1) 




        

<hr>



### function Select 

_Sets the pictogram index and redraws._ 
```C++
inline void evab::InputSelectorAlbum::Select (
    int aValue
) 
```





**Parameters:**


* `aValue` New pictogram index 




        

<hr>



### function Selected 

_Gets the current pictogram index._ 
```C++
inline signed char evab::InputSelectorAlbum::Selected () const
```





**Returns:**

Current pictogram index 





        

<hr>
## Protected Functions Documentation




### function drawer 

_Draws the pictogram on screen._ 
```C++
inline virtual void evab::InputSelectorAlbum::drawer (
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
The documentation for this class was generated from the following file `src/evabInputSelectorAlbum.h`

