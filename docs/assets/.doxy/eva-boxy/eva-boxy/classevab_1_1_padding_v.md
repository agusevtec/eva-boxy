

# Class evab::PaddingV

**template &lt;class T&gt;**



[**ClassList**](annotated.md) **>** [**evab**](namespaceevab.md) **>** [**PaddingV**](classevab_1_1_padding_v.md)



_Decorator that adds vertical padding (top and bottom) to any element._ [More...](#detailed-description)

* `#include <evabPadding.h>`



Inherits the following classes: T


































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**PaddingV**](#function-paddingv) (Args &&... args) <br>_Constructor forwarding all arguments to the base element._  |
























## Protected Functions

| Type | Name |
| ---: | :--- |
|  void | [**drawer**](#function-drawer) ([**Screen**](classevab_1_1_screen.md) \* aScreen, [**Coor**](structevab_1_1_coor.md) aPos, [**Coor**](structevab_1_1_coor.md) aSize, unsigned char aIsFocused) override<br>_Draws the element with vertical padding._  |




## Detailed Description


This class wraps an element and adds empty space at the top and bottom, effectively centering the content vertically within the available area.


The padding is applied as follows:
* Top: 1 tile cleared
* Content: drawn in the middle rows
* Bottom: 1 tile cleared






**Template parameters:**


* `T` Base element type to decorate



**Note:**

The element must be at least 3 tiles tall to have visible content. If the height is less than 3, the content may be clipped.




**See also:** [**PaddingH**](classevab_1_1_padding_h.md) For horizontal padding (left and right)

```C++
// Add vertical padding to an InputInt
PaddingV<InputInt> paddedInput(42);

// Use with Labeled decorator
PaddingV<LabeledLeft<InputInt>> paddedLabel("Value", 42);
```
 


    
## Public Functions Documentation




### function PaddingV 

_Constructor forwarding all arguments to the base element._ 
```C++
template<typename... Args>
inline evab::PaddingV::PaddingV (
    Args &&... args
) 
```





**Template parameters:**


* `Args` Types of the constructor arguments 



**Parameters:**


* `args` Arguments forwarded to the base element constructor 




        

<hr>
## Protected Functions Documentation




### function drawer 

_Draws the element with vertical padding._ 
```C++
inline void evab::PaddingV::drawer (
    Screen * aScreen,
    Coor aPos,
    Coor aSize,
    unsigned char aIsFocused
) override
```



Clears one tile at the top and bottom, then draws the base element in the remaining vertical space.




**Parameters:**


* `aScreen` [**Screen**](classevab_1_1_screen.md) to draw on 
* `aPos` Position on screen 
* `aSize` Size of the element 
* `aIsFocused` Focus state (1 = focused, 0 = not focused) 




        

<hr>

------------------------------
The documentation for this class was generated from the following file `src/evabPadding.h`

