# Visual Modifiers

Visual modifiers are template decorators that change **how** an element looks without changing **what** it does. They wrap an existing element and add visual enhancements — labels, padding, alignment, or titles.

All visual modifiers follow the same pattern: they take an element as a template parameter, forward constructor arguments to it, and override the `drawer()` method to add visual layers around the base element's rendering.

---

## Labeled

Adds a text label to the **left** of an element. The label and the element share the same row.

### How the Space Is Divided

| Case | Label Width | Element Width |
|------|-------------|---------------|
| Single row (height = 1) | 2/3 of total | 1/3 of total |
| Multiple rows (height > 1) | Same row only | Element spans full height |

### Visual Representation

```
Height = 1 tile:
┌──────────────────────┬──────────────────────┐
│ Label text           │    OriginalControl   │
│ <─── 2/3 ────────────┼────── 1/3 ──────────>│
└──────────────────────┴──────────────────────┘

Height = 2 tiles:
┌──────────────────────┬──────────────────────┐
│ Label text           │                      │
│                      │    OriginalControl   │
└──────────────────────┴──────────────────────┘
```

```cpp
#include <evabLabeled.h>

LabeledLeft<InputInt> labeledInt("Temperature", 42);
LabeledLeft<InputButton> labeledButton("Action", F("OK"));
LabeledLeft<InputSelectorPx<AlbumBattery>> labeledBattery("Battery", 3);
LabeledLeftF<InputInt> labeledFlash(F("Brightness"), 75);  // Flash string
```

| Decorator | Alignment | Use Case |
|-----------|-----------|----------|
| `LabeledLeft<T>` | Label left-aligned | Default, most common |
| `LabeledCenter<T>` | Label centered | Symmetrical layouts |
| `LabeledRight<T>` | Label right-aligned | Right-to-left languages |
| `LabeledLeftF<T>` | Flash string label | Memory-constrained projects |

---

## Titled

Places the label **above** the element, on a separate row. The element gets the full width below the label.

### How the Space Is Divided

| Case | Label Position | Element Position |
|------|----------------|------------------|
| Height = 1 | Falls back to Labeled behavior (2/3 + 1/3) | Same row |
| Height > 1 | First row, full width | Remaining rows, full width |

### Visual Representation

```
Height = 1 tile (falls back to Labeled):
┌──────────────────────┬──────────────────────┐
│ Title text           │    OriginalControl   │
└──────────────────────┴──────────────────────┘

Height = 3 tiles:
┌─────────────────────────────────────────────┐
│ Title text                                  │  ← Title (full width)
├─────────────────────────────────────────────┤
│              OriginalControl                │  ← Element (full width)
│                                             │  ← Extra space
└─────────────────────────────────────────────┘
```

```cpp
#include <evabTitled.h>

TitledLeft<InputInt> titledInt("Temperature", 42);
TitledCenter<InputFloat> titledFloat("Voltage", 3.3f);
TitledLeft<InputButton> titledButton("Action", F("Save"));
TitledLeftF<InputSelectorPx<AlbumLamp>> titledLamp(F("Mode"), 2);
```

| Decorator | Alignment | Use Case |
|-----------|-----------|----------|
| `TitledLeft<T>` | Title left-aligned | Forms with labels above fields |
| `TitledCenter<T>` | Title centered | Dialog headers |
| `TitledRight<T>` | Title right-aligned | Asymmetric layouts |
| `TitledLeftF<T>` | Flash string title | Memory-constrained projects |

---

## PaddingV / PaddingH

Adds empty space around an element. The padding area is **cleared** (filled with background color), and the original control is drawn in the remaining space.

### How the Space Is Divided

| Decorator | Action |
|-----------|--------|
| `PaddingV<T>` | Clears 1 tile at top, draws OriginalControl, clears 1 tile at bottom |
| `PaddingH<T>` | Clears 1 tile at left, draws OriginalControl, clears 1 tile at right |

### Visual Representation

```
PaddingV (height = 3 tiles):
┌─────────────────────────────────────────────┐
│                  CLEARED                    │  ← 1 tile cleared (top)
├─────────────────────────────────────────────┤
│              OriginalControl                │  ← Element drawn here
├─────────────────────────────────────────────┤
│                  CLEARED                    │  ← 1 tile cleared (bottom)
└─────────────────────────────────────────────┘

PaddingH (width = 6 tiles):
┌─────────────────────────────────────────────┐
│  CLEARED   │ OriginalControl │  CLEARED    │
│  (1 tile)  │                 │  (1 tile)   │
└─────────────────────────────────────────────┘

PaddingV + PaddingH (centered):
┌─────────────────────────────────────────────┐
│                  CLEARED                    │
├──────────┬──────────────────────┬───────────┤
│ CLEARED  │   OriginalControl    │  CLEARED  │
├──────────┴──────────────────────┴───────────┤
│                  CLEARED                    │
└─────────────────────────────────────────────┘
```

```cpp
#include <evabPadding.h>

PaddingV<InputInt> paddedInt(42);
PaddingH<InputButton> paddedButton(F("OK"));
PaddingV<InputSelectorPx<AlbumSpeaker>> paddedSpeaker(2);
PaddingV<PaddingH<InputInt>> centeredInt(42);
```

---

## Composing Visual Modifiers

Visual modifiers can be chained. The order determines the visual hierarchy: inner modifiers are applied first, outer modifiers wrap around them.

### Visual Representation of Composition

```
PaddingV<LabeledLeft<InputInt>> (height = 3 tiles):
┌─────────────────────────────────────────────┐
│                  CLEARED                    │  ← PaddingV (top)
├──────────────────────┬──────────────────────┤
│ Label text           │    OriginalControl   │  ← LabeledLeft
├──────────────────────┴──────────────────────┤
│                  CLEARED                    │  ← PaddingV (bottom)
└─────────────────────────────────────────────┘

PaddingV<TitledCenter<InputFloat>> (height = 3 tiles):
┌─────────────────────────────────────────────┐
│                  CLEARED                    │  ← PaddingV (top)
│              Title text                     │  ← TitledCenter
│              OriginalControl                │  ← Element
│                  CLEARED                    │  ← PaddingV (bottom)
└─────────────────────────────────────────────┘
```