

# Class evab::KeyCatcher

**template &lt;class T, Keys... KEYS&gt;**



[**ClassList**](annotated.md) **>** [**evab**](namespaceevab.md) **>** [**KeyCatcher**](classevab_1_1_key_catcher.md)



_Decorator that catches specified key events and forwards them to a listener._ [More...](#detailed-description)

* `#include <evabKeyCatcher.h>`



Inherits the following classes: T


































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**KeyCatcher**](#function-keycatcher) (eva::IHandler \* aListener, Args &&... args) <br>_Constructor for_ [_**KeyCatcher**_](classevab_1_1_key_catcher.md) _._ |
|  bool | [**OnKey**](#function-onkey) (Keys aKey) override<br>_Handles key events, catching specified keys._  |




























## Detailed Description


This class wraps any element and intercepts key presses matching the specified keys. When a matching key is pressed, it invokes the listener with an event callback.




**Template parameters:**


* `T` Base element type to decorate 
* `KEYS` OnKey codes to catch (variadic template parameters) 




    
## Public Functions Documentation




### function KeyCatcher 

_Constructor for_ [_**KeyCatcher**_](classevab_1_1_key_catcher.md) _._
```C++
template<typename... Args>
inline evab::KeyCatcher::KeyCatcher (
    eva::IHandler * aListener,
    Args &&... args
) 
```





**Parameters:**


* `aListener` Pointer to the event listener 
* `args` Arguments forwarded to the base element constructor 




        

<hr>



### function OnKey 

_Handles key events, catching specified keys._ 
```C++
inline bool evab::KeyCatcher::OnKey (
    Keys aKey
) override
```





**Parameters:**


* `aKey` The key code to process 



**Returns:**

true if the key was handled, false otherwise 





        

<hr>

------------------------------
The documentation for this class was generated from the following file `src/evabKeyCatcher.h`

