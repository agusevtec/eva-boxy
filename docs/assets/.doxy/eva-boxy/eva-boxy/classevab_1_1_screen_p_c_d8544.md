

# Class evab::ScreenPCD8544



[**ClassList**](annotated.md) **>** [**evab**](namespaceevab.md) **>** [**ScreenPCD8544**](classevab_1_1_screen_p_c_d8544.md)








Inherits the following classes: [evab::ScreenPage8Base](classevab_1_1_screen_page8_base.md)






























































































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**ScreenPCD8544**](#function-screenpcd8544) (const [**IFont**](classevab_1_1_i_font.md) \* aFont, uint8\_t aRST, uint8\_t aCE, uint8\_t aDC, uint8\_t aDIN, uint8\_t aCLK, uint8\_t aLED=255) <br> |
| virtual [**Coor**](structevab_1_1_coor.md) | [**Size**](#function-size) () override<br> |
|  void | [**clear**](#function-clear) () <br> |
|  void | [**setBacklight**](#function-setbacklight) (uint8\_t aState) <br> |
|  void | [**setContrast**](#function-setcontrast) (uint8\_t aContrast) <br> |
|   | [**~ScreenPCD8544**](#function-screenpcd8544) () <br> |


## Public Functions inherited from evab::ScreenPage8Base

See [evab::ScreenPage8Base](classevab_1_1_screen_page8_base.md)

| Type | Name |
| ---: | :--- |
| virtual void | [**DrawSymbol**](classevab_1_1_screen_page8_base.md#function-drawsymbol) ([**Coor**](structevab_1_1_coor.md) aPosition, [**Coor**](structevab_1_1_coor.md) aSize, char aCharcode, unsigned char aColor) <br> |
| virtual void | [**Picto**](classevab_1_1_screen_page8_base.md#function-picto) ([**Coor**](structevab_1_1_coor.md) aPosition, const unsigned char \* pictoData, unsigned char aColor) <br> |
|   | [**ScreenPage8Base**](classevab_1_1_screen_page8_base.md#function-screenpage8base) (const [**IFont**](classevab_1_1_i_font.md) \* mFont) <br> |


## Public Functions inherited from evab::ScreenBase

See [evab::ScreenBase](classevab_1_1_screen_base.md)

| Type | Name |
| ---: | :--- |
| virtual void | [**Clear**](classevab_1_1_screen_base.md#function-clear) ([**Coor**](structevab_1_1_coor.md) aPosition, [**Coor**](structevab_1_1_coor.md) aSize, unsigned char aColor) override<br> |
| virtual void | [**Picto**](classevab_1_1_screen_base.md#function-picto) ([**Coor**](structevab_1_1_coor.md) aPosition, const unsigned char \* pictoData, unsigned char aColor) <br> |
| virtual void | [**TextCenter**](classevab_1_1_screen_base.md#function-textcenter-12) ([**Coor**](structevab_1_1_coor.md) aPosition, [**Coor**](structevab_1_1_coor.md) aSize, const char \* text, unsigned char aColor) override<br> |
| virtual void | [**TextCenter**](classevab_1_1_screen_base.md#function-textcenter-22) ([**Coor**](structevab_1_1_coor.md) aPosition, [**Coor**](structevab_1_1_coor.md) aSize, const \_\_FlashStringHelper \* text, unsigned char aColor) override<br> |
| virtual void | [**TextLeft**](classevab_1_1_screen_base.md#function-textleft-12) ([**Coor**](structevab_1_1_coor.md) aPosition, [**Coor**](structevab_1_1_coor.md) aSize, const char \* text, unsigned char aColor) override<br> |
| virtual void | [**TextLeft**](classevab_1_1_screen_base.md#function-textleft-22) ([**Coor**](structevab_1_1_coor.md) aPosition, [**Coor**](structevab_1_1_coor.md) aSize, const \_\_FlashStringHelper \* text, unsigned char aColor) override<br> |
| virtual void | [**TextRight**](classevab_1_1_screen_base.md#function-textright-12) ([**Coor**](structevab_1_1_coor.md) aPosition, [**Coor**](structevab_1_1_coor.md) aSize, const char \* text, unsigned char aColor) override<br> |
| virtual void | [**TextRight**](classevab_1_1_screen_base.md#function-textright-22) ([**Coor**](structevab_1_1_coor.md) aPosition, [**Coor**](structevab_1_1_coor.md) aSize, const \_\_FlashStringHelper \* text, unsigned char aColor) override<br> |


## Public Functions inherited from evab::IScreen

See [evab::IScreen](classevab_1_1_i_screen.md)

| Type | Name |
| ---: | :--- |
| virtual void | [**Clear**](classevab_1_1_i_screen.md#function-clear) ([**Coor**](structevab_1_1_coor.md) aPosition, [**Coor**](structevab_1_1_coor.md) aSize, unsigned char aColor=0) = 0<br> |
| virtual void | [**DrawSymbol**](classevab_1_1_i_screen.md#function-drawsymbol) ([**Coor**](structevab_1_1_coor.md) aPosition, [**Coor**](structevab_1_1_coor.md) aSize, char aSymbol, unsigned char aColor) = 0<br> |
| virtual void | [**Picto**](classevab_1_1_i_screen.md#function-picto) ([**Coor**](structevab_1_1_coor.md) aPosition, const unsigned char \* pictoData, unsigned char aColor) = 0<br> |
| virtual [**Coor**](structevab_1_1_coor.md) | [**Size**](classevab_1_1_i_screen.md#function-size) () = 0<br> |
| virtual void | [**TextCenter**](classevab_1_1_i_screen.md#function-textcenter-12) ([**Coor**](structevab_1_1_coor.md) aPosition, [**Coor**](structevab_1_1_coor.md) aSize, const char \* text, unsigned char aColor) = 0<br> |
| virtual void | [**TextCenter**](classevab_1_1_i_screen.md#function-textcenter-22) ([**Coor**](structevab_1_1_coor.md) aPosition, [**Coor**](structevab_1_1_coor.md) aSize, const \_\_FlashStringHelper \* text, unsigned char aColor) = 0<br> |
| virtual void | [**TextLeft**](classevab_1_1_i_screen.md#function-textleft-12) ([**Coor**](structevab_1_1_coor.md) aPosition, [**Coor**](structevab_1_1_coor.md) aSize, const char \* text, unsigned char aColor) = 0<br> |
| virtual void | [**TextLeft**](classevab_1_1_i_screen.md#function-textleft-22) ([**Coor**](structevab_1_1_coor.md) aPosition, [**Coor**](structevab_1_1_coor.md) aSize, const \_\_FlashStringHelper \* text, unsigned char aColor) = 0<br> |
| virtual void | [**TextRight**](classevab_1_1_i_screen.md#function-textright-12) ([**Coor**](structevab_1_1_coor.md) aPosition, [**Coor**](structevab_1_1_coor.md) aSize, const char \* text, unsigned char aColor) = 0<br> |
| virtual void | [**TextRight**](classevab_1_1_i_screen.md#function-textright-22) ([**Coor**](structevab_1_1_coor.md) aPosition, [**Coor**](structevab_1_1_coor.md) aSize, const \_\_FlashStringHelper \* text, unsigned char aColor) = 0<br> |


























































































## Protected Functions

| Type | Name |
| ---: | :--- |
| virtual void | [**ClearTile**](#function-cleartile) ([**Coor**](structevab_1_1_coor.md) aPosition, unsigned char aColor) override<br> |
| virtual void | [**DrawVerticalSlice**](#function-drawverticalslice) ([**Coor**](structevab_1_1_coor.md) aPosition, unsigned char aSliceColumn, unsigned char aSlice) override<br> |


## Protected Functions inherited from evab::ScreenPage8Base

See [evab::ScreenPage8Base](classevab_1_1_screen_page8_base.md)

| Type | Name |
| ---: | :--- |
| virtual void | [**DrawVerticalSlice**](classevab_1_1_screen_page8_base.md#function-drawverticalslice) ([**Coor**](structevab_1_1_coor.md) aPosition, unsigned char aSliceColumn, unsigned char aSlice) = 0<br> |


## Protected Functions inherited from evab::ScreenBase

See [evab::ScreenBase](classevab_1_1_screen_base.md)

| Type | Name |
| ---: | :--- |
| virtual void | [**ClearTile**](classevab_1_1_screen_base.md#function-cleartile) ([**Coor**](structevab_1_1_coor.md) position, unsigned char aColor) <br> |












## Public Functions Documentation




### function ScreenPCD8544 

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




<hr>



### function Size 

```C++
inline virtual Coor evab::ScreenPCD8544::Size () override
```



Implements [*evab::IScreen::Size*](classevab_1_1_i_screen.md#function-size)


<hr>



### function clear 

```C++
void evab::ScreenPCD8544::clear () 
```




<hr>



### function setBacklight 

```C++
void evab::ScreenPCD8544::setBacklight (
    uint8_t aState
) 
```




<hr>



### function setContrast 

```C++
void evab::ScreenPCD8544::setContrast (
    uint8_t aContrast
) 
```




<hr>



### function ~ScreenPCD8544 

```C++
evab::ScreenPCD8544::~ScreenPCD8544 () 
```




<hr>
## Protected Functions Documentation




### function ClearTile 

```C++
virtual void evab::ScreenPCD8544::ClearTile (
    Coor aPosition,
    unsigned char aColor
) override
```



Implements [*evab::ScreenBase::ClearTile*](classevab_1_1_screen_base.md#function-cleartile)


<hr>



### function DrawVerticalSlice 

```C++
virtual void evab::ScreenPCD8544::DrawVerticalSlice (
    Coor aPosition,
    unsigned char aSliceColumn,
    unsigned char aSlice
) override
```



Implements [*evab::ScreenPage8Base::DrawVerticalSlice*](classevab_1_1_screen_page8_base.md#function-drawverticalslice)


<hr>

------------------------------
The documentation for this class was generated from the following file `src/evabScreenPCD8544.h`

