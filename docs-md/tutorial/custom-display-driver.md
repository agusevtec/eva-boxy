# Custom Display Driver

Creating a custom display driver for EVA Boxy requires inheriting from `ScreenBase` or `ScreenPage8Base` and implementing specific virtual methods.

## Base Classes

### ScreenBase

Base class for all screen implementations. Provides text rendering and basic operations.

```cpp
class ScreenBase : public IScreen {
public:
    // Inherited from IScreen
    virtual void DrawSymbol(Coor pos, Coor size, char symbol, unsigned char color) = 0;
    virtual Coor Size() = 0;
    
    // Text rendering (implemented in ScreenBase)
    void TextLeft(...);
    void TextCenter(...);
    void TextRight(...);
    
    // Clearing (implemented in ScreenBase)
    void Clear(Coor pos, Coor size, unsigned char color);
    
    // Pictogram (can be overridden)
    virtual void Picto(Coor pos, const unsigned char* pictoData, unsigned char color);
    
protected:
    // Must implement
    virtual void ClearTile(Coor pos, unsigned char color);
    
    // Serialization (must implement)
    virtual unsigned short Serialize(const Coor& pos, const Coor& size, bool isFocused);
    virtual void Deserialize(unsigned short serialized, Coor& pos, Coor& size, bool& isFocused);
};
```

### ScreenPage8Base

For page-oriented displays (8-pixel vertical strips like SSD1306, PCD8544).

```cpp
class ScreenPage8Base : public ScreenBase {
public:
    // Implements DrawSymbol and Picto using vertical slices
    void DrawSymbol(Coor pos, Coor size, char symbol, unsigned char color);
    void Picto(Coor pos, const unsigned char* pictoData, unsigned char color);
    
protected:
    // Must implement - write one 8-pixel vertical slice
    virtual void DrawVerticalSlice(Coor pos, unsigned char sliceColumn, unsigned char slice) = 0;
    
    // Must implement - clear a tile
    virtual void ClearTile(Coor pos, unsigned char color) = 0;
    
    // Font used
    const IFont* mFont;
};
```

## Required Methods

### ScreenBase Implementation

```cpp
class MyScreen : public ScreenBase {
public:
    // Screen dimensions in tiles
    Coor Size() override {
        return {16, 8};  // 16 tiles wide, 8 tiles high
    }
    
    // Draw a single symbol at the given position
    void DrawSymbol(Coor pos, Coor size, char symbol, unsigned char color) override {
        // Implementation depends on display type
        // For text displays: send character code
        // For graphical displays: render font pixel data
    }
    
    // Clear a tile (1x1 area)
    void ClearTile(Coor pos, unsigned char color) override {
        // Fill tile with blank (or fill if color=1)
        // Default implementation uses space character
        // Better to implement optimized clearing
    }
    
    // Serialize element state
    unsigned short Serialize(const Coor& pos, const Coor& size, bool isFocused) override {
        return serialize_16x8(pos, size, isFocused);  // Use provided serializer
    }
    
    // Deserialize element state
    void Deserialize(unsigned short serialized, Coor& pos, Coor& size, bool& isFocused) override {
        deserialize_16x8(serialized, pos, size, isFocused);  // Use provided deserializer
    }
};
```

## Simple Driver Examples

### Text Display Driver

Simple text-based display (e.g., LCD):

```cpp
class MyTextScreen : public ScreenBase {
public:
    Coor Size() override { return {16, 2}; }
    
    void DrawSymbol(Coor pos, Coor size, char symbol, unsigned char color) override {
        if (pos.X < Size().X && pos.Y < Size().Y) {
            setCursor(pos.X, pos.Y);
            sendChar(symbol);
        }
    }
    
    void ClearTile(Coor pos, unsigned char color) override {
        if (pos.X < Size().X && pos.Y < Size().Y) {
            setCursor(pos.X, pos.Y);
            sendChar(color ? 0xFF : ' ');
        }
    }
    
    unsigned short Serialize(const Coor& pos, const Coor& size, bool isFocused) override {
        return serialize_16x8(pos, size, isFocused);
    }
    
    void Deserialize(unsigned short serialized, Coor& pos, Coor& size, bool& isFocused) override {
        deserialize_16x8(serialized, pos, size, isFocused);
    }
    
private:
    void setCursor(int x, int y) { /* Hardware specific */ }
    void sendChar(char c) { /* Hardware specific */ }
};
```

