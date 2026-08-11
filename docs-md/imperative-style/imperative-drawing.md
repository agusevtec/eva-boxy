# Imperative Drawing

At its core, Boxy provides a straightforward imperative drawing API. This is the foundation upon which all higher-level elements are built. Understanding this layer gives you full control over the display and allows you to create custom elements when needed.

---

## Text Rendering

Boxy provides three alignment options for text rendering:

```cpp
screen.TextLeft({0, 2}, {16, 1}, "Hello Left", 0);
screen.TextCenter({0, 2}, {16, 1}, "Hello Center", 0);
screen.TextRight({0, 2}, {16, 1}, "Hello Right", 0);
```

| Method | Description |
|--------|-------------|
| `TextLeft` | Aligns text to the left edge of the rectangle |
| `TextCenter` | Centers text horizontally within the rectangle |
| `TextRight` | Aligns text to the right edge of the rectangle |

**Parameters:**
- `{0, 2}` — position (column, row) in tiles
- `{16, 1}` — size (width, height) in tiles
- `"Hello Left"` — text to display
- `0` — color (0 = normal, 1 = inverted)

---

## Text Scaling

Text can be scaled vertically by increasing the height parameter. The width scales proportionally:

```cpp
screen.TextCenter({0, 2}, {16, 1}, "Size 1", 0);  
screen.TextCenter({0, 2}, {16, 2}, "Size 2", 0);  
screen.TextCenter({0, 2}, {16, 3}, "Size 3", 0);  
```

| Height | Use Case |
|--------|----------|
| 1 tile | Normal text, dense information |
| 2 tiles | Headers, emphasis |
| 3 tiles | Large titles, splash screens |

---

## Flash Strings

For memory-constrained environments, Flash strings are fully supported using the `F()` macro. This stores the string in program memory (PROGMEM) rather than RAM:

```cpp
screen.TextCenter({0, 2}, {16, 1}, F("F-string"), 0);
```

---

## Drawing Symbols

Individual characters can be drawn at any position. This is useful for custom indicators or simple graphics:

```cpp
for (int i = 0; i < 8; i++) {
    screen.DrawSymbol({i, 3}, {1, 1}, 'A' + i, 0);
}
```

---

## Pictograms

Boxy includes Remixicon pictograms in three sizes:

```cpp
#include <evabGalleryRemixicon16.h>
#include <evabGalleryRemixicon24.h>
#include <evabGalleryRemixicon32.h>

screen.Picto({0, 3}, GalleryRemixicon16::PICTO_F243, 0);
screen.Picto({0, 3}, GalleryRemixicon24::PICTO_F243, 0);
screen.Picto({0, 3}, GalleryRemixicon32::PICTO_F243, 0);
```

| Size | Use Case |
|------|----------|
| 16×16 | Small icons, status indicators |
| 24×24 | Medium icons, buttons |
| 32×32 | Large icons, splash screens |

