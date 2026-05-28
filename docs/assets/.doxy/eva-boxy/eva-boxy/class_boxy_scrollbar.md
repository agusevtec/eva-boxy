

# Class BoxyScrollbar



[**ClassList**](annotated.md) **>** [**BoxyScrollbar**](class_boxy_scrollbar.md)








Inherits the following classes: [BoxyScrollbarField](class_boxy_scrollbar_field.md)






























































































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**BoxyScrollbar**](#function-boxyscrollbar) (unsigned aCount, IDelegate \* aOnPositionChanged) <br> |
| virtual bool | [**Key**](#function-key) (char aKey) override<br> |


## Public Functions inherited from BoxyScrollbarField

See [BoxyScrollbarField](class_boxy_scrollbar_field.md)

| Type | Name |
| ---: | :--- |
|   | [**BoxyScrollbarField**](class_boxy_scrollbar_field.md#function-boxyscrollbarfield) (unsigned aCount) <br> |
|  int | [**GetPosition**](class_boxy_scrollbar_field.md#function-getposition) () <br> |
|  void | [**SetPosition**](class_boxy_scrollbar_field.md#function-setposition) (int aPosition) <br> |


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




## Public Static Functions inherited from BoxyScrollbarField

See [BoxyScrollbarField](class_boxy_scrollbar_field.md)

| Type | Name |
| ---: | :--- |
|  void | [**IndeedDrawer**](class_boxy_scrollbar_field.md#function-indeeddrawer) ([**Coor**](struct_coor.md) aPos, [**Coor**](struct_coor.md) aSize, unsigned char aIsFocused, unsigned aPosition, unsigned aCount) <br> |




























































































## Protected Functions inherited from BoxyBaseField

See [BoxyBaseField](class_boxy_base_field.md)

| Type | Name |
| ---: | :--- |
|  void | [**updateView**](class_boxy_base_field.md#function-updateview) () <br>_use this method at any moment regardless whether object visible in the moment or not_  |










## Public Functions Documentation




### function BoxyScrollbar 

```C++
BoxyScrollbar::BoxyScrollbar (
    unsigned aCount,
    IDelegate * aOnPositionChanged
) 
```




<hr>



### function Key 

```C++
virtual bool BoxyScrollbar::Key (
    char aKey
) override
```



Implements [*BoxyBaseElement::Key*](class_boxy_base_element.md#function-key)


<hr>

------------------------------
The documentation for this class was generated from the following file `src/BoxyScrollbar.h`

