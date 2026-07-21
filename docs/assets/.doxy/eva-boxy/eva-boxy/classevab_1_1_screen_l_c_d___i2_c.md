

# Class evab::ScreenLCD\_I2C



[**ClassList**](annotated.md) **>** [**evab**](namespaceevab.md) **>** [**ScreenLCD\_I2C**](classevab_1_1_screen_l_c_d___i2_c.md)



_I2C LCD screen driver (HD44780 with PCF8574 I2C expander)._ [More...](#detailed-description)

* `#include <evabScreenLCD_I2C.h>`



Inherits the following classes: [evab::ScreenBase](classevab_1_1_screen_base.md)










































































## Public Functions

| Type | Name |
| ---: | :--- |
| virtual void | [**Deserialize**](#function-deserialize) (unsigned short aSerialized, [**Coor**](structevab_1_1_coor.md) & aPos, [**Coor**](structevab_1_1_coor.md) & aSize, bool & isFocused) <br>_Deserializes element state for 32x4 screen._  |
|   | [**ScreenLCD\_I2C**](#function-screenlcd_i2c) (uint8\_t aAddress, uint8\_t aCols, uint8\_t aRows, uint8\_t aBacklightPin) <br>_Constructor for I2C LCD screen driver._  |
| virtual unsigned short | [**Serialize**](#function-serialize) (const [**Coor**](structevab_1_1_coor.md) & aPos, const [**Coor**](structevab_1_1_coor.md) & aSize, bool isFocused) <br>_Serializes element state for 32x4 screen._  |
|  void | [**SetBacklight**](#function-setbacklight) (uint8\_t aState) <br>_Sets backlight state._  |
| virtual [**Coor**](structevab_1_1_coor.md) | [**Size**](#function-size) () override<br>_Gets the screen size._  |


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
| virtual void | [**DrawSymbol**](#function-drawsymbol) ([**Coor**](structevab_1_1_coor.md) aPosition, [**Coor**](structevab_1_1_coor.md) aSize, char aCharcode, unsigned char aColor) override<br>_Draws a symbol at the specified position._  |


## Protected Functions inherited from evab::ScreenBase

See [evab::ScreenBase](classevab_1_1_screen_base.md)

| Type | Name |
| ---: | :--- |
| virtual void | [**ClearTile**](classevab_1_1_screen_base.md#function-cleartile) ([**Coor**](structevab_1_1_coor.md) position, unsigned char aColor) <br>_Clears a single tile._  |










## Detailed Description


Supports standard 16x2, 20x4 LCD displays with I2C backpack. 


    
## Public Functions Documentation




### function Deserialize 

_Deserializes element state for 32x4 screen._ 
```C++
virtual void evab::ScreenLCD_I2C::Deserialize (
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



### function ScreenLCD\_I2C 

_Constructor for I2C LCD screen driver._ 
```C++
evab::ScreenLCD_I2C::ScreenLCD_I2C (
    uint8_t aAddress,
    uint8_t aCols,
    uint8_t aRows,
    uint8_t aBacklightPin
) 
```





**Parameters:**


* `aAddress` I2C address 
* `aCols` Number of columns 
* `aRows` Number of rows 
* `aBacklightPin` Backlight pin in the PCF8574 expander 




        

<hr>



### function Serialize 

_Serializes element state for 32x4 screen._ 
```C++
virtual unsigned short evab::ScreenLCD_I2C::Serialize (
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



### function SetBacklight 

_Sets backlight state._ 
```C++
void evab::ScreenLCD_I2C::SetBacklight (
    uint8_t aState
) 
```





**Parameters:**


* `aState` 1 = on, 0 = off 




        

<hr>



### function Size 

_Gets the screen size._ 
```C++
inline virtual Coor evab::ScreenLCD_I2C::Size () override
```





**Returns:**

[**Coor**](structevab_1_1_coor.md) Screen dimensions (cols, rows) 





        
Implements [*evab::IScreen::Size*](classevab_1_1_i_screen.md#function-size)


<hr>
## Protected Functions Documentation




### function DrawSymbol 

_Draws a symbol at the specified position._ 
```C++
virtual void evab::ScreenLCD_I2C::DrawSymbol (
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




        
Implements [*evab::IScreen::DrawSymbol*](classevab_1_1_i_screen.md#function-drawsymbol)


<hr>

------------------------------
The documentation for this class was generated from the following file `src/evabScreenLCD_I2C.h`

