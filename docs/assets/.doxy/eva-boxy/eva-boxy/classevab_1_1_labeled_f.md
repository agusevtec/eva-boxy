

# Class evab::LabeledF

**template &lt;class T&gt;**



[**ClassList**](annotated.md) **>** [**evab**](namespaceevab.md) **>** [**LabeledF**](classevab_1_1_labeled_f.md)



_Decorator that adds a Flash string label to any element._ [More...](#detailed-description)

* `#include <evabLabeled.h>`



Inherits the following classes: T


































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**LabeledF**](#function-labeledf) (const \_\_FlashStringHelper \* aName, Args &&... args) <br>_Constructor for_ [_**LabeledF**_](classevab_1_1_labeled_f.md) _with Flash string label._ |




























## Detailed Description


Wraps an element and adds a Flash string label either to the left (single line) or above (multi-line).




**Template parameters:**


* `T` Element type to label 




    
## Public Functions Documentation




### function LabeledF 

_Constructor for_ [_**LabeledF**_](classevab_1_1_labeled_f.md) _with Flash string label._
```C++
template<typename... Args>
inline evab::LabeledF::LabeledF (
    const __FlashStringHelper * aName,
    Args &&... args
) 
```





**Parameters:**


* `aName` Label text (Flash string, PROGMEM) 
* `args` Arguments forwarded to the base element constructor 




        

<hr>

------------------------------
The documentation for this class was generated from the following file `src/evabLabeled.h`

