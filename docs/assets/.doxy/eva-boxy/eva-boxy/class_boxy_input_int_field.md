

# Class BoxyInputIntField



[**ClassList**](annotated.md) **>** [**BoxyInputIntField**](class_boxy_input_int_field.md)








Inherits the following classes: [BoxyBaseElement](class_boxy_base_element.md)


Inherited by the following classes: [BoxyInputInt](class_boxy_input_int.md)








































































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**BoxyInputIntField**](#function-boxyinputintfield) (const char \* aName, int aValue) <br> |
|  int | [**GetValue**](#function-getvalue) () <br> |
|  void | [**SetValue**](#function-setvalue) (int aValue) <br> |


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
|  void | [**IndeedDrawer**](#function-indeeddrawer) ([**Coor**](struct_coor.md) aPos, [**Coor**](struct_coor.md) aSize, unsigned char aSelected, const char \* aName, int aValue) <br> |






































































## Protected Functions inherited from BoxyBaseField

See [BoxyBaseField](class_boxy_base_field.md)

| Type | Name |
| ---: | :--- |
|  void | [**updateView**](class_boxy_base_field.md#function-updateview) () <br>_use this method at any moment regardless whether object visible in the moment or not_  |








## Public Functions Documentation




### function BoxyInputIntField 

```C++
BoxyInputIntField::BoxyInputIntField (
    const char * aName,
    int aValue
) 
```




<hr>



### function GetValue 

```C++
int BoxyInputIntField::GetValue () 
```




<hr>



### function SetValue 

```C++
void BoxyInputIntField::SetValue (
    int aValue
) 
```




<hr>
## Public Static Functions Documentation




### function IndeedDrawer 

```C++
static void BoxyInputIntField::IndeedDrawer (
    Coor aPos,
    Coor aSize,
    unsigned char aSelected,
    const char * aName,
    int aValue
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `src/BoxyInputInt.h`

