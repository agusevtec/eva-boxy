# Use as "Pencil" - IScreen Interface

The **Pencil use case** in EVA Boxy provides direct drawing operations on the screen through the `IScreen` interface. This mode allows you to draw text, symbols, and pictograms without using the UI element system.


## Text Rendering

### Alignment Options

```cpp
#include <evabScreenSSD1306.h>
#include <evabFont8Compact.h>

evab::Font8Compact font;
evab::ScreenSSD1306 screen(&font, 800000L, 64);

// Left aligned
screen.TextLeft({0, 0}, {16, 1}, "Left", 0);

// Center aligned
screen.TextCenter({0, 1}, {16, 1}, "Center", 0);

// Right aligned
screen.TextRight({0, 2}, {16, 1}, "Right", 0);
```

### Text Size (Stretching)

The `size.Y` parameter controls vertical scaling:

```cpp
// Normal size (1 tile high)
screen.TextCenter({0, 0}, {16, 1}, "Normal", 0);

// Double height (2 tiles high)
screen.TextCenter({0, 2}, {16, 2}, "Double", 0);

// Triple height (3 tiles high)
screen.TextCenter({0, 5}, {16, 3}, "Triple", 0);
```

**Stretching Behavior:**
- `size.Y = 1`: Normal text height
- `size.Y = 2`: Double text height
- `size.Y = 3`: Tripple text height


### Flash String Support

```cpp
// Store strings in PROGMEM to save RAM
const __FlashStringHelper* label = F("Hello World");
screen.TextCenter({0, 0}, {16, 1}, label, 0);

// Or directly
screen.TextLeft({0, 0}, {16, 1}, F("Flash string"), 0);
```

## Pictograms

Pictograms are binary images stored in PROGMEM with a specific format.

### Pictogram Data Format

```cpp
// Format: [width_in_pixels][height_in_pixels][pixel_data...]
// Example: 16x8 pixel pictogram (2 tiles x 1 tile)
const uint8_t picto[] PROGMEM = {
    16, 8,  // Width in pixels (16), Height in pixels (8)
    // Pixel data (128 bits = 16 bytes)
    0x7e, 0xc3, 0x99, 0xbd, 0xbd, 0xbd, 0xbd, 0xbd,
    0x99, 0x81, 0x81, 0x81, 0x81, 0x81, 0xc3, 0x7e
};

screen.Picto({0, 0}, picto, 0);
```


### Custom Pictograms

```cpp
// Create a custom 16x16 pictogram (2x2 tiles)
const uint8_t customPicto[] PROGMEM = {
    16, 16,
    // Row 0 (16 bytes)
    0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff,
    // Row 1 (16 bytes)
    0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff
};

screen.Picto({0, 0}, customPicto, 0);
```
## Utility Scripts

The `fontsworkspace` directory contains tools for creating custom fonts and pictograms:

### font2textdir.py
Converts OpenType/TrueType font characters to pseudographics.

```bash
python font2textdir.py "arial.ttf" "Arial" 8 16
```

Each character is saved as a separate file in a subdirectory named after the font.

### txtdir2charmap.py
Converts text files with characters to a C array for microdisplays.

```bash
python txtdir2charmap.py ./Arial ./Arial.h "ArialFont"
```
