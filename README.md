# EVA Boxy

**EVA Boxy** is a lightweight, compile-time configurable C++ UI library tailored for Arduino driving low-resolution monochrome/OLED/LCD displays via physical keypads or buttons.

---

## Core Value Proposition
* **Declarative desktop-style user code**
* **Zero Dynamic Allocation**: 100% stack/static storage allocation. Safe for safety-critical and embedded real-time systems.
* **Compile-Time Composition**: Feature wrappers (labels, decorators, key reactors, listboxes) are composed via C++ templates, eliminating runtime dispatch overhead.
* **Guaranteed Bounding Box Principle**: Every visual component strictly owns, paints, and clears its allocated rectangular area (`Coor pos`, `Coor size`), completely preventing ghosting, visual artifacts, and trailing pixels without global screen flushes.
* **Hardware & Display Agnostic**: Simple driver abstraction interface (`Screen` / `ScreenPage8Base`) supporting OLED, LCD, parallel, and serial-debug output.
* **Gradual Optimization Path**: Seamlessly scale from a rapid, high-level declarative prototype down to imperative direct-to-screen pixel drawing as hardware constraints require.

---

## Quick Start (Declarative Style)

Below is a complete, minimal example showing how to construct a focusable form with an integer input field and a button bound to keypad events.
```text
┌──────────────────────────┐
│     System Settings      │
│                          │
│ Brightness    75         │
│                          │
│ (        Save          ) │
└──────────────────────────┘
```
```cpp
#include <evabBoxy.h>
#include <evabScreenSSD1306.h>
#include <evabFont8Narrow.h>
#include <evabLayoutBase.h>
#include <evabKeyModifier.h>
#include <evabKeyCatcher.h>
#include <evabLabeled.h>
#include <evabInputInt.h>
#include <evabInputButton.h>
#include <evabBoxyRest.h>

// EVA Core | EVA Survival kit assumed to be a source of physical keys pressures
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
    // Form submitted
  }

public:
  SystemSettingsForm()
    : mBrightness(this, F("Brightness"), 75, 0, 100, 5),
      mSaveButton(this, &onSavePressedHandler, F("Save")) {}

  void drawer(Screen* screen, Coor pos, Coor size, unsigned char isFocused) override {
    // BoxyRest handles coordinate slicing and clears unallocated pixels automatically
    BoxyRest rest(screen, pos, size, isFocused);

    rest.CutRow(1).TextCenter(F("System Settings"));
    rest.CutRow(1).Clear();  // Visual separator
    rest.CutRow(1).Draw(mBrightness, IsFocused(&mBrightness));
    rest.CutRow(1).Clear();  // Visual separator
    rest.CutRow(1).Draw(mSaveButton, IsFocused(&mSaveButton));
    rest.Clear();  // Clear remaining area
  }
};


// EVA Core | EVA Survical kit key source assumed
void onKeyPressed() {
  //    if ( ... ) {
  //        Boxy::Key(KEY_UP);
  //    }
  //    if ( ... ) {
  //        Boxy::Key(KEY_LEFT);
  //    }
  // ...
}

void setup() {
  // Root Ground Layout
  static SystemSettingsForm gMainForm;
  // Initialize display driver, font, and mount root layout layer
  Boxy::Begin<ScreenSSD1306, Font8Narrow>(&gMainForm);
}

void loop() {
  // Execute frame ticking & render pipeline
  eva::tac();
}
```

---

## Architecture & Programming Styles

EVA Boxy supports three distinct development paradigms depending on application complexity and memory budgets:

| Style | Best For | Focus Handling | Memory Footprint | Key Mechanics |
| :--- | :--- | :--- | :--- | :--- |
| **Primary (Declarative)** | Complex screens, rapid UI prototyping, multi-control forms. | Automatic focus ring (`Focusable<T>`). | Standard | Compile-time template composition & `BoxyRest` slicing. |
| **Intermediate (Contract-based)** | Custom composite widgets, dialog popups, optimized controls. | Manual (`focusChild()`). | Low | Subclassing `CompositeBase`, manual `freezer()` & `onResidualKey()`. |
| **Imperative (Direct Execution)** | Maximum FLASH/RAM savings, extreme resource limits. | Explicit manual state tracking. | Absolute Minimal | Direct coordinate math, stack-stamping, raw driver calls (`Screen`). |

---

## Documentation & Learning Path

The repository contains full MkDocs documentation with tutorials, architectural breakdowns, and complete API references.

### Navigating the Docs

