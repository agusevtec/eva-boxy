

# Class evab::Boxy



[**ClassList**](annotated.md) **>** [**evab**](namespaceevab.md) **>** [**Boxy**](classevab_1_1_boxy.md)



_Main application controller managing screen, input, and modal overlays._ [More...](#detailed-description)

* `#include <evabBoxy.h>`



Inherits the following classes: eva::IHandler




































## Public Static Functions

| Type | Name |
| ---: | :--- |
|  void | [**Begin**](#function-begin) ([**ElementBase**](classevab_1_1_element_base.md) \* aGround, Args &&... args) <br>_Initializes the_ [_**Boxy**_](classevab_1_1_boxy.md) _system with a screen and ground element._ |
|  [**Screen**](classevab_1_1_screen.md) \* | [**GetScreen**](#function-getscreen) () <br>_Gets the current screen pointer._  |
|  [**Boxy**](classevab_1_1_boxy.md) \* | [**Instance**](#function-instance) () <br>_Gets the singleton instance._  |
|  void | [**Key**](#function-key) (Keys aKey) <br>_Forwards key events to the ground element._  |
|  void | [**Message**](#function-message) (const \_\_FlashStringHelper \*, const char \* aText) <br>_Displays a temporary modal with a named integer value._  |


























## Detailed Description


[**Boxy**](classevab_1_1_boxy.md) is a singleton that provides global access to the display system, manages the current screen, and handles modal popups. 


    
## Public Static Functions Documentation




### function Begin 

_Initializes the_ [_**Boxy**_](classevab_1_1_boxy.md) _system with a screen and ground element._
```C++
template<class TScreen, class TFont, typename... Args>
static inline void evab::Boxy::Begin (
    ElementBase * aGround,
    Args &&... args
) 
```





**Template parameters:**


* `TScreen` [**Screen**](classevab_1_1_screen.md) type to use 
* `TFont` Font type to use 
* `Args` Additional arguments for screen constructor 



**Parameters:**


* `aGround` Base element to display 
* `args` Arguments forwarded to screen constructor 




        

<hr>



### function GetScreen 

_Gets the current screen pointer._ 
```C++
static Screen * evab::Boxy::GetScreen () 
```





**Returns:**

Pointer to current screen, or nullptr if modal is active 





        

<hr>



### function Instance 

_Gets the singleton instance._ 
```C++
static Boxy * evab::Boxy::Instance () 
```





**Returns:**

Pointer to the [**Boxy**](classevab_1_1_boxy.md) singleton 





        

<hr>



### function Key 

_Forwards key events to the ground element._ 
```C++
static void evab::Boxy::Key (
    Keys aKey
) 
```





**Parameters:**


* `aKey` Key code to process 




        

<hr>



### function Message 

_Displays a temporary modal with a named integer value._ 
```C++
static void evab::Boxy::Message (
    const __FlashStringHelper *,
    const char * aText
) 
```





**Parameters:**


* `aName` Label text 
* `aValue` Integer value to show 




        

<hr>

------------------------------
The documentation for this class was generated from the following file `src/evabBoxy.h`

