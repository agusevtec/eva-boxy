## Introduction

**EVA Boxy** is a lightweight C++ UI framework designed for resource-constrained embedded displays (OLED, monochrome LCDs) driven by physical keypads.

### Why EVA Boxy?

The core priority of EVA Boxy is developer comfort when building user interfaces.

Writing complex UI is enjoyable when the code is declarative, visual, and easily maintainable — just like in large desktop frameworks. However, a straightforward port of desktop patterns to microcontrollers is unviable: they rely on heavy class hierarchies, virtual tables, and dynamic memory allocation, which are fatal for resource-constrained embedded systems.

EVA Boxy breaks these limitations by leveraging the EVA approach.

Its defining architectural genotype is compile-time decorator composition, allowing you to include only the exact resources you need. Paired with deliberate functional boundaries — zero z-order, zero clipping buffers, and zero dynamic allocations — Boxy delivers pure, deterministic pixel execution.

At the same time, EVA Boxy remains comfortable for developers who prefer a traditional imperative style or require direct display control. The framework is optimized for text and symbol rendering on low-resolution displays, with optional pictogram support for icon-based interfaces.

### Architectural Styles

EVA Boxy scales cleanly depending on your task, performance budget, and architectural preferences:

#### 1. Primary Style: Declarative UI (Flagship)

The primary way to use EVA Boxy. Build complex, highly maintainable interactive screens using a clean, expressive syntax. You assemble core data inputs (`InputInt`), behavioral modifiers (`KeyReactor`, `KeyCatcher`), and visual wrappers (`Labeled`) directly via C++ compile-time templates — getting modern UI code ergonomics without paying a runtime memory penalty:

```cpp
class UserForm1 : public KeyModifier<LayoutBase, KEY_UP, KEY_DOWN> {
    Focusable<KeyReactor<InputInt, KEY_LEFT, KEY_RIGHT>> mInputField {this, &onValueChanged, 42};
    Focusable<KeyCatcher<InputButton, KEY_LEFT, KEY_RIGHT >> mSaveButton {this, &onSavePressed, "Save"};

    Handler<UserForm1> onValueChanged {this, &UserForm1::onValueChanged};
    void onValueChanged(void *aSender, CallbackInfo aInfo) {
        Serial.println("Value Changed");
    }

    Handler<UserForm1> onSavePressed {this, &UserForm1::onSavePressed};
    void onSavePressed(void *aSender, CallbackInfo aInfo) {
        Serial.println("Parameter Saved");
    }

    void drawer(Screen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override {
        BoxyRest rest(aScreen, aPos, aSize, aIsFocused);
        rest.CutRow(1).Draw(mInputField, IsFocused(&mInputField));
        rest.CutRow(1).Clear();
        rest.CutRow(1).Draw(mSaveButton, IsFocused(&mSaveButton));
        rest.Clear();
    }
};
```

**Visual Representation:**

```
┌───────────────────────────────────────────┐
│                    42                     │  ← InputInt
└───────────────────────────────────────────┘
│                                           │  ← Empty row 
┌───────────────────────────────────────────┐
│                  (Save)                   │  ← InputButton
└───────────────────────────────────────────┘
│                                           │  ← Empty rest
└───────────────────────────────────────────┘
```

**Navigation:**

- `KEY_UP` / `KEY_DOWN` — navigate between fields (handled by `KeyModifier<LayoutBase>`)

- `KEY_LEFT` / `KEY_RIGHT` — on InputInt → change value and triggers `onValueChanged`

- `KEY_LEFT` / `KEY_RIGHT` — on button → triggers `onSavePressed`

#### 2. Imperative Style (Fallback & Maximum Optimization)

For developers who prefer direct, traditional control or need absolute minimal resources usage. Even in direct-to-screen mode, Boxy upgrades standard imperative code with a **Guaranteed Bounding Box Principle**: every visual element strictly owns, clears, and renders within its assigned rectangular area. No visual artifacts, no manual clear-screen hacks, plus integrated vector icons powered by Remixicon.

Draw call explicitly defines its spatial boundaries using rest or pixel coordinates: `{X, Y}, {Width, Height}`

```cpp
screen.TextCenter({0, 1}, {16, 1}, "Size 1", 0); 
screen.TextCenter({0, 3}, {16, 2}, "Size 2", 0); 
screen.Picto({0, 5}, GalleryRemixicon16::PICTO_F243, 0);
```

#### 3. Intermediate Style (Contract-Based / Custom Components)

An advanced tier for building custom UI elements. It acts as the explicit optimization bridge: when compile-time declarative composition approaches resource limits, you can selectively refactor critical parts toward imperative execution.

Thanks to EVA Boxy's clear internal contracts (drawing routines, and event handling), you can smoothly shift components down toward low-level imperative code — extracting maximum performance while preserving full integration with the higher-level focus and event propagation engine.

Because of this complexity, the Intermediate Style is covered in detail in the final sections of this documentation.

### What EVA Boxy Provides

| Feature | Description |
|---------|-------------|
| Component Primitives | Extensible base elements designed for compile-time composition via EVA Core decorators. |
| Out-of-the-Box Controls | A rich set of pre-built, production-ready interactive widgets (inputs, buttons, indicators). |
| Form Management | Structured layout tools and contract-based base classes to construct complex custom screens cleanly. |
| Hardware Agnostic | Seamless support for diverse displays driven by a ultra-minimal rendering contract (drawSymbol / drawSlice). |