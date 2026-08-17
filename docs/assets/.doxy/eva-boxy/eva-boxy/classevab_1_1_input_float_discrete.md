

# Class evab::InputFloatDiscrete



[**ClassList**](annotated.md) **>** [**evab**](namespaceevab.md) **>** [**InputFloatDiscrete**](classevab_1_1_input_float_discrete.md)



_Discrete float input element._ [More...](#detailed-description)

* `#include <evabInputFloat.h>`



Inherits the following classes: [evab::InputFloat](classevab_1_1_input_float.md)










































































## Public Functions

| Type | Name |
| ---: | :--- |
|  unsigned short | [**Count**](#function-count) () const<br>_Returns the total number of steps._  |
|  void | [**Increment**](#function-increment) (signed char aSteps) <br>_Increments value by discrete grid steps._  |
|   | [**InputFloatDiscrete**](#function-inputfloatdiscrete) (float aValue, float aMin, float aMax, float aStep=0.1f) <br>_Constructs a discrete float input._  |
|  void | [**Select**](#function-select) (unsigned short aIndex) <br>_Selects a step by index (0 to_ [_**Count()**_](classevab_1_1_input_float_discrete.md#function-count) _-1)._ |
|  signed short | [**Selected**](#function-selected) () const<br>_Returns the currently selected index._  |
|  void | [**SetValue**](#function-setvalue) (float aValue) <br>_Sets the float value snapped to grid and redraws._  |


## Public Functions inherited from evab::InputFloat

See [evab::InputFloat](classevab_1_1_input_float.md)

| Type | Name |
| ---: | :--- |
|  float | [**GetValue**](classevab_1_1_input_float.md#function-getvalue) () const<br>_Gets the current float value._  |
|  void | [**Increment**](classevab_1_1_input_float.md#function-increment) (signed char aSteps) <br>_Increments the value by a step._  |
|   | [**InputFloat**](classevab_1_1_input_float.md#function-inputfloat) (float aValue=0) <br>_Constructor for_ [_**InputFloat**_](classevab_1_1_input_float.md) _._ |
|  void | [**SetValue**](classevab_1_1_input_float.md#function-setvalue) (float aValue) <br>_Sets the float value and redraws._  |


## Public Functions inherited from evab::ElementBase

See [evab::ElementBase](classevab_1_1_element_base.md)

| Type | Name |
| ---: | :--- |
|  void | [**Draw**](classevab_1_1_element_base.md#function-draw) ([**Screen**](classevab_1_1_screen.md) \* aScreen, [**Coor**](structevab_1_1_coor.md) aPos, [**Coor**](structevab_1_1_coor.md) aSize, unsigned char aIsFocused) <br>_Draws the element on the specified screen._  |
|  void | [**Freeze**](classevab_1_1_element_base.md#function-freeze) () <br>_Make element insensitive to redraw method._  |
| virtual bool | [**OnKey**](classevab_1_1_element_base.md#function-onkey) (Keys aKey) <br>_Handles key events for the element._  |






































































## Protected Functions inherited from evab::InputFloat

See [evab::InputFloat](classevab_1_1_input_float.md)

| Type | Name |
| ---: | :--- |
| virtual void | [**drawer**](classevab_1_1_input_float.md#function-drawer) ([**Screen**](classevab_1_1_screen.md) \* aScreen, [**Coor**](structevab_1_1_coor.md) aPos, [**Coor**](structevab_1_1_coor.md) aSize, unsigned char aIsFocused) override<br>_Draws the float value centered on screen._  |


## Protected Functions inherited from evab::ElementBase

See [evab::ElementBase](classevab_1_1_element_base.md)

| Type | Name |
| ---: | :--- |
| virtual void | [**drawer**](classevab_1_1_element_base.md#function-drawer) ([**Screen**](classevab_1_1_screen.md) \* aScreen, [**Coor**](structevab_1_1_coor.md) aPos, [**Coor**](structevab_1_1_coor.md) aSize, unsigned char aIsFocused) = 0<br>_Pure virtual method for drawing the element._  |
| virtual void | [**freezer**](classevab_1_1_element_base.md#function-freezer) () <br>_Virtual method for freezing the element._  |
|  bool | [**isFrozen**](classevab_1_1_element_base.md#function-isfrozen) () <br>_Checks if the element is currently freezed._  |
|  void | [**redraw**](classevab_1_1_element_base.md#function-redraw) () <br>_Redraws the element on the current screen._  |








## Detailed Description


Adds step-grid bound control to [**InputFloat**](classevab_1_1_input_float.md). 


    
## Public Functions Documentation




### function Count 

_Returns the total number of steps._ 
```C++
unsigned short evab::InputFloatDiscrete::Count () const
```




<hr>



### function Increment 

_Increments value by discrete grid steps._ 
```C++
void evab::InputFloatDiscrete::Increment (
    signed char aSteps
) 
```





**Parameters:**


* `aSteps` Amount of steps to increment (positive or negative) 




        

<hr>



### function InputFloatDiscrete 

_Constructs a discrete float input._ 
```C++
evab::InputFloatDiscrete::InputFloatDiscrete (
    float aValue,
    float aMin,
    float aMax,
    float aStep=0.1f
) 
```





**Parameters:**


* `aValue` Initial value. 
* `aMin` Minimum value / start of the step grid. 
* `aMax` Maximum boundary limit. 
* `aStep` [**Grid**](classevab_1_1_grid.md) step size (must be &gt; 0.0f). 




        

<hr>



### function Select 

_Selects a step by index (0 to_ [_**Count()**_](classevab_1_1_input_float_discrete.md#function-count) _-1)._
```C++
void evab::InputFloatDiscrete::Select (
    unsigned short aIndex
) 
```




<hr>



### function Selected 

_Returns the currently selected index._ 
```C++
signed short evab::InputFloatDiscrete::Selected () const
```




<hr>



### function SetValue 

_Sets the float value snapped to grid and redraws._ 
```C++
void evab::InputFloatDiscrete::SetValue (
    float aValue
) 
```





**Parameters:**


* `aValue` New float value 




        

<hr>

------------------------------
The documentation for this class was generated from the following file `src/evabInputFloat.h`

