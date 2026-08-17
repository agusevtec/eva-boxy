

# Class evab::InputIntDiscrete



[**ClassList**](annotated.md) **>** [**evab**](namespaceevab.md) **>** [**InputIntDiscrete**](classevab_1_1_input_int_discrete.md)



_Discrete integer input element._ [More...](#detailed-description)

* `#include <evabInputInt.h>`



Inherits the following classes: [evab::InputInt](classevab_1_1_input_int.md)










































































## Public Functions

| Type | Name |
| ---: | :--- |
|  unsigned char | [**Count**](#function-count) () const<br>_Returns the total number of steps._  |
|  void | [**Increment**](#function-increment) (signed char aSteps) <br>_Increments the pictogram index._  |
|   | [**InputIntDiscrete**](#function-inputintdiscrete) (int aValue, int aMin, int aMax, unsigned short aStep=1) <br>_Constructs a discrete integer input._  |
|  void | [**Select**](#function-select) (unsigned char aIndex) <br>_Selects a step by index (0 to_ [_**Count()**_](classevab_1_1_input_int_discrete.md#function-count) _-1)._ |
|  signed short | [**Selected**](#function-selected) () const<br>_Returns the currently selected index._  |
|  void | [**SetValue**](#function-setvalue) (int aValue) <br>_Sets the integer value and redraws._  |


## Public Functions inherited from evab::InputInt

See [evab::InputInt](classevab_1_1_input_int.md)

| Type | Name |
| ---: | :--- |
|  int | [**GetValue**](classevab_1_1_input_int.md#function-getvalue) () const<br>_Gets the current integer value._  |
|  void | [**Increment**](classevab_1_1_input_int.md#function-increment) (signed char aSteps) <br>_Increments the value by a step._  |
|   | [**InputInt**](classevab_1_1_input_int.md#function-inputint) (int aValue=0) <br>_Constructor for_ [_**InputInt**_](classevab_1_1_input_int.md) _._ |
|  void | [**SetValue**](classevab_1_1_input_int.md#function-setvalue) (int aValue) <br>_Sets the integer value and redraws._  |


## Public Functions inherited from evab::ElementBase

See [evab::ElementBase](classevab_1_1_element_base.md)

| Type | Name |
| ---: | :--- |
|  void | [**Draw**](classevab_1_1_element_base.md#function-draw) ([**Screen**](classevab_1_1_screen.md) \* aScreen, [**Coor**](structevab_1_1_coor.md) aPos, [**Coor**](structevab_1_1_coor.md) aSize, unsigned char aIsFocused) <br>_Draws the element on the specified screen._  |
|  void | [**Freeze**](classevab_1_1_element_base.md#function-freeze) () <br>_Make element insensitive to redraw method._  |
| virtual bool | [**OnKey**](classevab_1_1_element_base.md#function-onkey) (Keys aKey) <br>_Handles key events for the element._  |






































































## Protected Functions inherited from evab::InputInt

See [evab::InputInt](classevab_1_1_input_int.md)

| Type | Name |
| ---: | :--- |
| virtual void | [**drawer**](classevab_1_1_input_int.md#function-drawer) ([**Screen**](classevab_1_1_screen.md) \* aScreen, [**Coor**](structevab_1_1_coor.md) aPos, [**Coor**](structevab_1_1_coor.md) aSize, unsigned char aIsFocused) override<br>_Draws the integer value centered on screen._  |


## Protected Functions inherited from evab::ElementBase

See [evab::ElementBase](classevab_1_1_element_base.md)

| Type | Name |
| ---: | :--- |
| virtual void | [**drawer**](classevab_1_1_element_base.md#function-drawer) ([**Screen**](classevab_1_1_screen.md) \* aScreen, [**Coor**](structevab_1_1_coor.md) aPos, [**Coor**](structevab_1_1_coor.md) aSize, unsigned char aIsFocused) = 0<br>_Pure virtual method for drawing the element._  |
| virtual void | [**freezer**](classevab_1_1_element_base.md#function-freezer) () <br>_Virtual method for freezing the element._  |
|  bool | [**isFrozen**](classevab_1_1_element_base.md#function-isfrozen) () <br>_Checks if the element is currently freezed._  |
|  void | [**redraw**](classevab_1_1_element_base.md#function-redraw) () <br>_Redraws the element on the current screen._  |








## Detailed Description


Adds index-based control to [**InputInt**](classevab_1_1_input_int.md). 


    
## Public Functions Documentation




### function Count 

_Returns the total number of steps._ 
```C++
unsigned char evab::InputIntDiscrete::Count () const
```




<hr>



### function Increment 

_Increments the pictogram index._ 
```C++
void evab::InputIntDiscrete::Increment (
    signed char aSteps
) 
```





**Parameters:**


* `aSteps` Amount to increment (positive or negative) 




        

<hr>



### function InputIntDiscrete 

_Constructs a discrete integer input._ 
```C++
evab::InputIntDiscrete::InputIntDiscrete (
    int aValue,
    int aMin,
    int aMax,
    unsigned short aStep=1
) 
```





**Parameters:**


* `aValue` Initial value. 
* `aMin` Minimum value / start of the step grid. 
* `aMax` Maximum boundary limit. 
* `aStep` [**Grid**](classevab_1_1_grid.md) step size (must be &gt; 0). 




        

<hr>



### function Select 

_Selects a step by index (0 to_ [_**Count()**_](classevab_1_1_input_int_discrete.md#function-count) _-1)._
```C++
void evab::InputIntDiscrete::Select (
    unsigned char aIndex
) 
```




<hr>



### function Selected 

_Returns the currently selected index._ 
```C++
signed short evab::InputIntDiscrete::Selected () const
```




<hr>



### function SetValue 

_Sets the integer value and redraws._ 
```C++
void evab::InputIntDiscrete::SetValue (
    int aValue
) 
```





**Parameters:**


* `aValue` New integer value 




        

<hr>

------------------------------
The documentation for this class was generated from the following file `src/evabInputInt.h`

