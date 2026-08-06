

# Class evab::InputFloatDiscrete



[**ClassList**](annotated.md) **>** [**evab**](namespaceevab.md) **>** [**InputFloatDiscrete**](classevab_1_1_input_float_discrete.md)



_Discrete float input element._ [More...](#detailed-description)

* `#include <evabInputFloat.h>`



Inherits the following classes: [evab::InputFloat](classevab_1_1_input_float.md)










































































## Public Functions

| Type | Name |
| ---: | :--- |
|  unsigned char | [**Count**](#function-count) () const<br>_Returns the total number of steps._  |
|  void | [**Increment**](#function-increment) (int aSteps) <br>_Increments the pictogram index._  |
|   | [**InputFloatDiscrete**](#function-inputfloatdiscrete) (float aValue, unsigned char aCount, float aMin, float aMax) <br>_Constructs a discrete float input._  |
|  void | [**Select**](#function-select) (unsigned char aIndex) <br>_Selects a step by index (0 to_ [_**Count()**_](classevab_1_1_input_float_discrete.md#function-count) _-1)._ |
|  signed short | [**Selected**](#function-selected) () const<br>_Returns the currently selected index._  |


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


Adds index-based control to [**InputFloat**](classevab_1_1_input_float.md). 


    
## Public Functions Documentation




### function Count 

_Returns the total number of steps._ 
```C++
inline unsigned char evab::InputFloatDiscrete::Count () const
```




<hr>



### function Increment 

_Increments the pictogram index._ 
```C++
void evab::InputFloatDiscrete::Increment (
    int aSteps
) 
```





**Parameters:**


* `aSteps` Amount to increment (positive or negative) 




        

<hr>



### function InputFloatDiscrete 

_Constructs a discrete float input._ 
```C++
evab::InputFloatDiscrete::InputFloatDiscrete (
    float aValue,
    unsigned char aCount,
    float aMin,
    float aMax
) 
```





**Parameters:**


* `aValue` Initial value (snapped to nearest step). 
* `aCount` Number of steps (must be &gt;= 2). 
* `aMin` Minimum value (inclusive). 
* `aMax` Maximum value (inclusive). 




        

<hr>



### function Select 

_Selects a step by index (0 to_ [_**Count()**_](classevab_1_1_input_float_discrete.md#function-count) _-1)._
```C++
void evab::InputFloatDiscrete::Select (
    unsigned char aIndex
) 
```




<hr>



### function Selected 

_Returns the currently selected index._ 
```C++
signed short evab::InputFloatDiscrete::Selected () const
```




<hr>

------------------------------
The documentation for this class was generated from the following file `src/evabInputFloat.h`

