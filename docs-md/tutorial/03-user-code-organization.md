# 3. User Code Organization

This section covers how to organize user code without direct parent access and automatic element updates.

## Core Concepts

### Automatic Redrawing

Elements automatically redraw when their state changes. No manual screen refresh needed.

```cpp
#include <evabInputInt.h>

using namespace evab;

InputInt value(42);

// This automatically calls Redraw()
value.SetValue(100);

// This also triggers redraw
value.Increment(5);
```

### Redraw Mechanism

When `Redraw()` is called:
1. Checks if element is hidden (`IsHidden()`)
2. Gets current screen from `Boxy::Screen()`
3. Deserializes position, size, and focus state
4. Calls virtual `drawer()` method

```cpp
void ElementBase::Redraw() {
    if (IsHidden()) return;
    
    IScreen* screen = Boxy::Screen();
    if (screen) {
        Coor pos, sz;
        bool focused;
        deserialize(pos, sz, focused);
        drawer(screen, pos, sz, focused);
    }
}
```

## State Serialization

Elements store their state in a compact `unsigned short`:

| Bit(s) | Field |
|--------|-------|
| 0 | Visibility (1 = visible) |
| 1 | Focus state |
| 2-5 | Position X (0-15) |
| 6-8 | Position Y (0-7) |
| 9-12 | Size X (1-16, stored as value-1) |
| 13-15 | Size Y (1-8, stored as value-1) |

**Maximum display size:** 16×8 tiles

### Example: Creating a Custom Element

```cpp
#include <evabElementBase.h>
#include <evabIScreen.h>

using namespace evab;

class MyCustomElement : public ElementBase {
private:
    int mData;
    
    void drawer(IScreen* screen, Coor pos, Coor size, uint8_t focused) override {
        char buffer[20];
        itoa(mData, buffer, 10);
        screen->TextCenter(pos, size, buffer, focused);
    }
    
    void hider() override {
        // Optional: cleanup when hidden
    }
    
public:
    MyCustomElement(int value = 0) : mData(value) {}
    
    void SetValue(int value) {
        mData = value;
        Redraw(); // Automatic redraw
    }
    
    int GetValue() const { return mData; }
    
    bool Key(Keys key) override {
        // Handle key events
        return false;
    }
};
```

## No Direct Parent Access

Elements don't need to know about their parent. The framework handles:

1. **Drawing**: Parent passes screen, position, and size to child
2. **Focus**: Parent manages focus and passes focused state
3. **Hiding**: Parent calls `Hide()` on children

```cpp
class MyComposite : public CompositeBase {
private:
    MyCustomElement mElement;
    
    void drawer(IScreen* screen, Coor pos, Coor size, uint8_t focused) override {
        // Child doesn't know it's in a composite
        // All it sees is screen, position, size, and focus
        mElement.Draw(screen, pos, size, focused);
    }
    
    void hider() override {
        // Child handles hiding itself
        mElement.Hide();
    }
};
```

## Element Lifecycle

### Creation

```cpp
// Elements are created with initial values
InputInt* value = new InputInt(42);
Labeled<InputInt>* labeled = new Labeled<InputInt>("Value: ", 42);
```

### Drawing

```cpp
// Parent draws child at specified position
child.Draw(screen, {0, 0}, {16, 1}, true);
```

### Hiding

```cpp
// Hide element (stops redrawing)
child.Hide();

// Check if hidden
if (child.IsHidden()) {
    // Element is hidden
}
```

### Redrawing

```cpp
// Automatic on state change
child.SetValue(100); // Calls Redraw() internally

// Manual redraw
child.Redraw();
```

## Boxy - Global Context Manager

`Boxy` manages the global UI context:

```cpp
#include <evabBoxy.h>

using namespace evab;

// Initialize with ground element
Boxy::Begin<ScreenSSD1306, Font8Bold>(groundElement);

// Get current screen (null if modal shown)
IScreen* screen = Boxy::Screen();

// Send key events
Boxy::Key(KEY_ENTER);

// Show temporary popup
Boxy::ShowInt("Value: ", 42); // Shows for 1.2 seconds
```

### Modal Popups

```cpp
// Show integer popup (auto-hides after 1.2s)
Boxy::ShowInt("Temperature", 25);

// During popup, Boxy::Screen() returns nullptr
// Elements won't redraw until popup disappears
```

## Complete User Code Example

```cpp
#include <evabBoxy.h>
#include <evabScreenSSD1306.h>
#include <evabFont8Bold.h>
#include <evabInputInt.h>
#include <evabLabeled.h>
#include <evabCompositeBase.h>

using namespace evab;

class MyApplication : public CompositeBase {
private:
    Labeled<InputInt> mValue;
    Labeled<InputFloat> mTemp;
    
    void drawer(IScreen* screen, Coor pos, Coor size, uint8_t focused) override {
        // Draw children with automatic redraw
        mValue.Draw(screen, {pos.X, pos.Y}, {size.X, 1}, focused);
        mTemp.Draw(screen, {pos.X, pos.Y + 1}, {size.X, 1}, focused);
        
        // Draw separator
        screen->TextCenter({pos.X, pos.Y + 2}, {size.X, 1}, "----", 0);
    }
    
    void hider() override {
        mValue.Hide();
        mTemp.Hide();
    }
    
    bool onResidualKey(Keys key) override {
        if (key == KEY_ESCAPE) {
            // Handle escape
            return true;
        }
        return false;
    }
    
public:
    MyApplication() : 
        mValue("Value: ", 42),
        mTemp("Temp: ", 36.6f) {}
};

// Global instance
MyApplication app;

void setup() {
    static Font8Bold font;
    Boxy::Begin<ScreenSSD1306, Font8Bold>(&app);
}

void loop() {
    // Handle hardware buttons
    if (digitalRead(BUTTON_UP) == LOW) {
        Boxy::Key(KEY_UP);
        delay(50);
    }
    if (digitalRead(BUTTON_DOWN) == LOW) {
        Boxy::Key(KEY_DOWN);
        delay(50);
    }
    if (digitalRead(BUTTON_ENTER) == LOW) {
        Boxy::Key(KEY_ENTER);
        delay(50);
    }
}
```

---