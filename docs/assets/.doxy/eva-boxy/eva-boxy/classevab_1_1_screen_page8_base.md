

# Class evab::ScreenPage8Base



[**ClassList**](annotated.md) **>** [**evab**](namespaceevab.md) **>** [**ScreenPage8Base**](classevab_1_1_screen_page8_base.md)



_Base class for page-based 8-bit screens._ [More...](#detailed-description)

* `#include <evabScreenPage8Base.h>`



Inherits the following classes: [evab::ScreenBase](classevab_1_1_screen_base.md)


Inherited by the following classes: [evab::ScreenKS0108](classevab_1_1_screen_k_s0108.md),  [evab::ScreenPCD8544](classevab_1_1_screen_p_c_d8544.md),  [evab::ScreenSSD1306](classevab_1_1_screen_s_s_d1306.md),  [evab::ScreenSSH1106](classevab_1_1_screen_s_s_h1106.md),  [evab::ScreenSerialPixel](classevab_1_1_screen_serial_pixel.md)








































































## Public Functions

| Type | Name |
| ---: | :--- |
| virtual void | [**DrawSymbol**](#function-drawsymbol) ([**Coor**](structevab_1_1_coor.md) aPosition, [**Coor**](structevab_1_1_coor.md) aSize, char aCharcode, unsigned char aColor) <br>_Draws a symbol at the specified position with scaling._  |
| virtual void | [**Picto**](#function-picto) ([**Coor**](structevab_1_1_coor.md) aPosition, const unsigned char \* pictoData, unsigned char aColor) <br>_Draws a pictogram at the specified position._  |
|   | [**ScreenPage8Base**](#function-screenpage8base) (const [**IFont**](classevab_1_1_i_font.md) \* mFont) <br>_Constructor for page-based 8-bit screen base._  |


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
| virtual void | [**DrawVerticalSlice**](#function-drawverticalslice) ([**Coor**](structevab_1_1_coor.md) aPosition, unsigned char aSliceColumn, unsigned char aSlice) = 0<br>_Pure virtual method to draw a vertical slice._  |


## Protected Functions inherited from evab::ScreenBase

See [evab::ScreenBase](classevab_1_1_screen_base.md)

| Type | Name |
| ---: | :--- |
| virtual void | [**ClearTile**](classevab_1_1_screen_base.md#function-cleartile) ([**Coor**](structevab_1_1_coor.md) position, unsigned char aColor) <br>_Clears a single tile._  |










## Detailed Description


Provides common rendering for screens organized in 8-pixel pages. Used by SSD1306, KS0108, PCD8544, and similar displays. 


    
## Public Functions Documentation




### function DrawSymbol 

_Draws a symbol at the specified position with scaling._ 
```C++
virtual void evab::ScreenPage8Base::DrawSymbol (
    Coor aPosition,
    Coor aSize,
    char aCharcode,
    unsigned char aColor
) 
```





**Parameters:**


* `aPosition` Position on screen 
* `aSize` Size of the symbol 
* `aCharcode` Character code 
* `aColor` Color/inversion flag 




        
Implements [*evab::IScreen::DrawSymbol*](classevab_1_1_i_screen.md#function-drawsymbol)


<hr>



### function Picto 

_Draws a pictogram at the specified position._ 
```C++
virtual void evab::ScreenPage8Base::Picto (
    Coor aPosition,
    const unsigned char * pictoData,
    unsigned char aColor
) 
```





**Parameters:**


* `aPosition` Position on screen 
* `pictoData` Pictogram data 
* `aColor` Color/inversion flag 




        
Implements [*evab::ScreenBase::Picto*](classevab_1_1_screen_base.md#function-picto)


<hr>



### function ScreenPage8Base 

_Constructor for page-based 8-bit screen base._ 
```C++
evab::ScreenPage8Base::ScreenPage8Base (
    const IFont * mFont
) 
```





**Parameters:**


* `mFont` Font to use for rendering 




        

<hr>
## Protected Functions Documentation




### function DrawVerticalSlice 

_Pure virtual method to draw a vertical slice._ 
```C++
virtual void evab::ScreenPage8Base::DrawVerticalSlice (
    Coor aPosition,
    unsigned char aSliceColumn,
    unsigned char aSlice
) = 0
```





**Parameters:**


* `aPosition` Position on screen 
* `aSliceColumn` Column within the tile (0-7) 
* `aSlice` Bitmap data for the slice 




        

<hr>

------------------------------
The documentation for this class was generated from the following file `src/evabScreenPage8Base.h`

