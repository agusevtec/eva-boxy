

# Class evab::ListBox

**template &lt;class TWindowAlgorithm&gt;**



[**ClassList**](annotated.md) **>** [**evab**](namespaceevab.md) **>** [**ListBox**](classevab_1_1_list_box.md)



_List box element with configurable windowing algorithm._ [More...](#detailed-description)

* `#include <evabListBox.h>`



Inherits the following classes: [evab::ElementBase](classevab_1_1_element_base.md),  TWindowAlgorithm






















































## Public Functions

| Type | Name |
| ---: | :--- |
|  [**ElementBase**](classevab_1_1_element_base.md) \* | [**GetItem**](#function-getitem) (unsigned char aIndex) <br>_Gets an item by index._  |
|  void | [**Increment**](#function-increment) (signed char delta) <br>_Increments the selection by a delta._  |
| virtual bool | [**OnKey**](#function-onkey) (Keys aKey) override<br>_Handles key events, forwarding to selected item._  |
|  void | [**Select**](#function-select) (unsigned char aIndex) override<br>_Selects an item by index._  |
|  [**ListBox**](classevab_1_1_list_box.md)&lt; TWindowAlgorithm &gt; & | [**SetItemHeight**](#function-setitemheight) (unsigned char aItemHeight) <br>_Sets the height of each item._  |
|  [**ListBox**](classevab_1_1_list_box.md)&lt; TWindowAlgorithm &gt; & | [**SetItems**](#function-setitems) ([**ElementBase**](classevab_1_1_element_base.md) \* aItems, int aCount) <br>_Sets the list of items to display._  |


## Public Functions inherited from evab::ElementBase

See [evab::ElementBase](classevab_1_1_element_base.md)

| Type | Name |
| ---: | :--- |
|  void | [**Draw**](classevab_1_1_element_base.md#function-draw) ([**Screen**](classevab_1_1_screen.md) \* aScreen, [**Coor**](structevab_1_1_coor.md) aPos, [**Coor**](structevab_1_1_coor.md) aSize, unsigned char aIsFocused) <br>_Draws the element on the specified screen._  |
|  void | [**Freeze**](classevab_1_1_element_base.md#function-freeze) () <br>_Make element insensitive to redraw method._  |
| virtual bool | [**OnKey**](classevab_1_1_element_base.md#function-onkey) (Keys aKey) <br>_Handles key events for the element._  |














































## Protected Functions

| Type | Name |
| ---: | :--- |
| virtual void | [**drawer**](#function-drawer) ([**Screen**](classevab_1_1_screen.md) \* aScreen, [**Coor**](structevab_1_1_coor.md) aPos, [**Coor**](structevab_1_1_coor.md) aSize, unsigned char aIsFocused) override<br>_Draws the list box._  |
| virtual void | [**freezer**](#function-freezer) () override<br>_Hides all items._  |


## Protected Functions inherited from evab::ElementBase

See [evab::ElementBase](classevab_1_1_element_base.md)

| Type | Name |
| ---: | :--- |
| virtual void | [**drawer**](classevab_1_1_element_base.md#function-drawer) ([**Screen**](classevab_1_1_screen.md) \* aScreen, [**Coor**](structevab_1_1_coor.md) aPos, [**Coor**](structevab_1_1_coor.md) aSize, unsigned char aIsFocused) = 0<br>_Pure virtual method for drawing the element._  |
| virtual void | [**freezer**](classevab_1_1_element_base.md#function-freezer) () <br>_Virtual method for freezing the element._  |
|  bool | [**isFrozen**](classevab_1_1_element_base.md#function-isfrozen) () <br>_Checks if the element is currently freezed._  |
|  void | [**redraw**](classevab_1_1_element_base.md#function-redraw) () <br>_Redraws the element on the current screen._  |






## Detailed Description


Displays a scrollable list of items with navigation support.




**Template parameters:**


* `TWindowAlgorithm` Windowing algorithm for navigation (Flip/Scroll) 




    
## Public Functions Documentation




### function GetItem 

_Gets an item by index._ 
```C++
inline ElementBase * evab::ListBox::GetItem (
    unsigned char aIndex
) 
```





**Parameters:**


* `aIndex` Index of the item 



**Returns:**

Pointer to the item, or nullptr if invalid 





        

<hr>



### function Increment 

_Increments the selection by a delta._ 
```C++
inline void evab::ListBox::Increment (
    signed char delta
) 
```





**Parameters:**


* `delta` Amount to increment (positive or negative) 




        

<hr>



### function OnKey 

_Handles key events, forwarding to selected item._ 
```C++
inline virtual bool evab::ListBox::OnKey (
    Keys aKey
) override
```





**Parameters:**


* `aKey` Key code to process 



**Returns:**

true if the key was handled 





        
Implements [*evab::ElementBase::OnKey*](classevab_1_1_element_base.md#function-onkey)


<hr>



### function Select 

_Selects an item by index._ 
```C++
inline void evab::ListBox::Select (
    unsigned char aIndex
) override
```





**Parameters:**


* `aIndex` Index to select 




        

<hr>



### function SetItemHeight 

_Sets the height of each item._ 
```C++
inline ListBox < TWindowAlgorithm > & evab::ListBox::SetItemHeight (
    unsigned char aItemHeight
) 
```





**Parameters:**


* `aItemHeight` Height in tiles 



**Returns:**

Reference to this list box 





        

<hr>



### function SetItems 

_Sets the list of items to display._ 
```C++
inline ListBox < TWindowAlgorithm > & evab::ListBox::SetItems (
    ElementBase * aItems,
    int aCount
) 
```





**Parameters:**


* `aItems` Array of element pointers 
* `aCount` Number of items 



**Returns:**

Reference to this list box 





        

<hr>
## Protected Functions Documentation




### function drawer 

_Draws the list box._ 
```C++
inline virtual void evab::ListBox::drawer (
    Screen * aScreen,
    Coor aPos,
    Coor aSize,
    unsigned char aIsFocused
) override
```





**Parameters:**


* `aScreen` [**Screen**](classevab_1_1_screen.md) to draw on 
* `aPos` Position on screen 
* `aSize` Size of the element 
* `aIsFocused` Focus state (1 = focused, 0 = not focused) 




        
Implements [*evab::ElementBase::drawer*](classevab_1_1_element_base.md#function-drawer)


<hr>



### function freezer 

_Hides all items._ 
```C++
inline virtual void evab::ListBox::freezer () override
```



Implements [*evab::ElementBase::freezer*](classevab_1_1_element_base.md#function-freezer)


<hr>

------------------------------
The documentation for this class was generated from the following file `src/evabListBox.h`

