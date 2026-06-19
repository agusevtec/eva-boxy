# EVAB Library Documentation

## Overview

EVAB (Embedded Visual Application Builder) is a lightweight GUI library for embedded systems with graphical displays. It provides a complete framework for building user interfaces with support for various display controllers, input handling, and UI elements.

**Key Features:**
- Display driver abstraction with support for multiple controllers
- UI element framework with automatic redrawing
- Keyboard/button input handling with event system
- Composite elements for complex layouts
- Flash memory optimization for fonts and graphics
- Support for both graphical (pixel-based) and character LCD displays

## Quick Start

```cpp
#include <evabBoxy.h>
#include <evabScreenSSD1306.h>
#include <evabFont8Bold.h>
#include <evabInputInt.h>
#include <evabLabeled.h>

using namespace evab;

// Define your UI
class MyUI : public CompositeBase {
private:
    Labeled<InputInt> mValue;
    
    void drawer(IScreen *screen, Coor pos, Coor size, uint8_t focused) override {
        mValue.Draw(screen, pos, size, focused);
    }
    
    void hider() override {
        mValue.Hide();
    }
    
public:
    MyUI() : mValue("Value: ", 42) {}
};

void setup() {
    static Font8Bold font;
    Boxy::Begin<ScreenSSD1306, Font8Bold>(new MyUI());
}

void loop() {
    // Handle keys
    if (buttonPressed()) {
        Boxy::Key(KEY_ENTER);
    }
}
```

---