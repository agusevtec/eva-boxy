# 4. Keyboard & Behavior Organization

This section covers keyboard handling, event systems, and composite elements.

## Key Handling Overview

EVAB uses a hierarchical key handling system:

1. Key events are sent to `Boxy::Key()`
2. The root element receives the key
3. Each element processes the key and may pass it to children
4. If no element handles the key, it's ignored

## Keys Enumeration

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
    KEY_0 = 0x30,  // ASCII '0'
    KEY_1, KEY_2, KEY_3, KEY_4,
    KEY_5, KEY_6, KEY_7, KEY_8, KEY_9
};
```

## Element Key Handling

### Base Element

```cpp
class ElementBase {
public:
    // Override to handle keys
    virtual bool Key(Keys aKey);
    
    // Default implementation returns false (not handled)
};
```

### InputInt Key Handling

```cpp
// InputInt handles numeric keys and increment/decrement
InputInt value(42);

// Handles KEY_0..KEY_9 - sets value
// Handles KEY_UP - increments
// Handles KEY_DOWN - decrements
```

### CompositeBase Key Handling

```cpp
class CompositeBase : public ElementBase {
public:
    bool Key(Keys aKey) override {
        // First try focused child
        if (mFocusedChild && mFocusedChild->Key(aKey))
            return true;
        
        // Then try residual keys
        return onResidualKey(aKey);
    }
    
    // Override for composite-specific keys
    virtual bool onResidualKey(Keys aKey);
    
    // Focus management
    void focusChild(ElementBase* aChild);
    bool IsFocused(ElementBase* aChild);
    
private:
    ElementBase* mFocusedChild;
};
```

## Composite Element Example

### Simple Composite

```cpp
class Menu : public CompositeBase {
private:
    ScrollListbox mList;
    Labeled<InputInt> mValue;
    
    void drawer(IScreen* screen, Coor pos, Coor size, uint8_t focused) override {
        mList.Draw(screen, {pos.X, pos.Y}, {size.X, size.Y - 1}, focused);
        mValue.Draw(screen, {pos.X, pos.Y + size.Y - 1}, {size.X, 1}, focused);
    }
    
    void hider() override {
        mList.Hide();
        mValue.Hide();
    }
    
    bool onResidualKey(Keys key) override {
        switch (key) {
            case KEY_ENTER:
                // Execute selected item
                mValue.SetValue(mValue.GetValue() + 1);
                return true;
                
            case KEY_ESCAPE:
                // Exit menu
                return true;
                
            default:
                return false;
        }
    }
    
public:
    Menu() : mValue("Count: ", 0) {
        // Setup list items
        ElementBase* items[] = {/* ... */};
        mList.SetItems(items, 4);
        focusChild(&mList);
    }
};
```

## Behavior Templates

### KeyCatcher Template

Catches specific keys and forwards to a listener.

```cpp
template <class T, Keys... KEYS>
class KeyCatcher : public T {
public:
    enum EventType {
        EVENT_CATCH_KEY = 1,
    };
    
    template <typename... Args>
    KeyCatcher(eva::IHandler* listener, Args&&... args);
    
    bool Key(Keys aKey) override;
};

// Usage
class KeyListener : public eva::IHandler {
    void invoke(void* sender, eva::CallbackInfo info) override {
        if (info.EventType == KeyCatcher<InputInt, KEY_UP, KEY_DOWN>::EVENT_CATCH_KEY) {
            Keys caughtKey = (Keys)info.Param;
            // Handle caught key
        }
    }
};

KeyListener listener;
KeyCatcher<InputInt, KEY_UP, KEY_DOWN> catcher(&listener, 42);
```

### KeyModifier Template

Adds increment/decrement keys to any element with `Increment()` method.

```cpp
template <class T, unsigned char kDec, unsigned char kInc>
class KeyModifier : public T {
public:
    template <typename... Args>
    KeyModifier(Args&&... args);
    
    bool Key(Keys aKey) override;
};

