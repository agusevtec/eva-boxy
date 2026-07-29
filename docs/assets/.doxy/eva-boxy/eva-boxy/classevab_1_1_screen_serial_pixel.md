

# Class evab::ScreenSerialPixel



[**ClassList**](annotated.md) **>** [**evab**](namespaceevab.md) **>** [**ScreenSerialPixel**](classevab_1_1_screen_serial_pixel.md)



_Debug screen that renders pixels to serial output._ [More...](#detailed-description)

* `#include <evabScreenSerialPixel.h>`



Inherits the following classes: [evab::ScreenPage8Base](classevab_1_1_screen_page8_base.md)










































































## Public Functions

| Type | Name |
| ---: | :--- |
| virtual void | [**Deserialize**](#function-deserialize) (unsigned short aSerialized, [**Coor**](structevab_1_1_coor.md) & aPos, [**Coor**](structevab_1_1_coor.md) & aSize, bool & isFocused) <br>_Deserializes element state for 16x8 screen._  |
|  void | [**PrintToSerial**](#function-printtoserial) () <br>_Prints the pixel buffer to serial for debugging._  |
|   | [**ScreenSerialPixel**](#function-screenserialpixel) ([**IFont**](classevab_1_1_i_font.md) \* aFont) <br>_Constructor for serial pixel screen._  |
| virtual unsigned short | [**Serialize**](#function-serialize) (const [**Coor**](structevab_1_1_coor.md) & aPos, const [**Coor**](structevab_1_1_coor.md) & aSize, bool isFocused) <br>_Serializes element state for 16x8 screen._  |
| virtual [**Coor**](structevab_1_1_coor.md) | [**Size**](#function-size) () override<br>_Gets the screen size in tiles._  |
|  void | [**clear**](#function-clear) () <br>_Clears the pixel buffer._  |


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


Used for debugging UI layout without physical hardware. 


    
## Public Functions Documentation




### function Deserialize 

_Deserializes element state for 16x8 screen._ 
```C++
virtual void evab::ScreenSerialPixel::Deserialize (
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



### function PrintToSerial 

_Prints the pixel buffer to serial for debugging._ 
```C++
void evab::ScreenSerialPixel::PrintToSerial () 
```




<hr>



### function ScreenSerialPixel 

_Constructor for serial pixel screen._ 
```C++
evab::ScreenSerialPixel::ScreenSerialPixel (
    IFont * aFont
) 
```





**Parameters:**


* `aFont` Font to use 




        

<hr>



### function Serialize 

_Serializes element state for 16x8 screen._ 
```C++
virtual unsigned short evab::ScreenSerialPixel::Serialize (
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



### function Size 

_Gets the screen size in tiles._ 
```C++
virtual Coor evab::ScreenSerialPixel::Size () override
```





**Returns:**

[**Coor**](structevab_1_1_coor.md) [**Screen**](classevab_1_1_screen.md) dimensions (16x8 tiles) 





        
Implements [*evab::Screen::Size*](classevab_1_1_screen.md#function-size)


<hr>



### function clear 

_Clears the pixel buffer._ 
```C++
void evab::ScreenSerialPixel::clear () 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `src/evabScreenSerialPixel.h`

