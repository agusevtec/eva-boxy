

# Class evab::ScreenPCD8544



[**ClassList**](annotated.md) **>** [**evab**](namespaceevab.md) **>** [**ScreenPCD8544**](classevab_1_1_screen_p_c_d8544.md)



_PCD8544 screen driver (Nokia 5110 display)._ [More...](#detailed-description)

* `#include <evabScreenPCD8544.h>`



Inherits the following classes: [evab::ScreenPage8Base](classevab_1_1_screen_page8_base.md)










































































## Public Functions

| Type | Name |
| ---: | :--- |
| virtual void | [**Deserialize**](#function-deserialize) (unsigned short aSerialized, [**Coor**](structevab_1_1_coor.md) & aPos, [**Coor**](structevab_1_1_coor.md) & aSize, bool & isFocused) <br>_Deserializes element state for 16x8 screen._  |
|   | [**ScreenPCD8544**](#function-screenpcd8544) (const [**IFont**](classevab_1_1_i_font.md) \* aFont, uint8\_t aRST, uint8\_t aCE, uint8\_t aDC, uint8\_t aDIN, uint8\_t aCLK, uint8\_t aLED=255) <br>_Constructor for PCD8544 screen driver._  |
| virtual unsigned short | [**Serialize**](#function-serialize) (const [**Coor**](structevab_1_1_coor.md) & aPos, const [**Coor**](structevab_1_1_coor.md) & aSize, bool isFocused) <br>_Serializes element state for 16x8 screen._  |
|  void | [**SetBacklight**](#function-setbacklight) (uint8\_t aState) <br>_Sets backlight state._  |
|  void | [**SetContrast**](#function-setcontrast) (uint8\_t aContrast) <br>_Sets display contrast._  |
| virtual [**Coor**](structevab_1_1_coor.md) | [**Size**](#function-size) () override<br>_Gets the screen size in tiles._  |


## Public Functions inherited from evab::ScreenPage8Base

See [evab::ScreenPage8Base](classevab_1_1_screen_page8_base.md)

| Type | Name |
| ---: | :--- |
| virtual void | [**DrawSymbol**](classevab_1_1_screen_page8_base.md#function-drawsymbol) ([**Coor**](structevab_1_1_coor.md) aPosition, [**Coor**](structevab_1_1_coor.md) aSize, char aCharcode, unsigned char aColor) <br>_Draws a symbol at the specified position with scaling._  |
| virtual void | [**Picto**](classevab_1_1_screen_page8_base.md#function-picto) ([**Coor**](structevab_1_1_coor.md) aPosition, const unsigned char \* aPictogram, unsigned char aColor) <br>_Draws a pictogram at the specified position._  |
|   | [**ScreenPage8Base**](classevab_1_1_screen_page8_base.md#function-screenpage8base) (const [**IFont**](classevab_1_1_i_font.md) \* aFont) <br>_Constructor for page-based 8-bit screen base._  |


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


Supports 84x48 pixel displays with SPI interface. 


    
## Public Functions Documentation




### function Deserialize 

_Deserializes element state for 16x8 screen._ 
```C++
virtual void evab::ScreenPCD8544::Deserialize (
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




        
Implements [*evab::Screen::Deserialize*](classevab_1_1_screen.md#function-deserialize)


<hr>



### function ScreenPCD8544 

_Constructor for PCD8544 screen driver._ 
```C++
evab::ScreenPCD8544::ScreenPCD8544 (
    const IFont * aFont,
    uint8_t aRST,
    uint8_t aCE,
    uint8_t aDC,
    uint8_t aDIN,
    uint8_t aCLK,
    uint8_t aLED=255
) 
```





**Parameters:**


* `aFont` Font to use 
* `aRST` Reset pin 
* `aCE` Chip enable pin 
* `aDC` Data/Command pin 
* `aDIN` Data in pin (MOSI) 
* `aCLK` Clock pin (SCLK) 
* `aLED` Backlight pin (255 = none) 




        

<hr>



### function Serialize 

_Serializes element state for 16x8 screen._ 
```C++
virtual unsigned short evab::ScreenPCD8544::Serialize (
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





        
Implements [*evab::Screen::Serialize*](classevab_1_1_screen.md#function-serialize)


<hr>



### function SetBacklight 

_Sets backlight state._ 
```C++
void evab::ScreenPCD8544::SetBacklight (
    uint8_t aState
) 
```





**Parameters:**


* `aState` 1 = on, 0 = off 




        

<hr>



### function SetContrast 

_Sets display contrast._ 
```C++
void evab::ScreenPCD8544::SetContrast (
    uint8_t aContrast
) 
```





**Parameters:**


* `aContrast` Contrast value (0-127) 




        

<hr>



### function Size 

_Gets the screen size in tiles._ 
```C++
inline virtual Coor evab::ScreenPCD8544::Size () override
```





**Returns:**

[**Coor**](structevab_1_1_coor.md) [**Screen**](classevab_1_1_screen.md) dimensions (11x6 tiles) 





        
Implements [*evab::Screen::Size*](classevab_1_1_screen.md#function-size)


<hr>

------------------------------
The documentation for this class was generated from the following file `src/evabScreenPCD8544.h`

