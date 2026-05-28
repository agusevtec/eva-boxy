

# Class BoxyButtonListboxItem



[**ClassList**](annotated.md) **>** [**BoxyButtonListboxItem**](class_boxy_button_listbox_item.md)








Inherits the following classes: [BoxyBaseElement](class_boxy_base_element.md)


Inherited by the following classes: [BoxyButton](class_boxy_button.md)








































































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**BoxyButtonListboxItem**](#function-boxybuttonlistboxitem) (const char \* aName) <br> |


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


## Public Static Functions

| Type | Name |
| ---: | :--- |
|  void | [**IndeedDrawer**](#function-indeeddrawer) ([**Coor**](struct_coor.md) aPos, [**Coor**](struct_coor.md) aSize, unsigned char aIsFocused, const char \* aName) <br> |






































































## Protected Functions inherited from BoxyBaseField

See [BoxyBaseField](class_boxy_base_field.md)

| Type | Name |
| ---: | :--- |
|  void | [**updateView**](class_boxy_base_field.md#function-updateview) () <br>_use this method at any moment regardless whether object visible in the moment or not_  |








## Public Functions Documentation




### function BoxyButtonListboxItem 

```C++
BoxyButtonListboxItem::BoxyButtonListboxItem (
    const char * aName
) 
```




<hr>
## Public Static Functions Documentation




### function IndeedDrawer 

```C++
static void BoxyButtonListboxItem::IndeedDrawer (
    Coor aPos,
    Coor aSize,
    unsigned char aIsFocused,
    const char * aName
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `src/BoxyButton.h`

