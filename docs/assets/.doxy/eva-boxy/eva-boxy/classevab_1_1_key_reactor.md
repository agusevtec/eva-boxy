

# Class evab::KeyReactor

**template &lt;class T, unsigned char kDec, unsigned char kInc&gt;**



[**ClassList**](annotated.md) **>** [**evab**](namespaceevab.md) **>** [**KeyReactor**](classevab_1_1_key_reactor.md)



_Decorator that triggers events when values change via increment/decrement._ [More...](#detailed-description)

* `#include <evabKeyReactor.h>`



Inherits the following classes: T














## Public Types

| Type | Name |
| ---: | :--- |
| enum  | [**EventType**](#enum-eventtype)  <br>_Event types for_ [_**KeyReactor**_](classevab_1_1_key_reactor.md) _notifications._ |




















## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**KeyReactor**](#function-keyreactor) (eva::IHandler \* aListener, Args &&... args) <br>_Constructor for_ [_**KeyReactor**_](classevab_1_1_key_reactor.md) _._ |
|  bool | [**OnKey**](#function-onkey) (Keys aKey) override<br>_Handles key events, triggers event on value change._  |




























## Detailed Description


Similar to [**KeyModifier**](classevab_1_1_key_modifier.md) but additionally sends event notifications when the value changes through increment/decrement operations.




**Template parameters:**


* `T` Base element type (must have Increment(signed char) and Selected() methods) 
* `kDec` Key code for decrement 
* `kInc` Key code for increment 




    
## Public Types Documentation




### enum EventType 

_Event types for_ [_**KeyReactor**_](classevab_1_1_key_reactor.md) _notifications._
```C++
enum evab::KeyReactor::EventType {
    EVENT_VALUE_CHANGED = 2
};
```




<hr>
## Public Functions Documentation




### function KeyReactor 

_Constructor for_ [_**KeyReactor**_](classevab_1_1_key_reactor.md) _._
```C++
template<typename... Args>
inline evab::KeyReactor::KeyReactor (
    eva::IHandler * aListener,
    Args &&... args
) 
```





**Parameters:**


* `aListener` Pointer to the event listener 
* `args` Arguments forwarded to the base element constructor 




        

<hr>



### function OnKey 

_Handles key events, triggers event on value change._ 
```C++
inline bool evab::KeyReactor::OnKey (
    Keys aKey
) override
```





**Parameters:**


* `aKey` The key code to process 



**Returns:**

true if the key was handled, false otherwise 





        

<hr>

------------------------------
The documentation for this class was generated from the following file `src/evabKeyReactor.h`

