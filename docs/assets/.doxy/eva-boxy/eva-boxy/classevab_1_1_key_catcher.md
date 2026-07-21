

# Class evab::KeyCatcher

**template &lt;class T, Keys... KEYS&gt;**



[**ClassList**](annotated.md) **>** [**evab**](namespaceevab.md) **>** [**KeyCatcher**](classevab_1_1_key_catcher.md)



_Decorator that catches specified key events and forwards them to a listener._ [More...](#detailed-description)

* `#include <evabBehavior.h>`



Inherits the following classes: T














## Public Types

| Type | Name |
| ---: | :--- |
| enum  | [**EventType**](#enum-eventtype)  <br>_Event types for_ [_**KeyCatcher**_](classevab_1_1_key_catcher.md) _notifications._ |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  bool | [**Key**](#function-key) (Keys aKey) override<br>_Handles key events, catching specified keys._  |
|   | [**KeyCatcher**](#function-keycatcher) (eva::IHandler \* aListener, Args &&... args) <br>_Constructor for_ [_**KeyCatcher**_](classevab_1_1_key_catcher.md) _._ |




























## Detailed Description


This class wraps any element and intercepts key presses matching the specified keys. When a matching key is pressed, it invokes the listener with an event callback.




**Template parameters:**


* `T` Base element type to decorate 
* `KEYS` Key codes to catch (variadic template parameters) 




    
## Public Types Documentation




### enum EventType 

_Event types for_ [_**KeyCatcher**_](classevab_1_1_key_catcher.md) _notifications._
```C++
enum evab::KeyCatcher::EventType {
    EVENT_CATCH_KEY = 1
};
```




<hr>
## Public Functions Documentation




### function Key 

_Handles key events, catching specified keys._ 
```C++
inline bool evab::KeyCatcher::Key (
    Keys aKey
) override
```





**Parameters:**


* `aKey` The key code to process 



**Returns:**

true if the key was handled, false otherwise 





        

<hr>



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

------------------------------
The documentation for this class was generated from the following file `src/evabBehavior.h`

