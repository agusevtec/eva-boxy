

# Class evab::CompositeBase



[**ClassList**](annotated.md) **>** [**evab**](namespaceevab.md) **>** [**CompositeBase**](classevab_1_1_composite_base.md)








Inherits the following classes: [evab::ElementBase](classevab_1_1_element_base.md)






















































## Public Functions

| Type | Name |
| ---: | :--- |
|  bool | [**IsFocused**](#function-isfocused) ([**ElementBase**](classevab_1_1_element_base.md) \* aChild) <br> |
| virtual void | [**hider**](#function-hider) () = 0<br> |
| virtual bool | [**onResidualKey**](#function-onresidualkey) (Keys aKey) <br> |


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
|  void | [**focusChild**](#function-focuschild) ([**ElementBase**](classevab_1_1_element_base.md) \* aChild) <br> |








## Public Functions Documentation




### function IsFocused 

```C++
bool evab::CompositeBase::IsFocused (
    ElementBase * aChild
) 
```




<hr>



### function hider 

```C++
virtual void evab::CompositeBase::hider () = 0
```



Implements [*evab::ElementBase::hider*](classevab_1_1_element_base.md#function-hider)


<hr>



### function onResidualKey 

```C++
virtual bool evab::CompositeBase::onResidualKey (
    Keys aKey
) 
```




<hr>
## Protected Functions Documentation




### function focusChild 

```C++
void evab::CompositeBase::focusChild (
    ElementBase * aChild
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `src/evabCompositeBase.h`