### Page 8 Display Driver

For displays organized in 8-pixel pages:

```cpp
class MyPage8Screen : public ScreenPage8Base {
public:
    MyPage8Screen(const IFont* font) : ScreenPage8Base(font) {
        initDisplay();
        clear();
    }
    
    Coor Size() override { return {16, 8}; }
    
protected:
    void DrawVerticalSlice(Coor pos, unsigned char sliceColumn, unsigned char slice) override {
        int x = pos.X * 8 + sliceColumn;
        int page = pos.Y;
        
        if (x >= width() || page >= pages()) return;
        
        // Write the 8-bit slice to the display
        writeSlice(x, page, slice);
    }
    
    void ClearTile(Coor pos, unsigned char color) override {
        // Clear all 8 columns of the tile
        for (unsigned char col = 0; col < 8; col++) {
            DrawVerticalSlice(pos, col, color ? 0xFF : 0x00);
        }
    }
    
    unsigned short Serialize(const Coor& pos, const Coor& size, bool isFocused) override {
        return serialize_16x8(pos, size, isFocused);
    }
    
    void Deserialize(unsigned short serialized, Coor& pos, Coor& size, bool& isFocused) override {
        deserialize_16x8(serialized, pos, size, isFocused);
    }
    
private:
    int width() const { return 128; }   // Pixels
    int pages() const { return 8; }     // 8-pixel pages
    
    void writeSlice(int x, int page, unsigned char slice) {
        // Hardware-specific write
        setPage(page);
        setColumn(x);
        sendData(slice);
    }
    
    void initDisplay() {
        // Display initialization sequence
    }
};
```

## Driver Template

Complete custom driver template:

```cpp
// MyCustomScreen.h
#pragma once
#include <evabScreenBase.h>
#include <evabSerializers.h>

namespace evab {

class MyCustomScreen : public ScreenBase {
public:
    MyCustomScreen(/* hardware pins */) {
        initHardware();
        clear();
    }
    
    // ─── Required Methods ───
    
    Coor Size() override {
        return {widthInTiles, heightInTiles};
    }
    
    void DrawSymbol(Coor pos, Coor size, char symbol, unsigned char color) override {
        // Implement symbol drawing
        // For graphical: use font
        // For text: send char to display
    }
    
    void ClearTile(Coor pos, unsigned char color) override {
        // Clear 1x1 tile area
        // For text: write space
        // For graphical: write zeros or ones
    }
    
    unsigned short Serialize(const Coor& pos, const Coor& size, bool isFocused) override {
        // Use appropriate serializer
        return serialize_16x8(pos, size, isFocused);
    }
    
    void Deserialize(unsigned short serialized, Coor& pos, Coor& size, bool& isFocused) override {
        deserialize_16x8(serialized, pos, size, isFocused);
    }
    
    // ─── Optional Overrides ───
    
    // Override for faster clearing
    void Clear(Coor pos, Coor size, unsigned char color) override {
        // Optimized clearing
        for (int y = 0; y < size.Y; y++) {
            for (int x = 0; x < size.X; x++) {
                ClearTile({pos.X + x, pos.Y + y}, color);
            }
        }
    }
    
    // Override for custom pictogram handling
    void Picto(Coor pos, const unsigned char* pictoData, unsigned char color) override {
        // Custom pictogram rendering if needed
        ScreenBase::Picto(pos, pictoData, color);
    }

private:
    // Hardware-specific methods
    void initHardware();
    void writePixel(int x, int y, unsigned char color);
    
    static const int widthInTiles = 16;
    static const int heightInTiles = 8;
};

} // namespace evab
```

