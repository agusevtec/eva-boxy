

# Class DisplayPlatform



[**ClassList**](annotated.md) **>** [**DisplayPlatform**](class_display_platform.md)










Inherited by the following classes: [DebugPlatform](class_debug_platform.md),  [Gyver1306Platform](class_gyver1306_platform.md)
































## Public Functions

| Type | Name |
| ---: | :--- |
| virtual void | [**Display**](#function-display) ([**Coor**](struct_coor.md) aPos, [**Coor**](struct_coor.md) aSize, const char \* aText, unsigned char aAlign, unsigned char aMarkup=0) = 0<br> |
|  void | [**Draw**](#function-draw) ([**BoxyBaseElement**](class_boxy_base_element.md) \* aGroundElement=0) <br> |
| virtual void | [**Fill**](#function-fill) (const char aGlyph, [**Coor**](struct_coor.md) aPos, [**Coor**](struct_coor.md) aSize, unsigned char aMarkup) = 0<br> |
|  void | [**Key**](#function-key) (char aKey) <br> |
|  void | [**SetFreeze**](#function-setfreeze) (int aFreeze) <br> |
| virtual [**Coor**](struct_coor.md) | [**Size**](#function-size) () = 0<br> |


## Public Static Functions

| Type | Name |
| ---: | :--- |
|  [**DisplayPlatform**](class_display_platform.md) \* | [**Instance**](#function-instance) ([**DisplayPlatform**](class_display_platform.md) \* aPlatform=0) <br> |


























## Public Functions Documentation




### function Display 

```C++
virtual void DisplayPlatform::Display (
    Coor aPos,
    Coor aSize,
    const char * aText,
    unsigned char aAlign,
    unsigned char aMarkup=0
) = 0
```




<hr>



### function Draw 

```C++
void DisplayPlatform::Draw (
    BoxyBaseElement * aGroundElement=0
) 
```




<hr>



### function Fill 

```C++
virtual void DisplayPlatform::Fill (
    const char aGlyph,
    Coor aPos,
    Coor aSize,
    unsigned char aMarkup
) = 0
```




<hr>



### function Key 

```C++
void DisplayPlatform::Key (
    char aKey
) 
```




<hr>



### function SetFreeze 

```C++
void DisplayPlatform::SetFreeze (
    int aFreeze
) 
```




<hr>



### function Size 

```C++
virtual Coor DisplayPlatform::Size () = 0
```




<hr>
## Public Static Functions Documentation




### function Instance 

```C++
static DisplayPlatform * DisplayPlatform::Instance (
    DisplayPlatform * aPlatform=0
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `src/DisplayPlatform.h`

