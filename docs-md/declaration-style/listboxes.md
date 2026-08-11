# Listboxes: Containers & Custom Visual Wrappers

`ListBox` is a ready-to-use container designed for heterogeneous collections of interactive elements. Unlike custom implementations based on `LayoutBase`, `ListBox` provides fully encapsulated navigation, windowing, and clipping behavior out of the box, requiring no subclassing to alter control logic.

Elements inside the list retain their individual key bindings and value modifiers, while navigation, viewport calculations, and focus tracking are automatically managed by the container.

For convenience, two primary typedefs are provided based on the windowing strategy:
```cpp
using ScrollListbox = ListBox<ScrollWindowAlgorithm>; ///< Scrollable list box (line-by-line scrolling)
using FlipListbox   = ListBox<FlipWindowAlgorithm>;   ///< Flip-based list box (page-by-page paging)
```

---

## Technical Overview

### Windowing Strategies: Scroll vs. Flip
* **`ScrollListbox` (`ScrollWindowAlgorithm`):** Incremental scrolling that shifts focus item-by-item, smoothly advancing the viewport when reaching boundary edges.
* **`FlipListbox` (`FlipWindowAlgorithm`):** Page-based traversal that flips entire visible blocks at once when navigating past the viewport boundary, ideal for compact screens and rapid paging.

### Construction and Pointer Arrays
`ListBox` accepts a row height parameter and an array of pointers to `ElementBase` instances (`ElementBase* items[]`) in its constructor.

* **Heterogeneous Composition:** Elements inside the list do not need to be of the same type. Any control deriving from `ElementBase` (including elements wrapped in `KeyModifier`, `LabeledLeftF`, `Padding`, or `Percent`) can be passed into the container.
* **Row Height Alignment:** The integer height parameter defines the fixed vertical span allocated to each item within the viewport.
* **Focus Propagation:** Focus state is forwarded directly to the active, visible child element. This ensures seamless event routing (e.g., `KEY_LEFT` / `KEY_RIGHT` for value changes) while the container itself intercepts vertical events (`KEY_UP` / `KEY_DOWN`) for scrolling or flipping.

### Visual Customization Pattern
`ListBox` is designed as a closed component regarding its navigation logic—there is no need to override it. However, visual decoration (such as custom scrollbars, outer paddings, or borders) is easily achieved through **composition via template wrappers** (e.g., `Percent<T>`) or by creating a custom wrapper that invokes `ListBox::drawer()` within a reduced bounding box.

---

## Pattern 1: Standard Listbox Container

In standard forms or menus, `ScrollListbox` (or `FlipListbox`) is wrapped in a `KeyModifier` to intercept vertical navigation keys and automatically manage scrolling or page flipping.

```cpp
#include <evabScrollListbox.h>
#include <evabKeyModifier.h>
#include <evabLabeled.h>
#include <evabInputInt.h>
#include <evabLayoutBase.h>

class StandardMenu : public KeyModifier<LayoutBase, KEY_DOWN, KEY_UP> {
    // Elements with individual key handlers and labels
    KeyModifier<LabeledLeftF<InputInt>, KEY_LEFT, KEY_RIGHT> mSpeed {F("Speed"), 13};
    KeyModifier<LabeledLeftF<InputInt>, KEY_LEFT, KEY_RIGHT> mCourse{F("Course"), 37};
    KeyModifier<LabeledLeftF<InputInt>, KEY_LEFT, KEY_RIGHT> mFuel  {F("Fuel"), 95};

    // Array of element pointers to initialize the list
    ElementBase* mItems[3] = {&mSpeed, &mCourse, &mFuel};

    // ScrollListbox with row height 2, capturing UP/DOWN for navigation
    Focusable<KeyModifier<ScrollListbox, KEY_UP, KEY_DOWN>> mListbox{this, 2, mItems};

public:
    void drawer(Screen* aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override {
        mListbox.Draw(aScreen, aPos, aSize, aIsFocused && IsFocused(&mListbox));
    }
};
```

---

## Pattern 2: Custom Decorated Listbox (Scrollbar Integration)

To add custom visual elements (such as a vertical scrollbar), create a wrapper class deriving from a layout decorator (e.g., `Percent<ScrollListbox>`) or `ScrollListbox` itself. The wrapper adjusts the coordinates passed to `ScrollListbox::drawer()` and renders auxiliary elements in the remaining area.

```cpp
#include <evabScrollListbox.h>
#include <evabPercent.h>
#include <evabVerticalScrollBarPx.h>

// Custom Listbox with a vertical scrollbar on the right
class CustomListbox : public Percent<ScrollListbox> {
public:
    using Percent<ScrollListbox>::Percent;

    void drawer(Screen* aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override {
        // 1. Render the base ScrollListbox in a narrowed viewport (reserving 3 pixels on the right)
        ScrollListbox::drawer(aScreen, {aPos.X + 1, aPos.Y}, {aSize.X - 3, aSize.Y}, aIsFocused);

        // 2. Render a vertical scrollbar in the reserved right margin
        VerticalScrollBarPx scrollbar(100 - GetPercent());
        scrollbar.Draw(aScreen, {aPos.X + aSize.X - 1, aPos.Y}, {1, aSize.Y}, 0);
    }
};
```

### Usage Example in a Container

```cpp
#include <evabLayoutBase.h>
#include <evabKeyModifier.h>
#include <evabLabeled.h>
#include <evabInputInt.h>
#include <evabHorizontalProgressBarPx.h>

class DecoratedMenuApp : public KeyModifier<LayoutBase, KEY_DOWN, KEY_UP> {
    KeyModifier<LabeledLeftF<InputInt>, KEY_LEFT, KEY_RIGHT> mItem0{F("Speed"), 13};
    KeyModifier<LabeledLeftF<InputInt>, KEY_LEFT, KEY_RIGHT> mItem1{F("Course"), 37};
    KeyModifier<LabeledLeftF<HorizontalProgressBarPx>, KEY_LEFT, KEY_RIGHT> mItem2{F("Delay"), 30};

    ElementBase* mItems[3] = {&mItem0, &mItem1, &mItem2};

    // Listbox with custom drawing and a scrollbar
    Focusable<KeyModifier<CustomListbox, KEY_UP, KEY_DOWN>> mCustomListbox{this, 2, mItems};

public:
    void drawer(Screen* aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override {
        aScreen->TextCenter(aPos, {aSize.X, 1}, F("SETTINGS"), 0);
        mCustomListbox.Draw(aScreen, {aPos.X, aPos.Y + 2}, {aSize.X, aSize.Y - 2}, aIsFocused && IsFocused(&mCustomListbox));
    }
};
```

### Execution Characteristics
* **Independent Navigation and Editing:** Navigation keys (`KEY_UP` / `KEY_DOWN`) shift focus through items via `KeyModifier<CustomListbox>`, while `KEY_LEFT` / `KEY_RIGHT` are passed down to the focused row item to modify values.
* **State Integrity:** Child elements inside `ListBox` that fall outside the visible viewport area are automatically frozen by runtime checks in `ElementBase`, preventing unnecessary redraw operations.
