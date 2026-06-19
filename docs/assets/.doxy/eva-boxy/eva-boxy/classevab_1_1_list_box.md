

# Class evab::ListBox

**template &lt;class TWindowAlgorithm&gt;**



[**ClassList**](annotated.md) **>** [**evab**](namespaceevab.md) **>** [**ListBox**](classevab_1_1_list_box.md)








Inherits the following classes: [evab::ElementBase](classevab_1_1_element_base.md),  TWindowAlgorithm






















































## Public Functions

| Type | Name |
| ---: | :--- |
|  [**ElementBase**](classevab_1_1_element_base.md) \* | [**GetItem**](#function-getitem) (unsigned char aIndex) <br> |
|  void | [**Increment**](#function-increment) (signed char delta) <br> |
| virtual bool | [**Key**](#function-key) (Keys aKey) override<br> |
|  void | [**Select**](#function-select) (signed char aIndex) override<br> |
|  [**ListBox**](classevab_1_1_list_box.md)&lt; TWindowAlgorithm &gt; & | [**SetItemHeight**](#function-setitemheight) (unsigned char aItemHeight) <br> |
|  [**ListBox**](classevab_1_1_list_box.md)&lt; TWindowAlgorithm &gt; & | [**SetItems**](#function-setitems) ([**ElementBase**](classevab_1_1_element_base.md) \* aItems, int aCount) <br> |


## Public Functions inherited from evab::ElementBase

See [evab::ElementBase](classevab_1_1_element_base.md)

| Type | Name |
| ---: | :--- |
|  void | [**Draw**](classevab_1_1_element_base.md#function-draw) ([**IScreen**](classevab_1_1_i_screen.md) \* aScreen, [**Coor**](structevab_1_1_coor.md) aPos, [**Coor**](structevab_1_1_coor.md) aSize, unsigned char aIsFocused) <br> |
|  void | [**Hide**](classevab_1_1_element_base.md#function-hide) () <br> |
|  bool | [**IsHidden**](classevab_1_1_element_base.md#function-ishidden) () <br> |
| virtual bool | [**Key**](classevab_1_1_element_base.md#function-key) (Keys aKey) <br> |
|  void | [**Redraw**](classevab_1_1_element_base.md#function-redraw) () <br> |














































## Protected Functions

| Type | Name |
| ---: | :--- |
| virtual void | [**drawer**](#function-drawer) ([**IScreen**](classevab_1_1_i_screen.md) \* aScreen, [**Coor**](structevab_1_1_coor.md) aPos, [**Coor**](structevab_1_1_coor.md) aSize, unsigned char aIsFocused) override<br> |
| virtual void | [**hider**](#function-hider) () override<br> |








## Public Functions Documentation




### function GetItem 

```C++
inline ElementBase * evab::ListBox::GetItem (
    unsigned char aIndex
) 
```




<hr>



### function Increment 

```C++
inline void evab::ListBox::Increment (
    signed char delta
) 
```




<hr>



### function Key 

```C++
inline virtual bool evab::ListBox::Key (
    Keys aKey
) override
```



Implements [*evab::ElementBase::Key*](classevab_1_1_element_base.md#function-key)


<hr>



### function Select 

```C++
inline void evab::ListBox::Select (
    signed char aIndex
) override
```




<hr>



### function SetItemHeight 

```C++
inline ListBox < TWindowAlgorithm > & evab::ListBox::SetItemHeight (
    unsigned char aItemHeight
) 
```




<hr>



### function SetItems 

```C++
inline ListBox < TWindowAlgorithm > & evab::ListBox::SetItems (
    ElementBase * aItems,
    int aCount
) 
```




<hr>
## Protected Functions Documentation




### function drawer 

```C++
inline virtual void evab::ListBox::drawer (
    IScreen * aScreen,
    Coor aPos,
    Coor aSize,
    unsigned char aIsFocused
) override
```



Implements [*evab::ElementBase::drawer*](classevab_1_1_element_base.md#function-drawer)


<hr>



### function hider 

```C++
inline virtual void evab::ListBox::hider () override
```



Implements [*evab::ElementBase::hider*](classevab_1_1_element_base.md#function-hider)


<hr>

------------------------------
The documentation for this class was generated from the following file `src/evabListBox.h`

