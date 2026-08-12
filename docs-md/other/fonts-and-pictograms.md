# Custom Fonts and Pictograms

The font and pictogram generation pipeline is divided into two independent steps: rasterization into an intermediate text format (pseudo-graphics `.txt`) and code generation into C++ structures (`PROGMEM`)[cite: 1, 4, 5].

This two-stage approach simplifies manual tweaking, visual debugging (preview), and glyph alignment before the assets are stored in the microcontroller's flash memory.

> **Note on Tooling:** All utilities and scripts for generating fonts and pictograms are located in the `fontsworkspace` directory.

---

### Generation Pipeline: Two-Step Architecture

1. **Step 1: Rasterization (Font/PNG -> `.txt`)**
   * Source vector fonts (`.ttf`/`.otf`) or raster images (`.png`) are converted into a folder containing individual `.txt` files[cite: 1, 2, 3].
   * In these `.txt` files, each character is represented as a matrix of `#` (active pixel) and `.` (empty pixel) characters[cite: 1, 3].
   * Working rest sizes (e.g., 16x16, 24x24), baseline or bounding box alignment, automatic point size selection, and descaling are configured at this stage[cite: 1, 2].

2. **Step 2: Code Generation (`.txt` -> C++ PROGMEM)**
   * Scripts read the folder with `.txt` files, perform bit-packing (vertical columns of 8 bits where `bit 0` is the top pixel), and generate ready-to-use C++ code[cite: 4, 5].

---

### Resolution Nuances: 8x8 vs 16x16 with Descale

Although microdisplays most frequently deal with **8x8** fonts, rasterizing directly at low resolutions during Step 1 often results in jagged edges or lost character details.

In such cases, an experimental downscaling workflow works best:
* **High-Res Rendering:** The font is rasterized into a larger **16x16** (or 24x24) rest, after which a downscaling factor `--descale` (`-d 2`) reduces the matrix back to the final 8x8 target size[cite: 1, 2].
* **Experimental Process:** Finding the optimal parameters (`-w`, `-h`, `-s`, `-d`) is an unformalized, trial-and-error process[cite: 1, 2]. Different typefaces react to descaling uniquely, so maximum legibility is achieved by inspecting the preview `.txt` files and tweaking parameters iteratively.

---

### Step 1 Tools (Converters to `.txt`)

* **`fontliterals2textdir.py`** — Base font rasterizer with fixed point size (`-s`) and character alignment based on typography rules (baselines for letters, math symbols, etc.)[cite: 1].
* **`fontpicto2textdir.py`** — Utility tailored for icon fonts and pictograms[cite: 2]. Automatically calculates the maximum point size (`-s auto`) via binary search to fit characters tightly without clipping and centers them strictly by bounding box[cite: 2].
* **`png2text.py`** — Converts `.png` images into text matrices with options for splitting images into N x M tiles (`N M`) and adjusting brightness thresholding (`--threshold`)[cite: 3].

---

### Step 2 Tools (C++ Code Generators)

* **`txt_to_charmap.py`** — Packs text characters into a classic fixed-size font character map (Charmap) array[cite: 4]. Downsamples 2x (taking even rows/columns) and outputs a flat `kCharmap[][cols]` array[cite: 4].
* **`txtdir2collection.py`** — Packs arbitrary pictogram folders into a C++ `Album<Name>` class with a `GetTile(index)` accessor[cite: 5]. The first two bytes of each tile store its dimensions (`width, height`)[cite: 5].

---

### Practical Examples

**1. Generating a Text Font (Arial)**

Converting a standard typeface into a Charmap array for a microdisplay[cite: 4]:

```bash
# Step 1: Rasterize ASCII range (32-127) into a 16x16 rest
python fontliterals2textdir.py arial.ttf -r 32-127 -w 16 -h 16 -s 16 -d 2

# Inspect/tweak glyphs manually inside ./arial/*.txt if needed

# Step 2: Generate C++ charmap table (downsamples to 8x8, exports columns 0-7)
python txt_to_charmap.py arial/ arial_font.h 0 7
```

**2. Generating an Icon Set (Wingdings)**

Using automatic point-size optimization for symbol fonts[cite: 2] and assembling them into a C++ collection[cite: 5]:

```bash
# Step 1: Rasterize Wingdings icons (hex range 0x20-0x7F) with auto-sizing and auto-centering
python fontpicto2textdir.py wingdings.ttf -r 0x20-0x7F -w 16 -h 16 -s auto

# Step 2: Pack ./wingdings folder into AlbumWingdings (wingdings_icons.h and wingdings_icons.cpp)
python txtdir2collection.py wingdings/ wingdings_icons
```

---

### C++ Usage Example

Using the generated `AlbumWingdings` class[cite: 5]:

```cpp
#include "wingdings_icons.h"

// Drawing the first icon from the generated album
const unsigned char* iconData = AlbumWingdings::GetTile(0);
if (iconData != nullptr) {
    aScreen->Picto({X, Y}, iconData, false);
}
```