# EVA Boxy

**EVA Boxy** is a lightweight, compile-time configurable C++ UI library tailored for Arduino driving low-resolution monochrome/OLED/LCD displays via physical keypads or buttons.

---

## Core Value Proposition
* **Declarative desktop-style user code**: Write intuitive, structured UI layouts reminiscent of desktop frameworks without sacrificing the joy of custom creativity. It doesn't act as a rigid black box; instead, it offers a natural, deterministic scaffold that enforces good C++ design principles while preserving the creative freedom.
* **Compile-Time Composition**: Feature wrappers (labels, decorators, key reactors, listboxes) are composed via C++ templates, eliminating runtime dispatch overhead.
* **Guaranteed Bounding Box Principle**: Every visual component strictly owns, paints, and clears its allocated rectangular area (`Coor pos`, `Coor size`), completely preventing ghosting, visual artifacts, and trailing pixels without global screen flushes.
* **Hardware & Display Agnostic**: Simple driver abstraction interface (`Screen` / `ScreenPage8Base`) supporting OLED, LCD, parallel, and serial-debug output.
* **Gradual Optimization Path**: Seamlessly scale from a rapid, high-level declarative prototype down to imperative direct-to-screen drawing as hardware constraints require.
* **Zero Dynamic Allocation**: 100% stack/static storage allocation. The battle-tested approach for safety-critical and embedded real-time systems.

---

## Built on EVA Ecosystem

EVA Boxy is part of the [EVA ecosystem](https://agusevtec.github.io/eva-core-sk/) – an event-driven architecture for Arduino. This integration provides:

- Non-blocking timing – callbacks and animated controls use EVA's `Tickable` infrastructure
- Unified update cycle – Single `eva::tac()` call drives all time-based components
- Zero-polling design – Components update themselves when needed


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

// Here EVA Core | EVA Survival Kit key source is assumed
// https://agusevtec.github.io/eva-core-sk/quickstart/performance/
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

---

## Architecture & Programming Styles

EVA Boxy supports three distinct development paradigms depending on application complexity and memory budgets:

| Style | Best For |  Memory Footprint | Key Mechanics |
| :--- | :--- | :--- | :--- |
| **Primary (Declarative)** | Complex screens, rapid UI prototyping, multi-control forms. | Standard | Compile-time template composition & `Grid` slicing. |
| **Intermediate (Contract-based)** | Custom composite widgets, dialog popups, optimized controls. . | Low | Subclassing `CompositeBase`, manual `freezer()` & `onResidualKey()`. |
| **Imperative (Direct Execution)** | Maximum FLASH/RAM savings, extreme resource limits. |  Absolute Minimal | Direct coordinate math, stack-stamping, raw driver calls (`Screen`). |

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
* [Grid Helper](https://agusevtec.github.io/eva-boxy/imperative-style/boxyrest) — Fluent layout slicing (`CutRow`, `CutCol`), area clearance, and the Drawing Contract.
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
| **SSD1306** OLED | `ScreenSSD1306` | 16x8 tiles | I2C |
| **SH1106** OLED | `ScreenSSH1106` | 16x8 tiles | I2C |
| **PCD8544** (Nokia 5110) | `ScreenPCD8544` | 12x6 tiles | SPI |
| **KS0108** Graphical LCD | `ScreenKS0108` | 16x8 tiles | Parallel 8-bit |
| **HD44780** Character LCD | `ScreenLCD_I2C` | 20x4 and others | I2C (PCF8574) |
| **Serial Text Debug** | `ScreenSerialText` | 16x8 tiles | Serial Monitor |
| **Serial Pixel Debug** | `ScreenSerialPixel` | 16x8 tiles | Serial Monitor |

---

## Installation & Integration

### Arduino IDE
1. Open Arduino IDE
2. Go to **Sketch -> Include Library -> Manage Libraries**
3. Search for **"eva-boxy"**
4. Click **Install**

### PlatformIO
Add the repository or library directory to your `platformio.ini`:

```ini
lib_deps =
    [https://github.com/your-org/eva-boxy.git](https://github.com/your-org/eva-boxy.git)
```


---

## License

This project is licensed under the **MIT License** — see the [LICENSE](LICENSE) file for full details.
