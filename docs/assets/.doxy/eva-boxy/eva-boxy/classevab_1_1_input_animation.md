

# Class evab::InputAnimation

**template &lt;class TPictoset, unsigned char tMaxSpeed&gt;**



[**ClassList**](annotated.md) **>** [**evab**](namespaceevab.md) **>** [**InputAnimation**](classevab_1_1_input_animation.md)



_Animation input element with configurable speed._ [More...](#detailed-description)

* `#include <evabInputAnimation.h>`



Inherits the following classes: [evab::ElementBase](classevab_1_1_element_base.md),  eva::Tickable






















































## Public Functions

| Type | Name |
| ---: | :--- |
|  unsigned char | [**GetValue**](#function-getvalue) () const<br>_Gets the current speed value._  |
|  unsigned char | [**GetValuePercent**](#function-getvaluepercent) () const<br>_Gets the current speed as percentage (0-100)._  |
|  void | [**Increment**](#function-increment) (signed char delta) <br>_Increments the speed value by a delta._  |
|   | [**InputAnimation**](#function-inputanimation) (unsigned char aValue=0) <br>_Constructor for_ [_**InputAnimation**_](classevab_1_1_input_animation.md) _._ |
|  void | [**SetValue**](#function-setvalue) (unsigned char aValue) <br>_Sets the animation speed._  |
|  void | [**SetValuePercent**](#function-setvaluepercent) (unsigned char aValue) <br>_Sets speed from percentage value._  |
| virtual  | [**~InputAnimation**](#function-inputanimation) () <br>_Destructor - removes from Tickable list._  |


## Public Functions inherited from evab::ElementBase

See [evab::ElementBase](classevab_1_1_element_base.md)

| Type | Name |
| ---: | :--- |
|  void | [**Draw**](classevab_1_1_element_base.md#function-draw) ([**IScreen**](classevab_1_1_i_screen.md) \* aScreen, [**Coor**](structevab_1_1_coor.md) aPos, [**Coor**](structevab_1_1_coor.md) aSize, unsigned char aIsFocused) <br>_Draws the element on the specified screen._  |
|  void | [**Hide**](classevab_1_1_element_base.md#function-hide) () <br>_Hides the element from view._  |
|  bool | [**IsHidden**](classevab_1_1_element_base.md#function-ishidden) () <br>_Checks if the element is hidden._  |
| virtual bool | [**Key**](classevab_1_1_element_base.md#function-key) (Keys aKey) <br>_Handles key events for the element._  |
|  void | [**Redraw**](classevab_1_1_element_base.md#function-redraw) () <br>_Redraws the element on the current screen._  |














































## Protected Functions

| Type | Name |
| ---: | :--- |
| virtual void | [**drawer**](#function-drawer) ([**IScreen**](classevab_1_1_i_screen.md) \* aScreen, [**Coor**](structevab_1_1_coor.md) aPos, [**Coor**](structevab_1_1_coor.md) aSize, unsigned char aIsFocused) override<br>_Draws the animation on screen._  |
| virtual void | [**hider**](#function-hider) () override<br>_Hides the element and pauses animation._  |








## Detailed Description


This element displays an animated pictogram where the animation speed can be adjusted by the user. The animation cycles through available pictograms at a speed determined by the current value.


The element uses the eva::Tickable system for periodic updates. The speed value ranges from 0 (stopped) to tMaxSpeed (maximum animation speed). Animation is automatically paused when the element is hidden and resumed when it becomes visible again.


Redraws occur only on timer ticks to maintain consistent animation timing.




**Template parameters:**


* `TPictoset` Pictoset class providing pictogram data and count 
* `tMaxSpeed` Maximum speed value (must be &gt; 0)



**See also:** [**InputPictogram**](classevab_1_1_input_pictogram.md) For static pictogram selection 


**See also:** eva::Tickable Base class for periodic updates 



    
## Public Functions Documentation




### function GetValue 

_Gets the current speed value._ 
```C++
inline unsigned char evab::InputAnimation::GetValue () const
```





**Returns:**

Current speed value (0 to tMaxSpeed) 





        

<hr>



### function GetValuePercent 

_Gets the current speed as percentage (0-100)._ 
```C++
inline unsigned char evab::InputAnimation::GetValuePercent () const
```





**Returns:**

Percentage value (0-100) 





        

<hr>



### function Increment 

_Increments the speed value by a delta._ 
```C++
inline void evab::InputAnimation::Increment (
    signed char delta
) 
```





**Parameters:**


* `delta` Amount to add (positive or negative) 




        

<hr>



### function InputAnimation 

_Constructor for_ [_**InputAnimation**_](classevab_1_1_input_animation.md) _._
```C++
inline evab::InputAnimation::InputAnimation (
    unsigned char aValue=0
) 
```





**Parameters:**


* `aValue` Initial speed value (0 to tMaxSpeed) 




        

<hr>



### function SetValue 

_Sets the animation speed._ 
```C++
inline void evab::InputAnimation::SetValue (
    unsigned char aValue
) 
```





**Parameters:**


* `aValue` Speed value (0 = stopped, 1..tMaxSpeed = animation speed) 




        

<hr>



### function SetValuePercent 

_Sets speed from percentage value._ 
```C++
inline void evab::InputAnimation::SetValuePercent (
    unsigned char aValue
) 
```





**Parameters:**


* `aValue` Percentage value (0-100) 




        

<hr>



### function ~InputAnimation 

_Destructor - removes from Tickable list._ 
```C++
inline virtual evab::InputAnimation::~InputAnimation () 
```




<hr>
## Protected Functions Documentation




### function drawer 

_Draws the animation on screen._ 
```C++
inline virtual void evab::InputAnimation::drawer (
    IScreen * aScreen,
    Coor aPos,
    Coor aSize,
    unsigned char aIsFocused
) override
```



Resumes animation if element is visible and speed &gt; 0.




**Parameters:**


* `aScreen` Screen to draw on 
* `aPos` Position on screen 
* `aSize` Size of the element 
* `aIsFocused` Focus state (1 = focused, 0 = not focused) 




        
Implements [*evab::ElementBase::drawer*](classevab_1_1_element_base.md#function-drawer)


<hr>



### function hider 

_Hides the element and pauses animation._ 
```C++
inline virtual void evab::InputAnimation::hider () override
```



Implements [*evab::ElementBase::hider*](classevab_1_1_element_base.md#function-hider)


<hr>

------------------------------
The documentation for this class was generated from the following file `src/evabInputAnimation.h`

