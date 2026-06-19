

# Class evab::IScreen



[**ClassList**](annotated.md) **>** [**evab**](namespaceevab.md) **>** [**IScreen**](classevab_1_1_i_screen.md)










Inherited by the following classes: [evab::ScreenBase](classevab_1_1_screen_base.md)
































## Public Functions

| Type | Name |
| ---: | :--- |
| virtual void | [**Clear**](#function-clear) ([**Coor**](structevab_1_1_coor.md) aPosition, [**Coor**](structevab_1_1_coor.md) aSize, unsigned char aColor=0) = 0<br> |
| virtual void | [**DrawSymbol**](#function-drawsymbol) ([**Coor**](structevab_1_1_coor.md) aPosition, [**Coor**](structevab_1_1_coor.md) aSize, char aSymbol, unsigned char aColor) = 0<br> |
| virtual void | [**Picto**](#function-picto) ([**Coor**](structevab_1_1_coor.md) aPosition, const unsigned char \* pictoData, unsigned char aColor) = 0<br> |
| virtual [**Coor**](structevab_1_1_coor.md) | [**Size**](#function-size) () = 0<br> |
| virtual void | [**TextCenter**](#function-textcenter-12) ([**Coor**](structevab_1_1_coor.md) aPosition, [**Coor**](structevab_1_1_coor.md) aSize, const char \* text, unsigned char aColor) = 0<br> |
| virtual void | [**TextCenter**](#function-textcenter-22) ([**Coor**](structevab_1_1_coor.md) aPosition, [**Coor**](structevab_1_1_coor.md) aSize, const \_\_FlashStringHelper \* text, unsigned char aColor) = 0<br> |
| virtual void | [**TextLeft**](#function-textleft-12) ([**Coor**](structevab_1_1_coor.md) aPosition, [**Coor**](structevab_1_1_coor.md) aSize, const char \* text, unsigned char aColor) = 0<br> |
| virtual void | [**TextLeft**](#function-textleft-22) ([**Coor**](structevab_1_1_coor.md) aPosition, [**Coor**](structevab_1_1_coor.md) aSize, const \_\_FlashStringHelper \* text, unsigned char aColor) = 0<br> |
| virtual void | [**TextRight**](#function-textright-12) ([**Coor**](structevab_1_1_coor.md) aPosition, [**Coor**](structevab_1_1_coor.md) aSize, const char \* text, unsigned char aColor) = 0<br> |
| virtual void | [**TextRight**](#function-textright-22) ([**Coor**](structevab_1_1_coor.md) aPosition, [**Coor**](structevab_1_1_coor.md) aSize, const \_\_FlashStringHelper \* text, unsigned char aColor) = 0<br> |




























## Public Functions Documentation




### function Clear 

```C++
virtual void evab::IScreen::Clear (
    Coor aPosition,
    Coor aSize,
    unsigned char aColor=0
) = 0
```




<hr>



### function DrawSymbol 

```C++
virtual void evab::IScreen::DrawSymbol (
    Coor aPosition,
    Coor aSize,
    char aSymbol,
    unsigned char aColor
) = 0
```




<hr>



### function Picto 

```C++
virtual void evab::IScreen::Picto (
    Coor aPosition,
    const unsigned char * pictoData,
    unsigned char aColor
) = 0
```




<hr>



### function Size 

```C++
virtual Coor evab::IScreen::Size () = 0
```




<hr>



### function TextCenter [1/2]

```C++
virtual void evab::IScreen::TextCenter (
    Coor aPosition,
    Coor aSize,
    const char * text,
    unsigned char aColor
) = 0
```




<hr>



### function TextCenter [2/2]

```C++
virtual void evab::IScreen::TextCenter (
    Coor aPosition,
    Coor aSize,
    const __FlashStringHelper * text,
    unsigned char aColor
) = 0
```




<hr>



### function TextLeft [1/2]

```C++
virtual void evab::IScreen::TextLeft (
    Coor aPosition,
    Coor aSize,
    const char * text,
    unsigned char aColor
) = 0
```




<hr>



### function TextLeft [2/2]

```C++
virtual void evab::IScreen::TextLeft (
    Coor aPosition,
    Coor aSize,
    const __FlashStringHelper * text,
    unsigned char aColor
) = 0
```




<hr>



### function TextRight [1/2]

```C++
virtual void evab::IScreen::TextRight (
    Coor aPosition,
    Coor aSize,
    const char * text,
    unsigned char aColor
) = 0
```




<hr>



### function TextRight [2/2]

```C++
virtual void evab::IScreen::TextRight (
    Coor aPosition,
    Coor aSize,
    const __FlashStringHelper * text,
    unsigned char aColor
) = 0
```




<hr>

------------------------------
The documentation for this class was generated from the following file `src/evabIScreen.h`

