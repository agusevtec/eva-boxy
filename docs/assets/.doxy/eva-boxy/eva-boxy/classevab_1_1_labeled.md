

# Class evab::Labeled

**template &lt;class T&gt;**



[**ClassList**](annotated.md) **>** [**evab**](namespaceevab.md) **>** [**Labeled**](classevab_1_1_labeled.md)



_Decorator that adds a label to any element._ [More...](#detailed-description)

* `#include <evabLabeled.h>`



Inherits the following classes: T


































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**Labeled**](#function-labeled) (const char \* aName, Args &&... args) <br>_Constructor for_ [_**Labeled**_](classevab_1_1_labeled.md) _with C-string label._ |




























## Detailed Description


Wraps an element and adds a text label either to the left (single line) or above (multi-line).




**Template parameters:**


* `T` Element type to label 




    
## Public Functions Documentation




### function Labeled 

_Constructor for_ [_**Labeled**_](classevab_1_1_labeled.md) _with C-string label._
```C++
template<typename... Args>
inline evab::Labeled::Labeled (
    const char * aName,
    Args &&... args
) 
```





**Parameters:**


* `aName` Label text (C-string) 
* `args` Arguments forwarded to the base element constructor 




        

<hr>

------------------------------
The documentation for this class was generated from the following file `src/evabLabeled.h`

