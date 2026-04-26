

# Class BoxyBaseField



[**ClassList**](annotated.md) **>** [**BoxyBaseField**](class_boxy_base_field.md)



_Visual element with no behavior. It manages hide and visible things._ 

* `#include <BoxyBaseField.h>`





Inherited by the following classes: [BoxyBaseElement](class_boxy_base_element.md),  [BoxyBatteryIndicator](class_boxy_battery_indicator.md)
































## Public Functions

| Type | Name |
| ---: | :--- |
|  void | [**Draw**](#function-draw) ([**Coor**](struct_coor.md) aPos, [**Coor**](struct_coor.md) aSize, unsigned char aSelected) <br>_normally library users should not use this method. Managing the calls to this method is a responsibility of a container that element was put into. It's only for developers who enhance the library and build composite componets_  |
|  bool | [**IsHidden**](#function-ishidden) () <br> |
























## Protected Functions

| Type | Name |
| ---: | :--- |
|  void | [**updateView**](#function-updateview) () <br>_use this method at any moment regardless whether object visible in the moment or not_  |




## Public Functions Documentation




### function Draw 

_normally library users should not use this method. Managing the calls to this method is a responsibility of a container that element was put into. It's only for developers who enhance the library and build composite componets_ 
```C++
void BoxyBaseField::Draw (
    Coor aPos,
    Coor aSize,
    unsigned char aSelected
) 
```





**Parameters:**


* `aPos` upper left corner of a drawing area 
* `aSize` size of an area. {0,0} is aspecial value that means hide 




        

<hr>



### function IsHidden 

```C++
bool BoxyBaseField::IsHidden () 
```




<hr>
## Protected Functions Documentation




### function updateView 

_use this method at any moment regardless whether object visible in the moment or not_ 
```C++
void BoxyBaseField::updateView () 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `src/BoxyBaseField.h`

