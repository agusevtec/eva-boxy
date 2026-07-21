# Structured UI - Composite Elements

Structured UI in EVA Boxy allows building complex interfaces by composing multiple elements into containers. Two approaches are available:

1. **LayoutPane** - Quick prototyping with automatic layout
2. **CompositeBase** - Full control with custom composite elements

> **Note:** Structured UI works **with `evab::Boxy`** and provides automatic redraw capabilities.

## LayoutPane (Prototyping)

`LayoutPane` provides automatic layout for rapid prototyping. Elements are positioned using a numeric layout code.

```cpp
#include <evabLayoutPane.h>
#include <evabInputInt.h>
#include <evabLabeled.h>

// Create elements
Labeled<InputInt> param1("Param1", 10);
Labeled<InputInt> param2("Param2", 20);
InputButton button(F("OK"));

// Define layout
LayoutPaneItem items[] = {
    {&param1, {0, 0}, {8, 1}},
    {&param2, {0, 1}, {8, 1}},
    {&button, {0, 3}, {8, 1}}
};

LayoutPane layout;
layout.SetItems(123, items, 3);  // 123 defines the layout

// Draw
layout.Draw(screen, {0, 0}, {16, 8}, 0);
```

**Note:** `LayoutPane` is primarily for prototyping. For production code, use `CompositeBase`.

## CompositeBase (Production)

`CompositeBase` provides full control over composite elements with focus management and automatic redraw.

```cpp
#include <evabCompositeBase.h>
#include <evabInputInt.h>
#include <evabListBox.h>

class MyComposite : public evab::CompositeBase {
public:
    MyComposite() : mValue1("Param 1", 10), mValue2("Param 2", 20) {
        mList.SetItems(mItems, 2);
        focusChild(&mList);
    }
    
protected:
    void drawer(IScreen* screen, Coor pos, Coor size, unsigned char focused) override {
        // Draw title
        screen->TextCenter({pos.X, pos.Y}, {size.X, 1}, "Settings", focused);
        
        // Draw child
        mList.Draw(screen, {pos.X, pos.Y + 2}, {size.X, size.Y - 2}, 
                   IsFocused(&mList));
    }
    
    void hider() override {
        mList.Hide();
    }
    
    bool onResidualKey(Keys key) override {
        if (key == KEY_MENU) {
            // Toggle focus between children
            if (IsFocused(&mList)) {
                // Move to next child
            }
            Redraw();
            return true;
        }
        return false;
    }
    
private:
    Labeled<InputInt> mValue1;
    Labeled<InputInt> mValue2;
    ElementBase* mItems[2] = {&mValue1, &mValue2};
    ScrollListbox mList;
};
```

### Key Methods

```cpp
class CompositeBase : public ElementBase {
protected:
    // Call to change focused child
    void focusChild(ElementBase* child);
    
    // Check if child has focus
    bool IsFocused(ElementBase* child);
    
    // Override to handle keys not consumed by children
    virtual bool onResidualKey(Keys key);
    
    // Must implement - hides all children
    virtual void hider() = 0;
};
```

## Real-World Example

From the GraficInterface implementation:

```cpp
class GraficInterface : public evab::CompositeBase, public eva::IHandler {
public:
    GraficInterface(PhysicalControls* controls);
    
    void InitIndication(RxParameterGUI** params, unsigned char count);
    void InitSettings(RxParameterGUI** params, unsigned char count);
    void UpdateIndication(unsigned char index, unsigned short value, unsigned char percent);
    void ShowBattery(unsigned short value);
    
    void hider() override;

protected:
    void drawer(IScreen* screen, Coor pos, Coor size, unsigned char selected) override;
    bool onResidualKey(Keys key) override;
    
private:
    void invoke(void* sender, CallbackInfo info) override;
    
private:
    PhysicalControls* mPhysicalControls;
    FlipListbox mDashboardListbox;
    
    LabeledF<InputInt> mTXListboxItem0;
    LabeledF<InputInt> mTXListboxItem1;
    InputButton mRxSaveSettingsButton;
    InputButton mRxLoadDefaultsButton;
    ElementBase* mTXSettingsElemets[4];
    
    KeyCatcher<KeyModifier<ScrollListbox, KEY_UP, KEY_DOWN>, KEY_LEFT, KEY_RIGHT> mTXSettingsListbox;
    KeyCatcher<KeyModifier<ScrollListbox, KEY_UP, KEY_DOWN>, KEY_LEFT, KEY_RIGHT> mModelSettingsListbox;
};
```

### Composite Hierarchy

