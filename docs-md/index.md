# EVA Boxy Documentation

## Library Structure

EVA Boxy is a compact tile-based graphic framework designed for embedded systems with limited resources. The library follows the EVA (Extremely Versatile Architecture) ecosystem concept, providing a modular and efficient way to build user interfaces on microcontrollers.

### Core Concepts

#### Tile-Based Positioning
- **Minimum positioning unit is a tile**
- Each tile represents a single character cell or 8x8 pixel block
- Coordinates are expressed in tile units (X, Y)
- Screen sizes are measured in tiles (e.g., 16x8 for 128x64 pixel display)

#### Architecture Layers

1. **Display Drivers Layer** - Hardware abstraction for various display types
2. **Pencil Mode (IScreen)** - Direct drawing operations on the screen
3. **Stamp Mode (ElementBase)** - Reusable graphical elements with state management
4. **Structured UI** - Composite elements and layout management
5. **Keyboard Behavior** - Input handling and focus management

### Key Components

#### Core Classes

| Class | Purpose |
|-------|---------|
| `IScreen` | Interface for screen operations (text, pictograms, clearing) |
| `ScreenBase` | Base implementation of IScreen with text rendering |
| `ScreenPage8Base` | Base for page-oriented displays (8-pixel vertical strips) |
| `ElementBase` | Base class for all UI elements with drawing and hiding |
| `CompositeBase` | Container for multiple elements with focus management |
| `Boxy` | Global library manager and entry point |

#### Coordinate System

```cpp
struct Coor {
    unsigned char X, Y;
    Coor(int x = 0, int y = 0);
};
```

- Coordinates are 0-based
- X ranges from 0 to screen width in tiles - 1
- Y ranges from 0 to screen height in tiles - 1

### Basic Usage Pattern

```cpp
#include <evabBoxy.h>
#include <evabScreenSSD1306.h>
#include <evabFont8Compact.h>

// Define your root element
class MyRootElement : public ElementBase {
protected:
    void drawer(IScreen* screen, Coor pos, Coor size, unsigned char focused) override {
        screen->TextCenter(pos, size, "Hello World", focused);
    }
    void hider() override {}
};

void setup() {
    MyRootElement root;
    evab::Boxy::Begin<evab::ScreenSSD1306, evab::Font8Compact>(
        &root,
        800000L,  // I2C clock
        64        // Display height in pixels
    );
}

void loop() {
    // Process keyboard events
    if (buttonPressed) {
        evab::Boxy::Key(KEY_ENTER);
    }
}
```

### File Structure

```
evabBoxy/
├── Core/
│   ├── evabBoxy.h/cpp          - Library entry point
│   ├── evabCoor.h/cpp          - Coordinate system
│   ├── evabKeys.h              - Key definitions
│   └── evabIScreen.h           - Screen interface
├── Screens/
│   ├── evabScreenBase.h/cpp    - Base screen implementation
│   ├── evabScreenPage8Base.h/cpp - Page-based screen base
│   ├── evabScreenSSD1306.h/cpp - OLED display driver
│   ├── evabScreenPCD8544.h/cpp - Nokia 5110 driver
│   ├── evabScreenLCD_I2C.h/cpp - I2C LCD driver
│   ├── evabScreenKS0108.h/cpp  - KS0108 graphics driver
│   ├── evabScreenSSH1106.h/cpp - SSH1106 OLED driver
│   ├── evabScreenSerialPixel.h/cpp - Debug pixel display
│   └── evabScreenSerialText.h/cpp - Debug text display
├── Elements/
│   ├── evabElementBase.h/cpp   - Base UI element
│   ├── evabCompositeBase.h/cpp - Container element
│   ├── evabInputInt.h/cpp      - Integer input
│   ├── evabInputFloat.h/cpp    - Float input
│   ├── evabInputButton.h/cpp   - Button element
│   ├── evabInputPictogram.h    - Pictogram selector
│   ├── evabInputStretchBar.h   - Progress/scroll bars
│   ├── evabInputTextStretchBar.h - Text-based bars
│   ├── evabListBox.h           - List container
│   ├── evabLayoutPane.h/cpp    - Layout container (prototyping)
│   └── evabLabeled.h           - Label modifier
├── Fonts/
│   ├── evabIFont.h             - Font interface
│   ├── evabFont8Bold.h/cpp     - 8-pixel bold font
│   ├── evabFont8Compact.h/cpp  - 8-pixel compact font
│   └── evabFont8Thin.h/cpp     - 8-pixel thin font
├── Pictosets/
│   ├── evabPictosets.h/cpp      - Predefined pictogram sets
│   └── evabPictosetsStretchy.h/cpp - Resizable bar Pictosets
├── Behavior/
│   ├── evabBehavior.h          - Key modifiers and reactors
│   ├── evabWindowAlgorithms.h/cpp - Window scrolling algorithms
│   └── evabSerializers.h/cpp   - State serialization
└── Utilities/
    ├── font2textdir.py         - Convert TTF to pseudographics
    └── txtdir2charmap.py       - Convert text chars to C array
```

### Memory Considerations

- All coordinates use `unsigned char` (0-255) for compact storage
- Element state is serialized into 16-bit integers
- Font data stored in PROGMEM (flash memory)
- Minimal RAM usage through static allocation
- No dynamic memory allocation in core library

### Serialization

The library uses compact serialization to store element state:

```cpp
// 16x8 screens (16 tiles wide, 8 tiles high)
unsigned short Serialize(const Coor& pos, const Coor& size, bool isFocused);
void Deserialize(unsigned short serialized, Coor& pos, Coor& size, bool& isFocused);
```

Bit packing:
- Bit 0: Visibility
- Bit 1: Focus state
- Bits 2-5: X position (0-15)
- Bits 6-8: Y position (0-7)
- Bits 9-12: Width (1-16)
- Bits 13-15: Height (1-8)

## Next Steps

- [Display Drivers](display-drivers.md) - Understanding screen initialization
- [Pencil Mode](uc-paint.md) - Direct drawing with IScreen interface
- [Stamp Mode](uc-elements-stamps.md) - Reusable graphical elements
- [Structured UI](uc-structured-ui.md) - Building composite interfaces
- [Keyboard Behavior](keyboard-behavior.md) - Input handling and focus
- [Custom Display Driver](custom-display-driver.md) - Creating custom screen drivers