# Behavioral Modifiers & Implicit Interfaces

Behavioral modifiers are template decorators that change **how** an element behaves — how it responds to keys, what events it generates, or how its value is interpreted. Unlike visual modifiers, they don't change the element's appearance; they change its interaction model.

These modifiers rely on **implicit interfaces** — a convention in method naming within EVA Boxy. Instead of a formal inheritance hierarchy or abstract base classes, EVA Boxy uses duck typing: if an element has the required methods, the modifier works. This approach keeps the library lightweight and avoids virtual table overhead.

---

## The Four Implicit Interfaces

EVA Boxy recognizes four implicit interfaces that elements can implement:

| Interface | Methods | Purpose |
|-----------|---------|---------|
| **Value** | `SetValue(T)`, `GetValue()` | Numeric data (int, float) |
| **Increment** | `Increment(delta)` | Step-based navigation (next/previous) |
| **Index** | `Select(idx)`, `Selected()`, `Count()` | Selection from a set |
| **Percent** | `SetPercent(0-100)`, `GetPercent()` | Relative values (0-100%) |

**The Increment Interface:** This interface represents the ability to move forward or backward by a step. Many interactive elements support it — from `InputInt` (changes value) to `LayoutBase` (changes focus).

```cpp
// Increment is meaningful for these
InputInt value(42);
value.Increment(+1);   // → 43

LayoutBase form;
form.Increment(+1);    // → moves focus to next child
```

---

## Elements and Their Interface Support

| Element | Value | Increment | Index | Percent |
|---------|-------|-----------|-------|---------|
| `InputInt` | 🟢 Yes | 🟢 Yes | 🔴 No | 🔴 No |
| `InputFloat` | 🟢 Yes | 🟢 Yes | 🔴 No | 🔴 No |
| `InputIntDiscrete` | 🟢 Yes | 🟢 Yes | 🟢 Yes | 🟡 Yes (via `Percent<T>`) |
| `InputFloatDiscrete` | 🟢 Yes | 🟢 Yes | 🟢 Yes | 🟡 Yes (via `Percent<T>`) |
| `InputSelectorPx<T>` | 🔴 No | 🟢 Yes | 🟢 Yes | 🟡 Yes (via `Percent<T>`) |
| `InputAnimationPx` | 🔴 No | 🟢 Yes | 🟢 Yes | 🟡 Yes (via `Percent<T>`) |
| `InputButton` | 🔴 No | 🟡 Dummy | 🔴 No | 🔴 No |
| `InputButtonPx` | 🔴 No | 🟡 Dummy | 🔴 No | 🔴 No |
| `LayoutBase` | 🔴 No | 🟢 Yes | 🔴 No | 🔴 No |
| `ListBox<T>` | 🔴 No | 🟢 Yes | 🟢 Yes | 🟡 Yes (via `Percent<T>`) |
| **StretchBars** | 🔴 No | 🟢 Yes | 🔴 No | 🟢 Yes |
| `ScrollListbox` | 🔴 No | 🟢 Yes | 🟢 Yes | 🟡 Yes (via `Percent<T>`) |
| `FlipListbox` | 🔴 No | 🟢 Yes | 🟢 Yes | 🟡 Yes (via `Percent<T>`) |

**Legend:**

- 🟢 **Yes** — Supported natively (built into the class)

- 🟡 **Dummy** — Implemented as no-operation (for interface completeness)

- 🟡 **Yes (via mod.)** — Supported via `Percent<T>` modifier

- 🔴 **No** — Not supported

**Note on StretchBars** This group includes all progress and scroll bar variants:

- `VerticalProgressBarPx`, `HorizontalProgressBarPx`

- `VerticalScrollBarPx`, `HorizontalScrollBarPx`

- `VerticalProgressBar`, `HorizontalProgressBar`

- `VerticalScrollBar`, `HorizontalScrollBar`

The step of `Increment()` for these elements is **variable** — it depends on the visual representation. Each `Increment(+1)` moves the bar by exactly one visual block (one pictogram or one character position). The actual percent change depends on how many blocks fit in the current drawing area.

This is why StretchBar elements support **Increment** (visual step) and **Percent** (0-100% value), but not **Index** (no fixed discrete positions) — the number of positions is determined by the available space at draw time.

---

## The Percent Modifier

