

# Class evab::IScreen



[**ClassList**](annotated.md) **>** [**evab**](namespaceevab.md) **>** [**IScreen**](classevab_1_1_i_screen.md)



_Abstract interface for screen rendering._ [More...](#detailed-description)

* `#include <evabIScreen.h>`





Inherited by the following classes: [evab::ScreenBase](classevab_1_1_screen_base.md)
































## Public Functions

| Type | Name |
| ---: | :--- |
| virtual void | [**Clear**](#function-clear) ([**Coor**](structevab_1_1_coor.md) aPosition, [**Coor**](structevab_1_1_coor.md) aSize, unsigned char aColor=0) = 0<br>_Clears a rectangular area on screen._  |
| virtual void | [**Deserialize**](#function-deserialize) (unsigned short aSerialized, [**Coor**](structevab_1_1_coor.md) & aPos, [**Coor**](structevab_1_1_coor.md) & aSize, bool & isFocused) = 0<br>_Deserializes element state from 16-bit value._  |
| virtual void | [**DrawSymbol**](#function-drawsymbol) ([**Coor**](structevab_1_1_coor.md) aPosition, [**Coor**](structevab_1_1_coor.md) aSize, char aSymbol, unsigned char aColor) = 0<br>_Draws a single character symbol._  |
| virtual void | [**Picto**](#function-picto) ([**Coor**](structevab_1_1_coor.md) aPosition, const unsigned char \* pictoData, unsigned char aColor) = 0<br>_Draws a pictogram at the specified position._  |
| virtual unsigned short | [**Serialize**](#function-serialize) (const [**Coor**](structevab_1_1_coor.md) & aPos, const [**Coor**](structevab_1_1_coor.md) & aSize, bool isFocused) = 0<br>_Serializes element state into 16-bit value._  |
| virtual [**Coor**](structevab_1_1_coor.md) | [**Size**](#function-size) () = 0<br>_Gets the screen size in tiles._  |
| virtual void | [**TextCenter**](#function-textcenter-12) ([**Coor**](structevab_1_1_coor.md) aPosition, [**Coor**](structevab_1_1_coor.md) aSize, const char \* text, unsigned char aColor) = 0<br>_Draws text aligned to the center._  |
| virtual void | [**TextCenter**](#function-textcenter-22) ([**Coor**](structevab_1_1_coor.md) aPosition, [**Coor**](structevab_1_1_coor.md) aSize, const \_\_FlashStringHelper \* text, unsigned char aColor) = 0<br>_Draws flash string text aligned to the center._  |
| virtual void | [**TextLeft**](#function-textleft-12) ([**Coor**](structevab_1_1_coor.md) aPosition, [**Coor**](structevab_1_1_coor.md) aSize, const char \* text, unsigned char aColor) = 0<br>_Draws text aligned to the left._  |
| virtual void | [**TextLeft**](#function-textleft-22) ([**Coor**](structevab_1_1_coor.md) aPosition, [**Coor**](structevab_1_1_coor.md) aSize, const \_\_FlashStringHelper \* text, unsigned char aColor) = 0<br>_Draws flash string text aligned to the left._  |
| virtual void | [**TextRight**](#function-textright-12) ([**Coor**](structevab_1_1_coor.md) aPosition, [**Coor**](structevab_1_1_coor.md) aSize, const char \* text, unsigned char aColor) = 0<br>_Draws text aligned to the right._  |
| virtual void | [**TextRight**](#function-textright-22) ([**Coor**](structevab_1_1_coor.md) aPosition, [**Coor**](structevab_1_1_coor.md) aSize, const \_\_FlashStringHelper \* text, unsigned char aColor) = 0<br>_Draws flash string text aligned to the right._  |




























## Detailed Description


Defines the contract for display implementations, supporting text, pictograms, and state serialization. 


    
## Public Functions Documentation




### function Clear 

_Clears a rectangular area on screen._ 
```C++
virtual void evab::IScreen::Clear (
    Coor aPosition,
    Coor aSize,
    unsigned char aColor=0
) = 0
```





**Parameters:**


* `aPosition` Position of the area 
* `aSize` Size of the area 
* `aColor` Fill color (0 = clear, 1 = fill) 




        

<hr>



### function Deserialize 

_Deserializes element state from 16-bit value._ 
```C++
virtual void evab::IScreen::Deserialize (
    unsigned short aSerialized,
    Coor & aPos,
    Coor & aSize,
    bool & isFocused
) = 0
```





**Parameters:**


* `aSerialized` Serialized state 
* `aPos` Position of the element (output) 
* `aSize` Size of the element (output) 
* `isFocused` Focus state (output) 




        

<hr>



### function DrawSymbol 

_Draws a single character symbol._ 
```C++
virtual void evab::IScreen::DrawSymbol (
    Coor aPosition,
    Coor aSize,
    char aSymbol,
    unsigned char aColor
) = 0
```





**Parameters:**


* `aPosition` Position on screen 
* `aSize` Size of the symbol 
* `aSymbol` Character to draw 
* `aColor` Color/inversion flag (0 = normal, 1 = inverted) 




        

<hr>



### function Picto 

_Draws a pictogram at the specified position._ 
```C++
virtual void evab::IScreen::Picto (
    Coor aPosition,
    const unsigned char * pictoData,
    unsigned char aColor
) = 0
```





**Parameters:**


* `aPosition` Position on screen 
* `pictoData` Pictogram data (first two bytes: width/height in tiles) 
* `aColor` Color/inversion flag (0 = normal, 1 = inverted) 




        

<hr>



### function Serialize 

_Serializes element state into 16-bit value._ 
```C++
virtual unsigned short evab::IScreen::Serialize (
    const Coor & aPos,
    const Coor & aSize,
    bool isFocused
) = 0
```





**Parameters:**


* `aPos` Position of the element 
* `aSize` Size of the element 
* `isFocused` Focus state 



**Returns:**

unsigned short Serialized state 





        

<hr>



### function Size 

_Gets the screen size in tiles._ 
```C++
virtual Coor evab::IScreen::Size () = 0
```





**Returns:**

[**Coor**](structevab_1_1_coor.md) Screen dimensions in tiles (X, Y) 





        

<hr>



### function TextCenter [1/2]

_Draws text aligned to the center._ 
```C++
virtual void evab::IScreen::TextCenter (
    Coor aPosition,
    Coor aSize,
    const char * text,
    unsigned char aColor
) = 0
```





**Parameters:**


* `aPosition` Position on screen 
* `aSize` Size of the text area 
* `text` Null-terminated string 
* `aColor` Color/inversion flag (0 = normal, 1 = inverted) 




        

<hr>



### function TextCenter [2/2]

_Draws flash string text aligned to the center._ 
```C++
virtual void evab::IScreen::TextCenter (
    Coor aPosition,
    Coor aSize,
    const __FlashStringHelper * text,
    unsigned char aColor
) = 0
```





**Parameters:**


* `aPosition` Position on screen 
* `aSize` Size of the text area 
* `text` Flash string (PROGMEM) 
* `aColor` Color/inversion flag (0 = normal, 1 = inverted) 




        

<hr>



### function TextLeft [1/2]

_Draws text aligned to the left._ 
```C++
virtual void evab::IScreen::TextLeft (
    Coor aPosition,
    Coor aSize,
    const char * text,
    unsigned char aColor
) = 0
```





**Parameters:**


* `aPosition` Position on screen 
* `aSize` Size of the text area 
* `text` Null-terminated string 
* `aColor` Color/inversion flag (0 = normal, 1 = inverted) 




        

<hr>



### function TextLeft [2/2]

_Draws flash string text aligned to the left._ 
```C++
virtual void evab::IScreen::TextLeft (
    Coor aPosition,
    Coor aSize,
    const __FlashStringHelper * text,
    unsigned char aColor
) = 0
```





**Parameters:**


* `aPosition` Position on screen 
* `aSize` Size of the text area 
* `text` Flash string (PROGMEM) 
* `aColor` Color/inversion flag (0 = normal, 1 = inverted) 




        

<hr>



### function TextRight [1/2]

_Draws text aligned to the right._ 
```C++
virtual void evab::IScreen::TextRight (
    Coor aPosition,
    Coor aSize,
    const char * text,
    unsigned char aColor
) = 0
```





**Parameters:**


* `aPosition` Position on screen 
* `aSize` Size of the text area 
* `text` Null-terminated string 
* `aColor` Color/inversion flag (0 = normal, 1 = inverted) 




        

<hr>



### function TextRight [2/2]

_Draws flash string text aligned to the right._ 
```C++
virtual void evab::IScreen::TextRight (
    Coor aPosition,
    Coor aSize,
    const __FlashStringHelper * text,
    unsigned char aColor
) = 0
```





**Parameters:**


* `aPosition` Position on screen 
* `aSize` Size of the text area 
* `text` Flash string (PROGMEM) 
* `aColor` Color/inversion flag (0 = normal, 1 = inverted) 




        

<hr>

------------------------------
The documentation for this class was generated from the following file `src/evabIScreen.h`

