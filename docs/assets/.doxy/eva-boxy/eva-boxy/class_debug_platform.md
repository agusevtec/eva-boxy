

# Class DebugPlatform



[**ClassList**](annotated.md) **>** [**DebugPlatform**](class_debug_platform.md)








Inherits the following classes: [DisplayPlatform](class_display_platform.md)






















































## Public Functions

| Type | Name |
| ---: | :--- |
|  void | [**Debug**](#function-debug) (void \* aMsgSender, long aArgsMask) <br> |
|   | [**DebugPlatform**](#function-debugplatform) () <br> |
| virtual void | [**Display**](#function-display) ([**Coor**](struct_coor.md) aPos, [**Coor**](struct_coor.md) aSize, const char \* aText, unsigned char aAlign, unsigned char aMarkup) override<br> |
| virtual void | [**Fill**](#function-fill) (const char aGlyph, [**Coor**](struct_coor.md) aPos, [**Coor**](struct_coor.md) aSize, unsigned char aMarkup) override<br> |
| virtual [**Coor**](struct_coor.md) | [**Size**](#function-size) () <br> |


## Public Functions inherited from DisplayPlatform

See [DisplayPlatform](class_display_platform.md)

| Type | Name |
| ---: | :--- |
| virtual void | [**Display**](class_display_platform.md#function-display) ([**Coor**](struct_coor.md) aPos, [**Coor**](struct_coor.md) aSize, const char \* aText, unsigned char aAlign, unsigned char aMarkup=0) = 0<br> |
|  void | [**Draw**](class_display_platform.md#function-draw) ([**BoxyBaseElement**](class_boxy_base_element.md) \* aGroundElement=0) <br> |
| virtual void | [**Fill**](class_display_platform.md#function-fill) (const char aGlyph, [**Coor**](struct_coor.md) aPos, [**Coor**](struct_coor.md) aSize, unsigned char aMarkup) = 0<br> |
|  void | [**Key**](class_display_platform.md#function-key) (char aKey) <br> |
|  void | [**SetFreeze**](class_display_platform.md#function-setfreeze) (int aFreeze) <br> |
| virtual [**Coor**](struct_coor.md) | [**Size**](class_display_platform.md#function-size) () = 0<br> |




## Public Static Functions inherited from DisplayPlatform

See [DisplayPlatform](class_display_platform.md)

| Type | Name |
| ---: | :--- |
|  [**DisplayPlatform**](class_display_platform.md) \* | [**Instance**](class_display_platform.md#function-instance) ([**DisplayPlatform**](class_display_platform.md) \* aPlatform=0) <br> |


















































## Public Functions Documentation




### function Debug 

```C++
void DebugPlatform::Debug (
    void * aMsgSender,
    long aArgsMask
) 
```




<hr>



### function DebugPlatform 

```C++
DebugPlatform::DebugPlatform () 
```




<hr>



### function Display 

```C++
virtual void DebugPlatform::Display (
    Coor aPos,
    Coor aSize,
    const char * aText,
    unsigned char aAlign,
    unsigned char aMarkup
) override
```



Implements [*DisplayPlatform::Display*](class_display_platform.md#function-display)


<hr>



### function Fill 

```C++
virtual void DebugPlatform::Fill (
    const char aGlyph,
    Coor aPos,
    Coor aSize,
    unsigned char aMarkup
) override
```



Implements [*DisplayPlatform::Fill*](class_display_platform.md#function-fill)


<hr>



### function Size 

```C++
virtual Coor DebugPlatform::Size () 
```



Implements [*DisplayPlatform::Size*](class_display_platform.md#function-size)


<hr>

------------------------------
The documentation for this class was generated from the following file `src/DebugPlatform.h`