```cpp
void GraficInterface::drawer(IScreen* screen, Coor pos, Coor size, unsigned char selected) {
    if (IsFocused(&mDashboardListbox)) {
        // Dashboard view
        screen->TextCenter(pos, {size.X, 1}, F("DASHBOARD"), 0);
        mDashboardListbox.Draw(screen, {pos.X, pos.Y + 2}, {size.X, size.Y - 3}, 0);
        mTXSettingsListbox.Hide();
        mModelSettingsListbox.Hide();
    }
    if (IsFocused(&mTXSettingsListbox)) {
        // TX settings view
        screen->TextCenter(pos, {size.X, 1}, F("TX/RX SETS"), 0);
        mDashboardListbox.Hide();
        mTXSettingsListbox.Draw(screen, {pos.X, pos.Y + 2}, {size.X, size.Y - 3}, selected);
        mModelSettingsListbox.Hide();
    }
    if (IsFocused(&mModelSettingsListbox)) {
        // Model settings view
        screen->TextCenter(pos, {size.X, 1}, F("MODEL SETS"), 0);
        mDashboardListbox.Hide();
        mTXSettingsListbox.Hide();
        mModelSettingsListbox.Draw(screen, {pos.X, pos.Y + 2}, {size.X, size.Y - 3}, selected);
    }
}
```

## Automatic Redraw

### Redraw Mechanism (With Boxy)

When using Boxy, elements automatically redraw when their state changes:

```cpp
// Automatic redraw triggered by SetValue (when Boxy is active)
void SetValue(int newValue) {
    mValue = newValue;
    Redraw();  // ← Automatically redraws this element
}

// Redraw only updates the element, not the whole hierarchy
void Redraw() {
    if (IsHidden()) return;
    
    IScreen* screen = Boxy::Screen();  // ← Requires Boxy
    if (screen) {
        Coor pos, size;
        bool focused;
        screen->Deserialize(mSerialized, pos, size, focused);
        drawer(screen, pos, size, focused);  // Only redraws this element
    }
}
```

### Redraw Safety

Automatic redraw prevents unnecessary full-tree updates:

```cpp
// Value change only redraws the changed element
value.SetValue(42);  // Only InputInt redraws (with Boxy)

// Composite redraws all children
composite->Redraw();  // Full hierarchy redraws
```

### Redraw vs Draw

```cpp
// With Boxy - use Redraw for updates
value.SetValue(99);  // Auto-redraws if Boxy is active

// Manual redraw
composite->Redraw();  // Updates composite and children

// Force full redraw (re-draws everything)
composite->Draw(screen, pos, size, focused);
```

## Focus Management

### Basic Focus Control

```cpp
class MyComposite : public CompositeBase {
protected:
    void onInitialFocus() {
        focusChild(&mFirstChild);
    }
    
    bool onResidualKey(Keys key) override {
        if (key == KEY_MENU) {
            // Cycle through children
            if (IsFocused(&mChild1)) {
                focusChild(&mChild2);
            } else if (IsFocused(&mChild2)) {
                focusChild(&mChild3);
            } else {
                focusChild(&mChild1);
            }
            Redraw();
            return true;
        }
        if (key == KEY_PAGEDOWN) {
            // Switch between views
            focusChild(&mNextView);
            Redraw();
            return true;
        }
        return false;
    }
};
```

### Focus and Key Handling

```cpp
bool CompositeBase::Key(Keys key) {
    // First, give focused child opportunity to handle key
    if (mFocusedChild && mFocusedChild->Key(key))
        return true;
    
    // If not consumed, try residual keys
    return onResidualKey(key);
}
```

## Best Practices

### 1. Always Implement hider()

```cpp
void hider() override {
    child1.Hide();
    child2.Hide();
    child3.Hide();
}
```

### 2. Use Redraw() on State Changes (With Boxy)

```cpp
void setMode(Mode mode) {
    mMode = mode;
    Redraw();  // Update visual (requires Boxy)
}
```

### 3. Check Visibility

```cpp
void updateValue(int val) {
    mValue = val;
    if (!IsHidden()) {
        Redraw();  // Only redraw if visible (requires Boxy)
    }
}
```

### 4. Handle Focus Properly

```cpp
void drawer(IScreen* screen, Coor pos, Coor size, unsigned char focused) override {
    // Pass focus state to children
    bool childFocused = IsFocused(&mChild) && focused;
    mChild.Draw(screen, childPos, childSize, childFocused);
}
```

### 5. Initialize Boxy Before Using Redraw

```cpp
void setup() {
    MyRoot root;
    evab::Boxy::Begin<evab::ScreenSSD1306, evab::Font8Compact>(
        &root,
        800000L, 64
    );
    // Now Redraw() works
    root.Redraw();
}
```

## Summary

| Approach | Use Case | With Boxy | Redraw Support |
|----------|----------|-----------|----------------|
| LayoutPane | Prototyping | ✓ | Automatic |
| CompositeBase | Production | ✓ | Automatic |

**Key Points:**
- `LayoutPane` for quick prototyping with auto-layout
- `CompositeBase` for full control in production
- Structured UI **requires Boxy** for `Redraw()` functionality
- `Redraw()` only updates the element, not the hierarchy
- Focus management via `focusChild()` and `IsFocused()`
- Always implement `hider()` to clean up children
- Automatic redraw allows safe updates without full hierarchy traversal