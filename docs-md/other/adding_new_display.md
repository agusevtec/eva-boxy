# Adding Support for a New Display

## Introduction

The library is designed as an extensible system for working with various types of displays. The primary use case is text output with support for alignment, scaling, and pictograms. The base class `Screen` provides a minimal interface, while `ScreenPage8Base` adds optimizations for displays with page-based organization.


## Choosing a Base Class

| Display Type | Base Class | Examples in Library |
|--------------|------------|---------------------|
| Page-organized (8 pixels per page) | `ScreenPage8Base` | SSD1306, KS0108, PCD8544, SSH1106 |
| No assumptions about internal structure | `Screen` | LCD_I2C |

## Method Requirements Summary

| Method | Inheriting from Screen | Inheriting from ScreenPage8Base |
|--------|----------------------|-------------------------------|
| `Size()` | Required | Required |
| `DrawSymbol(...)` | Required | Implemented in base class |
| `Picto(...)` | Required* | Implemented in base class |
| `Serialize(...)` | Required | Required |
| `Deserialize(...)` | Required | Required |
| `drawVerticalSlice(...)` | Not available | Required |
| `Clear(...)` | Recommended** | Recommended** |
| `clearTile(...)` | Recommended*** | Recommended*** |

**Notes:**

\* `Picto()` — When inheriting from `Screen`, if the connected display is graphical, pictogram rendering must be implemented manually.

\*\* `Clear(...)` — The base version performs tile-by-tile clearing in a double loop. Overriding allows using hardware fill commands or block transfers over the bus.

\*\*\* `clearTile(...)` — In `Screen`, a tile is cleared by calling `DrawSymbol` with a space character; in `ScreenPage8Base` — through 8 consecutive `drawVerticalSlice` calls. Driver-level implementation allows filling or clearing an 8x8 pixel block in a single fast operation.

When implementing your own driver, it's important to understand: in the base `Screen` class, the `DrawSymbol()` method renders a single character without scaling. If scaling support (the `aSize` parameter) is required, it must be implemented manually using font data through `IFont`.

## Serialization

To pack element state (position, size, focus) into a 16-bit value, the `evabSerializers.h` file defines the following functions:

```cpp
// For screens with 16x8 tile size (128x64 pixels)
unsigned short serialize_16x8(const Coor &aPos, const Coor &aSize, bool isFocused);
void deserialize_16x8(unsigned short aSerialized, Coor &aPos, Coor &aSize, bool &isFocused);

// For screens with 32x4 character size (character LCDs)
unsigned short serialize_32x4(const Coor &aPos, const Coor &aSize, bool isFocused);
void deserialize_32x4(unsigned short aSerialized, Coor &aPos, Coor &aSize, bool &isFocused);
```

When implementing a new display, use the appropriate function pair in the `Serialize()` and `Deserialize()` methods.

## Examples for Study

To understand the interface without hardware specifics, study the debug classes:

- **`ScreenSerialText`** — inherits from `Screen`, shows minimal implementation for a basic display
- **`ScreenSerialPixel`** — inherits from `ScreenPage8Base`, demonstrates working with a pixel buffer

These classes contain only interface logic and are ideal for understanding the structure before implementing a real driver.

## Typical Implementation Steps

1. Create a derived class
2. Choose the base class based on display type
3. Implement required methods (according to the table)
4. Add hardware initialization in the constructor
5. Test with existing examples
6. Add optimizations if necessary