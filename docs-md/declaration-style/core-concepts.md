# Core Concepts

EVA Boxy serves user interfaces based on parent-child composition:

```text
┌─────────────────────────────┐
│           Parent            │
│  ┌──────────┐ ┌──────────┐  │
│  │  Child 1 │ │  Child 2 │  │
│  └──────────┘ └──────────┘  │
│  ┌────────────────────────┐ │
│  │       Child 3          │ │
│  └────────────────────────┘ │
└─────────────────────────────┘
```
**Note:** Parent-child in EVA Boxy means composition of objects, not class inheritance.

In EVA Boxy, every element is a rectangle (a "box") that knows how to draw itself within an allocated boundary.

Repeating this scheme recursively — where any child can be a parent for other children — forms layers.

Consistent interaction between these layers is ensured by two chains of responsibility:


1. **Draw - Freeze Chain** — top-down, from Parent to Child. Manages rendering state. 

2. **Key Chain** — bottom-up, from Child to Parent. Handles event processing.

Both chains are anchored by the EVA Boxy Singleton — a central runtime component that initializes the display driver and dispatches hardware key events via Boxy::key()

---

## The EVA Boxy Ground & Hardware Dispatch

At the base of every application is the central `EVA Boxy` ground. It bridges reactive hardware events to the active UI hierarchy and manages the display pipeline:

```cpp
// 1. Define your top-level layout layer
class MainGroundLayout : public LayoutBase { // or any other ElementBase 
    // ... root composition
};

// 2. Instantiate and bind to the EVA Boxy ground
MainGroundLayout mGroundLayer;

// 3. Dispatch hardware events into EVA Boxy
void onKeyPress() {
    // ...
    Boxy::key(KEY_DOWN);
    // ...
}

void setup() {
    // Initialize display driver, font, and active root layer
    Boxy::Begin<ScreenSSD1306, Font8Sharp>(&mGroundLayer);
}

void loop() {
    eva::tac();
}
```

---

## Two Chains of Responsibility

Through these layers flow **two primary chains of responsibility**:

1. **Draw – Freeze Chain:** Manages visual rendering and visibility state simultaneously.

2. **Key Chain:** Manages behavioral event processing and focus routing.

All library tools are designed to make implementing these chains as seamless as possible.

### Why Two Chains?

These two chains enable **event-driven updates** — the ability for elements to update themselves in response to external events (timers, sensor data, user input) without corrupting the display.

* **For the library:** This is essential. Elements can redraw themselves when their underlying data changes, while the freezer chain guarantees they only do so when currently visible.
* **For the user:** This provides a decoupled architecture. A child element can respond to its own events and request a redraw without requiring parent intervention or global state management.

---

## 1. Draw – Freeze Chain

Rendering and visibility management are two sides of the same mechanism, particularly relevant for containers with children. Before drawing, execution freezes all children. The user's `drawer()` code then simultaneously draws and unfreezes visible children. This simple rule effectively produces a branching execution tree of visible vs. invisible elements.

### The Draw Contract (`drawer` method)
Every element **has to** completely draw its rectangle, including clearing any unused areas. An element that fails to do so will leave visual garbage from previously drawn content.

All ready-made elements of the library implement this contract. When you create custom element classes, they **have to** implement this contract too.

```cpp
void drawer(Screen* screen, Coor pos, Coor size, bool focused) override {
    screen->TextCenter(pos, {size.X, 1}, "Hi", focused);
    screen->Clear({pos.X + 1, pos.Y}, {size.X - 1, aSize.Y}, focused);        // Clear allocated space to avoid visual artifacts
}
```

> **Helpers:** The `Grid` class greatly helps in implementing this contract by slicing rectangles for children and automatically handling the clearing of unused areas.

### The Freeze Contract
The rule is simple: **every parent has to freeze its children when the parent itself is frozen.** This ensures the entire invisible subtree stops redrawing.

All ready-made elements implement this contract. When you create custom containers, they should propagate freezing to all children.

```cpp
void freezer() override {
    // Freeze all children when I'm frozen
    child1.Freeze();
    child2.Freeze();
    child3.Freeze();
}
```

---

## 2. Key Chain (Event Processing)

Events propagate **bottom-up**. A child gets the first opportunity to handle a key. Only if the child does not handle it does the event travel up to the parent.

This arrangement allows different layers to handle the same keys without conflict — a grandchild may interpret `KEY_ENTER` as "select item", the child as "confirm", and the parent as "close dialog". Each layer gets its chance, and the first one that handles the key stops the propagation. No deadlocks, no conflicts.

### Helper: `CompositeBase`, `LayoutBase` 

`CompositeBase` and `LayoutBase` provide the foundation for building parent-child chains with focus management. They handle bottom-up propagation automatically so you don't have to manually pass events to children.

When building custom elements with `CompositeBase` or `LayoutBase`, you implement **`onResidualKey`** — a hook that is executed only if none of the nested children consumed the key event:

```cpp
class MyDialog : public LayoutBase {
protected:
    // Called ONLY if active children did not consume the key
    bool onResidualKey(unsigned char key) override {
        if (key == KEY_ENTER) {
            CloseDialog();
            return true; // Key consumed — stops propagation
        }
        return false; // Key unhandled — bubbles further up
    }
};
```
