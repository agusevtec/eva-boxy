

# Class SlidingMethodBase



[**ClassList**](annotated.md) **>** [**SlidingMethodBase**](class_sliding_method_base.md)










Inherited by the following classes: [FlipSlidingMethod](class_flip_sliding_method.md),  [ScrollSlidingMethod](class_scroll_sliding_method.md)
















## Public Attributes

| Type | Name |
| ---: | :--- |
|  signed char | [**Count**](#variable-count)  <br> |
|  signed char | [**PageSize**](#variable-pagesize)  <br> |
















## Public Functions

| Type | Name |
| ---: | :--- |
|  signed char | [**IndexInWindow**](#function-indexinwindow) (signed char aPosition) <br> |
| virtual void | [**Select**](#function-select) (signed char aIndex) = 0<br> |
|  void | [**SelectRelative**](#function-selectrelative) (signed char aShift) <br> |
|  signed char | [**Selected**](#function-selected) () <br> |
|   | [**SlidingMethodBase**](#function-slidingmethodbase) () <br> |








## Protected Attributes

| Type | Name |
| ---: | :--- |
|  signed char | [**mIndex**](#variable-mindex)  <br> |
|  signed char | [**mSlidingWindow**](#variable-mslidingwindow)  <br> |




















## Public Attributes Documentation




### variable Count 

```C++
signed char SlidingMethodBase::Count;
```




<hr>



### variable PageSize 

```C++
signed char SlidingMethodBase::PageSize;
```




<hr>
## Public Functions Documentation




### function IndexInWindow 

```C++
signed char SlidingMethodBase::IndexInWindow (
    signed char aPosition
) 
```




<hr>



### function Select 

```C++
virtual void SlidingMethodBase::Select (
    signed char aIndex
) = 0
```




<hr>



### function SelectRelative 

```C++
void SlidingMethodBase::SelectRelative (
    signed char aShift
) 
```




<hr>



### function Selected 

```C++
signed char SlidingMethodBase::Selected () 
```




<hr>



### function SlidingMethodBase 

```C++
SlidingMethodBase::SlidingMethodBase () 
```




<hr>
## Protected Attributes Documentation




### variable mIndex 

```C++
signed char SlidingMethodBase::mIndex;
```




<hr>



### variable mSlidingWindow 

```C++
signed char SlidingMethodBase::mSlidingWindow;
```




<hr>

------------------------------
The documentation for this class was generated from the following file `src/SlidingMethods.h`

