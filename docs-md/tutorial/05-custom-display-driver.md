# 5. Custom Display Driver

This section covers creating custom display drivers and using debug displays.

## Display Driver Architecture

```
IScreen (interface)
    └── ScreenBase (base implementation)
            └── ScreenPage8Base (graphical displays)
            │   ├── ScreenSSD1306
            │   ├── ScreenKS0108
            │   ├── ScreenPCD8544
            │   └── ScreenSerialPixel
            └── ScreenLCD_I2C (character displays)
                └── ScreenSerialText
```

## IScreen Interface

The core interface that all display drivers implement:

```cpp
class IScreen {
public:
    // Text rendering (C strings)
    virtual void TextLeft(Coor pos, Coor size, const char* text, uint8_t color) = 0;
    virtual void TextCenter(Coor pos, Coor size, const char* text, uint8_t color) = 0;
    virtual void TextRight(Coor pos, Coor size, const char* text, uint8_t color) = 0;
    
    // Text rendering (Flash strings - PROGMEM)
    virtual void TextLeft(Coor pos, Coor size, const __FlashStringHelper* text, uint8_t color) = 0;
    virtual void TextCenter(Coor pos, Coor size, const __FlashStringHelper* text, uint8_t color) = 0;
    virtual void TextRight(Coor pos, Coor size, const __FlashStringHelper* text, uint8_t color) = 0;
    
    // Graphics
    virtual void Picto(Coor pos, const unsigned char* pictoData, uint8_t color) = 0;
    virtual void Clear(Coor pos, Coor size, uint8_t color = 0) = 0;
    virtual void DrawSymbol(Coor pos, Coor size, char symbol, uint8_t color) = 0;
    
    // Get display size in tiles (8x8 blocks)
    virtual Coor Size() = 0;
};
```

## ScreenBase Class

Provides common text rendering functionality:

```cpp
class ScreenBase : public IScreen {
protected:
    // Must be implemented by derived class
    virtual void DrawSymbol(Coor pos, Coor size, char symbol, uint8_t color) = 0;
    
    // Optional override for tile clearing optimization
    virtual void ClearTile(Coor pos, uint8_t color);
};
```

## ScreenPage8Base Class

For graphical displays (8-pixel tall pages):

```cpp
class ScreenPage8Base : public ScreenBase {
public:
    ScreenPage8Base(const IFont* font);
    
    // Implements DrawSymbol using vertical slices
    void DrawSymbol(Coor pos, Coor size, char symbol, uint8_t color) override;
    
    // Implements Picto using vertical slices
    void Picto(Coor pos, const unsigned char* pictoData, uint8_t color) override;
    
protected:
    // Must be implemented - draw an 8-pixel vertical slice
    virtual void DrawVerticalSlice(Coor pos, uint8_t sliceColumn, uint8_t slice) = 0;
    
private:
    const IFont* mFont;
};
```

## Creating a Custom Display Driver

### 1. For Graphical Displays (ScreenPage8Base)

```cpp
#include <evabScreenPage8Base.h>
#include <evabIFont.h>

class MyGraphicalDisplay : public ScreenPage8Base {
public:
    MyGraphicalDisplay(const IFont* font) 
        : ScreenPage8Base(font) {
        // Initialize hardware
        initHardware();
        clear();
    }
    
    // Required: Get display size in tiles
    Coor Size() override {
        return {16, 8}; // 128/8 = 16 tiles wide, 8 tiles tall
    }
    
protected:
    // Required: Draw a vertical slice (8 pixels) at position
    void DrawVerticalSlice(Coor pos, uint8_t sliceColumn, uint8_t slice) override {
        uint8_t x = pos.X * 8 + sliceColumn;
        uint8_t page = pos.Y;
        
        if (x >= displayWidth || page >= displayPages)
            return;
        
        // Write slice to display memory
        setPage(page);
        setColumn(x);
        sendData(slice);
    }
    
    // Optional: Optimize tile clearing
    void ClearTile(Coor pos, uint8_t color) override {
        // Write 8 vertical slices of 0x00 or 0xFF
        for (uint8_t col = 0; col < 8; col++) {
            DrawVerticalSlice(pos, col, color ? 0xFF : 0x00);
        }
    }
    
private:
    void initHardware() {
        // Hardware initialization
    }
    
    void setPage(uint8_t page) {
        // Set page (y) address
    }
    
    void setColumn(uint8_t col) {
        // Set column (x) address
    }
    
    void sendData(uint8_t data) {
        // Send data byte to display
    }
    
    static constexpr uint8_t displayWidth = 128;
    static constexpr uint8_t displayPages = 8;
};
```

### 2. For Character Displays (ScreenBase)

```cpp
#include <evabScreenBase.h>

class MyCharacterDisplay : public ScreenBase {
public:
    MyCharacterDisplay() {
        initDisplay();
        clear();
    }
    
    Coor Size() override {
        return {16, 2}; // 16 columns, 2 rows
    }
    
protected:
    // Required: Draw a character at tile position
    void DrawSymbol(Coor pos, Coor size, char symbol, uint8_t color) override {
        (void)size; // Character displays usually ignore size
        (void)color; // And color
        
        if (pos.X < cols && pos.Y < rows) {
            setCursor(pos.X, pos.Y);
            sendChar(symbol);
        }
    }
    
private:
    void initDisplay() {
        // Display initialization
    }
    
    void setCursor(uint8_t col, uint8_t row) {
        // Set cursor position
    }
    
    void sendChar(char symbol) {
        // Send character to display
    }
    
    static constexpr uint8_t cols = 16;
    static constexpr uint8_t rows = 2;
};
```

