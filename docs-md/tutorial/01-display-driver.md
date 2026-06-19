# 1. Display Driver Usage

This section covers using EVAB as a display driver library.

## Supported Displays

### Graphical Displays (Pixel-Based)

| Display | Resolution | Interface | Class | Features |
|---------|------------|-----------|-------|----------|
| **SSD1306** | 128×64, 128×32 | I2C | `ScreenSSD1306` | OLED, contrast control |
| **SSH1106** | 128×64 | I2C | `ScreenSSH1106` | OLED, larger internal RAM |
| **KS0108** | 128×64 | Parallel | `ScreenKS0108` | GLCD, dual chip |
| **PCD8544** | 84×48 | SPI | `ScreenPCD8544` | Nokia 5110 LCD |

### Character Displays (Text-Based)

| Display | Resolution | Interface | Class | Features |
|---------|------------|-----------|-------|----------|
| **HD44780** | 16×2, 20×4, etc. | I2C | `ScreenLCD_I2C` | Character LCD, backlight |

### Debug/Simulation Displays

| Display | Resolution | Interface | Class | Features |
|---------|------------|-----------|-------|----------|
| **Serial Pixel** | 128×64 | Serial | `ScreenSerialPixel` | Debug output as pixels |
| **Serial Text** | 16×8 | Serial | `ScreenSerialText` | Debug output as characters |

## Display Initialization Examples

### SSD1306 OLED (I2C)

```cpp
#include <evabScreenSSD1306.h>
#include <evabFont8Bold.h>

using namespace evab;

// Create font instance
static Font8Bold font;

// Initialize display with custom I2C clock
ScreenSSD1306 display(&font, 800000L, 64); // 800kHz, 64px height

// Or with default parameters
ScreenSSD1306 display(&font);

// Set contrast (0-255)
display.SetContrast(127);

// Clear entire screen
display.ClearDisplay();

// Get display size in tiles
Coor size = display.Size(); // {16, 8} for 128x64
```

### KS0108 Graphical GLCD (Parallel)

```cpp
#include <evabScreenKS0108.h>
#include <evabFont8Bold.h>

using namespace evab;

static Font8Bold font;

// Pin configuration: RS, RW, E, CS1, CS2, DB0-DB7, LED (optional)
ScreenKS0108 display(&font,
    2, 3, 4,    // RS, RW, E
    5, 6,        // CS1, CS2
    7, 8, 9, 10, // DB0-DB3
    11, 12, 13, 14, // DB4-DB7
    15           // LED (255 if not used)
);

// Control backlight
display.setBacklight(HIGH);

// Clear display
display.clear();
```

### PCD8544 (Nokia 5110)

```cpp
#include <evabScreenPCD8544.h>
#include <evabFont8Bold.h>

using namespace evab;

static Font8Bold font;

// Pin configuration: RST, CE, DC, DIN, CLK, LED
ScreenPCD8544 display(&font,
    9, 8, 7,    // RST, CE, DC
    11, 10,     // DIN, CLK
    6           // LED (255 if not used)
);

// Set contrast (0-127)
display.setContrast(0x30);

// Control backlight
display.setBacklight(HIGH);

// Clear display
display.clear();
```

### HD44780 Character LCD (I2C)

```cpp
#include <evabScreenLCD_I2C.h>

using namespace evab;

// Address, columns, rows, backlight pin
ScreenLCD_I2C display(0x27, 16, 2, 3);

// Control backlight
display.setBacklight(HIGH);

// Clear screen
display.clear();

// Get size
Coor size = display.Size(); // {16, 2}
```

## Font Support

EVAB includes three built-in fonts:

| Font | Width | Height | Style | Class |
|------|-------|--------|-------|-------|
| **Font8Bold** | 8px | 8px | Bold | `Font8Bold` |
| **Font8Thin** | 7px | 8px | Thin | `Font8Thin` |
| **Font8Compact** | 5px | 8px | Compact | `Font8Compact` |

### Font Usage Example

```cpp
#include <evabFont8Bold.h>
#include <evabFont8Thin.h>
#include <evabFont8Compact.h>

using namespace evab;

// Choose one font
static Font8Bold boldFont;
static Font8Thin thinFont;
static Font8Compact compactFont;

// Pass to display constructor
ScreenSSD1306 display(&boldFont);
```

## Text Drawing Functions

All display classes implement the `IScreen` interface with text functions:

```cpp
void TextLeft(Coor pos, Coor size, const char* text, uint8_t color);
void TextCenter(Coor pos, Coor size, const char* text, uint8_t color);
void TextRight(Coor pos, Coor size, const char* text, uint8_t color);

// Also support flash strings (PROGMEM)
void TextLeft(Coor pos, Coor size, const __FlashStringHelper* text, uint8_t color);
```

### Text Example

```cpp
// Display size in tiles
Coor size = display.Size(); // {16, 8} for 128x64

// Draw text at top-left
display.TextLeft({0, 0}, {16, 1}, "Hello World", 1);

// Draw centered text
display.TextCenter({0, 3}, {16, 2}, "Centered", 1);

// Draw right-aligned text
display.TextRight({0, 6}, {16, 1}, "Right", 1);

// Using flash strings (saves RAM)
display.TextCenter({0, 4}, {16, 1}, F("Flash String"), 1);
```

## Graphics Primitives

### Drawing Symbols/Pixels

```cpp
// Draw a single character at tile position
display.DrawSymbol({5, 3}, {1, 1}, 'A', 1); // 1 = white/filled

// Draw with scaling (2x size)
display.DrawSymbol({2, 4}, {2, 2}, 'B', 1);
```

### Clearing Areas

```cpp
// Clear a specific area
display.Clear({0, 0}, {16, 8}, 0); // 0 = black/clear

// Clear single tile
display.Clear({5, 5}, {1, 1}, 0);
```

### Drawing Pictograms

```cpp
#include <evabTilesets.h>

// Battery indicator
const uint8_t* battery = TileSetBattery::GetTile(3);
display.Picto({0, 0}, battery, 1);

// Progress indicator
const uint8_t* progress = TileSetProgress::GetTile(5);
display.Picto({2, 0}, progress, 1);

// Signal strength
const uint8_t* signal = TileSetSignal::GetTile(3);
display.Picto({4, 0}, signal, 1);
```

---