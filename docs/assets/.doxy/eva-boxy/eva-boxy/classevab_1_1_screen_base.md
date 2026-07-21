

# Class evab::ScreenBase



[**ClassList**](annotated.md) **>** [**evab**](namespaceevab.md) **>** [**ScreenBase**](classevab_1_1_screen_base.md)



_Base class for screen implementations._ [More...](#detailed-description)

* `#include <evabScreenBase.h>`



Inherits the following classes: [evab::IScreen](classevab_1_1_i_screen.md)


Inherited by the following classes: [evab::ScreenLCD\_I2C](classevab_1_1_screen_l_c_d___i2_c.md),  [evab::ScreenPage8Base](classevab_1_1_screen_page8_base.md),  [evab::ScreenSerialText](classevab_1_1_screen_serial_text.md)




















































## Public Functions

| Type | Name |
| ---: | :--- |
| virtual void | [**Clear**](#function-clear) ([**Coor**](structevab_1_1_coor.md) aPosition, [**Coor**](structevab_1_1_coor.md) aSize, unsigned char aColor) override<br>_Clears a rectangular area._  |
| virtual void | [**Picto**](#function-picto) ([**Coor**](structevab_1_1_coor.md) aPosition, const unsigned char \* pictoData, unsigned char aColor) <br>_Draws a pictogram (default implementation)._  |
| virtual void | [**TextCenter**](#function-textcenter-12) ([**Coor**](structevab_1_1_coor.md) aPosition, [**Coor**](structevab_1_1_coor.md) aSize, const char \* text, unsigned char aColor) override<br>_Draws text aligned center (C-string)._  |
| virtual void | [**TextCenter**](#function-textcenter-22) ([**Coor**](structevab_1_1_coor.md) aPosition, [**Coor**](structevab_1_1_coor.md) aSize, const \_\_FlashStringHelper \* text, unsigned char aColor) override<br>_Draws text aligned center (Flash string)._  |
| virtual void | [**TextLeft**](#function-textleft-12) ([**Coor**](structevab_1_1_coor.md) aPosition, [**Coor**](structevab_1_1_coor.md) aSize, const char \* text, unsigned char aColor) override<br>_Draws text aligned left (C-string)._  |
| virtual void | [**TextLeft**](#function-textleft-22) ([**Coor**](structevab_1_1_coor.md) aPosition, [**Coor**](structevab_1_1_coor.md) aSize, const \_\_FlashStringHelper \* text, unsigned char aColor) override<br>_Draws text aligned left (Flash string)._  |
| virtual void | [**TextRight**](#function-textright-12) ([**Coor**](structevab_1_1_coor.md) aPosition, [**Coor**](structevab_1_1_coor.md) aSize, const char \* text, unsigned char aColor) override<br>_Draws text aligned right (C-string)._  |
| virtual void | [**TextRight**](#function-textright-22) ([**Coor**](structevab_1_1_coor.md) aPosition, [**Coor**](structevab_1_1_coor.md) aSize, const \_\_FlashStringHelper \* text, unsigned char aColor) override<br>_Draws text aligned right (Flash string)._  |


## Public Functions inherited from evab::IScreen

See [evab::IScreen](classevab_1_1_i_screen.md)

| Type | Name |
| ---: | :--- |
| virtual void | [**Clear**](classevab_1_1_i_screen.md#function-clear) ([**Coor**](structevab_1_1_coor.md) aPosition, [**Coor**](structevab_1_1_coor.md) aSize, unsigned char aColor=0) = 0<br>_Clears a rectangular area on screen._  |
| virtual void | [**Deserialize**](classevab_1_1_i_screen.md#function-deserialize) (unsigned short aSerialized, [**Coor**](structevab_1_1_coor.md) & aPos, [**Coor**](structevab_1_1_coor.md) & aSize, bool & isFocused) = 0<br>_Deserializes element state from 16-bit value._  |
| virtual void | [**DrawSymbol**](classevab_1_1_i_screen.md#function-drawsymbol) ([**Coor**](structevab_1_1_coor.md) aPosition, [**Coor**](structevab_1_1_coor.md) aSize, char aSymbol, unsigned char aColor) = 0<br>_Draws a single character symbol._  |
| virtual void | [**Picto**](classevab_1_1_i_screen.md#function-picto) ([**Coor**](structevab_1_1_coor.md) aPosition, const unsigned char \* pictoData, unsigned char aColor) = 0<br>_Draws a pictogram at the specified position._  |
| virtual unsigned short | [**Serialize**](classevab_1_1_i_screen.md#function-serialize) (const [**Coor**](structevab_1_1_coor.md) & aPos, const [**Coor**](structevab_1_1_coor.md) & aSize, bool isFocused) = 0<br>_Serializes element state into 16-bit value._  |
| virtual [**Coor**](structevab_1_1_coor.md) | [**Size**](classevab_1_1_i_screen.md#function-size) () = 0<br>_Gets the screen size in tiles._  |
| virtual void | [**TextCenter**](classevab_1_1_i_screen.md#function-textcenter-12) ([**Coor**](structevab_1_1_coor.md) aPosition, [**Coor**](structevab_1_1_coor.md) aSize, const char \* text, unsigned char aColor) = 0<br>_Draws text aligned to the center._  |
| virtual void | [**TextCenter**](classevab_1_1_i_screen.md#function-textcenter-22) ([**Coor**](structevab_1_1_coor.md) aPosition, [**Coor**](structevab_1_1_coor.md) aSize, const \_\_FlashStringHelper \* text, unsigned char aColor) = 0<br>_Draws flash string text aligned to the center._  |
| virtual void | [**TextLeft**](classevab_1_1_i_screen.md#function-textleft-12) ([**Coor**](structevab_1_1_coor.md) aPosition, [**Coor**](structevab_1_1_coor.md) aSize, const char \* text, unsigned char aColor) = 0<br>_Draws text aligned to the left._  |
| virtual void | [**TextLeft**](classevab_1_1_i_screen.md#function-textleft-22) ([**Coor**](structevab_1_1_coor.md) aPosition, [**Coor**](structevab_1_1_coor.md) aSize, const \_\_FlashStringHelper \* text, unsigned char aColor) = 0<br>_Draws flash string text aligned to the left._  |
| virtual void | [**TextRight**](classevab_1_1_i_screen.md#function-textright-12) ([**Coor**](structevab_1_1_coor.md) aPosition, [**Coor**](structevab_1_1_coor.md) aSize, const char \* text, unsigned char aColor) = 0<br>_Draws text aligned to the right._  |
| virtual void | [**TextRight**](classevab_1_1_i_screen.md#function-textright-22) ([**Coor**](structevab_1_1_coor.md) aPosition, [**Coor**](structevab_1_1_coor.md) aSize, const \_\_FlashStringHelper \* text, unsigned char aColor) = 0<br>_Draws flash string text aligned to the right._  |














































## Protected Functions

| Type | Name |
| ---: | :--- |
| virtual void | [**ClearTile**](#function-cleartile) ([**Coor**](structevab_1_1_coor.md) position, unsigned char aColor) <br>_Clears a single tile._  |








## Detailed Description


Provides common text rendering functionality for all screens. 


    
## Public Functions Documentation




### function Clear 

_Clears a rectangular area._ 
```C++
virtual void evab::ScreenBase::Clear (
    Coor aPosition,
    Coor aSize,
    unsigned char aColor
) override
```





**Parameters:**


* `aPosition` Position of the area 
* `aSize` Size of the area 
* `aColor` Fill color (0 = clear, 1 = fill) 




        
Implements [*evab::IScreen::Clear*](classevab_1_1_i_screen.md#function-clear)


<hr>



### function Picto 

_Draws a pictogram (default implementation)._ 
```C++
virtual void evab::ScreenBase::Picto (
    Coor aPosition,
    const unsigned char * pictoData,
    unsigned char aColor
) 
```





**Parameters:**


* `aPosition` Position on screen 
* `pictoData` Pictogram data 
* `aColor` Color/inversion flag 




        
Implements [*evab::IScreen::Picto*](classevab_1_1_i_screen.md#function-picto)


<hr>



### function TextCenter [1/2]

_Draws text aligned center (C-string)._ 
```C++
virtual void evab::ScreenBase::TextCenter (
    Coor aPosition,
    Coor aSize,
    const char * text,
    unsigned char aColor
) override
```





**Parameters:**


* `aPosition` Position on screen 
* `aSize` Size of the text area 
* `text` Null-terminated string 
* `aColor` Color/inversion flag 




        
Implements [*evab::IScreen::TextCenter*](classevab_1_1_i_screen.md#function-textcenter-12)


<hr>



### function TextCenter [2/2]

_Draws text aligned center (Flash string)._ 
```C++
virtual void evab::ScreenBase::TextCenter (
    Coor aPosition,
    Coor aSize,
    const __FlashStringHelper * text,
    unsigned char aColor
) override
```





**Parameters:**


* `aPosition` Position on screen 
* `aSize` Size of the text area 
* `text` Flash string 
* `aColor` Color/inversion flag 




        
Implements [*evab::IScreen::TextCenter*](classevab_1_1_i_screen.md#function-textcenter-22)


<hr>



### function TextLeft [1/2]

_Draws text aligned left (C-string)._ 
```C++
virtual void evab::ScreenBase::TextLeft (
    Coor aPosition,
    Coor aSize,
    const char * text,
    unsigned char aColor
) override
```





**Parameters:**


* `aPosition` Position on screen 
* `aSize` Size of the text area 
* `text` Null-terminated string 
* `aColor` Color/inversion flag 




        
Implements [*evab::IScreen::TextLeft*](classevab_1_1_i_screen.md#function-textleft-12)


<hr>



### function TextLeft [2/2]

_Draws text aligned left (Flash string)._ 
```C++
virtual void evab::ScreenBase::TextLeft (
    Coor aPosition,
    Coor aSize,
    const __FlashStringHelper * text,
    unsigned char aColor
) override
```





**Parameters:**


* `aPosition` Position on screen 
* `aSize` Size of the text area 
* `text` Flash string 
* `aColor` Color/inversion flag 




        
Implements [*evab::IScreen::TextLeft*](classevab_1_1_i_screen.md#function-textleft-22)


<hr>



### function TextRight [1/2]

_Draws text aligned right (C-string)._ 
```C++
virtual void evab::ScreenBase::TextRight (
    Coor aPosition,
    Coor aSize,
    const char * text,
    unsigned char aColor
) override
```





**Parameters:**


* `aPosition` Position on screen 
* `aSize` Size of the text area 
* `text` Null-terminated string 
* `aColor` Color/inversion flag 




        
Implements [*evab::IScreen::TextRight*](classevab_1_1_i_screen.md#function-textright-12)


<hr>



### function TextRight [2/2]

_Draws text aligned right (Flash string)._ 
```C++
virtual void evab::ScreenBase::TextRight (
    Coor aPosition,
    Coor aSize,
    const __FlashStringHelper * text,
    unsigned char aColor
) override
```





**Parameters:**


* `aPosition` Position on screen 
* `aSize` Size of the text area 
* `text` Flash string 
* `aColor` Color/inversion flag 




        
Implements [*evab::IScreen::TextRight*](classevab_1_1_i_screen.md#function-textright-22)


<hr>
## Protected Functions Documentation




### function ClearTile 

_Clears a single tile._ 
```C++
virtual void evab::ScreenBase::ClearTile (
    Coor position,
    unsigned char aColor
) 
```





**Parameters:**


* `position` Position of the tile 
* `aColor` Fill color 




        

<hr>

------------------------------
The documentation for this class was generated from the following file `src/evabScreenBase.h`

