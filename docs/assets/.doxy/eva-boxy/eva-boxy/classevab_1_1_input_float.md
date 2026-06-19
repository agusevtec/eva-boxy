

# Class evab::InputFloat



[**ClassList**](annotated.md) **>** [**evab**](namespaceevab.md) **>** [**InputFloat**](classevab_1_1_input_float.md)








Inherits the following classes: [evab::ElementBase](classevab_1_1_element_base.md)






















































## Public Functions

| Type | Name |
| ---: | :--- |
|  float | [**GetValue**](#function-getvalue) () const<br> |
|  void | [**Increment**](#function-increment) (signed char delta) <br> |
|   | [**InputFloat**](#function-inputfloat) (float aValue=0) <br> |
|  void | [**SetValue**](#function-setvalue) (float aValue) <br> |


## Public Functions inherited from evab::ElementBase

See [evab::ElementBase](classevab_1_1_element_base.md)

| Type | Name |
| ---: | :--- |
|  void | [**Draw**](classevab_1_1_element_base.md#function-draw) ([**IScreen**](classevab_1_1_i_screen.md) \* aScreen, [**Coor**](structevab_1_1_coor.md) aPos, [**Coor**](structevab_1_1_coor.md) aSize, unsigned char aIsFocused) <br> |
|  void | [**Hide**](classevab_1_1_element_base.md#function-hide) () <br> |
|  bool | [**IsHidden**](classevab_1_1_element_base.md#function-ishidden) () <br> |
| virtual bool | [**Key**](classevab_1_1_element_base.md#function-key) (Keys aKey) <br> |
|  void | [**Redraw**](classevab_1_1_element_base.md#function-redraw) () <br> |














































## Protected Functions

| Type | Name |
| ---: | :--- |
| virtual void | [**drawer**](#function-drawer) ([**IScreen**](classevab_1_1_i_screen.md) \* aScreen, [**Coor**](structevab_1_1_coor.md) aPos, [**Coor**](structevab_1_1_coor.md) aSize, unsigned char aIsFocused) override<br> |








## Public Functions Documentation




### function GetValue 

```C++
float evab::InputFloat::GetValue () const
```




<hr>



### function Increment 

```C++
void evab::InputFloat::Increment (
    signed char delta
) 
```




<hr>



### function InputFloat 

```C++
evab::InputFloat::InputFloat (
    float aValue=0
) 
```




<hr>



### function SetValue 

```C++
void evab::InputFloat::SetValue (
    float aValue
) 
```




<hr>
## Protected Functions Documentation




### function drawer 

```C++
virtual void evab::InputFloat::drawer (
    IScreen * aScreen,
    Coor aPos,
    Coor aSize,
    unsigned char aIsFocused
) override
```



Implements [*evab::ElementBase::drawer*](classevab_1_1_element_base.md#function-drawer)


<hr>

------------------------------
The documentation for this class was generated from the following file `src/evabInputFloat.h`