### 3. Using a Custom Driver

```cpp
#include <evabBoxy.h>
#include <evabFont8Bold.h>

using namespace evab;

// Create your custom display
static Font8Bold font;
MyGraphicalDisplay display(&font);

// Use with Boxy
class MyUI : public ElementBase {
    // ...
};

MyUI ui;

// In setup, you can use Boxy::Begin with any display type
// or use the display directly:
ui.Draw(&display, {0, 0}, display.Size(), 1);
```

## Debug Displays

### ScreenSerialPixel - Debug Pixel Output

Outputs graphical content as ASCII art via Serial.

```cpp
#include <evabScreenSerialPixel.h>
#include <evabFont8Bold.h>

using namespace evab;

static Font8Bold font;
ScreenSerialPixel debugDisplay(&font);

// Draw something
debugDisplay.TextCenter({0, 3}, {16, 2}, "Hello", 1);

// Output to Serial as # and . characters
debugDisplay.printToSerial();

// Output example:
// ................
// ......######.....
// .....#......#....
// .....#......#....
// ......######.....
// ................
```

### ScreenSerialText - Debug Character Output

Outputs text content to Serial.

```cpp
#include <evabScreenSerialText.h>

using namespace evab;

ScreenSerialText debugDisplay;

// Draw text
debugDisplay.TextCenter({0, 3}, {16, 2}, "Hello", 1);

// Output to Serial as characters
debugDisplay.printToSerial();

// Output example:
// ................
// ................
// ................
// .....Hello.......
// ................
// ................
```

## Font Interface

To use custom fonts with graphical displays:

```cpp
class IFont {
public:
    // Get 8-pixel vertical slice for character at column
    virtual unsigned char GetVerticalSlice(char charcode, uint8_t col) const = 0;
};

// Custom font example
class MyCustomFont : public IFont {
public:
    unsigned char GetVerticalSlice(char charcode, uint8_t col) const override {
        // Return font data for charcode at column col
        // charcode should be in range 32-126
        return pgm_read_byte(&fontData[charcode - 32][col]);
    }
    
private:
    static const uint8_t fontData[][8] PROGMEM;
};

// Font data (8x8 pixels per character)
const uint8_t MyCustomFont::fontData[][8] PROGMEM = {
    // Space ' '
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    // 'A'
    {0x00, 0x7E, 0x81, 0x81, 0x81, 0x81, 0x7E, 0x00},
    // ... more characters
};
```

## Complete Custom Driver Example

```cpp
// Custom driver for a 128x64 SPI display with custom protocol
#include <evabScreenPage8Base.h>

class MySPIDisplay : public ScreenPage8Base {
private:
    uint8_t mCSPin;
    uint8_t mDCPin;
    uint8_t mRSTPin;
    
public:
    MySPIDisplay(const IFont* font, uint8_t cs, uint8_t dc, uint8_t rst) 
        : ScreenPage8Base(font), mCSPin(cs), mDCPin(dc), mRSTPin(rst) {
        // Setup pins
        pinMode(mCSPin, OUTPUT);
        pinMode(mDCPin, OUTPUT);
        pinMode(mRSTPin, OUTPUT);
        
        // Reset
        digitalWrite(mRSTPin, LOW);
        delay(10);
        digitalWrite(mRSTPin, HIGH);
        delay(10);
        
        // Init SPI
        SPI.begin();
        SPI.setBitOrder(MSBFIRST);
        SPI.setDataMode(SPI_MODE0);
        SPI.setClockDivider(SPI_CLOCK_DIV4);
        
        // Send init commands
        sendCommand(0xAE); // Display off
        sendCommand(0x40); // Start line
        // ... more init commands
        sendCommand(0xAF); // Display on
        
        clear();
    }
    
    Coor Size() override { return {16, 8}; }
    
protected:
    void DrawVerticalSlice(Coor pos, uint8_t sliceColumn, uint8_t slice) override {
        uint8_t x = pos.X * 8 + sliceColumn;
        uint8_t page = pos.Y;
        
        if (x >= 128 || page >= 8) return;
        
        setPage(page);
        setColumn(x);
        sendData(slice);
    }
    
private:
    void sendCommand(uint8_t cmd) {
        digitalWrite(mDCPin, LOW);
        digitalWrite(mCSPin, LOW);
        SPI.transfer(cmd);
        digitalWrite(mCSPin, HIGH);
    }
    
    void sendData(uint8_t data) {
        digitalWrite(mDCPin, HIGH);
        digitalWrite(mCSPin, LOW);
        SPI.transfer(data);
        digitalWrite(mCSPin, HIGH);
    }
    
    void setPage(uint8_t page) {
        sendCommand(0xB0 | (page & 0x07));
    }
    
    void setColumn(uint8_t col) {
        sendCommand(0x00 | (col & 0x0F));
        sendCommand(0x10 | ((col >> 4) & 0x0F));
    }
    
    void clear() {
        for (uint8_t page = 0; page < 8; page++) {
            for (uint8_t col = 0; col < 128; col++) {
                setPage(page);
                setColumn(col);
                sendData(0x00);
            }
        }
    }
};
```

---