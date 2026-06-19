

# Class evab::Boxy



[**ClassList**](annotated.md) **>** [**evab**](namespaceevab.md) **>** [**Boxy**](classevab_1_1_boxy.md)








Inherits the following classes: eva::IHandler




































## Public Static Functions

| Type | Name |
| ---: | :--- |
|  void | [**Begin**](#function-begin) ([**ElementBase**](classevab_1_1_element_base.md) \* aGround, Args &&... args) <br> |
|  [**Boxy**](classevab_1_1_boxy.md) \* | [**Instance**](#function-instance) () <br> |
|  void | [**Key**](#function-key) (Keys aKey) <br> |
|  [**IScreen**](classevab_1_1_i_screen.md) \* | [**Screen**](#function-screen) () <br> |
|  void | [**ShowInt**](#function-showint) (const char \* aName, int aValue) <br> |


























## Public Static Functions Documentation




### function Begin 

```C++
template<class TScreen, class TFont, typename... Args>
static inline void evab::Boxy::Begin (
    ElementBase * aGround,
    Args &&... args
) 
```




<hr>



### function Instance 

```C++
static Boxy * evab::Boxy::Instance () 
```




<hr>



### function Key 

```C++
static void evab::Boxy::Key (
    Keys aKey
) 
```




<hr>



### function Screen 

```C++
static IScreen * evab::Boxy::Screen () 
```




<hr>



### function ShowInt 

```C++
static void evab::Boxy::ShowInt (
    const char * aName,
    int aValue
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `src/evabBoxy.h`

