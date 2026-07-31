

# Class evab::WindowAlgorithmBase



[**ClassList**](annotated.md) **>** [**evab**](namespaceevab.md) **>** [**WindowAlgorithmBase**](classevab_1_1_window_algorithm_base.md)



_Abstract base class for window navigation algorithms._ [More...](#detailed-description)

* `#include <evabWindowAlgorithms.h>`





Inherited by the following classes: [evab::FlipWindowAlgorithm](classevab_1_1_flip_window_algorithm.md),  [evab::ScrollWindowAlgorithm](classevab_1_1_scroll_window_algorithm.md)
































## Public Functions

| Type | Name |
| ---: | :--- |
|  unsigned char | [**Count**](#function-count) () <br>_Gets the total number of items._  |
| virtual void | [**Select**](#function-select) (unsigned char aIndex) = 0<br>_Pure virtual method to select an item._  |
|  signed short | [**Selected**](#function-selected) () <br>_Gets the currently selected item index._  |
|   | [**WindowAlgorithmBase**](#function-windowalgorithmbase) () <br>_Constructor for window algorithm base._  |
|  unsigned char | [**WindowSize**](#function-windowsize) () <br>_Gets the window size._  |








## Protected Attributes

| Type | Name |
| ---: | :--- |
|  unsigned char | [**mCount**](#variable-mcount)  <br>_Total number of items._  |
|  unsigned char | [**mSelected**](#variable-mselected)  <br>_Currently selected index._  |
|  unsigned char | [**mWindowSize**](#variable-mwindowsize)  <br>_Window size._  |
|  unsigned char | [**mWindowStart**](#variable-mwindowstart)  <br>_Start of the current window._  |
















## Protected Functions

| Type | Name |
| ---: | :--- |
|  signed char | [**indexInWindow**](#function-indexinwindow) (unsigned char aPosition) <br>_Calculates the visual index of an item in the current window._  |
|  void | [**resizeWindow**](#function-resizewindow) (unsigned char aWindowSize) <br>_Resizes the window._  |
|  void | [**setCount**](#function-setcount) (unsigned char Count) <br>_Sets the total number of items._  |




## Detailed Description


Provides common functionality for list box navigation strategies. 


    
## Public Functions Documentation




### function Count 

_Gets the total number of items._ 
```C++
unsigned char evab::WindowAlgorithmBase::Count () 
```





**Returns:**

Total number of items 





        

<hr>



### function Select 

_Pure virtual method to select an item._ 
```C++
virtual void evab::WindowAlgorithmBase::Select (
    unsigned char aIndex
) = 0
```





**Parameters:**


* `aIndex` Index to select 




        

<hr>



### function Selected 

_Gets the currently selected item index._ 
```C++
signed short evab::WindowAlgorithmBase::Selected () 
```





**Returns:**

Selected index, or -1 if empty 





        

<hr>



### function WindowAlgorithmBase 

_Constructor for window algorithm base._ 
```C++
evab::WindowAlgorithmBase::WindowAlgorithmBase () 
```




<hr>



### function WindowSize 

_Gets the window size._ 
```C++
unsigned char evab::WindowAlgorithmBase::WindowSize () 
```





**Returns:**

Window size 





        

<hr>
## Protected Attributes Documentation




### variable mCount 

_Total number of items._ 
```C++
unsigned char evab::WindowAlgorithmBase::mCount;
```




<hr>



### variable mSelected 

_Currently selected index._ 
```C++
unsigned char evab::WindowAlgorithmBase::mSelected;
```




<hr>



### variable mWindowSize 

_Window size._ 
```C++
unsigned char evab::WindowAlgorithmBase::mWindowSize;
```




<hr>



### variable mWindowStart 

_Start of the current window._ 
```C++
unsigned char evab::WindowAlgorithmBase::mWindowStart;
```




<hr>
## Protected Functions Documentation




### function indexInWindow 

_Calculates the visual index of an item in the current window._ 
```C++
signed char evab::WindowAlgorithmBase::indexInWindow (
    unsigned char aPosition
) 
```





**Parameters:**


* `aPosition` Absolute position of the item 



**Returns:**

Visual index, or -1 if not visible 





        

<hr>



### function resizeWindow 

_Resizes the window._ 
```C++
void evab::WindowAlgorithmBase::resizeWindow (
    unsigned char aWindowSize
) 
```





**Parameters:**


* `aWindowSize` New window size 




        

<hr>



### function setCount 

_Sets the total number of items._ 
```C++
void evab::WindowAlgorithmBase::setCount (
    unsigned char Count
) 
```





**Parameters:**


* `Count` Total number of items 




        

<hr>

------------------------------
The documentation for this class was generated from the following file `src/evabWindowAlgorithms.h`

