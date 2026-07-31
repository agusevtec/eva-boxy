

# Class evab::InputIntDiscrete



[**ClassList**](annotated.md) **>** [**evab**](namespaceevab.md) **>** [**InputIntDiscrete**](classevab_1_1_input_int_discrete.md)








Inherits the following classes: [evab::InputInt](classevab_1_1_input_int.md)










































































## Public Functions

| Type | Name |
| ---: | :--- |
|  unsigned char | [**Count**](#function-count) () const<br> |
|  void | [**Increment**](#function-increment) (int aSteps) <br> |
|   | [**InputIntDiscrete**](#function-inputintdiscrete) (int aValue, unsigned char aCount, int aMin, int aMax) <br> |
|  void | [**Select**](#function-select) (unsigned char aIndex) <br> |
|  signed short | [**Selected**](#function-selected) () const<br> |


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








## Public Functions Documentation




### function Count 

```C++
inline unsigned char evab::InputIntDiscrete::Count () const
```




<hr>



### function Increment 

```C++
void evab::InputIntDiscrete::Increment (
    int aSteps
) 
```




<hr>



### function InputIntDiscrete 

```C++
evab::InputIntDiscrete::InputIntDiscrete (
    int aValue,
    unsigned char aCount,
    int aMin,
    int aMax
) 
```




<hr>



### function Select 

```C++
void evab::InputIntDiscrete::Select (
    unsigned char aIndex
) 
```




<hr>



### function Selected 

```C++
signed short evab::InputIntDiscrete::Selected () const
```




<hr>

------------------------------
The documentation for this class was generated from the following file `src/evabInputInt.h`