## Serialization

### 16x8 Screen Serialization

For 16 tile wide, 8 tile high displays:

```cpp
unsigned short serialize_16x8(const Coor& pos, const Coor& size, bool isFocused) {
    unsigned short serialized = 0;
    
    // Bit 0: Visibility
    if (size.X > 0 || size.Y > 0)
        serialized |= (1 << 0);
    
    // Bit 1: Focus
    if (isFocused)
        serialized |= (1 << 1);
    
    // Bits 2-5: X (0-15)
    serialized |= ((pos.X & 0x0F) << 2);
    
    // Bits 6-8: Y (0-7)
    serialized |= ((pos.Y & 0x07) << 6);
    
    // Bits 9-12: Width (1-16)
    serialized |= (((size.X - 1) & 0x0F) << 9);
    
    // Bits 13-15: Height (1-8)
    serialized |= (((size.Y - 1) & 0x07) << 13);
    
    return serialized;
}

void deserialize_16x8(unsigned short serialized, Coor& pos, Coor& size, bool& isFocused) {
    if ((serialized >> 0) & 1) {
        size.X = ((serialized >> 9) & 0x0F) + 1;
        size.Y = ((serialized >> 13) & 0x07) + 1;
    } else {
        size.X = 0;
        size.Y = 0;
    }
    
    isFocused = (serialized >> 1) & 1;
    pos.X = (serialized >> 2) & 0x0F;
    pos.Y = (serialized >> 6) & 0x07;
}
```

### Other Screen Sizes

For different screen sizes, create custom serializers or use existing ones:

```cpp
// 32x4 screens (e.g., 20x4 LCD)
unsigned short serialize_32x4(const Coor& pos, const Coor& size, bool isFocused);
void deserialize_32x4(unsigned short serialized, Coor& pos, Coor& size, bool& isFocused);
```

## Best Practices

### 1. Optimize ClearTile

Default `ClearTile` uses space character. Override for better performance:

```cpp
void ClearTile(Coor pos, unsigned char color) override {
    // Direct hardware clearing
    if (color) {
        // Fill with 1s
        writeFilledTile(pos, 0xFF);
    } else {
        // Fill with 0s
        writeFilledTile(pos, 0x00);
    }
}
```

### 2. Add Display Controls

Add backlight and contrast controls:

```cpp
class MyScreen : public ScreenBase {
public:
    void setBacklight(uint8_t state);
    void setContrast(uint8_t value);
    void setPower(bool on);
};
```

### 3. Validate Coordinates

Always validate positions before writing:

```cpp
void DrawVerticalSlice(Coor pos, unsigned char sliceColumn, unsigned char slice) override {
    int x = pos.X * 8 + sliceColumn;
    int page = pos.Y;
    
    // Validate
    if (x >= mWidth || page >= mPages) return;
    if (x < 0 || page < 0) return;
    
    // Write data
    writeSlice(x, page, slice);
}
```

### 4. Use PROGMEM

Store static data in flash memory:

```cpp
static const uint8_t initSequence[] PROGMEM = {0xAE, 0xD5, 0x80, ...};
```

## Summary

| Required Method | ScreenBase | Page8Base |
|-----------------|------------|-----------|
| `DrawSymbol()` | ✓ | ✓ (implemented) |
| `DrawVerticalSlice()` | - | ✓ |
| `ClearTile()` | ✓ | ✓ |
| `Size()` | ✓ | ✓ |
| `Serialize()` | ✓ | ✓ |
| `Deserialize()` | ✓ | ✓ |

**Key Points:**
1. Inherit from `ScreenBase` for any display
2. For page-based displays, inherit from `ScreenPage8Base`
3. Override `ClearTile()` for better performance
4. Use serializers from `evabSerializers.h`
5. Validate all coordinates before writing
6. Add display-specific controls (backlight, contrast, etc.)
7. Store initialization data in PROGMEM