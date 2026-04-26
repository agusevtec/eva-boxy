

# Class FlipSlidingMethod



[**ClassList**](annotated.md) **>** [**FlipSlidingMethod**](class_flip_sliding_method.md)








Inherits the following classes: [SlidingMethodBase](class_sliding_method_base.md)
























## Public Attributes inherited from SlidingMethodBase

See [SlidingMethodBase](class_sliding_method_base.md)

| Type | Name |
| ---: | :--- |
|  signed char | [**Count**](class_sliding_method_base.md#variable-count)  <br> |
|  signed char | [**PageSize**](class_sliding_method_base.md#variable-pagesize)  <br> |






























## Public Functions

| Type | Name |
| ---: | :--- |
| virtual void | [**Select**](#function-select) (signed char aIndex) override<br> |


## Public Functions inherited from SlidingMethodBase

See [SlidingMethodBase](class_sliding_method_base.md)

| Type | Name |
| ---: | :--- |
|  signed char | [**IndexInWindow**](class_sliding_method_base.md#function-indexinwindow) (signed char aPosition) <br> |
| virtual void | [**Select**](class_sliding_method_base.md#function-select) (signed char aIndex) = 0<br> |
|  void | [**SelectRelative**](class_sliding_method_base.md#function-selectrelative) (signed char aShift) <br> |
|  signed char | [**Selected**](class_sliding_method_base.md#function-selected) () <br> |
|   | [**SlidingMethodBase**](class_sliding_method_base.md#function-slidingmethodbase) () <br> |
















## Protected Attributes inherited from SlidingMethodBase

See [SlidingMethodBase](class_sliding_method_base.md)

| Type | Name |
| ---: | :--- |
|  signed char | [**mIndex**](class_sliding_method_base.md#variable-mindex)  <br> |
|  signed char | [**mSlidingWindow**](class_sliding_method_base.md#variable-mslidingwindow)  <br> |






































## Public Functions Documentation




### function Select 

```C++
virtual void FlipSlidingMethod::Select (
    signed char aIndex
) override
```



Implements [*SlidingMethodBase::Select*](class_sliding_method_base.md#function-select)


<hr>

------------------------------
The documentation for this class was generated from the following file `src/SlidingMethods.h`

