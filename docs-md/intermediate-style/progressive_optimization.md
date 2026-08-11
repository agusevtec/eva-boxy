# Progressive Optimization Path

Designing UIs in Boxy follows the principle of **Gradual Optimization**. You start with a highly declarative, rapid-prototyping structure and progressively trim abstraction layers as FLASH and RAM constraints dictate.

Below is the step-by-step transformation of `UserForm1`, highlighting **only the code that changes at each step** alongside its inherent trade-offs.

---

## Baseline: Declarative Prototype

Passing `aIsFocused` directly into the `Grid` constructor allows `Grid` to handle top-level container focus internally. You only pass `IsFocused(&child)` to individual row draw calls.

```cpp
class UserForm1 : public KeyModifier<LayoutBase, KEY_DOWN, KEY_UP> {
    FocusChain<KeyReactor<InputInt, KEY_LEFT, KEY_RIGHT>> mInputField {this, &onValueChanged, 42};
    FocusChain<KeyCatcher<InputButton, KEY_LEFT, KEY_RIGHT>> mSaveButton {this, &onSavePressed, F("Save")};

    void drawer(Screen *aScreen, Coor aPos, Coor aSize, bool aIsFocused) override {
        Grid grid(aScreen, aPos, aSize, aIsFocused);
        grid.SliceRow(1).Draw(mInputField, IsFocused(&mInputField));
        grid.SliceRow(1).Clear();
        grid.SliceRow(1).Draw(mSaveButton, IsFocused(&mSaveButton));
        grid.Rest().Clear();
    }
};
```

---

## Step 1: Removing `Grid` (Direct Coordinate Math)

Replace dynamic grid slicing with direct `Coor` calculations in `drawer()`.

### Code Diff
```cpp
// REPLACE drawer() implementation:
void drawer(Screen *aScreen, Coor aPos, Coor aSize, bool aIsFocused) override {
    const int16_t rowHeight = 10;
    
    // Grid automatically combined container focus (aIsFocused) with child focus.
    // Without Grid, you must manually chain them using `&&` on every single draw call:
    mInputField.drawer(aScreen, aPos, {aSize.x, rowHeight}, aIsFocused && IsFocused(&mInputField));
    
    Coor row2Pos = {aPos.x, (int16_t)(aPos.y + rowHeight + 1)};
    aScreen->Clear(row2Pos, {aSize.x, 1}, 0);
    
    Coor row3Pos = {aPos.x, (int16_t)(aPos.y + rowHeight + 2)};
    mSaveButton.drawer(aScreen, row3Pos, {aSize.x, rowHeight}, aIsFocused && IsFocused(&mSaveButton));
    
    Coor restPos = {aPos.x, (int16_t)(aPos.y + rowHeight * 2 + 2)};
    Coor restSize = {aSize.x, (int16_t)(aSize.y - (rowHeight * 2 + 2))};
    aScreen->Clear(restPos, restSize, 0);
}
```

### Trade-offs
* **Manual Focus Propagation:** Losing `Grid` forces you to explicitly repeat the `aIsFocused &&` condition for every single child control during rendering.
* **Fragile Layout:** Any change to a row height forces manual re-calculation of all subsequent offsets.
* **Overlapping Risk:** Higher probability of manual offset calculation errors leading to visual bugs.

---

## Step 2: Transitioning to `CompositeBase` & `onResidualKey` 

Switch the base class to `CompositeBase`. Focus movement between children is moved to `onResidualKey()`, while children retain their internal reactors for actions.

### Code Diff
```cpp
// CHANGE Base class & Add manual freezer + focus routing:
class UserForm1 : public CompositeBase {
    // Children keep their KeyReactor / KeyCatcher wrappers for inner actions
    KeyReactor<InputInt, KEY_LEFT, KEY_RIGHT> mInputField {this, &onValueChanged, 42};
    KeyCatcher<InputButton, KEY_LEFT, KEY_RIGHT> mSaveButton {this, &onSavePressed, F("Save")};

protected:
    // MUST implement manual freezer contract
    void freezer() override {
        mInputField.Freeze();
        mSaveButton.Freeze();
    }

    // Manual focus switching using focusChild()
    bool onResidualKey(unsigned char aKey) override {
        if (aKey == KEY_UP)   { focusChild(&mInputField); return true; }
        if (aKey == KEY_DOWN) { focusChild(&mSaveButton); return true; }
        return false;
    }
};
```

### Trade-offs
* **Manual Freezer Contract Risk:** Omitting a child inside `freezer()` causes caching bugs where child redrawing gets frozen indefinitely.
* **Hardcoded Focus Routing:** Changing the navigation order requires manual rewrite of conditional logic instead of relying on automatic container sequences.

