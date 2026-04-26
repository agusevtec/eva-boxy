

# Class BoxyLayoutPane



[**ClassList**](annotated.md) **>** [**BoxyLayoutPane**](class_boxy_layout_pane.md)








Inherits the following classes: [BoxyBaseComposite](class_boxy_base_composite.md)






























































































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**BoxyLayoutPane**](#function-boxylayoutpane) ([**BoxyBaseComposite**](class_boxy_base_composite.md) \* aContainer) <br> |
|  void | [**SetItems**](#function-setitems) ([**BoxyLayoutPaneItem**](struct_boxy_layout_pane_item.md) aItems, int aCount) <br> |


## Public Functions inherited from BoxyBaseComposite

See [BoxyBaseComposite](class_boxy_base_composite.md)

| Type | Name |
| ---: | :--- |
|   | [**BoxyBaseComposite**](class_boxy_base_composite.md#function-boxybasecomposite) ([**BoxyBaseComposite**](class_boxy_base_composite.md) \* aParent=0) <br> |
|  bool | [**IsFocused**](class_boxy_base_composite.md#function-isfocused-12) ([**BoxyBaseElement**](class_boxy_base_element.md) \* aChild) <br> |
|  bool | [**IsFocused**](class_boxy_base_composite.md#function-isfocused-22) () <br> |
| virtual bool | [**Key**](class_boxy_base_composite.md#function-key) (char aKey) override<br> |


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




























































































## Protected Functions inherited from BoxyBaseComposite

See [BoxyBaseComposite](class_boxy_base_composite.md)

| Type | Name |
| ---: | :--- |
|  void | [**focusChild**](class_boxy_base_composite.md#function-focuschild) ([**BoxyBaseElement**](class_boxy_base_element.md) \* aChild) <br> |




## Protected Functions inherited from BoxyBaseField

See [BoxyBaseField](class_boxy_base_field.md)

| Type | Name |
| ---: | :--- |
|  void | [**updateView**](class_boxy_base_field.md#function-updateview) () <br>_use this method at any moment regardless whether object visible in the moment or not_  |










## Public Functions Documentation




### function BoxyLayoutPane 

```C++
BoxyLayoutPane::BoxyLayoutPane (
    BoxyBaseComposite * aContainer
) 
```




<hr>



### function SetItems 

```C++
void BoxyLayoutPane::SetItems (
    BoxyLayoutPaneItem aItems,
    int aCount
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `src/BoxyLayoutPane.h`

