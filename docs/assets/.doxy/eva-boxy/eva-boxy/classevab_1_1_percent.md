

# Class evab::Percent

**template &lt;typename TElement, unsigned char kStep&gt;**



[**ClassList**](annotated.md) **>** [**evab**](namespaceevab.md) **>** [**Percent**](classevab_1_1_percent.md)



[_**Percent**_](classevab_1_1_percent.md) _modifier for discrete inputs._[More...](#detailed-description)

* `#include <evabPercent.h>`



Inherits the following classes: TElement


































## Public Functions

| Type | Name |
| ---: | :--- |
|  unsigned char | [**GetPercent**](#function-getpercent) () const<br>_Gets current value as percent (0-100)._  |
|  unsigned char | [**GetStep**](#function-getstep) () const<br>_Gets the step size in percent._  |
|   | [**Percent**](#function-percent) (Args &&... args) <br> |
|  void | [**SetPercent**](#function-setpercent) (unsigned char aPercent) <br>_Sets value by percent (0-100)._  |




























## Detailed Description


Adds percent-based control (0-100) to any discrete input.




**Template parameters:**


* `TElement` Base element type (must have Select, Selected, Count methods) 
* `kStep` Step size in percent (default: 100 / Count) 




    
## Public Functions Documentation




### function GetPercent 

_Gets current value as percent (0-100)._ 
```C++
inline unsigned char evab::Percent::GetPercent () const
```




<hr>



### function GetStep 

_Gets the step size in percent._ 
```C++
inline unsigned char evab::Percent::GetStep () const
```




<hr>



### function Percent 

```C++
template<typename... Args>
inline evab::Percent::Percent (
    Args &&... args
) 
```




<hr>



### function SetPercent 

_Sets value by percent (0-100)._ 
```C++
inline void evab::Percent::SetPercent (
    unsigned char aPercent
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `src/evabPercent.h`