#### Getting Started
* [What is EVA Boxy?](https://agusevtec.github.io/eva-boxy) — Architecture, design principles, and feature comparison.
* [Core Concepts](https://agusevtec.github.io/eva-boxy/declaration-style/core-concepts) — Ground singleton, Parent-Child composition, and the Two Chains of Responsibility.

#### Declarative UI Development
* [Layout and Focus Management](https://agusevtec.github.io/eva-boxy/declaration-style/layout-and-focus) — `LayoutBase`, `Focusable<T>` focus rings, and sub-screen paging.
* [Behavioral Modifiers](https://agusevtec.github.io/eva-boxy/declaration-style/behavioral-modifiers) — Input reactors (`KeyReactor`, `KeyCatcher`) and key event delegation.
* [Listboxes](https://agusevtec.github.io/eva-boxy/declaration-style/listboxes) — `ScrollListbox` vs. `FlipListbox`, custom windowing algorithms, and vertical scrollbars.

#### Layout Helper & Drawing Contract
* [BoxyRest Helper](https://agusevtec.github.io/eva-boxy/imperative-style/boxyrest) — Fluent layout slicing (`CutRow`, `CutCol`), area clearance, and the Drawing Contract.
* [Imperative Drawing & Modifiers](https://agusevtec.github.io/eva-boxy/imperative-style/imperative-drawing) — Direct rendering, text alignment, and visual decorators.

#### Intermediate Optimization & Custom Controls
* [CompositeBase Engine](https://agusevtec.github.io/eva-boxy/intermediate-style/composite-base) — Bare-bones composite elements, manual focus routing, and custom freezer contracts.
* [Custom User Controls](https://agusevtec.github.io/eva-boxy/intermediate-style/custom-user-controls) — Building reusable widgets from scratch.
* [Progressive Optimization Path](https://agusevtec.github.io/eva-boxy/intermediate-style/progressive_optimization) — Step-by-step guide on converting declarative views to zero-abstraction imperative code.

#### Hardware, Drivers & Tools
* [Display Drivers](https://agusevtec.github.io/eva-boxy/imperative-style/display-drivers) — Driver list and initialization for SSD1306, SH1106, PCD8544, KS0108, LCD_I2C, and Serial debug screens.
* [Adding Support for New Displays](https://agusevtec.github.io/eva-boxy/other/adding_new_display) — Extending `Screen` or `ScreenPage8Base` for custom display hardware.
* [Fonts and Pictograms](https://agusevtec.github.io/eva-boxy/other/fonts-and-pictograms) — Vector/PNG rasterization pipeline (`fontsworkspace`), glyph alignment, descaling, and `PROGMEM` code generation.

#### API Reference
* [Class List](https://agusevtec.github.io/eva-boxy/eva-boxy/annotated) | [Class Hierarchy](https://agusevtec.github.io/eva-boxy/eva-boxy/hierarchy) | [File Index](https://agusevtec.github.io/eva-boxy/eva-boxy/files)

---

## Supported Displays & Hardware

EVA Boxy includes built-in drivers for both graphical and text-based displays, alongside serial debug adapters for hardware-free development:

| Display Driver | Class Name | Resolution | Protocol / Interface |
| :--- | :--- | :--- | :--- |
| **SSD1306** OLED | `ScreenSSD1306` | 128x64 px | I2C |
| **SH1106** OLED | `ScreenSSH1106` | 128x64 px | I2C |
| **PCD8544** (Nokia 5110) | `ScreenPCD8544` | 84x48 px | SPI |
| **KS0108** Graphical LCD | `ScreenKS0108` | 128x64 px | Parallel 8-bit |
| **HD44780** Character LCD | `ScreenLCD_I2C` | 16x2, 20x4, etc. | I2C (PCF8574) |
| **Serial Text Debug** | `ScreenSerialText` | 16x8 tiles | Serial Monitor |
| **Serial Pixel Debug** | `ScreenSerialPixel` | 16x8 tiles | Serial Monitor |

---

## Installation & Integration

### PlatformIO
Add the repository or library directory to your `platformio.ini`:

```ini
lib_deps =
    [https://github.com/your-org/eva-boxy.git](https://github.com/your-org/eva-boxy.git)
```

### Arduino IDE
1. Download the latest release `.zip` from GitHub.
2. Navigate to **Sketch** -> **Include Library** -> **Add .ZIP Library...**
3. Include `<evabBoxy.h>` in your sketch.

---

## License

This project is licensed under the **MIT License** — see the [LICENSE](LICENSE) file for full details.
