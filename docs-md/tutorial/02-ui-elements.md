# 2. UI Elements (Footprint)

This section covers using EVAB's UI elements for building user interfaces.

## Element Hierarchy

```
ElementBase (abstract)
├── InputInt
├── InputFloat
├── CompositeBase (abstract)
│   └── (user-defined composites)
├── LayoutPane
└── ListBox<T>
    ├── ScrollListbox
    └── FlipListbox
```

## Basic UI Elements

### InputInt - Integer Input

Displays and edits integer values.

```cpp
#include <evabInputInt.h>

using namespace evab;

// Create with initial value
InputInt value(42);

// Get/set value
value.SetValue(100);
int current = value.GetValue();

// Increment/decrement
value.Increment(1);  // +1
value.Increment(-1); // -1

// Redraw will happen automatically
```

### InputFloat - Float Input

Displays and edits floating-point values.

```cpp
#include <evabInputFloat.h>

using namespace evab;

// Create with initial value
InputFloat temperature(36.6);

// Get/set value
temperature.SetValue(37.2);
float current = temperature.GetValue();

// Increment/decrement
temperature.Increment(1);  // +1.0
temperature.Increment(-1); // -1.0
```

### BatteryIndicator

Displays voltage as a battery icon.

```cpp
#include <evabBatteryIndicator.h>

using namespace evab;

BatteryIndicator battery;

// Set voltage (will display as "3.70v")
battery.SetVoltage(3.7);

// Redraw automatically called
```

## Labeled Elements

Wrap any element with a label using `Labeled` template.

```cpp
#include <evabLabeled.h>
#include <evabInputInt.h>

using namespace evab;

// Label on same line (if height == 1)
Labeled<InputInt> labeled1("Value: ", 42);

// Label on separate line (if height > 1)
// Label will be on top, input below
Labeled<InputInt> labeled2("Value: ", 42);

// With flash string labels (PROGMEM)
LabeledF<InputInt> labeled3(F("Temp: "), 25);
```

**Layout:**
- If `aSize.Y == 1`: Label takes 2/3 of width, input takes 1/3
- If `aSize.Y > 1`: Label on first row, input on remaining rows

## ListBox

Scrollable list of elements with windowing algorithms.

```cpp
#include <evabListBox.h>

using namespace evab;

// Create elements
InputInt item1(10);
InputInt item2(20);
InputInt item3(30);
InputInt item4(40);

ElementBase* items[] = {&item1, &item2, &item3, &item4};

// Scrollable listbox (smooth scrolling)
ScrollListbox scrollList;
scrollList.SetItems(items, 4)
          .SetItemHeight(1); // Each item takes 1 row

// Flip listbox (page-based scrolling)
FlipListbox flipList;
flipList.SetItems(items, 4)
        .SetItemHeight(1);

// Select item
flipList.Select(2);

// Get selected item
ElementBase* selected = flipList.GetItem(2);

// Increment selection
flipList.Increment(1);  // Next item
flipList.Increment(-1); // Previous item
```

**Window Algorithms:**
- `ScrollWindowAlgorithm`: Smooth scrolling with one visible edge
- `FlipWindowAlgorithm`: Page-based scrolling

## LayoutPane

Organizes elements using a numeric layout.

```cpp
#include <evabLayoutPane.h>

using namespace evab;

// Create elements
ElementBase* elem1 = new InputInt(1);
ElementBase* elem2 = new InputInt(2);
ElementBase* elem3 = new InputInt(3);

// Layout definition: 123 means 1 row with 3 columns
// 12/3 means 2 rows: first with 2 columns, second with 1
unsigned short layout = 123; // or 12, 1234, etc.

LayoutPaneItem items[] = {
    {elem1, {0, 0}, {4, 1}},
    {elem2, {4, 0}, {4, 1}},
    {elem3, {8, 0}, {4, 1}}
};

LayoutPane layoutPane;
layoutPane.SetItems(layout, items, 3);
```

## Composite Elements

Build complex UI from multiple elements.

```cpp
#include <evabCompositeBase.h>
#include <evabInputInt.h>
#include <evabLabeled.h>

using namespace evab;

class MyComposite : public CompositeBase {
private:
    Labeled<InputInt> mValue;
    Labeled<InputFloat> mTemp;
    
    void drawer(IScreen* screen, Coor pos, Coor size, uint8_t focused) override {
        // Draw all child elements
        mValue.Draw(screen, {pos.X, pos.Y}, {size.X, 1}, focused);
        mTemp.Draw(screen, {pos.X, pos.Y + 1}, {size.X, 1}, focused);
    }
    
    void hider() override {
        mValue.Hide();
        mTemp.Hide();
    }
    
    bool onResidualKey(Keys key) override {
        // Handle keys not handled by children
        return false;
    }
    
public:
    MyComposite() : mValue("Value: ", 42), mTemp("Temp: ", 36.6f) {}
};
```

## Behavior Modifiers

### KeyCatcher

Catches specific keys and forwards to a listener.

```cpp
#include <evabBehavior.h>

using namespace evab;

class MyListener : public eva::IHandler {
    void invoke(void* sender, eva::CallbackInfo info) override {
        if (info.EventType == KeyCatcher<InputInt, KEY_UP, KEY_DOWN>::EVENT_CATCH_KEY) {
            // Handle caught key
            Keys key = (Keys)info.Param;
            // ...
        }
    }
};

MyListener listener;
KeyCatcher<InputInt, KEY_UP, KEY_DOWN> catcher(&listener, 42);
```

### KeyModifier

Adds increment/decrement keys to any element.

```cpp
#include <evabBehavior.h>

using namespace evab;

// Elements with value get KEY_UP/KEY_DOWN for inc/dec
KeyModifier<InputInt, KEY_UP, KEY_DOWN> inputWithKeys(42);

// Pressing KEY_UP increments, KEY_DOWN decrements
```

### KeyReactor

Like KeyModifier but also notifies listener of value changes.

```cpp
#include <evabBehavior.h>

using namespace evab;

class ChangeListener : public eva::IHandler {
    void invoke(void* sender, eva::CallbackInfo info) override {
        if (info.EventType == KeyReactor<InputInt, KEY_UP, KEY_DOWN>::EVENT_VALUE_CHANGED) {
            int newValue = info.Param;
            // Handle value change
        }
    }
};

ChangeListener listener;
KeyReactor<InputInt, KEY_UP, KEY_DOWN> reactor(&listener, 42);
```

---