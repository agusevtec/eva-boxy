

# Class evab::IFocusChain



[**ClassList**](annotated.md) **>** [**evab**](namespaceevab.md) **>** [**IFocusChain**](classevab_1_1_i_focus_chain.md)










































## Public Functions

| Type | Name |
| ---: | :--- |
| virtual [**ElementBase**](classevab_1_1_element_base.md) \* | [**AsElementBase**](#function-aselementbase) () = 0<br>_Sets the next element in the chain._  |
| virtual [**IFocusChain**](classevab_1_1_i_focus_chain.md) \* | [**Next**](#function-next) () = 0<br>_Gets the next element in the chain._  |
| virtual void | [**SetNext**](#function-setnext) ([**IFocusChain**](classevab_1_1_i_focus_chain.md) \* aNext) = 0<br> |




























## Public Functions Documentation




### function AsElementBase 

_Sets the next element in the chain._ 
```C++
virtual ElementBase * evab::IFocusChain::AsElementBase () = 0
```





**Parameters:**


* `aNext` Pointer to next element 




        

<hr>



### function Next 

_Gets the next element in the chain._ 
```C++
virtual IFocusChain * evab::IFocusChain::Next () = 0
```





**Returns:**

Pointer to next element, or nullptr if none 





        

<hr>



### function SetNext 

```C++
virtual void evab::IFocusChain::SetNext (
    IFocusChain * aNext
) = 0
```




<hr>

------------------------------
The documentation for this class was generated from the following file `src/evabLayoutBase.h`

