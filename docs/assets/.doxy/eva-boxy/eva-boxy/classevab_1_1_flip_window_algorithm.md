

# Class evab::FlipWindowAlgorithm



[**ClassList**](annotated.md) **>** [**evab**](namespaceevab.md) **>** [**FlipWindowAlgorithm**](classevab_1_1_flip_window_algorithm.md)



_Flip-page navigation algorithm._ [More...](#detailed-description)

* `#include <evabWindowAlgorithms.h>`



Inherits the following classes: [evab::WindowAlgorithmBase](classevab_1_1_window_algorithm_base.md)


Inherited by the following classes: [evab::ListBox](classevab_1_1_list_box.md)




















































## Public Functions

| Type | Name |
| ---: | :--- |
| virtual void | [**Select**](#function-select) (unsigned char aIndex) override<br>_Selects an item using flip-page navigation._  |
|   | [**WindowAlgorithmBase**](#function-windowalgorithmbase) (unsigned char aCount=0) <br>_Constructor for window algorithm base._  |


## Public Functions inherited from evab::WindowAlgorithmBase

See [evab::WindowAlgorithmBase](classevab_1_1_window_algorithm_base.md)

| Type | Name |
| ---: | :--- |
|  unsigned char | [**Count**](classevab_1_1_window_algorithm_base.md#function-count) () <br>_Gets the total number of items._  |
| virtual void | [**Select**](classevab_1_1_window_algorithm_base.md#function-select) (unsigned char aIndex) = 0<br>_Pure virtual method to select an item._  |
|  signed short | [**Selected**](classevab_1_1_window_algorithm_base.md#function-selected) () <br>_Gets the currently selected item index._  |
|   | [**WindowAlgorithmBase**](classevab_1_1_window_algorithm_base.md#function-windowalgorithmbase) (unsigned char aCount=0) <br>_Constructor for window algorithm base._  |
|  unsigned char | [**WindowSize**](classevab_1_1_window_algorithm_base.md#function-windowsize) () <br>_Gets the window size._  |
















## Protected Attributes inherited from evab::WindowAlgorithmBase

See [evab::WindowAlgorithmBase](classevab_1_1_window_algorithm_base.md)

| Type | Name |
| ---: | :--- |
|  unsigned char | [**mCount**](classevab_1_1_window_algorithm_base.md#variable-mcount)  <br>_Total number of items._  |
|  unsigned char | [**mSelected**](classevab_1_1_window_algorithm_base.md#variable-mselected)  <br>_Currently selected index._  |
|  unsigned char | [**mWindowSize**](classevab_1_1_window_algorithm_base.md#variable-mwindowsize)  <br>_Window size._  |
|  unsigned char | [**mWindowStart**](classevab_1_1_window_algorithm_base.md#variable-mwindowstart)  <br>_Start of the current window._  |
































## Protected Functions inherited from evab::WindowAlgorithmBase

See [evab::WindowAlgorithmBase](classevab_1_1_window_algorithm_base.md)

| Type | Name |
| ---: | :--- |
|  signed char | [**indexInWindow**](classevab_1_1_window_algorithm_base.md#function-indexinwindow) (unsigned char aPosition) <br>_Calculates the visual index of an item in the current window._  |
|  void | [**setCount**](classevab_1_1_window_algorithm_base.md#function-setcount) (unsigned char aCount) <br>_Sets the total number of items._  |
|  void | [**setWindowSize**](classevab_1_1_window_algorithm_base.md#function-setwindowsize) (unsigned char aWindowSize) <br>_Resizes the window._  |






## Detailed Description


Pages are flipped in chunks of window size. 


    
## Public Functions Documentation




### function Select 

_Selects an item using flip-page navigation._ 
```C++
virtual void evab::FlipWindowAlgorithm::Select (
    unsigned char aIndex
) override
```





**Parameters:**


* `aIndex` Index to select 




        
Implements [*evab::WindowAlgorithmBase::Select*](classevab_1_1_window_algorithm_base.md#function-select)


<hr>



### function WindowAlgorithmBase 

_Constructor for window algorithm base._ 
```C++
evab::FlipWindowAlgorithm::WindowAlgorithmBase (
    unsigned char aCount=0
) 
```





**Parameters:**


* `aCount` Total number of items 




        

<hr>

------------------------------
The documentation for this class was generated from the following file `src/evabWindowAlgorithms.h`

