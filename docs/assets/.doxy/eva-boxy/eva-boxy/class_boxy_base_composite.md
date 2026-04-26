

# Class BoxyBaseComposite



[**ClassList**](annotated.md) **>** [**BoxyBaseComposite**](class_boxy_base_composite.md)








Inherits the following classes: [BoxyBaseElement](class_boxy_base_element.md)


Inherited by the following classes: [BoxyLayoutPane](class_boxy_layout_pane.md),  [BoxyListBox](class_boxy_list_box.md)








































































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**BoxyBaseComposite**](#function-boxybasecomposite) ([**BoxyBaseComposite**](class_boxy_base_composite.md) \* aParent=0) <br> |
|  bool | [**IsFocused**](#function-isfocused-12) ([**BoxyBaseElement**](class_boxy_base_element.md) \* aChild) <br> |
|  bool | [**IsFocused**](#function-isfocused-22) () <br> |
| virtual bool | [**Key**](#function-key) (char aKey) override<br> |


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




































































## Protected Functions

| Type | Name |
| ---: | :--- |
|  void | [**focusChild**](#function-focuschild) ([**BoxyBaseElement**](class_boxy_base_element.md) \* aChild) <br> |




## Protected Functions inherited from BoxyBaseField

See [BoxyBaseField](class_boxy_base_field.md)

| Type | Name |
| ---: | :--- |
|  void | [**updateView**](class_boxy_base_field.md#function-updateview) () <br>_use this method at any moment regardless whether object visible in the moment or not_  |








## Public Functions Documentation




### function BoxyBaseComposite 

```C++
BoxyBaseComposite::BoxyBaseComposite (
    BoxyBaseComposite * aParent=0
) 
```




<hr>



### function IsFocused [1/2]

```C++
bool BoxyBaseComposite::IsFocused (
    BoxyBaseElement * aChild
) 
```




<hr>



### function IsFocused [2/2]

```C++
bool BoxyBaseComposite::IsFocused () 
```




<hr>



### function Key 

```C++
virtual bool BoxyBaseComposite::Key (
    char aKey
) override
```



Implements [*BoxyBaseElement::Key*](class_boxy_base_element.md#function-key)


<hr>
## Protected Functions Documentation




### function focusChild 

```C++
void BoxyBaseComposite::focusChild (
    BoxyBaseElement * aChild
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `src/BoxyBaseComposite.h`

