

# Class evab::WindowAlgorithmBase



[**ClassList**](annotated.md) **>** [**evab**](namespaceevab.md) **>** [**WindowAlgorithmBase**](classevab_1_1_window_algorithm_base.md)










Inherited by the following classes: [evab::FlipWindowAlgorithm](classevab_1_1_flip_window_algorithm.md),  [evab::ScrollWindowAlgorithm](classevab_1_1_scroll_window_algorithm.md)
































## Public Functions

| Type | Name |
| ---: | :--- |
|  signed char | [**Count**](#function-count) () <br> |
| virtual void | [**Select**](#function-select) (signed char aIndex) = 0<br> |
|  signed char | [**Selected**](#function-selected) () <br> |
|   | [**WindowAlgorithmBase**](#function-windowalgorithmbase) () <br> |
|  signed char | [**WindowSize**](#function-windowsize) () <br> |








## Protected Attributes

| Type | Name |
| ---: | :--- |
|  signed char | [**mCount**](#variable-mcount)  <br> |
|  signed char | [**mSelected**](#variable-mselected)  <br> |
|  signed char | [**mWindowSize**](#variable-mwindowsize)  <br> |
|  signed char | [**mWindowStart**](#variable-mwindowstart)  <br> |
















## Protected Functions

| Type | Name |
| ---: | :--- |
|  signed char | [**indexInWindow**](#function-indexinwindow) (signed char aPosition) <br> |
|  void | [**resizeWindow**](#function-resizewindow) (signed char aWindowSize) <br> |
|  void | [**setCount**](#function-setcount) (signed char Count) <br> |




## Public Functions Documentation




### function Count 

```C++
signed char evab::WindowAlgorithmBase::Count () 
```




<hr>



### function Select 

```C++
virtual void evab::WindowAlgorithmBase::Select (
    signed char aIndex
) = 0
```




<hr>



### function Selected 

```C++
signed char evab::WindowAlgorithmBase::Selected () 
```




<hr>



### function WindowAlgorithmBase 

```C++
evab::WindowAlgorithmBase::WindowAlgorithmBase () 
```




<hr>



### function WindowSize 

```C++
signed char evab::WindowAlgorithmBase::WindowSize () 
```




<hr>
## Protected Attributes Documentation




### variable mCount 

```C++
signed char evab::WindowAlgorithmBase::mCount;
```




<hr>



### variable mSelected 

```C++
signed char evab::WindowAlgorithmBase::mSelected;
```




<hr>



### variable mWindowSize 

```C++
signed char evab::WindowAlgorithmBase::mWindowSize;
```




<hr>



### variable mWindowStart 

```C++
signed char evab::WindowAlgorithmBase::mWindowStart;
```




<hr>
## Protected Functions Documentation




### function indexInWindow 

```C++
signed char evab::WindowAlgorithmBase::indexInWindow (
    signed char aPosition
) 
```




<hr>



### function resizeWindow 

```C++
void evab::WindowAlgorithmBase::resizeWindow (
    signed char aWindowSize
) 
```




<hr>



### function setCount 

```C++
void evab::WindowAlgorithmBase::setCount (
    signed char Count
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `src/evabWindowAlgorithms.h`

