

# Class evab::ScreenBase



[**ClassList**](annotated.md) **>** [**evab**](namespaceevab.md) **>** [**ScreenBase**](classevab_1_1_screen_base.md)








Inherits the following classes: [evab::IScreen](classevab_1_1_i_screen.md)


Inherited by the following classes: [evab::ScreenLCD\_I2C](classevab_1_1_screen_l_c_d___i2_c.md),  [evab::ScreenPage8Base](classevab_1_1_screen_page8_base.md),  [evab::ScreenSerialText](classevab_1_1_screen_serial_text.md)




















































## Public Functions

| Type | Name |
| ---: | :--- |
| virtual void | [**Clear**](#function-clear) ([**Coor**](structevab_1_1_coor.md) aPosition, [**Coor**](structevab_1_1_coor.md) aSize, unsigned char aColor) override<br> |
| virtual void | [**Picto**](#function-picto) ([**Coor**](structevab_1_1_coor.md) aPosition, const unsigned char \* pictoData, unsigned char aColor) <br> |
| virtual void | [**TextCenter**](#function-textcenter-12) ([**Coor**](structevab_1_1_coor.md) aPosition, [**Coor**](structevab_1_1_coor.md) aSize, const char \* text, unsigned char aColor) override<br> |
| virtual void | [**TextCenter**](#function-textcenter-22) ([**Coor**](structevab_1_1_coor.md) aPosition, [**Coor**](structevab_1_1_coor.md) aSize, const \_\_FlashStringHelper \* text, unsigned char aColor) override<br> |
| virtual void | [**TextLeft**](#function-textleft-12) ([**Coor**](structevab_1_1_coor.md) aPosition, [**Coor**](structevab_1_1_coor.md) aSize, const char \* text, unsigned char aColor) override<br> |
| virtual void | [**TextLeft**](#function-textleft-22) ([**Coor**](structevab_1_1_coor.md) aPosition, [**Coor**](structevab_1_1_coor.md) aSize, const \_\_FlashStringHelper \* text, unsigned char aColor) override<br> |
| virtual void | [**TextRight**](#function-textright-12) ([**Coor**](structevab_1_1_coor.md) aPosition, [**Coor**](structevab_1_1_coor.md) aSize, const char \* text, unsigned char aColor) override<br> |
| virtual void | [**TextRight**](#function-textright-22) ([**Coor**](structevab_1_1_coor.md) aPosition, [**Coor**](structevab_1_1_coor.md) aSize, const \_\_FlashStringHelper \* text, unsigned char aColor) override<br> |


## Public Functions inherited from evab::IScreen

See [evab::IScreen](classevab_1_1_i_screen.md)

| Type | Name |
| ---: | :--- |
| virtual void | [**Clear**](classevab_1_1_i_screen.md#function-clear) ([**Coor**](structevab_1_1_coor.md) aPosition, [**Coor**](structevab_1_1_coor.md) aSize, unsigned char aColor=0) = 0<br> |
| virtual void | [**DrawSymbol**](classevab_1_1_i_screen.md#function-drawsymbol) ([**Coor**](structevab_1_1_coor.md) aPosition, [**Coor**](structevab_1_1_coor.md) aSize, char aSymbol, unsigned char aColor) = 0<br> |
| virtual void | [**Picto**](classevab_1_1_i_screen.md#function-picto) ([**Coor**](structevab_1_1_coor.md) aPosition, const unsigned char \* pictoData, unsigned char aColor) = 0<br> |
| virtual [**Coor**](structevab_1_1_coor.md) | [**Size**](classevab_1_1_i_screen.md#function-size) () = 0<br> |
| virtual void | [**TextCenter**](classevab_1_1_i_screen.md#function-textcenter-12) ([**Coor**](structevab_1_1_coor.md) aPosition, [**Coor**](structevab_1_1_coor.md) aSize, const char \* text, unsigned char aColor) = 0<br> |
| virtual void | [**TextCenter**](classevab_1_1_i_screen.md#function-textcenter-22) ([**Coor**](structevab_1_1_coor.md) aPosition, [**Coor**](structevab_1_1_coor.md) aSize, const \_\_FlashStringHelper \* text, unsigned char aColor) = 0<br> |
| virtual void | [**TextLeft**](classevab_1_1_i_screen.md#function-textleft-12) ([**Coor**](structevab_1_1_coor.md) aPosition, [**Coor**](structevab_1_1_coor.md) aSize, const char \* text, unsigned char aColor) = 0<br> |
| virtual void | [**TextLeft**](classevab_1_1_i_screen.md#function-textleft-22) ([**Coor**](structevab_1_1_coor.md) aPosition, [**Coor**](structevab_1_1_coor.md) aSize, const \_\_FlashStringHelper \* text, unsigned char aColor) = 0<br> |
| virtual void | [**TextRight**](classevab_1_1_i_screen.md#function-textright-12) ([**Coor**](structevab_1_1_coor.md) aPosition, [**Coor**](structevab_1_1_coor.md) aSize, const char \* text, unsigned char aColor) = 0<br> |
| virtual void | [**TextRight**](classevab_1_1_i_screen.md#function-textright-22) ([**Coor**](structevab_1_1_coor.md) aPosition, [**Coor**](structevab_1_1_coor.md) aSize, const \_\_FlashStringHelper \* text, unsigned char aColor) = 0<br> |














































## Protected Functions

| Type | Name |
| ---: | :--- |
| virtual void | [**ClearTile**](#function-cleartile) ([**Coor**](structevab_1_1_coor.md) position, unsigned char aColor) <br> |








## Public Functions Documentation




### function Clear 

```C++
virtual void evab::ScreenBase::Clear (
    Coor aPosition,
    Coor aSize,
    unsigned char aColor
) override
```



Implements [*evab::IScreen::Clear*](classevab_1_1_i_screen.md#function-clear)


<hr>



### function Picto 

```C++
virtual void evab::ScreenBase::Picto (
    Coor aPosition,
    const unsigned char * pictoData,
    unsigned char aColor
) 
```



Implements [*evab::IScreen::Picto*](classevab_1_1_i_screen.md#function-picto)


<hr>



### function TextCenter [1/2]

```C++
virtual void evab::ScreenBase::TextCenter (
    Coor aPosition,
    Coor aSize,
    const char * text,
    unsigned char aColor
) override
```



Implements [*evab::IScreen::TextCenter*](classevab_1_1_i_screen.md#function-textcenter-12)


<hr>



### function TextCenter [2/2]

```C++
virtual void evab::ScreenBase::TextCenter (
    Coor aPosition,
    Coor aSize,
    const __FlashStringHelper * text,
    unsigned char aColor
) override
```



Implements [*evab::IScreen::TextCenter*](classevab_1_1_i_screen.md#function-textcenter-22)


<hr>



### function TextLeft [1/2]

```C++
virtual void evab::ScreenBase::TextLeft (
    Coor aPosition,
    Coor aSize,
    const char * text,
    unsigned char aColor
) override
```



Implements [*evab::IScreen::TextLeft*](classevab_1_1_i_screen.md#function-textleft-12)


<hr>



### function TextLeft [2/2]

```C++
virtual void evab::ScreenBase::TextLeft (
    Coor aPosition,
    Coor aSize,
    const __FlashStringHelper * text,
    unsigned char aColor
) override
```



Implements [*evab::IScreen::TextLeft*](classevab_1_1_i_screen.md#function-textleft-22)


<hr>



### function TextRight [1/2]

```C++
virtual void evab::ScreenBase::TextRight (
    Coor aPosition,
    Coor aSize,
    const char * text,
    unsigned char aColor
) override
```



Implements [*evab::IScreen::TextRight*](classevab_1_1_i_screen.md#function-textright-12)


<hr>



### function TextRight [2/2]

```C++
virtual void evab::ScreenBase::TextRight (
    Coor aPosition,
    Coor aSize,
    const __FlashStringHelper * text,
    unsigned char aColor
) override
```



Implements [*evab::IScreen::TextRight*](classevab_1_1_i_screen.md#function-textright-22)


<hr>
## Protected Functions Documentation




### function ClearTile 

```C++
virtual void evab::ScreenBase::ClearTile (
    Coor position,
    unsigned char aColor
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `src/evabScreenBase.h`

