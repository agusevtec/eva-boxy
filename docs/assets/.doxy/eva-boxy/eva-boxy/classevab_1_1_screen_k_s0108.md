

# Class evab::ScreenKS0108



[**ClassList**](annotated.md) **>** [**evab**](namespaceevab.md) **>** [**ScreenKS0108**](classevab_1_1_screen_k_s0108.md)








Inherits the following classes: [evab::ScreenPage8Base](classevab_1_1_screen_page8_base.md)






























































































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**ScreenKS0108**](#function-screenks0108) (const [**IFont**](classevab_1_1_i_font.md) \* aFont, uint8\_t aRS, uint8\_t aRW, uint8\_t aE, uint8\_t aCS1, uint8\_t aCS2, uint8\_t aDB0, uint8\_t aDB1, uint8\_t aDB2, uint8\_t aDB3, uint8\_t aDB4, uint8\_t aDB5, uint8\_t aDB6, uint8\_t aDB7, uint8\_t aLED=255) <br> |
| virtual [**Coor**](structevab_1_1_coor.md) | [**Size**](#function-size) () override<br> |
|  void | [**clear**](#function-clear) () <br> |
|  void | [**setBacklight**](#function-setbacklight) (uint8\_t aState) <br> |
|   | [**~ScreenKS0108**](#function-screenks0108) () <br> |


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




### function ScreenKS0108 

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




<hr>



### function Size 

```C++
virtual Coor evab::ScreenKS0108::Size () override
```



Implements [*evab::IScreen::Size*](classevab_1_1_i_screen.md#function-size)


<hr>



### function clear 

```C++
void evab::ScreenKS0108::clear () 
```




<hr>



### function setBacklight 

```C++
void evab::ScreenKS0108::setBacklight (
    uint8_t aState
) 
```




<hr>



### function ~ScreenKS0108 

```C++
evab::ScreenKS0108::~ScreenKS0108 () 
```




<hr>
## Protected Functions Documentation




### function ClearTile 

```C++
virtual void evab::ScreenKS0108::ClearTile (
    Coor aPosition,
    unsigned char aColor
) override
```



Implements [*evab::ScreenBase::ClearTile*](classevab_1_1_screen_base.md#function-cleartile)


<hr>



### function DrawVerticalSlice 

```C++
virtual void evab::ScreenKS0108::DrawVerticalSlice (
    Coor aPosition,
    unsigned char aSliceColumn,
    unsigned char aSlice
) override
```



Implements [*evab::ScreenPage8Base::DrawVerticalSlice*](classevab_1_1_screen_page8_base.md#function-drawverticalslice)


<hr>

------------------------------
The documentation for this class was generated from the following file `src/evabScreenKS0108.h`

