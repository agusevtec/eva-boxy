

# Class Gyver1306Platform



[**ClassList**](annotated.md) **>** [**Gyver1306Platform**](class_gyver1306_platform.md)








Inherits the following classes: [DisplayPlatform](class_display_platform.md)






















































## Public Functions

| Type | Name |
| ---: | :--- |
| virtual void | [**Display**](#function-display) ([**Coor**](struct_coor.md) aPos, [**Coor**](struct_coor.md) aSize, const char \* aText, unsigned char aAlign, unsigned char aMarkup=0) override<br> |
| virtual void | [**Fill**](#function-fill) (const char aGlyph, [**Coor**](struct_coor.md) aPos, [**Coor**](struct_coor.md) aSize, unsigned char aMarkup) override<br> |
|   | [**Gyver1306Platform**](#function-gyver1306platform) () <br> |
| virtual [**Coor**](struct_coor.md) | [**Size**](#function-size) () override<br> |


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




### function Display 

```C++
virtual void Gyver1306Platform::Display (
    Coor aPos,
    Coor aSize,
    const char * aText,
    unsigned char aAlign,
    unsigned char aMarkup=0
) override
```



Implements [*DisplayPlatform::Display*](class_display_platform.md#function-display)


<hr>



### function Fill 

```C++
virtual void Gyver1306Platform::Fill (
    const char aGlyph,
    Coor aPos,
    Coor aSize,
    unsigned char aMarkup
) override
```



Implements [*DisplayPlatform::Fill*](class_display_platform.md#function-fill)


<hr>



### function Gyver1306Platform 

```C++
Gyver1306Platform::Gyver1306Platform () 
```




<hr>



### function Size 

```C++
virtual Coor Gyver1306Platform::Size () override
```



Implements [*DisplayPlatform::Size*](class_display_platform.md#function-size)


<hr>

------------------------------
The documentation for this class was generated from the following file `src/Gyver1306Platform.h`