`Percent<T>` transforms an **Index-based** element into a **Percent-based** interface. This is useful when you want to control selection using a 0-100% scale.

**How it works:** `Percent<T>` takes an element that implements the Index interface (`Select()`, `Selected()`, `Count()`) and adds `SetPercent()` and `GetPercent()` methods. The percentage is automatically mapped to the index range.

```cpp
#include <evabPercent.h>

// Album selector (Index) → Percent control
Percent<InputSelectorPx<AlbumBattery>> batteryPercent(3);

// Animation speed (Index) → Percent control
Percent<InputAnimationPx<AlbumFan>> fanSpeedPercent(5);  // 5 → 50% of max speed

// ListBox (Index) → Percent control
Percent<ScrollListbox> listPercent(33);

// Discrete int (Value + Index) → Percent control
Percent<InputIntDiscrete> discretePercent(50);
```

| Feature | Description |
|---------|-------------|
| `SetPercent(0-100)` | Sets value as a percentage, mapped to index range |
| `GetPercent()` | Returns current value as a percentage |
| `GetStep()` | Returns the step size in percent |

---

## Behavioral Modifiers

### KeyModifier

Adds keyboard control to any element that has a meaningful `Increment()` method. When the specified keys are pressed, the value changes accordingly.

```cpp
#include <evabKeyModifier.h>

// Int with UP/DOWN control — meaningful
KeyModifier<InputInt, KEY_DOWN, KEY_UP> intControl(42);

// Album selector with LEFT/RIGHT control — meaningful
KeyModifier<InputSelectorPx<AlbumBattery>, KEY_LEFT, KEY_RIGHT> batteryControl(3);

// Animation speed with UP/DOWN — meaningful
KeyModifier<InputAnimationPx<AlbumFan>, KEY_DOWN, KEY_UP> fanControl(5);

// Layout navigation with UP/DOWN — meaningful
KeyModifier<LayoutBase, KEY_DOWN, KEY_UP> formNavigation();

// Stretch bar with LEFT/RIGHT — steps by one visual block
KeyModifier<HorizontalProgressBarPx, KEY_LEFT, KEY_RIGHT> progressControl(50);

// Percent-modified selector with UP/DOWN — meaningful
KeyModifier<Percent<InputSelectorPx<AlbumBattery>>, KEY_DOWN, KEY_UP> percentControl(3);
```

| Parameter | Description |
|-----------|-------------|
| `T` | Element type (must have `Increment()`) |
| `kDec` | Key code for decrement |
| `kInc` | Key code for increment |

> **Note on Buttons:** `InputButton` and `InputButtonPx` implement `Increment()` as a dummy (no-operation) method. This is done for interface completeness, but makes `KeyModifier` effectively useless on them — pressing keys does nothing. For buttons, use `KeyCatcher` instead.

```cpp
// Button with keys — compiles but does nothing (dummy Increment)
KeyModifier<InputButton, KEY_DOWN, KEY_UP> uselessButtonControl(F("OK"));  // ⚠️ No effect!
```

---

### KeyReactor

Similar to `KeyModifier`, but additionally generates an event when the value changes. The event can be captured by a handler.

```cpp
#include <evabKeyReactor.h>

class MyForm : public LayoutBase, private eva::IHandler {
    KeyReactor<InputInt, KEY_DOWN, KEY_UP> mValue {this, 42};
    
public:
    void invoke(void* sender, CallbackInfo info) override {
        Serial.println("Value changed!");
    }
};
```

---

### KeyCatcher

Intercepts specific keys and generates an event. This is the recommended way to handle button presses, since `KeyModifier` has no effect on buttons.

```cpp
#include <evabKeyCatcher.h>

class MyForm : public LayoutBase, private eva::IHandler {
    // KeyCatcher is the right tool for buttons
    Focusable<KeyCatcher<InputButton, KEY_ENTER>> mSaveButton {this, F("Save")};
    Focusable<KeyCatcher<InputButtonPx, KEY_ENTER>> mIconButton {this, GalleryRemixicon24::PICTO_F243};
    
public:
    void invoke(void* sender, CallbackInfo info) override {
        if (sender == &mSaveButton) {
            Serial.println("Save pressed!");
        }
        if (sender == &mIconButton) {
            Serial.println("Icon button pressed!");
        }
    }
};
```
