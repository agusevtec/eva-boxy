

# Class evab::ScreenSSD1306



[**ClassList**](annotated.md) **>** [**evab**](namespaceevab.md) **>** [**ScreenSSD1306**](classevab_1_1_screen_s_s_d1306.md)



_SSD1306 screen driver for OLED displays._ [More...](#detailed-description)

* `#include <evabScreenSSD1306.h>`



Inherits the following classes: [evab::ScreenPage8Base](classevab_1_1_screen_page8_base.md)






























































































## Public Functions

| Type | Name |
| ---: | :--- |
| virtual void | [**Deserialize**](#function-deserialize) (unsigned short aSerialized, [**Coor**](structevab_1_1_coor.md) & aPos, [**Coor**](structevab_1_1_coor.md) & aSize, bool & isFocused) <br>_Deserializes element state for 16x8 screen._  |
|   | [**ScreenSSD1306**](#function-screenssd1306) (const [**IFont**](classevab_1_1_i_font.md) \* aFont, unsigned long aWireClock=800000L, uint8\_t aHeightPx=64) <br>_Constructor for SSD1306 screen driver._  |
| virtual unsigned short | [**Serialize**](#function-serialize) (const [**Coor**](structevab_1_1_coor.md) & aPos, const [**Coor**](structevab_1_1_coor.md) & aSize, bool isFocused) <br>_Serializes element state for 16x8 screen._  |
|  void | [**SetContrast**](#function-setcontrast) (uint8\_t aContrast) <br>_Sets display contrast._  |
| virtual [**Coor**](structevab_1_1_coor.md) | [**Size**](#function-size) () override<br>_Gets the screen size in tiles._  |
|   | [**~ScreenSSD1306**](#function-screenssd1306) () <br> |


## Public Functions inherited from evab::ScreenPage8Base

See [evab::ScreenPage8Base](classevab_1_1_screen_page8_base.md)

| Type | Name |
| ---: | :--- |
| virtual void | [**DrawSymbol**](classevab_1_1_screen_page8_base.md#function-drawsymbol) ([**Coor**](structevab_1_1_coor.md) aPosition, [**Coor**](structevab_1_1_coor.md) aSize, char aCharcode, unsigned char aColor) <br>_Draws a symbol at the specified position with scaling._  |
| virtual void | [**Picto**](classevab_1_1_screen_page8_base.md#function-picto) ([**Coor**](structevab_1_1_coor.md) aPosition, const unsigned char \* pictoData, unsigned char aColor) <br>_Draws a pictogram at the specified position._  |
|   | [**ScreenPage8Base**](classevab_1_1_screen_page8_base.md#function-screenpage8base) (const [**IFont**](classevab_1_1_i_font.md) \* mFont) <br>_Constructor for page-based 8-bit screen base._  |


## Public Functions inherited from evab::ScreenBase

See [evab::ScreenBase](classevab_1_1_screen_base.md)

| Type | Name |
| ---: | :--- |
| virtual void | [**Clear**](classevab_1_1_screen_base.md#function-clear) ([**Coor**](structevab_1_1_coor.md) aPosition, [**Coor**](structevab_1_1_coor.md) aSize, unsigned char aColor) override<br>_Clears a rectangular area._  |
| virtual void | [**Picto**](classevab_1_1_screen_base.md#function-picto) ([**Coor**](structevab_1_1_coor.md) aPosition, const unsigned char \* pictoData, unsigned char aColor) <br>_Draws a pictogram (default implementation)._  |
| virtual void | [**TextCenter**](classevab_1_1_screen_base.md#function-textcenter-12) ([**Coor**](structevab_1_1_coor.md) aPosition, [**Coor**](structevab_1_1_coor.md) aSize, const char \* text, unsigned char aColor) override<br>_Draws text aligned center (C-string)._  |
| virtual void | [**TextCenter**](classevab_1_1_screen_base.md#function-textcenter-22) ([**Coor**](structevab_1_1_coor.md) aPosition, [**Coor**](structevab_1_1_coor.md) aSize, const \_\_FlashStringHelper \* text, unsigned char aColor) override<br>_Draws text aligned center (Flash string)._  |
| virtual void | [**TextLeft**](classevab_1_1_screen_base.md#function-textleft-12) ([**Coor**](structevab_1_1_coor.md) aPosition, [**Coor**](structevab_1_1_coor.md) aSize, const char \* text, unsigned char aColor) override<br>_Draws text aligned left (C-string)._  |
| virtual void | [**TextLeft**](classevab_1_1_screen_base.md#function-textleft-22) ([**Coor**](structevab_1_1_coor.md) aPosition, [**Coor**](structevab_1_1_coor.md) aSize, const \_\_FlashStringHelper \* text, unsigned char aColor) override<br>_Draws text aligned left (Flash string)._  |
| virtual void | [**TextRight**](classevab_1_1_screen_base.md#function-textright-12) ([**Coor**](structevab_1_1_coor.md) aPosition, [**Coor**](structevab_1_1_coor.md) aSize, const char \* text, unsigned char aColor) override<br>_Draws text aligned right (C-string)._  |
| virtual void | [**TextRight**](classevab_1_1_screen_base.md#function-textright-22) ([**Coor**](structevab_1_1_coor.md) aPosition, [**Coor**](structevab_1_1_coor.md) aSize, const \_\_FlashStringHelper \* text, unsigned char aColor) override<br>_Draws text aligned right (Flash string)._  |


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
| virtual void | [**ClearTile**](#function-cleartile) ([**Coor**](structevab_1_1_coor.md) aPosition, unsigned char aColor) override<br>_Clears a tile at the specified position._  |
| virtual void | [**DrawVerticalSlice**](#function-drawverticalslice) ([**Coor**](structevab_1_1_coor.md) aPosition, unsigned char aSliceColumn, unsigned char aSlice) override<br>_Draws a vertical slice at the specified position._  |
|  void | [**initDisplay**](#function-initdisplay) () <br>_Initializes the display._  |


## Protected Functions inherited from evab::ScreenPage8Base

See [evab::ScreenPage8Base](classevab_1_1_screen_page8_base.md)

| Type | Name |
| ---: | :--- |
| virtual void | [**DrawVerticalSlice**](classevab_1_1_screen_page8_base.md#function-drawverticalslice) ([**Coor**](structevab_1_1_coor.md) aPosition, unsigned char aSliceColumn, unsigned char aSlice) = 0<br>_Pure virtual method to draw a vertical slice._  |


## Protected Functions inherited from evab::ScreenBase

See [evab::ScreenBase](classevab_1_1_screen_base.md)

| Type | Name |
| ---: | :--- |
| virtual void | [**ClearTile**](classevab_1_1_screen_base.md#function-cleartile) ([**Coor**](structevab_1_1_coor.md) position, unsigned char aColor) <br>_Clears a single tile._  |












## Detailed Description


Supports 128x64 and 128x32 OLED displays with I2C interface. 


    
## Public Functions Documentation




### function Deserialize 

_Deserializes element state for 16x8 screen._ 
```C++
virtual void evab::ScreenSSD1306::Deserialize (
    unsigned short aSerialized,
    Coor & aPos,
    Coor & aSize,
    bool & isFocused
) 
```





**Parameters:**


* `aSerialized` Serialized state 
* `aPos` Position of the element (output) 
* `aSize` Size of the element (output) 
* `isFocused` Focus state (output) 




        
Implements [*evab::IScreen::Deserialize*](classevab_1_1_i_screen.md#function-deserialize)


<hr>



### function ScreenSSD1306 

_Constructor for SSD1306 screen driver._ 
```C++
evab::ScreenSSD1306::ScreenSSD1306 (
    const IFont * aFont,
    unsigned long aWireClock=800000L,
    uint8_t aHeightPx=64
) 
```





**Parameters:**


* `aFont` Font to use 
* `aWireClock` I2C clock speed (default 800000) 
* `aHeightPx` Display height in pixels (default 64) 




        

<hr>



### function Serialize 

_Serializes element state for 16x8 screen._ 
```C++
virtual unsigned short evab::ScreenSSD1306::Serialize (
    const Coor & aPos,
    const Coor & aSize,
    bool isFocused
) 
```





**Parameters:**


* `aPos` Position of the element 
* `aSize` Size of the element 
* `isFocused` Focus state 



**Returns:**

unsigned short Serialized state 





        
Implements [*evab::IScreen::Serialize*](classevab_1_1_i_screen.md#function-serialize)


<hr>



### function SetContrast 

_Sets display contrast._ 
```C++
void evab::ScreenSSD1306::SetContrast (
    uint8_t aContrast
) 
```





**Parameters:**


* `aContrast` Contrast value 




        

<hr>



### function Size 

_Gets the screen size in tiles._ 
```C++
virtual Coor evab::ScreenSSD1306::Size () override
```





**Returns:**

[**Coor**](structevab_1_1_coor.md) Screen dimensions (16 x pages) 





        
Implements [*evab::IScreen::Size*](classevab_1_1_i_screen.md#function-size)


<hr>



### function ~ScreenSSD1306 

```C++
evab::ScreenSSD1306::~ScreenSSD1306 () 
```




<hr>
## Protected Functions Documentation




### function ClearTile 

_Clears a tile at the specified position._ 
```C++
virtual void evab::ScreenSSD1306::ClearTile (
    Coor aPosition,
    unsigned char aColor
) override
```





**Parameters:**


* `aPosition` Position of the tile 
* `aColor` Fill color 




        
Implements [*evab::ScreenBase::ClearTile*](classevab_1_1_screen_base.md#function-cleartile)


<hr>



### function DrawVerticalSlice 

_Draws a vertical slice at the specified position._ 
```C++
virtual void evab::ScreenSSD1306::DrawVerticalSlice (
    Coor aPosition,
    unsigned char aSliceColumn,
    unsigned char aSlice
) override
```





**Parameters:**


* `aPosition` Position on screen 
* `aSliceColumn` Column within the tile (0-7) 
* `aSlice` Bitmap data for the slice 




        
Implements [*evab::ScreenPage8Base::DrawVerticalSlice*](classevab_1_1_screen_page8_base.md#function-drawverticalslice)


<hr>



### function initDisplay 

_Initializes the display._ 
```C++
void evab::ScreenSSD1306::initDisplay () 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `src/evabScreenSSD1306.h`

