# CompositeBase

`CompositeBase` is a lightweight alternative to `LayoutBase`. While `LayoutBase` provides automatic focus routing and rest-based child propagation, `CompositeBase` serves as a minimal, bare-bones foundation for custom composite elements without layout calculation overhead.

Because it eliminates structural constraints, you gain full control over child execution, but you are directly responsible for **manual focus management**, **explicit freezer propagation**, and **manual positioning**.

---

## Key Differences

| Feature | `CompositeBase` | `LayoutBase` |
| :--- | :--- | :--- |
| **Freezer Propagation** | **Manual** (override `freezer()`) | Automatic across layout slots |
| **Focus & Key Routing** | **Manual** (via `onResidualKey()`) | Automatic focus movement |

---

## Developer Responsibilities

When inheriting from `CompositeBase`, you must manage three key aspects manually:

### 1. Manual Freezer Propagation
Since `CompositeBase` does not maintain an internal layout array, it cannot automatically propagate visibility states. You **must override `freezer()`** and manually call `Freeze()` on all nested children to satisfy the Freeze Contract:

```cpp
class CustomWidget : public CompositeBase {
private:
    Button mButtonA;
    Button mButtonB;

protected:
    void freezer() override {
        // Mandatory: Pass freeze signal down to every child
        mButtonA.Freeze();
        mButtonB.Freeze();
    }
};
```

### 2. Manual Focus Switching via `focusChild()`
Key events propagate bottom-up. You manage focus between children using the protected **`focusChild()`** method provided by `CompositeBase`. Switch focus by passing a pointer to the child element inside `onResidualKey()`:

```cpp
class CustomWidget : public CompositeBase {
protected:
    bool onResidualKey(unsigned char key) override {
        if (key == KEY_NAVIGATE) {
            // Switch active child using protected focusChild() helper
            if (mButtonA.IsFocused()) {
                focusChild(&mButtonB);
            } else {
                focusChild(&mButtonA);
            }
            return true; // Key consumed
        }

        return false; // Key unhandled — bubbles up to parent
    }
};
```

### 3. Lightweight Drawing Without Grid
To keep memory and FLASH usage as low as possible, avoid using `Grid` or heavy layout engines inside `drawer()`. Calculate positions directly using simple `Coor` offsets.

When passing the `focused` state to children, combine the parent's global focus with the child's local focus (`focused && child.IsFocused()`). This ensures child elements are not highlighted as active when the entire container itself loses focus:

```cpp
void drawer(Screen* screen, Coor pos, Coor size, bool focused) override {
    screen->Clear(pos, size, 0); // Mandatory rect clearance

    // Manual positioning without Grid overhead
    Coor halfWidth = { (int16_t)(size.x / 2), size.y };
    Coor rightOffset = { (int16_t)(pos.x + halfWidth.x), pos.y };

    // Pass active focus state ONLY if the container itself is focused
    mButtonA.drawer(screen, pos, halfWidth, focused && mButtonA.IsFocused());
    mButtonB.drawer(screen, rightOffset, halfWidth, focused && mButtonB.IsFocused());
}
```

---

## Summary

Use `CompositeBase` when you want absolute control over your element's inner mechanics without paying the FLASH/RAM cost of automatic layout management. 

Just remember: **If you own the children, you manually freeze them in `freezer()`, route focus using `focusChild(&child)` inside `onResidualKey()`, and calculate their bounds in `drawer()` using `focused && child.IsFocused()` logic.**