// Usage
KeyModifier<InputInt, KEY_LEFT, KEY_RIGHT> input(42);
// KEY_LEFT decrements, KEY_RIGHT increments
```

### KeyReactor Template

Like KeyModifier but notifies listener of value changes.

```cpp
template <class T, unsigned char kDec, unsigned char kInc>
class KeyReactor : public T {
public:
    enum EventType {
        EVENT_VALUE_CHANGED = 1,
    };
    
    template <typename... Args>
    KeyReactor(eva::IHandler* listener, Args&&... args);
    
    bool Key(Keys aKey) override;
};

// Usage
class ValueListener : public eva::IHandler {
    void invoke(void* sender, eva::CallbackInfo info) override {
        if (info.EventType == KeyReactor<InputInt, KEY_LEFT, KEY_RIGHT>::EVENT_VALUE_CHANGED) {
            int newValue = info.Param;
            // React to value change
        }
    }
};

ValueListener listener;
KeyReactor<InputInt, KEY_LEFT, KEY_RIGHT> reactor(&listener, 42);
```

## Custom Behavior Example

```cpp
// Custom key handling with multiple behaviors
class CustomInput : public InputInt {
private:
    int mMinValue;
    int mMaxValue;
    
public:
    CustomInput(int value, int min, int max) 
        : InputInt(value), mMinValue(min), mMaxValue(max) {}
    
    bool Key(Keys key) override {
        // Handle custom key first
        if (key == KEY_ENTER) {
            // Reset to default
            SetValue(0);
            return true;
        }
        
        // Let base class handle standard keys
        bool handled = InputInt::Key(key);
        
        // Clamp value after any change
        if (handled) {
            int v = GetValue();
            if (v < mMinValue) SetValue(mMinValue);
            if (v > mMaxValue) SetValue(mMaxValue);
        }
        
        return handled;
    }
};
```

## Focus Management

```cpp
class FocusManager : public CompositeBase {
private:
    InputInt mInput1;
    InputInt mInput2;
    InputInt mInput3;
    int mCurrentFocus = 0;
    
    void drawer(IScreen* screen, Coor pos, Coor size, uint8_t focused) override {
        // Draw all inputs, only current has focus
        bool isFocused = focused;
        mInput1.Draw(screen, {pos.X, pos.Y}, {size.X, 1}, isFocused && mCurrentFocus == 0);
        mInput2.Draw(screen, {pos.X, pos.Y + 1}, {size.X, 1}, isFocused && mCurrentFocus == 1);
        mInput3.Draw(screen, {pos.X, pos.Y + 2}, {size.X, 1}, isFocused && mCurrentFocus == 2);
        
        // Focus the current input
        focusChild(&mInput1);
        focusChild(&mInput2);
        focusChild(&mInput3);
    }
    
    bool onResidualKey(Keys key) override {
        if (key == KEY_UP) {
            mCurrentFocus = (mCurrentFocus - 1 + 3) % 3;
            return true;
        }
        if (key == KEY_DOWN) {
            mCurrentFocus = (mCurrentFocus + 1) % 3;
            return true;
        }
        return false;
    }
    
    void hider() override {
        mInput1.Hide();
        mInput2.Hide();
        mInput3.Hide();
    }
    
public:
    FocusManager() : mInput1(0), mInput2(0), mInput3(0) {}
};
```

## Event Handler Interface

```cpp
namespace eva {
    struct CallbackInfo {
        int EventType;
        int Param;
    };
    
    class IHandler {
    public:
        virtual void invoke(void* sender, CallbackInfo info) = 0;
    };
}

// Usage example
class MyHandler : public eva::IHandler {
    void invoke(void* sender, eva::CallbackInfo info) override {
        switch (info.EventType) {
            case 1: // Value changed
                handleValueChange(info.Param);
                break;
            case 2: // Key caught
                handleKeyCaught((Keys)info.Param);
                break;
        }
    }
};
```

---