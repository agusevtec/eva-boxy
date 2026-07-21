

# Class evab::ScrollWindowAlgorithm



[**ClassList**](annotated.md) **>** [**evab**](namespaceevab.md) **>** [**ScrollWindowAlgorithm**](classevab_1_1_scroll_window_algorithm.md)



_Scroll navigation algorithm._ [More...](#detailed-description)

* `#include <evabWindowAlgorithms.h>`



Inherits the following classes: [evab::WindowAlgorithmBase](classevab_1_1_window_algorithm_base.md)


Inherited by the following classes: [evab::ListBox](classevab_1_1_list_box.md)




















































## Public Functions

| Type | Name |
| ---: | :--- |
| virtual void | [**Select**](#function-select) (signed char aIndex) override<br>_Selects an item using scroll navigation._  |


## Public Functions inherited from evab::WindowAlgorithmBase

See [evab::WindowAlgorithmBase](classevab_1_1_window_algorithm_base.md)

| Type | Name |
| ---: | :--- |
|  signed char | [**Count**](classevab_1_1_window_algorithm_base.md#function-count) () <br>_Gets the total number of items._  |
| virtual void | [**Select**](classevab_1_1_window_algorithm_base.md#function-select) (signed char aIndex) = 0<br>_Pure virtual method to select an item._  |
|  signed char | [**Selected**](classevab_1_1_window_algorithm_base.md#function-selected) () <br>_Gets the currently selected item index._  |
|   | [**WindowAlgorithmBase**](classevab_1_1_window_algorithm_base.md#function-windowalgorithmbase) () <br>_Constructor for window algorithm base._  |
|  signed char | [**WindowSize**](classevab_1_1_window_algorithm_base.md#function-windowsize) () <br>_Gets the window size._  |
















## Protected Attributes inherited from evab::WindowAlgorithmBase

See [evab::WindowAlgorithmBase](classevab_1_1_window_algorithm_base.md)

| Type | Name |
| ---: | :--- |
|  signed char | [**mCount**](classevab_1_1_window_algorithm_base.md#variable-mcount)  <br>_Total number of items._  |
|  signed char | [**mSelected**](classevab_1_1_window_algorithm_base.md#variable-mselected)  <br>_Currently selected index._  |
|  signed char | [**mWindowSize**](classevab_1_1_window_algorithm_base.md#variable-mwindowsize)  <br>_Window size._  |
|  signed char | [**mWindowStart**](classevab_1_1_window_algorithm_base.md#variable-mwindowstart)  <br>_Start of the current window._  |
































## Protected Functions inherited from evab::WindowAlgorithmBase

See [evab::WindowAlgorithmBase](classevab_1_1_window_algorithm_base.md)

| Type | Name |
| ---: | :--- |
|  signed char | [**indexInWindow**](classevab_1_1_window_algorithm_base.md#function-indexinwindow) (signed char aPosition) <br>_Calculates the visual index of an item in the current window._  |
|  void | [**resizeWindow**](classevab_1_1_window_algorithm_base.md#function-resizewindow) (signed char aWindowSize) <br>_Resizes the window._  |
|  void | [**setCount**](classevab_1_1_window_algorithm_base.md#function-setcount) (signed char Count) <br>_Sets the total number of items._  |






## Detailed Description


Scrolls the window to keep selection visible. 


    
## Public Functions Documentation




### function Select 

_Selects an item using scroll navigation._ 
```C++
virtual void evab::ScrollWindowAlgorithm::Select (
    signed char aIndex
) override
```





**Parameters:**


* `aIndex` Index to select 




        
Implements [*evab::WindowAlgorithmBase::Select*](classevab_1_1_window_algorithm_base.md#function-select)


<hr>

------------------------------
The documentation for this class was generated from the following file `src/evabWindowAlgorithms.h`

