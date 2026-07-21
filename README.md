# EVA Boxy Documentation

## Overview

EVA Boxy is a compact tile-based graphical framework for embedded systems, following the EVA (Extremely Versatile Architecture) ecosystem concept. It provides efficient UI development for resource-constrained devices.

## Key Features

- **Tile-based positioning** - All elements positioned on 8x8 pixel tiles
- **Multiple display drivers** - Support for various graphic and text displays
- **Automatic redraw** - Safe content updates without hierarchy traversal
- **Event-driven keyboard** - Complete keyboard handling with focus management
- **Extensible architecture** - Easy to add custom displays and UI elements
- **Low memory footprint** - Minimal RAM/ROM usage through efficient serialization

## Getting Started

### Minimal Example

```cpp
#include <evabBoxy.h>
#include <evabCompositeBase.h>
#include <evabInputInt.h>
#include <evabFont8Bold.h>
#include <evabScreenSSD1306.h>

class MyUI : public CompositeBase {
private:
    InputInt mValue;
    
public:
    MyUI() : mValue(42) {}
    
protected:
    void drawer(IScreen *screen, Coor pos, Coor size, unsigned char focused) override {
        mValue.Draw(screen, {0, 0}, {8, 1}, focused && IsFocused(&mValue));
    }
    
    void hider() override { mValue.Hide(); }
};

void setup() {
    Font8Bold font;
    MyUI ui;
    
    // Start with SSD1306 display
    Boxy::Begin<ScreenSSD1306, Font8Bold>(&ui, 800000L, 64);
}

void loop() {
    // Handle keyboard input
    if (Serial.available()) {
        char c = Serial.read();
        if (c == '+') Boxy::Key(KEY_PLUS);
        if (c == '-') Boxy::Key(KEY_MINUS);
        // ... other keys
    }
}
```

## Documentation Sections

1. **[Library Structure](structure.md)** - Core architecture and component organization
2. **[Display Drivers](display-drivers.md)** - Available display implementations and initialization
3. **[Pencil Mode](uc-paint.md)** - IScreen interface for drawing operations
4. **[Stamp Mode](uc-elements-stamps.md)** - ElementBase interface for UI components
5. **[Structured UI](uc-structured-ui.md)** - Composite interfaces for complex layouts
6. **[Keyboard Behavior](keyboard-behavior.md)** - Key handling and event management
7. **[Custom Display Driver](custom-display-driver.md)** - Extending the library with new displays

## Quick Reference

### Common Elements

| Element | Purpose |
|---------|---------|
| `InputInt` | Integer input field |
| `InputFloat` | Float input field |
| `Labeled<T>` | Wrapper with text label |
| `ListBox` | Scrollable list |
| `LayoutPane` | Grid layout (prototyping) |
| `CompositeBase` | Container for child elements |

### Fonts

| Font | Width | Style |
|------|-------|-------|
| `Font8Bold` | 8px | Bold |
| `Font8Compact` | 8px | Compact |
| `Font8Thin` | 8px | Thin |

### Tile Sets

| Tile Set | Count | Size | Use Case |
|----------|-------|------|----------|
| `PictosetOnOff` | 2 | 16×8 | Toggle states |
| `PictosetBattery` | 7 | 16×8 | Battery level |
| `PictosetSignal` | 4 | 16×8 | Signal strength |
| `PictosetLamp` | 6 | 16×16 | Lamp brightness |
| `PictosetProgress` | 9 | 16×16 | Progress indicator |
| `PictosetSpeaker` | 4 | 16×16 | Audio states |
| `PictosetFan` | 3 | 24×24 | Fan animation |
| `PictosetRoundmeter` | 9 | 32×24 | Circular gauge |
| `PictosetRainbowmeter` | 7 | 32×16 | Color gradient |

### Key Codes

```cpp
Keys: KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT,
      KEY_ENTER, KEY_ESCAPE, KEY_MENU, KEY_MODE,
      KEY_PLUS, KEY_MINUS,
      KEY_0 to KEY_9
```

### Keyboard Reactors

```cpp
// Auto increment/decrement with notifications
KeyReactor<InputInt, KEY_MINUS, KEY_PLUS> reactor(&listener, 42);

// Auto increment/decrement without notifications
KeyModifier<InputInt, KEY_LEFT, KEY_RIGHT> modifier(100);

// Catch specific keys
KeyCatcher<InputInt, KEY_ENTER, KEY_ESCAPE> catcher(&listener, 0);
```

## Dependencies

- Arduino framework
- Wire library (for I2C displays)
- SPI library (for SPI displays)

## License

See license file for details.

## Support

For issues and questions, please refer to the source code and examples in the library repository.