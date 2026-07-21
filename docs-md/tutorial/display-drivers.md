# Display Drivers

EVA Boxy supports multiple display types through a unified interface. All positioning uses **tiles** as the minimum unit. The library provides both graphical and text-based display drivers, including debug variants for development.

## Display Types

### Graphical Displays
Pixel-based displays that can render fonts and pictograms:

| Driver | Class | Resolution | Interface |
|--------|-------|------------|-----------|
| SSD1306 | `ScreenSSD1306` | 128x64px | I2C |
| SSH1106 | `ScreenSSH1106` | 128x64px | I2C |
| PCD8544 | `ScreenPCD8544` | 84x48px | SPI |
| KS0108 | `ScreenKS0108` | 128x64px | Parallel |

### Text Displays
Character-based displays with limited graphics:

| Driver | Class | Resolution | Interface |
|--------|-------|------------|-----------|
| LCD I2C | `ScreenLCD_I2C` | 16x2, 20x4, etc. | I2C |

### Debug Displays
Virtual displays for development and testing:

| Driver | Class | Resolution | Output |
|--------|-------|------------|--------|
| Serial Text | `ScreenSerialText` | 16x8 tiles | Serial |
| Serial Pixel | `ScreenSerialPixel` | 16x8 tiles | Serial |

## Graphical Display Drivers

### ScreenSSD1306 - OLED Display

I2C OLED display driver for 128x64 pixel screens.

```cpp
#include <evabScreenSSD1306.h>
#include <evabFont8Compact.h>

evab::Font8Compact font;
evab::ScreenSSD1306 screen(&font, 800000L, 64);
```

### ScreenPCD8544 - Nokia 5110 Display

SPI-based driver for Nokia 5110/3310 displays.

```cpp
#include <evabScreenPCD8544.h>
#include <evabFont8Bold.h>

evab::Font8Bold font;
evab::ScreenPCD8544 screen(
    &font,
    9,   // RST pin
    10,  // CE pin
    11,  // DC pin
    12,  // DIN pin
    13,  // CLK pin
    8    // LED pin (optional)
);

// Control backlight
screen.SetBacklight(HIGH);

// Adjust contrast
screen.SetContrast(0x30);  // 0x00-0x7F
```

### ScreenKS0108 - Parallel Graphics

Parallel interface driver for KS0108-based displays.

```cpp
#include <evabScreenKS0108.h>
#include <evabFont8Thin.h>

evab::Font8Thin font;
evab::ScreenKS0108 screen(
    &font,
    2,   // RS
    3,   // RW
    4,   // E
    5,   // CS1
    6,   // CS2
    7,   // DB0
    8,   // DB1
    9,   // DB2
    10,  // DB3
    11,  // DB4
    12,  // DB5
    13,  // DB6
    14,  // DB7
    15   // LED (optional)
);
```

### ScreenSSH1106 - Alternative OLED

I2C driver for SSH1106-based OLED displays.

```cpp
#include <evabScreenSSH1106.h>
#include <evabFont8Compact.h>

evab::Font8Compact font;
evab::ScreenSSH1106 screen(&font, 800000L);
```

## Text Display Drivers

### ScreenLCD_I2C - I2C LCD

Driver for HD44780-based LCD displays via I2C.

```cpp
#include <evabScreenLCD_I2C.h>

evab::ScreenLCD_I2C screen(
    0x27,  // I2C address
    16,    // Columns
    2,     // Rows
    3      // Backlight pin (on PCF8574)
);

// Control backlight
screen.SetBacklight(HIGH);
```

## Debug Displays

Debug displays output to Serial for development without hardware.

### ScreenSerialText - Text Debug

Displays characters as-is on serial monitor.

```cpp
#include <evabScreenSerialText.h>

evab::ScreenSerialText screen;

// Draw text
screen.TextCenter({0, 0}, {16, 8}, "Debug", 0);

// Output to serial
screen.printToSerial();

/* Output:
................
................
....Debug.......
................
................
................
................
................
*/
```

### ScreenSerialPixel - Pixel Debug

Displays pixel-accurate representation.

```cpp
#include <evabScreenSerialPixel.h>
#include <evabFont8Compact.h>

evab::Font8Compact font;
evab::ScreenSerialPixel screen(&font);

// Draw something
screen.TextCenter({0, 0}, {16, 8}, "8", 0);

// Output to serial
screen.printToSerial();

/* Output:
...####...........
..#....#..........
..#....#..........
..######..........
..#....#..........
..#....#..........
..######..........
..................
*/
```

## Fonts

**All graphical displays require a font to be specified during initialization.**

Available fonts:
- `Font8Bold` - Bold 8-pixel font
- `Font8Compact` - Compact 8-pixel font (narrower characters)
- `Font8Thin` - Thin 8-pixel font

