

# Class evab::FlipWindowAlgorithm



[**ClassList**](annotated.md) **>** [**evab**](namespaceevab.md) **>** [**FlipWindowAlgorithm**](classevab_1_1_flip_window_algorithm.md)








Inherits the following classes: [evab::WindowAlgorithmBase](classevab_1_1_window_algorithm_base.md)


Inherited by the following classes: [evab::ListBox](classevab_1_1_list_box.md)




















































## Public Functions

| Type | Name |
| ---: | :--- |
| virtual void | [**Select**](#function-select) (signed char aIndex) override<br> |


## Public Functions inherited from evab::WindowAlgorithmBase

See [evab::WindowAlgorithmBase](classevab_1_1_window_algorithm_base.md)

| Type | Name |
| ---: | :--- |
|  signed char | [**Count**](classevab_1_1_window_algorithm_base.md#function-count) () <br> |
| virtual void | [**Select**](classevab_1_1_window_algorithm_base.md#function-select) (signed char aIndex) = 0<br> |
|  signed char | [**Selected**](classevab_1_1_window_algorithm_base.md#function-selected) () <br> |
|   | [**WindowAlgorithmBase**](classevab_1_1_window_algorithm_base.md#function-windowalgorithmbase) () <br> |
|  signed char | [**WindowSize**](classevab_1_1_window_algorithm_base.md#function-windowsize) () <br> |
















## Protected Attributes inherited from evab::WindowAlgorithmBase

See [evab::WindowAlgorithmBase](classevab_1_1_window_algorithm_base.md)

| Type | Name |
| ---: | :--- |
|  signed char | [**mCount**](classevab_1_1_window_algorithm_base.md#variable-mcount)  <br> |
|  signed char | [**mSelected**](classevab_1_1_window_algorithm_base.md#variable-mselected)  <br> |
|  signed char | [**mWindowSize**](classevab_1_1_window_algorithm_base.md#variable-mwindowsize)  <br> |
|  signed char | [**mWindowStart**](classevab_1_1_window_algorithm_base.md#variable-mwindowstart)  <br> |
































## Protected Functions inherited from evab::WindowAlgorithmBase

See [evab::WindowAlgorithmBase](classevab_1_1_window_algorithm_base.md)

| Type | Name |
| ---: | :--- |
|  signed char | [**indexInWindow**](classevab_1_1_window_algorithm_base.md#function-indexinwindow) (signed char aPosition) <br> |
|  void | [**resizeWindow**](classevab_1_1_window_algorithm_base.md#function-resizewindow) (signed char aWindowSize) <br> |
|  void | [**setCount**](classevab_1_1_window_algorithm_base.md#function-setcount) (signed char Count) <br> |






## Public Functions Documentation




### function Select 

```C++
virtual void evab::FlipWindowAlgorithm::Select (
    signed char aIndex
) override
```



Implements [*evab::WindowAlgorithmBase::Select*](classevab_1_1_window_algorithm_base.md#function-select)


<hr>

------------------------------
The documentation for this class was generated from the following file `src/evabWindowAlgorithms.h`

