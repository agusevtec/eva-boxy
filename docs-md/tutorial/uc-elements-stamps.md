# Stamp Mode (ElementBase Interface)

## Overview

Elements in EVA Boxy are graphical components that can be stamped onto the screen. Each element inherits from `ElementBase` and implements custom rendering through the `drawer()` method.

## Input Controls

### InputInt
Integer input field with increment/decrement support.

```cpp
#include <evabInputInt.h>

// Create with initial value
InputInt myInt(42);

// Methods
myInt.SetValue(100);        // Set new value
int val = myInt.GetValue(); // Get current value
myInt.Increment(1);         // Increase by 1
myInt.Increment(-1);        // Decrease by 1
```

### InputFloat
Floating-point input field with increment/decrement support.

```cpp
#include <evabInputFloat.h>

// Create with initial value
InputFloat myFloat(3.14);

// Methods
myFloat.SetValue(2.718);    // Set new value
float val = myFloat.GetValue(); // Get current value
myFloat.Increment(0.1);     // Increase by 0.1
myFloat.Increment(-0.5);    // Decrease by 0.5
```

### Resize Behavior

Both InputInt and InputFloat support resizing to fit available space:

```cpp
// Single line (height=1)
InputInt small;  // Shows compact text

// Multiple lines (height>1)
InputInt big;    // Shows larger text with scaling
```

## InputPicto Controls

InputPicto displays graphical icons from tile sets. **Resize is not supported** - picto tiles have fixed dimensions.

### Tile Set Usage

```cpp
#include <evabPictosets.h>

class InputPicto : public ElementBase {
private:
    const unsigned char **mTiles;
    unsigned char mIndex;
    unsigned char mCount;
    
public:
    InputPicto(const unsigned char **tiles, unsigned char count) 
        : mTiles(tiles), mIndex(0), mCount(count) {}
    
    void SetIndex(unsigned char index) {
        mIndex = min(index, mCount - 1);
        Redraw();
    }
    
protected:
    void drawer(IScreen *screen, Coor pos, Coor size, unsigned char focused) override {
        // Picto size is fixed - cannot resize
        // Size parameter is ignored for picto elements
        screen->Picto(pos, mTiles[mIndex], 0);
    }
};
```

### Available Tile Sets (No Resize)

| Tile Set | Tile Count | Tile Size | Usage |
|----------|------------|-----------|-------|
| `PictosetOnOff` | 2 | 16×8 | On/off indicator |
| `PictosetRainbowmeter` | 7 | 32×16 | Rainbow gradient |
| `PictosetRoundmeter` | 9 | 32×24 | Circular gauge |
| `PictosetFan` | 3 | 24×24 | Fan animation |
| `PictosetBattery` | 7 | 16×8 | Battery indicator |
| `PictosetLamp` | 6 | 16×16 | Lamp status |
| `PictosetProgress` | 9 | 16×16 | Progress indicator |
| `PictosetSpeaker` | 4 | 16×16 | Speaker states |
| `PictosetSignal` | 4 | 16×8 | Signal meter |

### InputPicto Example

```cpp
class BatteryIndicator : public ElementBase {
private:
    unsigned char mLevel;
    
public:
    BatteryIndicator() : mLevel(0) {}
    
    void SetLevel(unsigned char level) {
        mLevel = min(level, (unsigned char)6);
        Redraw();
    }
    
protected:
    void drawer(IScreen *screen, Coor pos, Coor size, unsigned char focused) override {
        // No resize - uses fixed 16×8 tile
        screen->Picto(pos, PictosetBattery::GetTile(mLevel), 0);
    }
};

// Usage
BatteryIndicator battery;
battery.SetLevel(3);  // Half full
battery.Draw(screen, {0, 0}, {2, 1}, 0);  // Size is {2,1} (16×8 pixels)
```

## Labeled Modifier

Labeled wraps any input control with a text label.

### Labeled (RAM strings)

```cpp
#include <evabLabeled.h>

// Wrap InputInt with label
Labeled<InputInt> labeledInt("Value", 42);

// Wrap InputFloat with label
Labeled<InputFloat> labeledFloat("Temperature", 23.5);

// Usage
labeledInt.Draw(screen, {0, 0}, {16, 1}, 1);  // Single line layout
labeledInt.Draw(screen, {0, 2}, {16, 2}, 0);  // Two line layout
```

### LabeledF (Flash strings)

```cpp
// Use PROGMEM strings
LabeledF<InputInt> labeledFlash(F("Speed"), 100);
LabeledF<InputFloat> labeledFloatF(F("Pressure"), 1.23);
```

### Label Layout

#### Single Line (height=1)
```
┌────────────────────────┐
│ Label (2/3) │ Value (1/3) │
└────────────────────────┘
```

#### Multiple Lines (height>1)
```
┌────────────────────────┐
│ Label (row 0)          │
├────────────────────────┤
│ Value (rows 1..height) │
└────────────────────────┘
```

### Labeled Example

```cpp
// Create labeled controls
Labeled<InputInt> age("Age", 30);
Labeled<InputFloat> weight("Weight", 75.5);
LabeledF<InputInt> height(F("Height"), 180);

// Layout
age.Draw(screen, {0, 0}, {16, 1}, 1);      // Single line
weight.Draw(screen, {0, 2}, {16, 2}, 0);   // Two lines
height.Draw(screen, {0, 4}, {16, 1}, 0);   // Single line with flash label
```

## Complete Example

```cpp
#include <evabBoxy.h>
#include <evabInputInt.h>
#include <evabInputFloat.h>
#include <evabLabeled.h>
#include <evabPictosets.h>

class MyComposite : public CompositeBase {
private:
    Labeled<InputInt> mSpeed;
    Labeled<InputFloat> mTemperature;
    LabeledF<InputInt> mAltitude;
    BatteryIndicator mBattery;
    
public:
    MyComposite() 
        : mSpeed("Speed", 0)
        , mTemperature("Temp", 20.0)
        , mAltitude(F("Alt"), 0)
    {}
    
    void SetValues(int speed, float temp, int alt, unsigned char bat) {
        mSpeed.SetValue(speed);
        mTemperature.SetValue(temp);
        mAltitude.SetValue(alt);
        mBattery.SetLevel(bat);
    }
    
protected:
    void drawer(IScreen *screen, Coor pos, Coor size, unsigned char focused) override {
        // Row 0: Speed (single line)
        mSpeed.Draw(screen, {0, 0}, {8, 1}, focused && IsFocused(&mSpeed));
        
        // Row 0: Battery indicator (right side)
        mBattery.Draw(screen, {14, 0}, {2, 1}, 0);
        
        // Row 1: Temperature (two lines)
        mTemperature.Draw(screen, {0, 1}, {8, 2}, focused && IsFocused(&mTemperature));
        
        // Row 3: Altitude (single line)
        mAltitude.Draw(screen, {0, 3}, {8, 1}, focused && IsFocused(&mAltitude));
    }
};
```