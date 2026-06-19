

# Class evab::KeyCatcher

**template &lt;class T, Keys... KEYS&gt;**



[**ClassList**](annotated.md) **>** [**evab**](namespaceevab.md) **>** [**KeyCatcher**](classevab_1_1_key_catcher.md)








Inherits the following classes: T














## Public Types

| Type | Name |
| ---: | :--- |
| enum  | [**EventType**](#enum-eventtype)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  bool | [**Key**](#function-key) (Keys aKey) override<br> |
|   | [**KeyCatcher**](#function-keycatcher) (eva::IHandler \* aListener, Args &&... args) <br> |




























## Public Types Documentation




### enum EventType 

```C++
enum evab::KeyCatcher::EventType {
    EVENT_CATCH_KEY = 1
};
```




<hr>
## Public Functions Documentation




### function Key 

```C++
inline bool evab::KeyCatcher::Key (
    Keys aKey
) override
```




<hr>



### function KeyCatcher 

```C++
template<typename... Args>
inline evab::KeyCatcher::KeyCatcher (
    eva::IHandler * aListener,
    Args &&... args
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `src/evabBehavior.h`

