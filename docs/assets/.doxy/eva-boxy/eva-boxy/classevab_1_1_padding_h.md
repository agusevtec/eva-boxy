

# Class evab::PaddingH

**template &lt;class T&gt;**



[**ClassList**](annotated.md) **>** [**evab**](namespaceevab.md) **>** [**PaddingH**](classevab_1_1_padding_h.md)



_Decorator that adds horizontal padding (left and right) to any element._ [More...](#detailed-description)

* `#include <evabPadding.h>`



Inherits the following classes: T


































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**PaddingH**](#function-paddingh) (Args &&... args) <br>_Constructor forwarding all arguments to the base element._  |
























## Protected Functions

| Type | Name |
| ---: | :--- |
|  void | [**drawer**](#function-drawer) ([**Screen**](classevab_1_1_screen.md) \* aScreen, [**Coor**](structevab_1_1_coor.md) aPos, [**Coor**](structevab_1_1_coor.md) aSize, unsigned char aIsFocused) override<br>_Draws the element with horizontal padding._  |




## Detailed Description


This class wraps an element and adds empty space at the left and right, effectively centering the content horizontally within the available area.


The padding is applied as follows:
* Left: 1 tile cleared
* Content: drawn in the middle columns
* Right: 1 tile cleared






**Template parameters:**


* `T` Base element type to decorate



**Note:**

The element must be at least 3 tiles wide to have visible content. If the width is less than 3, the content may be clipped.




**See also:** [**PaddingV**](classevab_1_1_padding_v.md) For vertical padding (top and bottom)

```C++
// Add horizontal padding to an InputInt
PaddingH<InputInt> paddedInput(42);

// Use with Labeled decorator
PaddingH<LabeledLeft<InputInt>> paddedLabel("Value", 42);

// Combine vertical and horizontal padding (center element)
PaddingV<PaddingH<InputInt>> centeredInput(42);
```
 


    
## Public Functions Documentation




### function PaddingH 

_Constructor forwarding all arguments to the base element._ 
```C++
template<typename... Args>
inline evab::PaddingH::PaddingH (
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

_Draws the element with horizontal padding._ 
```C++
inline void evab::PaddingH::drawer (
    Screen * aScreen,
    Coor aPos,
    Coor aSize,
    unsigned char aIsFocused
) override
```



Clears one tile at the left and right, then draws the base element in the remaining horizontal space.




**Parameters:**


* `aScreen` [**Screen**](classevab_1_1_screen.md) to draw on 
* `aPos` Position on screen 
* `aSize` Size of the element 
* `aIsFocused` Focus state (1 = focused, 0 = not focused) 




        

<hr>

------------------------------
The documentation for this class was generated from the following file `src/evabPadding.h`

