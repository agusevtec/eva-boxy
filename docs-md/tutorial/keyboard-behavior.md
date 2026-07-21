# Keyboard Behavior

EVA Boxy provides automatic keyboard event handling through the `Boxy::Key()` method. Elements must be wrapped with behavior modifiers to handle key events properly.

## Key Handling Flow

```
Physical Input → Boxy::Key() → Root Element → Composite → Child Elements
                                    ↓
                          Focused Element
                                    ↓
                          Returns true if consumed
                                    ↓
                     Parent checks if key was used
```

## Key Codes

```cpp
enum Keys {
    KEY_MENU = 1,
    KEY_MODE,
    KEY_ENTER,
    KEY_ESCAPE,
    KEY_DELETE,
    KEY_BACKSPACE,
    KEY_DOWN,
    KEY_UP,
    KEY_LEFT,
    KEY_RIGHT,
    KEY_PAGEUP,
    KEY_PAGEDOWN,
    KEY_PLUS,
    KEY_MINUS,
    KEY_0 = 0x30,
    KEY_1,
    KEY_2,
    KEY_3,
    KEY_4,
    KEY_5,
    KEY_6,
    KEY_7,
    KEY_8,
    KEY_9
};
```

## Key Input

### Sending Keys to Boxy

```cpp
// In your main loop
void loop() {
    if (buttonDownPressed()) {
        evab::Boxy::Key(KEY_DOWN);
    }
    if (buttonUpPressed()) {
        evab::Boxy::Key(KEY_UP);
    }
    if (buttonMenuPressed()) {
        evab::Boxy::Key(KEY_MENU);
    }
    if (buttonEnterPressed()) {
        evab::Boxy::Key(KEY_ENTER);
    }
}
```

### Key Propagation

Keys are passed to the root element and propagated down:

```cpp
void Boxy::Key(Keys key) {
    auto instance = Instance();
    if (instance->mGround)
        instance->mGround->Key(key);  // Start at root
}
```

## Behavior Modifiers

### KeyCatcher

Catches specific keys and notifies a listener.

```cpp
#include <evabBehavior.h>

// Wrap an element to catch specific keys
KeyCatcher<ElementType, KEY_LEFT, KEY_RIGHT> catcher(listener, args...);

// Example
KeyCatcher<ScrollListbox, KEY_LEFT, KEY_RIGHT> listbox = {this};

// Listener receives EVENT_CATCH_KEY
void invoke(void* sender, CallbackInfo info) {
    if (info.eventType == EVENT_CATCH_KEY) {
        int key = info.eventArg;
        if (key == KEY_LEFT) { /* handle left */ }
        if (key == KEY_RIGHT) { /* handle right */ }
    }
}
```

### KeyModifier

Adds increment/decrement behavior to an element.

```cpp
// Element with +/- keys
KeyModifier<InputInt, KEY_MINUS, KEY_PLUS> modifier;

// Example with listbox
KeyModifier<ScrollListbox, KEY_UP, KEY_DOWN> listbox;
// KEY_UP → Select(-1), KEY_DOWN → Select(+1)
```

### KeyReactor

Combines KeyModifier with event notification.

```cpp
// Reactor that notifies on value change
KeyReactor<InputInt, KEY_MINUS, KEY_PLUS> reactor(listener, 0);

// Listener receives EVENT_VALUE_CHANGED
void invoke(void* sender, CallbackInfo info) {
    if (info.eventType == EVENT_VALUE_CHANGED) {
        int value = info.eventArg;
        // Handle changed value
    }
}
```

## Focus Management

### Focus Hierarchy

```
┌─────────────────────────────────┐
│  CompositeBase                  │
│  ┌───────────────────────────┐  │
│  │  Focused Child            │  │
│  │  ┌─────────────────────┐  │  │
│  │  │  Sub-child          │  │  │
│  │  └─────────────────────┘  │  │
│  └───────────────────────────┘  │
└─────────────────────────────────┘
```

### Focus Control Methods

```cpp
class CompositeBase {
protected:
    // Set focused child
    void focusChild(ElementBase* child);
    
    // Check if child has focus
    bool IsFocused(ElementBase* child);
    
    // Override for custom focus handling
    virtual bool onResidualKey(Keys key);
};
```

### Focus Example

```cpp
class MyUI : public CompositeBase {
public:
    MyUI() {
        focusChild(&mListbox);  // Initial focus
    }
    
protected:
    bool onResidualKey(Keys key) override {
        if (key == KEY_MENU) {
            // Cycle focus between children
            if (IsFocused(&mListbox)) {
                focusChild(&mButton);
            } else {
                focusChild(&mListbox);
            }
            Redraw();
            return true;
        }
        return false;
    }
    
private:
    ScrollListbox mListbox;
    InputButton mButton;
};
```