You can visit [remixicon.com](https://remixicon.com) and find the hex code of desired image. (F243 in the example is a hex code)

---

## Working with Elements Imperatively

Every element in Boxy can be drawn imperatively using its `Draw()` method.

### Button Controls

```cpp
#include <evabInputButton.h>
#include <evabInputButtonPicto.h>
#include <evabGalleryRemixicon24.h>

InputButton button(F("OK"));
button.Draw(&screen, {0, 4}, {16, 1}, 1);

InputButtonPicto buttonPicto(GalleryRemixicon24::PICTO_F243);
buttonPicto.Draw(&screen, {6, 4}, {3, 3}, 1);
```

| Control | Description | Use Case |
|---------|-------------|----------|
| `InputButton` | Text button with label in parentheses | Action triggers: OK, Cancel, Save |
| `InputButtonPicto` | Icon-only button | Toolbars, icon-based navigation |

> **Note:** Parameters of `Draw()` method: `Draw(screen, position, size, focused)` — `focused=1` draws with highlight.

---

### Numeric Input Controls

```cpp
#include <evabInputInt.h>
#include <evabInputFloat.h>

InputInt intVal(42);
intVal.Draw(&screen, {0, 4}, {16, 1}, 0);

InputFloat floatVal(3.14f);
floatVal.Draw(&screen, {0, 4}, {16, 1}, 0);
```

| Control | Description | Use Case |
|---------|-------------|----------|
| `InputInt` | Integer value display | Brightness, channel, step count |
| `InputFloat` | Floating-point value display | Temperature, voltage, frequency |

---

### Pictogram Selection Controls

`InputSelectorAlbum` allows selecting from a set of pictograms. The album template parameter determines both the available states and their visual representation.

> **Important:** Because of limited graphics support, Boxy does not control the size of the drawing area for pictogram-related methods. The user must handle the size of the area manually.

```cpp
#include <evabInputSelectorAlbum.h>
#include <evabAlbums.h>

InputSelectorAlbum<AlbumOnOff> selOnOff(0);
selOnOff.Draw(&screen, {7, 4}, {2, 1}, 0);

InputSelectorAlbum<AlbumBattery> battery(3);
battery.Draw(&screen, {7, 4}, {2, 1}, 0);

InputSelectorAlbum<AlbumRainbowmeter> rainbow(3);
rainbow.Draw(&screen, {6, 4}, {4, 2}, 0);

InputSelectorAlbum<AlbumLamp> lamp(2);
lamp.Draw(&screen, {7, 4}, {2, 2}, 0);

InputSelectorAlbum<AlbumProgress> progress(4);
progress.Draw(&screen, {7, 4}, {2, 2}, 0);

InputSelectorAlbum<AlbumSpeaker> speaker(1);
speaker.Draw(&screen, {7, 4}, {2, 2}, 0);

InputSelectorAlbum<AlbumSignal> signal(2);
signal.Draw(&screen, {7, 4}, {2, 1}, 0);

InputSelectorAlbum<AlbumRoundmeter> roundmeter(6);
roundmeter.Draw(&screen, {7, 4}, {3, 3}, 0);
```

| Album | States | Visual | Use Case |
|-------|--------|--------|----------|
| `AlbumOnOff` | 2 | Rounded bar → filled circle | Power state, enable/disable |
| `AlbumBattery` | 7 | Battery with fill level | Battery status, charge level |
| `AlbumRainbowmeter` | 7 | Rainbow-form bar | Audio meters, colorful progress |
| `AlbumLamp` | 6 | Lamp with brightness | Lighting control, dimmer |
| `AlbumProgress` | 9 | Circular progress | Download progress, loading |
| `AlbumSpeaker` | 4 | Speaker with sound waves | Volume control |
| `AlbumSignal` | 4 | Signal bars | Wi-Fi, cellular strength |
| `AlbumRoundmeter` | 13 | Analog gauge with needle | Dashboard, speedometer |

---

### Stretch Bar Controls

Graphical stretch bars use pictograms for rendering:

```cpp
#include <evabInputStretchBar.h>

VerticalProgressBar vProgress(50);
vProgress.Draw(&screen, {8, 2}, {2, 5}, 0);

HorizontalProgressBar hProgress(50);
hProgress.Draw(&screen, {1, 3}, {14, 1}, 0);

VerticalScrollBar vScroll(50);
vScroll.Draw(&screen, {8, 2}, {2, 5}, 0);

HorizontalScrollBar scrollBar(50);
scrollBar.Draw(&screen, {1, 3}, {14, 1}, 0);
```

| Control | Description | Use Case |
|---------|-------------|----------|
| `VerticalProgressBar` | Fills from bottom to top | Level indicators, tank levels |
| `HorizontalProgressBar` | Fills from left to right | Progress bars, loading |
| `VerticalScrollBar` | Thumb position on vertical track | Scroll position in lists |
| `HorizontalScrollBar` | Thumb position on horizontal track | Scroll position in wide content |

> **Parameters:** Constructor: initial percent (0-100); `Draw(screen, position, size, focused)`

---

### Text-Based Stretch Bars

Text-based variants use ASCII characters instead of pictograms. These are more memory-efficient and work on character LCD displays:

```cpp
#include <evabInputTextStretchBar.h>

TextVerticalProgressBar vtProgress(50);
vtProgress.Draw(&screen, {8, 2}, {2, 5}, 0);

TextHorizontalProgressBar htProgress(50);
htProgress.Draw(&screen, {1, 3}, {14, 1}, 0);

TextVerticalScrollBar vtScroll(50);
vtScroll.Draw(&screen, {8, 2}, {2, 5}, 0);

TextHorizontalScrollBar tscrollBar(50);
tscrollBar.Draw(&screen, {1, 3}, {14, 1}, 0);
```

| Control | Character Set | Use Case |
|---------|---------------|----------|
| `TextVerticalProgressBar` | `#` and `|` | Memory-constrained devices |
| `TextHorizontalProgressBar` | `-` and `|` | Character LCD displays |
| `TextVerticalScrollBar` | `|`, `#`, `|` | Scroll indication on text displays |
| `TextHorizontalScrollBar` | `-`, `|`, `-` | Scroll indication on text displays |