---

## Step 3: Eliminating Child Reactors (Centralized Input)

Strip `KeyReactor` and `KeyCatcher` wrappers from child members. All key handling (both navigation and actions) is centralized in `onResidualKey()`.

### Code Diff
```cpp
// CHANGE Member definitions to raw controls:
InputInt mInputField {42};
InputButton mSaveButton {F("Save")};

// UPDATE onResidualKey to route actions directly:
bool onResidualKey(unsigned char aKey) override {
    if (aKey == KEY_UP)   { focusChild(&mInputField); return true; }
    if (aKey == KEY_DOWN) { focusChild(&mSaveButton); return true; }

    if (mInputField.IsFocused()) {
        if (aKey == KEY_RIGHT) { mInputField.Increment(); Serial.println("Value Changed"); return true; }
        if (aKey == KEY_LEFT)  { mInputField.Decrement(); Serial.println("Value Changed"); return true; }
    } else if (mSaveButton.IsFocused()) {
        if (aKey == KEY_RIGHT || aKey == KEY_LEFT) {
            Serial.println("Parameter Saved");
            return true;
        }
    }
    return false;
}
```

### Trade-offs
* **Encapsulation Breakdown:** The parent container must explicitly know the inner API and behavior of every child.
* **Loss of Reusable Actions:** Key behaviors cannot be encapsulated into reusable wrappers and must be written imperatively.

---

## Step 4: Footprints / Dynamic Stamping (`ElementBase`)

Inherit from `ElementBase`. Remove persistent child members from RAM entirely, maintaining only raw data state. Re-create temporary instances ("footprints") inside `drawer()`, and process events in `OnKey()`.

### Code Diff
```cpp
// CHANGE Base class & remove persistent child members from RAM:
class UserForm1 : public ElementBase {
private:
    int mValue = 42;
    uint8_t mFocusIndex = 0; // Raw index replaces focusChild()

protected:
    // Event handling moves from onResidualKey() to OnKey():
    bool OnKey(unsigned char aKey) override {
        if (aKey == KEY_UP)   { mFocusIndex = 0; return true; }
        if (aKey == KEY_DOWN) { mFocusIndex = 1; return true; }
        // Action logic operates on raw mValue instead of child methods...
        return false;
    }

public:
    void drawer(Screen *aScreen, Coor aPos, Coor aSize, bool aIsFocused) override {
        // Instantiate temporary "footprints" on stack during render pass:
        InputInt stampInput(mValue);
        stampInput.drawer(aScreen, aPos, {aSize.x, 10}, aIsFocused && (mFocusIndex == 0));

        Coor row3Pos = {aPos.x, (int16_t)(aPos.y + 12)};
        InputButton stampButton(F("Save"));
        stampButton.drawer(aScreen, row3Pos, {aSize.x, 10}, aIsFocused && (mFocusIndex == 1));
    }
};
```

### Trade-offs
* **Forced Full Redraw:** Because persistent child objects no longer exist to track local dirty states or freeze flags, partial invalidation is impossible. Any state update requires redrawing the entire parent container and all its footprints.
* **Loss of Child Autonomy:** Children cannot exist, retain state, or be manipulated independently outside the parent container context.
* **Construction Overhead:** Transient footprint objects are repeatedly constructed and destructed on the stack during render loops.

---

## Step 5: Direct Screen Rendering (Zero Abstraction)

Bypass widget classes entirely. Execute drawing directly via driver primitives (`Screen`) inside `drawer()`.

### Code Diff
```cpp
// REPLACE drawer() implementation with raw Screen calls:
void drawer(Screen *aScreen, Coor aPos, Coor aSize, bool aIsFocused) override {
    const int16_t rowHeight = 10;

    // Direct text rendering and focus invert for row 1
    aScreen->Clear(aPos, {aSize.x, rowHeight}, mFocusIndex == 0 && aIsFocused ? 1 : 0);
    aScreen->PrintNumber(aPos.x + 2, aPos.y + 1, mValue);

    // Direct text rendering and focus invert for row 2
    Coor row3Pos = {aPos.x, (int16_t)(aPos.y + rowHeight + 2)};
    aScreen->Clear(row3Pos, {aSize.x, rowHeight}, mFocusIndex == 1 && aIsFocused ? 1 : 0);
    aScreen->Text(row3Pos.x + 2, row3Pos.y + 1, "Save");
}
```

### Trade-offs
* **Complete Loss of UI Abstractions:** Code reverts to low-level procedural canvas drawing.
* **Zero Reusability:** Every single visual element, focus frame, and font offset must be manually calculated and hardcoded for that specific view.