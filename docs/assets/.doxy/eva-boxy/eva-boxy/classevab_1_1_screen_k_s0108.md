

# Class evab::ScreenKS0108



[**ClassList**](annotated.md) **>** [**evab**](namespaceevab.md) **>** [**ScreenKS0108**](classevab_1_1_screen_k_s0108.md)



_KS0108-based GLCD screen driver._ [More...](#detailed-description)

* `#include <evabScreenKS0108.h>`



Inherits the following classes: [evab::ScreenPage8Base](classevab_1_1_screen_page8_base.md)










































































## Public Functions

| Type | Name |
| ---: | :--- |
| virtual void | [**Deserialize**](#function-deserialize) (unsigned short aSerialized, [**Coor**](structevab_1_1_coor.md) & aPos, [**Coor**](structevab_1_1_coor.md) & aSize, bool & isFocused) <br>_Deserializes element state for 16x8 screen._  |
|   | [**ScreenKS0108**](#function-screenks0108) (const [**IFont**](classevab_1_1_i_font.md) \* aFont, uint8\_t aRS, uint8\_t aRW, uint8\_t aE, uint8\_t aCS1, uint8\_t aCS2, uint8\_t aDB0, uint8\_t aDB1, uint8\_t aDB2, uint8\_t aDB3, uint8\_t aDB4, uint8\_t aDB5, uint8\_t aDB6, uint8\_t aDB7, uint8\_t aLED=255) <br>_Constructor for KS0108 screen driver._  |
| virtual unsigned short | [**Serialize**](#function-serialize) (const [**Coor**](structevab_1_1_coor.md) & aPos, const [**Coor**](structevab_1_1_coor.md) & aSize, bool isFocused) <br>_Serializes element state for 16x8 screen._  |
|  void | [**SetBacklight**](#function-setbacklight) (uint8\_t aState) <br>_Sets backlight state._  |
| virtual [**Coor**](structevab_1_1_coor.md) | [**Size**](#function-size) () override<br>_Gets the screen size in tiles._  |
|  void | [**clearDisplay**](#function-cleardisplay) () <br>_Clears the entire display._  |
|   | [**~ScreenKS0108**](#function-screenks0108) () <br> |


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


Supports 128x64 pixel displays with two KS0108 chips. 


    
## Public Functions Documentation




### function Deserialize 

_Deserializes element state for 16x8 screen._ 
```C++
virtual void evab::ScreenKS0108::Deserialize (
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



### function ScreenKS0108 

_Constructor for KS0108 screen driver._ 
```C++
evab::ScreenKS0108::ScreenKS0108 (
    const IFont * aFont,
    uint8_t aRS,
    uint8_t aRW,
    uint8_t aE,
    uint8_t aCS1,
    uint8_t aCS2,
    uint8_t aDB0,
    uint8_t aDB1,
    uint8_t aDB2,
    uint8_t aDB3,
    uint8_t aDB4,
    uint8_t aDB5,
    uint8_t aDB6,
    uint8_t aDB7,
    uint8_t aLED=255
) 
```





**Parameters:**


* `aFont` Font to use 
* `aRS` Register select pin 
* `aRW` Read/Write pin 
* `aE` Enable pin 
* `aCS1` Chip select 1 pin 
* `aCS2` Chip select 2 pin 
* `aDB0-DB7` Data bus pins 
* `aLED` Backlight pin (255 = none) 




        

<hr>



### function Serialize 

_Serializes element state for 16x8 screen._ 
```C++
virtual unsigned short evab::ScreenKS0108::Serialize (
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
void evab::ScreenKS0108::SetBacklight (
    uint8_t aState
) 
```





**Parameters:**


* `aState` 1 = on, 0 = off 




        

<hr>



### function Size 

_Gets the screen size in tiles._ 
```C++
virtual Coor evab::ScreenKS0108::Size () override
```





**Returns:**

[**Coor**](structevab_1_1_coor.md) [**Screen**](classevab_1_1_screen.md) dimensions (16x8 tiles) 





        
Implements [*evab::Screen::Size*](classevab_1_1_screen.md#function-size)


<hr>



### function clearDisplay 

_Clears the entire display._ 
```C++
void evab::ScreenKS0108::clearDisplay () 
```




<hr>



### function ~ScreenKS0108 

```C++
evab::ScreenKS0108::~ScreenKS0108 () 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `src/evabScreenKS0108.h`

