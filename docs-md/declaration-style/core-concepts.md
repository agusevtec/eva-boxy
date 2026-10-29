# Core Concepts

`eva-boxy` is designed around **object composition and hierarchical forms**. You build your user interface by creating custom form classes (screens, menus, panels) inherited from `LayoutBase`, and nesting them to manage views, focus, and user navigation.

```text
┌─────────────────────────────────────┐
│ ┌──────────────────────────────┐    │
│ │ ┌───────────┐ ┌────────────┐ │ ─┐ │
│ │ │ ButtonMon │ │ ButtonSet  │ │  │ │
│ │ └───────────┘ └────────────┘ │  │ │
│ └────────────────── MenuForm ──┘  │ │
│  └────────────── MonitoringForm ──┘ │
└───────────────────────── HomeForm ──┘
```

Every UI element represents a rectangular area ("box") that handles its own layout via `Grid`, drawing, and input processing.

---

## 1. Building Layouts and Forms

The foundation of any screen or container is `LayoutBase`. You inherit your custom classes from it and implement the `drawer()` method to render content using a `Grid`:

```cpp
class MenuForm : public LayoutBase {
    InputButtonPx mMonitorButton{ GalleryRemixicon32::PICTO_F243};
    InputButtonPx mSettingsButton{ GalleryRemixicon32::PICTO_F0E4};
private:
    void drawer(Screen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override {
        Grid rest(aScreen, aPos, aSize, aIsFocused);
        rest.CutRow(2).TextCenter(F("MENU"));
        rest.CutRow(2).Clear();
        rest.CutCol(4).Draw(&mMonitorButton);
        rest.CutCol(4).Draw(&mSettingsButton);
        rest.Clear();
    }
};
```

---

## 2. Focus Management & Navigation (`Focusable` + `KeyModifier`)

To enable keyboard navigation inside a layout, elements must be wrapped with **`Focusable<>`** (passing a pointer to the parent layout `this` to register them in the focus chain), while the container itself uses **`KeyModifier`** to process hardware navigation keys (such as `KEY_LEFT` and `KEY_RIGHT`):

```cpp
// KeyModifier listens to navigation keys, while Focusable elements register themselves within 'this' layout
class MenuForm : public KeyModifier<LayoutBase, KEY_LEFT, KEY_RIGHT> {
    Focusable<InputButtonPx> mMonitorButton{this, GalleryRemixicon32::PICTO_F243};
    Focusable<InputButtonPx> mSettingsButton{this, GalleryRemixicon32::PICTO_F0E4};
private:
   // void drawer(Screen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override {
   // ...
};
```

---

## 3. Adding Button Reactions (`KeyCatcher`)

To bind physical confirmation keys (like `KEY_ENTER`) directly to execution logic, you combine `Focusable<>` with **`KeyCatcher`**. 

`KeyCatcher` accepts a callback handler (`Handler`) in its constructor, which intercepts the specified key when the element is focused and invokes the action:

```cpp
class MenuForm : public KeyModifier<LayoutBase, KEY_LEFT, KEY_RIGHT> {
    Focusable<KeyCatcher<InputButtonPx, KEY_ENTER>> mMonitorButton{this, &onMonitorButtonHandler, GalleryRemixicon32::PICTO_F243};
    Focusable<KeyCatcher<InputButtonPx, KEY_ENTER>> mSettingsButton{this, &onSettingsButtonHandler, GalleryRemixicon32::PICTO_F0E4};

private:
    //...
    // Declaration of the event handler callback
    Handler<MenuForm> onMonitorButtonHandler{this, &MenuForm::onMonitorButton};
    void onMonitorButton(void *aSender, CallbackInfo aCallbackInfo) {
        // Handle a pressing
    }
    Handler<MenuForm> onSettingsButtonHandler{this, &MenuForm::onSettingsButton};
    void onSettingsButton(void *aSender, CallbackInfo aCallbackInfo) {
        // Handle a pressing
    }
};
```

---

## 4. The EVA Boxy Ground & Hardware Dispatch

At the base of every application is the central `EVA Boxy` ground. It bridges reactive hardware events to the active UI hierarchy and manages the display pipeline:

```cpp
// 1. Define your top-level layout layer
class HomeForm : public LayoutBase { // or any other ElementBase 
    // ... root composition
};

// 2. Instantiate and bind to the EVA Boxy ground
HomeForm mGroundLayer;

// 3. Dispatch hardware events into EVA Boxy
void onKeyPress() {
    // ...
    Boxy::key(KEY_DOWN);
    // ...
}

void setup() {
    // Initialize display driver, font, and active root layer
    Boxy::Begin<ScreenSSD1306, Font8Sharp>(&mGroundLayer);
}

void loop() {
    eva::tac();
}
```
