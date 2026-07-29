

# Class evab::ScreenPage8Base



[**ClassList**](annotated.md) **>** [**evab**](namespaceevab.md) **>** [**ScreenPage8Base**](classevab_1_1_screen_page8_base.md)



_Base class for page-based 8-bit screens._ [More...](#detailed-description)

* `#include <evabScreenPage8Base.h>`



Inherits the following classes: [evab::Screen](classevab_1_1_screen.md)


Inherited by the following classes: [evab::ScreenKS0108](classevab_1_1_screen_k_s0108.md),  [evab::ScreenPCD8544](classevab_1_1_screen_p_c_d8544.md),  [evab::ScreenSSD1306](classevab_1_1_screen_s_s_d1306.md),  [evab::ScreenSSH1106](classevab_1_1_screen_s_s_h1106.md),  [evab::ScreenSerialPixel](classevab_1_1_screen_serial_pixel.md)




















































## Public Functions

| Type | Name |
| ---: | :--- |
| virtual void | [**DrawSymbol**](#function-drawsymbol) ([**Coor**](structevab_1_1_coor.md) aPosition, [**Coor**](structevab_1_1_coor.md) aSize, char aCharcode, unsigned char aColor) <br>_Draws a symbol at the specified position with scaling._  |
| virtual void | [**Picto**](#function-picto) ([**Coor**](structevab_1_1_coor.md) aPosition, const unsigned char \* aPictogram, unsigned char aColor) <br>_Draws a pictogram at the specified position._  |
|   | [**ScreenPage8Base**](#function-screenpage8base) (const [**IFont**](classevab_1_1_i_font.md) \* aFont) <br>_Constructor for page-based 8-bit screen base._  |


## Public Functions inherited from evab::Screen

See [evab::Screen](classevab_1_1_screen.md)

| Type | Name |
| ---: | :--- |
| virtual void | [**Clear**](classevab_1_1_screen.md#function-clear) ([**Coor**](structevab_1_1_coor.md) aPosition, [**Coor**](structevab_1_1_coor.md) aSize, unsigned char aColor=0) <br> |
| virtual void | [**Deserialize**](classevab_1_1_screen.md#function-deserialize) (unsigned short aSerialized, [**Coor**](structevab_1_1_coor.md) & aPosition, [**Coor**](structevab_1_1_coor.md) & aSize, bool & isFocused) = 0<br> |
| virtual void | [**DrawSymbol**](classevab_1_1_screen.md#function-drawsymbol) ([**Coor**](structevab_1_1_coor.md) aPosition, [**Coor**](structevab_1_1_coor.md) aSize, char aSymbol, unsigned char aColor=0) = 0<br> |
| virtual void | [**Picto**](classevab_1_1_screen.md#function-picto) ([**Coor**](structevab_1_1_coor.md) aPosition, const unsigned char \* aPictogram, unsigned char aColor=0) <br> |
| virtual unsigned short | [**Serialize**](classevab_1_1_screen.md#function-serialize) (const [**Coor**](structevab_1_1_coor.md) & aPosition, const [**Coor**](structevab_1_1_coor.md) & aSize, bool isFocused) = 0<br> |
| virtual [**Coor**](structevab_1_1_coor.md) | [**Size**](classevab_1_1_screen.md#function-size) () = 0<br> |
|  void | [**Text**](classevab_1_1_screen.md#function-text) ([**Coor**](structevab_1_1_coor.md) aPosition, [**Coor**](structevab_1_1_coor.md) aSize, TText aText, unsigned char aColor=0) <br>_Draws text with specified alignment strategy._  |
|  void | [**TextCenter**](classevab_1_1_screen.md#function-textcenter) ([**Coor**](structevab_1_1_coor.md) aPosition, [**Coor**](structevab_1_1_coor.md) aSize, T aText, unsigned char aColor=0) <br> |
|  void | [**TextLeft**](classevab_1_1_screen.md#function-textleft) ([**Coor**](structevab_1_1_coor.md) aPosition, [**Coor**](structevab_1_1_coor.md) aSize, T aText, unsigned char aColor=0) <br> |
|  void | [**TextRight**](classevab_1_1_screen.md#function-textright) ([**Coor**](structevab_1_1_coor.md) aPosition, [**Coor**](structevab_1_1_coor.md) aSize, T aText, unsigned char aColor=0) <br> |






















































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




        
Implements [*evab::Screen::DrawSymbol*](classevab_1_1_screen.md#function-drawsymbol)


<hr>



### function Picto 

_Draws a pictogram at the specified position._ 
```C++
virtual void evab::ScreenPage8Base::Picto (
    Coor aPosition,
    const unsigned char * aPictogram,
    unsigned char aColor
) 
```





**Parameters:**


* `aPosition` Position on screen 
* `aPictogram` Pictogram data 
* `aColor` Color/inversion flag 




        
Implements [*evab::Screen::Picto*](classevab_1_1_screen.md#function-picto)


<hr>



### function ScreenPage8Base 

_Constructor for page-based 8-bit screen base._ 
```C++
evab::ScreenPage8Base::ScreenPage8Base (
    const IFont * aFont
) 
```





**Parameters:**


* `mFont` Font to use for rendering 




        

<hr>

------------------------------
The documentation for this class was generated from the following file `src/evabScreenPage8Base.h`

