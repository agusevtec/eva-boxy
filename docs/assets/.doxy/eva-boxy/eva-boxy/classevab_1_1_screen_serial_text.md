

# Class evab::ScreenSerialText



[**ClassList**](annotated.md) **>** [**evab**](namespaceevab.md) **>** [**ScreenSerialText**](classevab_1_1_screen_serial_text.md)



_Debug screen that renders text to serial output._ [More...](#detailed-description)

* `#include <evabScreenSerialText.h>`



Inherits the following classes: [evab::Screen](classevab_1_1_screen.md)






















































## Public Functions

| Type | Name |
| ---: | :--- |
|  void | [**Clear**](#function-clear) () <br>_Clears the text buffer._  |
| virtual void | [**Deserialize**](#function-deserialize) (unsigned short aSerialized, [**Coor**](structevab_1_1_coor.md) & aPos, [**Coor**](structevab_1_1_coor.md) & aSize, bool & isFocused) <br>_Deserializes element state for 16x8 screen._  |
| virtual void | [**DrawSymbol**](#function-drawsymbol) ([**Coor**](structevab_1_1_coor.md) aPosition, [**Coor**](structevab_1_1_coor.md) aSize, char aCharcode, unsigned char aColor) override<br>_Draws a symbol in the text buffer._  |
|  void | [**PrintToSerial**](#function-printtoserial) () <br>_Prints the text buffer to serial for debugging._  |
|   | [**ScreenSerialText**](#function-screenserialtext) () <br>_Constructor for serial text screen._  |
| virtual unsigned short | [**Serialize**](#function-serialize) (const [**Coor**](structevab_1_1_coor.md) & aPos, const [**Coor**](structevab_1_1_coor.md) & aSize, bool isFocused) <br>_Serializes element state for 16x8 screen._  |
| virtual [**Coor**](structevab_1_1_coor.md) | [**Size**](#function-size) () override<br>_Gets the screen size in characters._  |


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


Used for debugging UI layout without physical hardware. Displays characters in a 16x8 grid. 


    
## Public Functions Documentation




### function Clear 

_Clears the text buffer._ 
```C++
void evab::ScreenSerialText::Clear () 
```




<hr>



### function Deserialize 

_Deserializes element state for 16x8 screen._ 
```C++
virtual void evab::ScreenSerialText::Deserialize (
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



### function DrawSymbol 

_Draws a symbol in the text buffer._ 
```C++
virtual void evab::ScreenSerialText::DrawSymbol (
    Coor aPosition,
    Coor aSize,
    char aCharcode,
    unsigned char aColor
) override
```





**Parameters:**


* `aPosition` Position on screen 
* `aSize` Size of the symbol 
* `aCharcode` Character code 
* `aColor` Color/inversion flag 




        
Implements [*evab::Screen::DrawSymbol*](classevab_1_1_screen.md#function-drawsymbol)


<hr>



### function PrintToSerial 

_Prints the text buffer to serial for debugging._ 
```C++
void evab::ScreenSerialText::PrintToSerial () 
```




<hr>



### function ScreenSerialText 

_Constructor for serial text screen._ 
```C++
evab::ScreenSerialText::ScreenSerialText () 
```




<hr>



### function Serialize 

_Serializes element state for 16x8 screen._ 
```C++
virtual unsigned short evab::ScreenSerialText::Serialize (
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

_Gets the screen size in characters._ 
```C++
virtual Coor evab::ScreenSerialText::Size () override
```





**Returns:**

[**Coor**](structevab_1_1_coor.md) [**Screen**](classevab_1_1_screen.md) dimensions (16x8 chars) 





        
Implements [*evab::Screen::Size*](classevab_1_1_screen.md#function-size)


<hr>

------------------------------
The documentation for this class was generated from the following file `src/evabScreenSerialText.h`

