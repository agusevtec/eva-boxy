

# Class evab::LayoutBase::FocusChain

**template &lt;class T&gt;**



[**ClassList**](annotated.md) **>** [**FocusChain**](classevab_1_1_layout_base_1_1_focus_chain.md)



_Wrapper that chains elements in a circular doubly-linked list._ [More...](#detailed-description)




Inherits the following classes: T,  [evab::IFocusChain](classevab_1_1_i_focus_chain.md)






















































## Public Functions

| Type | Name |
| ---: | :--- |
| virtual [**ElementBase**](classevab_1_1_element_base.md) \* | [**AsElementBase**](#function-aselementbase) () override<br> |
|   | [**FocusChain**](#function-focuschain) ([**LayoutBase**](classevab_1_1_layout_base.md) \* aParent, Args &&... args) <br> |
|  [**IFocusChain**](classevab_1_1_i_focus_chain.md) \* | [**Next**](#function-next) () override<br> |
| virtual void | [**SetNext**](#function-setnext) ([**IFocusChain**](classevab_1_1_i_focus_chain.md) \* aNext) override<br> |


## Public Functions inherited from evab::IFocusChain

See [evab::IFocusChain](classevab_1_1_i_focus_chain.md)

| Type | Name |
| ---: | :--- |
| virtual [**ElementBase**](classevab_1_1_element_base.md) \* | [**AsElementBase**](classevab_1_1_i_focus_chain.md#function-aselementbase) () = 0<br>_Sets the next element in the chain._  |
| virtual [**IFocusChain**](classevab_1_1_i_focus_chain.md) \* | [**Next**](classevab_1_1_i_focus_chain.md#function-next) () = 0<br>_Gets the next element in the chain._  |
| virtual void | [**SetNext**](classevab_1_1_i_focus_chain.md#function-setnext) ([**IFocusChain**](classevab_1_1_i_focus_chain.md) \* aNext) = 0<br> |






















































## Detailed Description




**Template parameters:**


* `T` Element type to wrap (must inherit [**ElementBase**](classevab_1_1_element_base.md)) 




    
## Public Functions Documentation




### function AsElementBase 

```C++
inline virtual ElementBase * FocusChain::AsElementBase () override
```




<hr>



### function FocusChain 

```C++
template<typename... Args>
inline FocusChain::FocusChain (
    LayoutBase * aParent,
    Args &&... args
) 
```




<hr>



### function Next 

```C++
inline IFocusChain * FocusChain::Next () override
```




<hr>



### function SetNext 

```C++
inline virtual void FocusChain::SetNext (
    IFocusChain * aNext
) override
```




<hr>

------------------------------
The documentation for this class was generated from the following file `src/evabLayoutBase.h`

