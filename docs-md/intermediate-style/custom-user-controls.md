# Custom User Controls & Extensibility

This section covers extending the library by creating custom components. Depending on the goal, you can either implement atomic controls from scratch or create specialized visual decorators.

---

## Technical Overview

* **Atomic Controls (Leaf Elements):** Classes deriving directly from `ElementBase`. They store state and render it to the screen, providing mutation interfaces (such as `Increment` or `SetValue`) without embedding input handling logic.
* **Visual Composition (Decorators):** Layout controls wrapping inner elements to manage visual placement, adding labels, units of measurement, or conditional status indicators without altering the core control logic.

---

## 1. Anatomy of an Atomic Control (`InputInt`)

As a design rule, behavior is applied via decorators using an implicit interface like `Increment`. Consequently, an atomic element like `InputInt` is strictly responsible for managing its own state and rendering it.

```cpp
#include <evabElementBase.h>

class InputInt : public ElementBase {
private:
    int mValue;

public:
    InputInt(int aValue = 0) : mValue(aValue) {}

    void SetValue(int aValue) {
        if (mValue != aValue) {
            mValue = aValue;
            redraw(); // Notify system that rendering state has changed
        }
    }

    int GetValue() const {
        return mValue;
    }

    // Implicit interface invoked by Reactors and KeyModifiers
    void Increment(signed char aSteps) {
        SetValue(mValue + aSteps);
    }

    void drawer(Screen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override {
        char buffer[20];
        itoa(mValue, buffer, 10);
        aScreen->TextCenter(aPos, aSize, buffer, aIsFocused);
    }
};
```

### Core Principle & Rendering Characteristics

* **State Notification (`redraw()`):** The central rule of state changes in an element is calling `redraw()`. Whenever internal values change (e.g., inside `SetValue`), invoking `redraw()` informs the UI engine that a repaint is needed.
* **Purity of `drawer()`:** The `drawer()` method is strictly side-effect free regarding control state. It reads the current values, formats them, and calls `Screen` API methods (`TextCenter`, `TextLeft`, etc.) without modifying member variables or triggering business logic.
* **Decoupled Input:** The base control does not intercept or process hardware key events directly. It exposes mutation methods (`Increment`), leaving event mapping entirely to external reactors or decorators.

---

## 2. Custom Visual Composition (`LabeledUnitAlarm`)

When standard layouts (like `LabeledLeftF`) are insufficient, custom layout decorators can be implemented. The following pattern demonstrates wrapping an inner control to display a label, unit string, and conditional alarm indicator side-by-side.

```cpp
#include <evabElementBase.h>

template <typename TControl>
class LabeledUnitAlarm : public ElementBase {
private:
    TControl mControl;
    const __FlashStringHelper* mLabel;
    const __FlashStringHelper* mUnit;
    int mThreshold;

public:
    template <typename... Args>
    LabeledUnitAlarm(const __FlashStringHelper* aLabel, const __FlashStringHelper* aUnit, int aThreshold, Args&&... aArgs)
        : mControl(static_cast<Args&&>(aArgs)...), mLabel(aLabel), mUnit(aUnit), mThreshold(aThreshold) {}

    TControl& GetControl() {
        return mControl;
    }

    void drawer(Screen* aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override {
        int x = aPos.X;

        // 1. Conditional status indicator based on value threshold
        if (mControl.GetValue() > mThreshold) {
            aScreen->TextLeft({x, aPos.Y}, {1, 1}, F("!"), aIsFocused);
        } else {
            aScreen->TextLeft({x, aPos.Y}, {1, 1}, F(" "), 0);
        }
        x += 1;

        // 2. Render label
        aScreen->TextLeft({x, aPos.Y}, {6, 1}, mLabel, 0);
        x += 6;

        // 3. Delegate rendering to inner control with narrowed bounding box
        int controlWidth = aSize.X - 10;
        mControl.Draw(aScreen, {x, aPos.Y}, {controlWidth, aSize.Y}, aIsFocused);
        x += controlWidth;

        // 4. Render units
        aScreen->TextLeft({x, aPos.Y}, {3, 1}, mUnit, 0);
    }
};
```

### Layout and Integration Rules

* **Coordinate Partitioning:** The enclosing decorator recalculates local bounds (`aPos`, `aSize`), passing the constrained sub-rectangle down to `mControl.Draw()`.
* **Behavior Forwarding:** Since `mControl` remains accessible (e.g., via `GetControl()`), key modifiers or reactors can be attached directly to either the wrapper or the inner element depending on navigation needs.
