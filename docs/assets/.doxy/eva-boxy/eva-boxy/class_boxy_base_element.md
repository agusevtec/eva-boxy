

# Class BoxyBaseElement



[**ClassList**](annotated.md) **>** [**BoxyBaseElement**](class_boxy_base_element.md)



_Visual element with a behavior._ 

* `#include <BoxyBaseElement.h>`



Inherits the following classes: [BoxyBaseField](class_boxy_base_field.md)


Inherited by the following classes: [BoxyBaseComposite](class_boxy_base_composite.md),  [BoxyButtonListboxItem](class_boxy_button_listbox_item.md),  [BoxyInputFloatField](class_boxy_input_float_field.md),  [BoxyInputIntField](class_boxy_input_int_field.md),  [BoxyScrollbarField](class_boxy_scrollbar_field.md)




















































## Public Functions

| Type | Name |
| ---: | :--- |
| virtual bool | [**Key**](#function-key) (char aKey) <br> |


## Public Functions inherited from BoxyBaseField

See [BoxyBaseField](class_boxy_base_field.md)

| Type | Name |
| ---: | :--- |
|  void | [**Draw**](class_boxy_base_field.md#function-draw) ([**Coor**](struct_coor.md) aPos, [**Coor**](struct_coor.md) aSize, unsigned char aSelected) <br>_normally library users should not use this method. Managing the calls to this method is a responsibility of a container that element was put into. It's only for developers who enhance the library and build composite componets_  |
|  bool | [**IsHidden**](class_boxy_base_field.md#function-ishidden) () <br> |
















































## Protected Functions inherited from BoxyBaseField

See [BoxyBaseField](class_boxy_base_field.md)

| Type | Name |
| ---: | :--- |
|  void | [**updateView**](class_boxy_base_field.md#function-updateview) () <br>_use this method at any moment regardless whether object visible in the moment or not_  |






## Public Functions Documentation




### function Key 

```C++
virtual bool BoxyBaseElement::Key (
    char aKey
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `src/BoxyBaseElement.h`

