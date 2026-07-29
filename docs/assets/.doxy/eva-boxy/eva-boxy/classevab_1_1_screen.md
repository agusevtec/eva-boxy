

# Class evab::Screen



[**ClassList**](annotated.md) **>** [**evab**](namespaceevab.md) **>** [**Screen**](classevab_1_1_screen.md)



_Base class for screen implementations._ [More...](#detailed-description)

* `#include <evabScreen.h>`





Inherited by the following classes: [evab::ScreenLCD\_I2C](classevab_1_1_screen_l_c_d___i2_c.md),  [evab::ScreenPage8Base](classevab_1_1_screen_page8_base.md),  [evab::ScreenSerialText](classevab_1_1_screen_serial_text.md)
































## Public Functions

| Type | Name |
| ---: | :--- |
| virtual void | [**Clear**](#function-clear) ([**Coor**](structevab_1_1_coor.md) aPosition, [**Coor**](structevab_1_1_coor.md) aSize, unsigned char aColor=0) <br> |
| virtual void | [**Deserialize**](#function-deserialize) (unsigned short aSerialized, [**Coor**](structevab_1_1_coor.md) & aPosition, [**Coor**](structevab_1_1_coor.md) & aSize, bool & isFocused) = 0<br> |
| virtual void | [**DrawSymbol**](#function-drawsymbol) ([**Coor**](structevab_1_1_coor.md) aPosition, [**Coor**](structevab_1_1_coor.md) aSize, char aSymbol, unsigned char aColor=0) = 0<br> |
| virtual void | [**Picto**](#function-picto) ([**Coor**](structevab_1_1_coor.md) aPosition, const unsigned char \* aPictogram, unsigned char aColor=0) <br> |
| virtual unsigned short | [**Serialize**](#function-serialize) (const [**Coor**](structevab_1_1_coor.md) & aPosition, const [**Coor**](structevab_1_1_coor.md) & aSize, bool isFocused) = 0<br> |
| virtual [**Coor**](structevab_1_1_coor.md) | [**Size**](#function-size) () = 0<br> |
|  void | [**Text**](#function-text) ([**Coor**](structevab_1_1_coor.md) aPosition, [**Coor**](structevab_1_1_coor.md) aSize, TText aText, unsigned char aColor=0) <br>_Draws text with specified alignment strategy._  |
|  void | [**TextCenter**](#function-textcenter) ([**Coor**](structevab_1_1_coor.md) aPosition, [**Coor**](structevab_1_1_coor.md) aSize, T aText, unsigned char aColor=0) <br> |
|  void | [**TextLeft**](#function-textleft) ([**Coor**](structevab_1_1_coor.md) aPosition, [**Coor**](structevab_1_1_coor.md) aSize, T aText, unsigned char aColor=0) <br> |
|  void | [**TextRight**](#function-textright) ([**Coor**](structevab_1_1_coor.md) aPosition, [**Coor**](structevab_1_1_coor.md) aSize, T aText, unsigned char aColor=0) <br> |




























## Detailed Description


Provides low-level drawing operations and text rendering with alignment. 


    
## Public Functions Documentation




### function Clear 

```C++
virtual void evab::Screen::Clear (
    Coor aPosition,
    Coor aSize,
    unsigned char aColor=0
) 
```




<hr>



### function Deserialize 

```C++
virtual void evab::Screen::Deserialize (
    unsigned short aSerialized,
    Coor & aPosition,
    Coor & aSize,
    bool & isFocused
) = 0
```




<hr>



### function DrawSymbol 

```C++
virtual void evab::Screen::DrawSymbol (
    Coor aPosition,
    Coor aSize,
    char aSymbol,
    unsigned char aColor=0
) = 0
```




<hr>



### function Picto 

```C++
virtual void evab::Screen::Picto (
    Coor aPosition,
    const unsigned char * aPictogram,
    unsigned char aColor=0
) 
```




<hr>



### function Serialize 

```C++
virtual unsigned short evab::Screen::Serialize (
    const Coor & aPosition,
    const Coor & aSize,
    bool isFocused
) = 0
```




<hr>



### function Size 

```C++
virtual Coor evab::Screen::Size () = 0
```




<hr>



### function Text 

_Draws text with specified alignment strategy._ 
```C++
template<typename TAlign, typename TText>
inline void evab::Screen::Text (
    Coor aPosition,
    Coor aSize,
    TText aText,
    unsigned char aColor=0
) 
```





**Template parameters:**


* `TAlign` Alignment strategy ([**LeftAlign**](structevab_1_1_left_align.md), [**CenterAlign**](structevab_1_1_center_align.md), [**RightAlign**](structevab_1_1_right_align.md)) 
* `TText` Text type (char\*, const char\*, \_\_FlashStringHelper\*) 



**Parameters:**


* `aPosition` Position on screen 
* `aSize` Available area size 
* `aText` Text to draw 
* `aColor` Color/inversion flag 




        

<hr>



### function TextCenter 

```C++
template<typename T>
inline void evab::Screen::TextCenter (
    Coor aPosition,
    Coor aSize,
    T aText,
    unsigned char aColor=0
) 
```




<hr>



### function TextLeft 

```C++
template<typename T>
inline void evab::Screen::TextLeft (
    Coor aPosition,
    Coor aSize,
    T aText,
    unsigned char aColor=0
) 
```




<hr>



### function TextRight 

```C++
template<typename T>
inline void evab::Screen::TextRight (
    Coor aPosition,
    Coor aSize,
    T aText,
    unsigned char aColor=0
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `src/evabScreen.h`

