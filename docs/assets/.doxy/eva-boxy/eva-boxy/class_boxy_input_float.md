

# Class BoxyInputFloat



[**ClassList**](annotated.md) **>** [**BoxyInputFloat**](class_boxy_input_float.md)








Inherits the following classes: [BoxyInputFloatField](class_boxy_input_float_field.md)






























































































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**BoxyInputFloat**](#function-boxyinputfloat) (const char \* aName, float aValue, IDelegate \* aOnValueChangedDelegate) <br> |
| virtual bool | [**Key**](#function-key) (char aKey) override<br> |


## Public Functions inherited from BoxyInputFloatField

See [BoxyInputFloatField](class_boxy_input_float_field.md)

| Type | Name |
| ---: | :--- |
|   | [**BoxyInputFloatField**](class_boxy_input_float_field.md#function-boxyinputfloatfield) (const char \* aName, float aValue) <br> |
|  float | [**GetValue**](class_boxy_input_float_field.md#function-getvalue) () <br> |
|  void | [**SetValue**](class_boxy_input_float_field.md#function-setvalue) (float aValue) <br> |


## Public Functions inherited from BoxyBaseElement

See [BoxyBaseElement](class_boxy_base_element.md)

| Type | Name |
| ---: | :--- |
| virtual bool | [**Key**](class_boxy_base_element.md#function-key) (char aKey) <br> |


## Public Functions inherited from BoxyBaseField

See [BoxyBaseField](class_boxy_base_field.md)

| Type | Name |
| ---: | :--- |
|  void | [**Draw**](class_boxy_base_field.md#function-draw) ([**Coor**](struct_coor.md) aPos, [**Coor**](struct_coor.md) aSize, unsigned char aIsFocused) <br>_normally library users should not use this method. Managing the calls to this method is a responsibility of a container that element was put into. It's only for developers who enhance the library and build composite componets_  |
|  bool | [**IsHidden**](class_boxy_base_field.md#function-ishidden) () <br> |




## Public Static Functions inherited from BoxyInputFloatField

See [BoxyInputFloatField](class_boxy_input_float_field.md)

| Type | Name |
| ---: | :--- |
|  void | [**IndeedDrawer**](class_boxy_input_float_field.md#function-indeeddrawer) ([**Coor**](struct_coor.md) aPos, [**Coor**](struct_coor.md) aSize, unsigned char aIsFocused, const char \* aName, float aValue) <br> |




























































































## Protected Functions inherited from BoxyBaseField

See [BoxyBaseField](class_boxy_base_field.md)

| Type | Name |
| ---: | :--- |
|  void | [**updateView**](class_boxy_base_field.md#function-updateview) () <br>_use this method at any moment regardless whether object visible in the moment or not_  |










## Public Functions Documentation




### function BoxyInputFloat 

```C++
BoxyInputFloat::BoxyInputFloat (
    const char * aName,
    float aValue,
    IDelegate * aOnValueChangedDelegate
) 
```




<hr>



### function Key 

```C++
virtual bool BoxyInputFloat::Key (
    char aKey
) override
```



Implements [*BoxyBaseElement::Key*](class_boxy_base_element.md#function-key)


<hr>

------------------------------
The documentation for this class was generated from the following file `src/BoxyInputFloat.h`

