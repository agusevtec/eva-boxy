

# Class BoxyListBox



[**ClassList**](annotated.md) **>** [**BoxyListBox**](class_boxy_list_box.md)








Inherits the following classes: [BoxyBaseComposite](class_boxy_base_composite.md)






























































































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**BoxyListBox**](#function-boxylistbox) ([**BoxyBaseComposite**](class_boxy_base_composite.md) \* aParent, [**SlidingMethodBase**](class_sliding_method_base.md) \* aSlidingMethod) <br> |
|  int | [**Count**](#function-count) () <br> |
|  [**BoxyBaseField**](class_boxy_base_field.md) \* | [**GetItem**](#function-getitem) (unsigned char aIndex) <br> |
|  int | [**PageSize**](#function-pagesize) () <br> |
|  void | [**Select**](#function-select) (int mIndex) <br> |
|  int | [**Selected**](#function-selected) () <br> |
|  [**BoxyListBox**](class_boxy_list_box.md) & | [**SetGap**](#function-setgap) (unsigned char aGap) <br> |
|  [**BoxyListBox**](class_boxy_list_box.md) & | [**SetItems**](#function-setitems) ([**BoxyBaseField**](class_boxy_base_field.md) \* aItems, int aCount) <br> |
|  [**BoxyListBox**](class_boxy_list_box.md) & | [**SetOnItemModified**](#function-setonitemmodified) (IDelegate \* aOnItemModifyDelegate) <br> |
|  [**BoxyListBox**](class_boxy_list_box.md) & | [**SetReadOnly**](#function-setreadonly) (bool aIsReadonly) <br> |


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




### function BoxyListBox 

```C++
BoxyListBox::BoxyListBox (
    BoxyBaseComposite * aParent,
    SlidingMethodBase * aSlidingMethod
) 
```




<hr>



### function Count 

```C++
int BoxyListBox::Count () 
```




<hr>



### function GetItem 

```C++
BoxyBaseField * BoxyListBox::GetItem (
    unsigned char aIndex
) 
```




<hr>



### function PageSize 

```C++
int BoxyListBox::PageSize () 
```




<hr>



### function Select 

```C++
void BoxyListBox::Select (
    int mIndex
) 
```




<hr>



### function Selected 

```C++
int BoxyListBox::Selected () 
```




<hr>



### function SetGap 

```C++
BoxyListBox & BoxyListBox::SetGap (
    unsigned char aGap
) 
```




<hr>



### function SetItems 

```C++
BoxyListBox & BoxyListBox::SetItems (
    BoxyBaseField * aItems,
    int aCount
) 
```




<hr>



### function SetOnItemModified 

```C++
BoxyListBox & BoxyListBox::SetOnItemModified (
    IDelegate * aOnItemModifyDelegate
) 
```




<hr>



### function SetReadOnly 

```C++
BoxyListBox & BoxyListBox::SetReadOnly (
    bool aIsReadonly
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `src/BoxyListBox.h`

