## Introduction

**EVA Boxy** is a lightweight C++ UI framework designed for resource-constrained embedded displays (OLED, monochrome LCDs) driven by physical keypads.

### Why EVA Boxy?

The core priority of EVA Boxy is developer comfort when building user interfaces.

Writing complex UI is enjoyable when the code is declarative, visual, and easily maintainable — just like in large desktop frameworks. However, a straightforward port of desktop patterns to microcontrollers is unviable: they rely on heavy class hierarchies, virtual tables, and dynamic memory allocation, which are fatal for resource-constrained embedded systems.

EVA Boxy breaks these limitations by leveraging the EVA approach.

Its defining architectural genotype is compile-time decorator composition, allowing you to include only the exact resources you need. Paired with deliberate functional boundaries — zero z-order, zero clipping buffers, and zero dynamic allocations — Boxy delivers pure, deterministic pixel execution.

At the same time, EVA Boxy remains comfortable for developers who prefer a traditional imperative style or require direct display control. The framework is optimized for text and symbol rendering on low-resolution displays, with optional pictogram support for icon-based interfaces.

### Built on EVA Ecosystem

EVA Boxy is part of the [EVA ecosystem](https://agusevtec.github.io/eva-core-sk/) – an event-driven architecture for Arduino. This integration provides:

- Non-blocking timing – callbacks and animated controls use EVA's `Tickable` infrastructure
- Unified update cycle – Single `eva::tac()` call drives all time-based components
- Zero-polling design – Components update themselves when needed

### Architectural Styles

EVA Boxy scales cleanly depending on your task, performance budget, and architectural preferences:

#### 1. Primary Style: Declarative UI (Flagship)

The primary way to use EVA Boxy. Build complex, highly maintainable interactive screens using a clean, expressive syntax. You assemble core data inputs (`InputDiscreteInt`), behavioral modifiers (`KeyModifier`, `KeyCatcher`), and visual wrappers (`Labeled`) directly via C++ compile-time templates — getting modern UI code ergonomics without paying a runtime memory penalty:

**Visual Representation:**
```text
┌──────────────────────────┐
│     System Settings      │
│                          │
│ Brightness    75         │
│                          │
│ (        Save          ) │
└──────────────────────────┘
```
**Navigation:**

- `KEY_UP` / `KEY_DOWN` — navigate between fields (handled by `KeyModifier<LayoutBase>`)

- `KEY_LEFT` / `KEY_RIGHT` — on InputDiscreteInt → change value

- `KEY_LEFT` / `KEY_RIGHT` — on button → triggers `onSavePressed`
```cpp
#include <evabBoxy.h>
#include <evabScreenSSD1306.h>
#include <evabFont8Sharp.h>
#include <evabLayoutBase.h>
#include <evabKeyModifier.h>
#include <evabKeyCatcher.h>
#include <evabLabeled.h>
#include <evabInputInt.h>
#include <evabInputButton.h>
#include <evabBoxyRest.h>

// EVA Core | EVA Survival Kit assumed to be a source of physical key presses
#include <evaTac.h>

using namespace eva;
using namespace evab;

// Declare form with vertical navigation (KEY_DOWN / KEY_UP)
class SystemSettingsForm : public KeyModifier<LayoutBase, KEY_UP, KEY_DOWN> {
  // [1] InputIntDiscrete bounded to KEY_LEFT / KEY_RIGHT
  Focusable<KeyModifier<LabeledLeftF<InputIntDiscrete>, KEY_LEFT, KEY_RIGHT>> mBrightness;
  // [2] Action Button bounded to KEY_LEFT / KEY_RIGHT
  Focusable<KeyCatcher<InputButtonF, KEY_LEFT, KEY_RIGHT>> mSaveButton;

  Handler<SystemSettingsForm> onSavePressedHandler{ this, &SystemSettingsForm::onSavePressed };
  void onSavePressed(void* sender, CallbackInfo info) {
    // do useful things here
  }

public:
  SystemSettingsForm()
    : mBrightness(this, F("Brightness"), 75, 0, 100, 5),
      mSaveButton(this, &onSavePressedHandler, F("Save")) {}

  void drawer(Screen* screen, Coor pos, Coor size, unsigned char isFocused) override {
    // Grid handles coordinate slicing and clears unallocated pixels automatically
    Grid rest(screen, pos, size, isFocused);

    rest.CutRow(1).TextCenter(F("System Settings"));
    rest.CutRow(1).Clear();  // Visual separator
    rest.CutRow(1).Draw(mBrightness, IsFocused(&mBrightness));
    rest.CutRow(1).Clear();  // Visual separator
    rest.CutRow(1).Draw(mSaveButton, IsFocused(&mSaveButton));
    rest.Clear();  // Clear remaining area
  }
};

// EVA Core | EVA Survival Kit is assumed as the key source
// This code snippet is incomplete
// see https://agusevtec.github.io/eva-core-sk/quickstart/performance/
void onPhysicalButtonPressed(void* sender, CallbackInfo cbInfo) {
  char button = cbInfo.eventArg; 
  switch(button) {
    case 'u': Boxy::Key(KEY_UP); break;
    case 'd': Boxy::Key(KEY_DOWN); break;
    case 'l': Boxy::Key(KEY_LEFT); break;
    case 'r': Boxy::Key(KEY_RIGHT); break;
  }
}

void setup() {
  static SystemSettingsForm gMainForm;
  // Initialize display driver, font, and mount root layout layer
  Boxy::Begin<ScreenSSD1306, Font8Sharp>(&gMainForm);
}

void loop() {
  // Execute frame ticking & render pipeline
  eva::tac();
}
```

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