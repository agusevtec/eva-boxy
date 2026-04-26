

# Class BoxyInputFloatField



[**ClassList**](annotated.md) **>** [**BoxyInputFloatField**](class_boxy_input_float_field.md)








Inherits the following classes: [BoxyBaseElement](class_boxy_base_element.md)


Inherited by the following classes: [BoxyInputFloat](class_boxy_input_float.md)








































































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**BoxyInputFloatField**](#function-boxyinputfloatfield) (const char \* aName, float aValue) <br> |
|  float | [**GetValue**](#function-getvalue) () <br> |
|  void | [**SetValue**](#function-setvalue) (float aValue) <br> |


## Public Functions inherited from BoxyBaseElement

See [BoxyBaseElement](class_boxy_base_element.md)

| Type | Name |
| ---: | :--- |
| virtual bool | [**Key**](class_boxy_base_element.md#function-key) (char aKey) <br> |


## Public Functions inherited from BoxyBaseField

See [BoxyBaseField](class_boxy_base_field.md)

| Type | Name |
| ---: | :--- |
|  void | [**Draw**](class_boxy_base_field.md#function-draw) ([**Coor**](struct_coor.md) aPos, [**Coor**](struct_coor.md) aSize, unsigned char aSelected) <br>_normally library users should not use this method. Managing the calls to this method is a responsibility of a container that element was put into. It's only for developers who enhance the library and build composite componets_  |
|  bool | [**IsHidden**](class_boxy_base_field.md#function-ishidden) () <br> |


## Public Static Functions

| Type | Name |
| ---: | :--- |
|  void | [**IndeedDrawer**](#function-indeeddrawer) ([**Coor**](struct_coor.md) aPos, [**Coor**](struct_coor.md) aSize, unsigned char aSelected, const char \* aName, float aValue) <br> |






































































## Protected Functions inherited from BoxyBaseField

See [BoxyBaseField](class_boxy_base_field.md)

| Type | Name |
| ---: | :--- |
|  void | [**updateView**](class_boxy_base_field.md#function-updateview) () <br>_use this method at any moment regardless whether object visible in the moment or not_  |








## Public Functions Documentation




### function BoxyInputFloatField 

```C++
BoxyInputFloatField::BoxyInputFloatField (
    const char * aName,
    float aValue
) 
```




<hr>



### function GetValue 

```C++
float BoxyInputFloatField::GetValue () 
```




<hr>



### function SetValue 

```C++
void BoxyInputFloatField::SetValue (
    float aValue
) 
```




<hr>
## Public Static Functions Documentation




### function IndeedDrawer 

```C++
static void BoxyInputFloatField::IndeedDrawer (
    Coor aPos,
    Coor aSize,
    unsigned char aSelected,
    const char * aName,
    float aValue
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `src/BoxyInputFloat.h`