## Greedy Key Capture

Elements at the top of the hierarchy can "capture" keys before children.

### Key Capture Chain

```cpp
bool ElementBase::Key(Keys key) {
    // Children process first
    if (mFocusedChild && mFocusedChild->Key(key))
        return true;  // Key consumed by child
    
    // Then try own keys
    if (mOwnKeyHandler(key))
        return true;  // Key consumed by parent
    
    return false;  // Key not consumed
}
```

### Greedy Element Example

```cpp
// This element captures all keys before children can see them
class GreedyElement : public CompositeBase {
protected:
    bool onResidualKey(Keys key) override {
        // Always capture keys, never pass to children
        return true;  // Consumes all keys
    }
};

// Selective greedy - captures only certain keys
class SelectiveGreedy : public CompositeBase {
protected:
    bool onResidualKey(Keys key) override {
        if (key == KEY_MENU || key == KEY_ENTER) {
            // These keys are captured
            return true;
        }
        // Other keys pass to children
        return false;
    }
};
```

## CompositeBase Customization

### Overriding Key Handling

```cpp
class MyComposite : public CompositeBase {
protected:
    bool onResidualKey(Keys key) override {
        switch(key) {
            case KEY_MENU:
                // Toggle between views
                if (IsFocused(&mView1)) {
                    focusChild(&mView2);
                } else {
                    focusChild(&mView1);
                }
                Redraw();
                return true;
                
            case KEY_PAGEDOWN:
                // Move to next section
                focusChild(&mNextSection);
                Redraw();
                return true;
                
            case KEY_ENTER:
                // Execute action
                executeAction();
                return true;
                
            default:
                return false;
        }
    }
};
```

## Complete Example

```cpp
#include <evabBoxy.h>
#include <evabBehavior.h>
#include <evabInputInt.h>
#include <evabLabeled.h>

class MyUI : public CompositeBase, public IHandler {
public:
    MyUI()
        : mParam1("Value", 50),
          mParam2("Speed", 25),
          mButton(F("OK"))
    {
        mParams[0] = &mParam1;
        mParams[1] = &mParam2;
        mParams[2] = &mButton;
        
        mListbox.SetItems(mParams, 3)
                .SetItemHeight(1);
        
        // Wrap with key modifiers
        // KEY_UP/DOWN for navigation
        // KEY_LEFT/RIGHT for value adjustment (with notifications)
        // KEY_MENU for special handling
        
        focusChild(&mListbox);
    }
    
protected:
    void drawer(IScreen* screen, Coor pos, Coor size, unsigned char focused) override {
        screen->TextCenter(pos, {size.X, 1}, F("Settings"), focused);
        mListbox.Draw(screen, {pos.X, pos.Y + 1}, {size.X, size.Y - 1},
                      IsFocused(&mListbox));
    }
    
    void hider() override {
        mListbox.Hide();
    }
    
    bool onResidualKey(Keys key) override {
        if (key == KEY_MENU) {
            // Confirm selection
            CommandQueue::Put(ACTION_CONFIRM, mListbox.Selected());
            return true;
        }
        return false;
    }
    
    void invoke(void* sender, CallbackInfo info) override {
        if (info.eventType == EVENT_VALUE_CHANGED) {
            int value = info.eventArg;
            int index = mListbox.Selected();
            // Update settings
        }
    }
    
private:
    Labeled<InputInt> mParam1;
    Labeled<InputInt> mParam2;
    InputButton mButton;
    ElementBase* mParams[3];
    
    // Wrapped listbox with key modifiers
    KeyCatcher<
        KeyModifier<ScrollListbox, KEY_UP, KEY_DOWN>,
        KEY_LEFT, KEY_RIGHT
    > mListbox = {this};
};
```

## Summary

| Modifier | Purpose | Use Case |
|----------|---------|----------|
| `KeyCatcher` | Catch specific keys | Menu navigation |
| `KeyModifier` | Add +/- behavior | Value adjustment |
| `KeyReactor` | Notify on change | Real-time updates |

**Key Points:**
- `Boxy::Key()` is the entry point for all keyboard events
- Elements must be wrapped with modifiers for automatic handling
- React methods use increments for value changes
- Focus determines which element receives keys first
- Greedy elements at the top of hierarchy can capture keys
- `onResidualKey()` must be implemented in custom composites
- Always check if a key was consumed before passing it on