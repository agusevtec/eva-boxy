# Element Composition: Focusable & LayoutBase

Interactive interfaces in EVA Boxy are structured around two core abstractions: **Focusable** (manages focus order and navigation state) and **LayoutBase** (provides layout coordination, event routing, and rendering contract).

Components are declared directly as class members. The declaration order defines the sequential focus navigation ring.

## Parent-Child Composition

In the framework, every element is a rectangle (a "box") that knows how to draw itself. Complex visual representation is formed by layers — elements nested inside other elements:

```text
┌─────────────────────────────┐
│          Parent             │
│  ┌──────────┐ ┌──────────┐  │
│  │  Child 1 │ │  Child 2 │  │
│  └──────────┘ └──────────┘  │
│  ┌────────────────────────┐ │
│  │       Child 3          │ │
│  └────────────────────────┘ │
└─────────────────────────────┘
```

## Technical Overview

### Inheritance and Rendering Contract
`LayoutBase` is designed as an **abstract base class intended strictly for subclassing** (directly or in combination with one of its template wrappers like `KeyModifier`). When implementing a custom view, form, or screen manager, you derive from `LayoutBase` or a wrapper class and implement the pure virtual `drawer()` method.

The implementation of `drawer()` must adhere to one strict rule:

* **Complete Area Coverage:** The implementation **must repaint or clear the entire screen area** defined by the `aPos` and `aSize` parameters passed to `drawer()`. Leaving unrendered regions causes visual artifacts during redrawing.

To simplify layout management and meet this requirement, the `Grid` helper class can be used to slice `aSize` into region-aligned bounding boxes and automatically clear unallocated space via `Clear()`.

### Focusable
`Focusable<T>` is a template wrapper that integrates a UI control or modifier into the focus ring of a container.

* **Registration:** Registers the encapsulated instance `T` with the parent `LayoutBase` upon construction.
* **Navigation Linkage:** Maintained via an internal doubly linked list (`Next()`, `Prev()`) initialized without dynamic memory allocations.
* **Passthrough Delegation:** Routes rendering calls, state operations, and freeze notifications directly to the inner type `T`.

### LayoutBase & Implicit Interface
`LayoutBase` tracks the active `Focusable` node and manages event propagation. Interaction between LayoutBase and target controls relies on C++ duck typing. Controls implement member functions expected by their active modifiers or handlers, such as:
* **`Increment()`** — Value modification (numeric adjustments, option cycling).

---

## Pattern 1: Single Form Element Focus

In a standard single-screen layout, focus transitions sequentially between individual fields via keyboard events.

```cpp
#include <evabLayoutBase.h>
#include <evabFocusable.h>
#include <evabKeyModifier.h>
#include <evabKeyReactor.h>
#include <evabKeyCatcher.h>
#include <evabInputInt.h>
#include <evabInputButton.h>
#include <evabBoxyRest.h>

// Derive from KeyModifier (which inherits from LayoutBase)
class FormExample : public KeyModifier<LayoutBase, KEY_DOWN, KEY_UP> {
    // Focus sequence: [1] mField1 -> [2] mField2 -> [3] mSaveBtn
    Focusable<KeyReactor<InputInt, KEY_LEFT, KEY_RIGHT>> mField1 {this, 10};
    Focusable<KeyReactor<InputInt, KEY_LEFT, KEY_RIGHT>> mField2 {this, 20};
    Focusable<KeyCatcher<InputButton, KEY_ENTER>>       mSaveBtn{this, &onSave, F("Save")};

    Handler<FormExample> onSave {this, &FormExample::onSave};
    void onSave(void*, CallbackInfo) { /* Execution logic */ }

public:
    void drawer(Screen* aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override {
        // Grid covers and manages the total allocated area
        Grid rest(aScreen, aPos, aSize);

        rest.CutRow(1).Draw(&mField1,  aIsFocused && IsFocused(&mField1));
        rest.CutRow(1).Draw(&mField2,  aIsFocused && IsFocused(&mField2));
        rest.CutRow(1).Draw(&mSaveBtn, aIsFocused && IsFocused(&mSaveBtn));
        
        // Clear remaining unallocated pixels in the area
        rest.Clear();
    }
};
```

### Event Handling Behavior
1. **`KEY_UP` / `KEY_DOWN`:** Captured by `KeyModifier<LayoutBase>` to shift focus between `Focusable` nodes.
2. **`KEY_LEFT` / `KEY_RIGHT`:** Passed to the currently focused node, triggering its internal `KeyReactor` to invoke `Increment()` or `Decrement()`.

---

## Pattern 2: Sub-screen (LayoutBase) Paging

When managing multi-screen flows or tabbed views, `Focusable` wraps entire `LayoutBase` instances. Focus transitions switch the active sub-screen. 

*(Note: Internal frame lifecycle and state freezing are automatically managed by `ElementBase` upon draw call dispatching)*.

```cpp
#include <evabLayoutBase.h>
#include <evabFocusable.h>
#include <evabKeyModifier.h>
#include <evabBoxyRest.h>

#include "ScreenStatus.h"
#include "ScreenSettings.h"
#include "ScreenInfo.h"

class PagedApp : public KeyModifier<LayoutBase, KEY_PAGEDOWN, KEY_PAGEUP> {
    // Focus sequence across full LayoutBase instances
    Focusable<ScreenStatus>   mStatusScreen   {this};
    Focusable<ScreenSettings> mSettingsScreen {this};
    Focusable<ScreenInfo>     mInfoScreen     {this};

public:
    void drawer(Screen* aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override {
        // Draw only the active sub-screen
        if (IsFocused(&mStatusScreen)) {
            mStatusScreen.Draw(aScreen, aPos, aSize, aIsFocused);
        } 
        else if (IsFocused(&mSettingsScreen)) {
            mSettingsScreen.Draw(aScreen, aPos, aSize, aIsFocused);
        } 
        else if (IsFocused(&mInfoScreen)) {
            mInfoScreen.Draw(aScreen, aPos, aSize, aIsFocused);
        }
    }
};
```

### Execution Characteristics
* Each sub-screen retains its own internal `Focusable` ring and key bindings.
* Outer key events (`KEY_PAGEDOWN` / `KEY_PAGEUP`) shift focus at the container level without interfering with inner sub-screen key mapping.
