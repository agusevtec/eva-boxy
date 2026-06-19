

# Class evab::ElementBase



[**ClassList**](annotated.md) **>** [**evab**](namespaceevab.md) **>** [**ElementBase**](classevab_1_1_element_base.md)










Inherited by the following classes: [evab::ListBox](classevab_1_1_list_box.md),  [evab::ListBox](classevab_1_1_list_box.md),  [evab::BatteryIndicator](classevab_1_1_battery_indicator.md),  [evab::CompositeBase](classevab_1_1_composite_base.md),  [evab::InputFloat](classevab_1_1_input_float.md),  [evab::InputInt](classevab_1_1_input_int.md),  [evab::LayoutPane](classevab_1_1_layout_pane.md),  [evab::ListBox](classevab_1_1_list_box.md)
































## Public Functions

| Type | Name |
| ---: | :--- |
|  void | [**Draw**](#function-draw) ([**IScreen**](classevab_1_1_i_screen.md) \* aScreen, [**Coor**](structevab_1_1_coor.md) aPos, [**Coor**](structevab_1_1_coor.md) aSize, unsigned char aIsFocused) <br> |
|  void | [**Hide**](#function-hide) () <br> |
|  bool | [**IsHidden**](#function-ishidden) () <br> |
| virtual bool | [**Key**](#function-key) (Keys aKey) <br> |
|  void | [**Redraw**](#function-redraw) () <br> |




























## Public Functions Documentation




### function Draw 

```C++
void evab::ElementBase::Draw (
    IScreen * aScreen,
    Coor aPos,
    Coor aSize,
    unsigned char aIsFocused
) 
```




<hr>



### function Hide 

```C++
void evab::ElementBase::Hide () 
```




<hr>



### function IsHidden 

```C++
bool evab::ElementBase::IsHidden () 
```




<hr>



### function Key 

```C++
virtual bool evab::ElementBase::Key (
    Keys aKey
) 
```




<hr>



### function Redraw 

```C++
void evab::ElementBase::Redraw () 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `src/evabElementBase.h`

