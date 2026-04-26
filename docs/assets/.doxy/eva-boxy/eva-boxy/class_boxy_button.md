

# Class BoxyButton



[**ClassList**](annotated.md) **>** [**BoxyButton**](class_boxy_button.md)








Inherits the following classes: [BoxyButtonListboxItem](class_boxy_button_listbox_item.md)






























































































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**BoxyButton**](#function-boxybutton) (const char \* aName, IDelegate \* aOnButtonPressedDelegate=0) <br> |
| virtual bool | [**Key**](#function-key) (char aKey) override<br> |


## Public Functions inherited from BoxyButtonListboxItem

See [BoxyButtonListboxItem](class_boxy_button_listbox_item.md)

| Type | Name |
| ---: | :--- |
|   | [**BoxyButtonListboxItem**](class_boxy_button_listbox_item.md#function-boxybuttonlistboxitem) (const char \* aName) <br> |


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




## Public Static Functions inherited from BoxyButtonListboxItem

See [BoxyButtonListboxItem](class_boxy_button_listbox_item.md)

| Type | Name |
| ---: | :--- |
|  void | [**IndeedDrawer**](class_boxy_button_listbox_item.md#function-indeeddrawer) ([**Coor**](struct_coor.md) aPos, [**Coor**](struct_coor.md) aSize, unsigned char aSelected, const char \* aName) <br> |




























































































## Protected Functions inherited from BoxyBaseField

See [BoxyBaseField](class_boxy_base_field.md)

| Type | Name |
| ---: | :--- |
|  void | [**updateView**](class_boxy_base_field.md#function-updateview) () <br>_use this method at any moment regardless whether object visible in the moment or not_  |










## Public Functions Documentation




### function BoxyButton 

```C++
BoxyButton::BoxyButton (
    const char * aName,
    IDelegate * aOnButtonPressedDelegate=0
) 
```




<hr>



### function Key 

```C++
virtual bool BoxyButton::Key (
    char aKey
) override
```



Implements [*BoxyBaseElement::Key*](class_boxy_base_element.md#function-key)


<hr>

------------------------------
The documentation for this class was generated from the following file `src/BoxyButton.h`

