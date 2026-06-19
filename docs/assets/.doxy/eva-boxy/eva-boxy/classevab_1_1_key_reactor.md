

# Class evab::KeyReactor

**template &lt;class T, unsigned char kDec, unsigned char kInc&gt;**



[**ClassList**](annotated.md) **>** [**evab**](namespaceevab.md) **>** [**KeyReactor**](classevab_1_1_key_reactor.md)








Inherits the following classes: T














## Public Types

| Type | Name |
| ---: | :--- |
| enum  | [**EventType**](#enum-eventtype)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  bool | [**Key**](#function-key) (Keys aKey) override<br> |
|   | [**KeyReactor**](#function-keyreactor) (eva::IHandler \* aListener, Args &&... args) <br> |




























## Public Types Documentation




### enum EventType 

```C++
enum evab::KeyReactor::EventType {
    EVENT_VALUE_CHANGED = 1
};
```




<hr>
## Public Functions Documentation




### function Key 

```C++
inline bool evab::KeyReactor::Key (
    Keys aKey
) override
```




<hr>



### function KeyReactor 

```C++
template<typename... Args>
inline evab::KeyReactor::KeyReactor (
    eva::IHandler * aListener,
    Args &&... args
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `src/evabBehavior.h`

