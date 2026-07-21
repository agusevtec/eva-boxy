

# Class evab::KeyModifier

**template &lt;class T, unsigned char kDec, unsigned char kInc&gt;**



[**ClassList**](annotated.md) **>** [**evab**](namespaceevab.md) **>** [**KeyModifier**](classevab_1_1_key_modifier.md)



_Decorator that modifies values using increment/decrement keys._ [More...](#detailed-description)

* `#include <evabBehavior.h>`



Inherits the following classes: T


































## Public Functions

| Type | Name |
| ---: | :--- |
|  bool | [**Key**](#function-key) (Keys aKey) override<br>_Handles key events for increment/decrement._  |
|   | [**KeyModifier**](#function-keymodifier) (Args &&... args) <br>_Constructor for_ [_**KeyModifier**_](classevab_1_1_key_modifier.md) _._ |




























## Detailed Description


This class wraps any element and adds behavior for increment and decrement keys. It calls the underlying element's Increment() method with +/- 1.




**Template parameters:**


* `T` Base element type (must have Increment(signed char) method) 
* `kDec` Key code for decrement 
* `kInc` Key code for increment 




    
## Public Functions Documentation




### function Key 

_Handles key events for increment/decrement._ 
```C++
inline bool evab::KeyModifier::Key (
    Keys aKey
) override
```





**Parameters:**


* `aKey` The key code to process 



**Returns:**

true if the key was handled, false otherwise 





        

<hr>



### function KeyModifier 

_Constructor for_ [_**KeyModifier**_](classevab_1_1_key_modifier.md) _._
```C++
template<typename... Args>
inline evab::KeyModifier::KeyModifier (
    Args &&... args
) 
```





**Parameters:**


* `args` Arguments forwarded to the base element constructor 




        

<hr>

------------------------------
The documentation for this class was generated from the following file `src/evabBehavior.h`

