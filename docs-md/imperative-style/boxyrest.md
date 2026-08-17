# BoxyRest

BoxyRest is a layout helper that provides a fluent interface for slicing rectangular areas into rows and columns, and automatically handles the clearing of unused space.

## The EVA Boxy Drawing Contract

In Boxy, there is a fundamental rule: every element has to completely draw its rectangle, including clearing any unused areas. An element that fails to do so will leave visual garbage from previously drawn content.

This rule applies to all elements. All ready-made elements of the library implement it. When you create custom elements, they must implement it too.

The need to fulfill this contract consistently led to the creation of BoxyRest — a helper that makes the contract easy to implement.

BoxyRest is equally useful whether you are building a complex declarative form or drawing directly on the screen. Even in imperative style, BoxyRest helps organize your layout and automatically handles the cleanup that would otherwise require manual calculations.

## The Problem BoxyRest Solves

Consider a typical container with three children. Without BoxyRest, you would need to manually calculate positions, sizes, and clear unused space:

```cpp
// Without BoxyRest — manual and error-prone
void drawer(Screen* screen, Coor pos, Coor size, bool focused) {
    // Child 1
    child1.Draw(screen, {pos.X, pos.Y}, {size.X, 2}, focused);
    
    // Child 2
    child2.Draw(screen, {pos.X, pos.Y + 2}, {size.X, 2}, focused);
    
    // Child 3
    child3.Draw(screen, {pos.X, pos.Y + 4}, {size.X, 2}, focused);
    
    // Must clear remaining space manually
    screen->Clear({pos.X, pos.Y + 6}, {size.X, size.Y - 6}, 0);
}
```

With BoxyRest, the same logic becomes clean and self-documenting:

```cpp
// With BoxyRest — clear and maintainable
void drawer(Screen* screen, Coor pos, Coor size, bool focused) {
    BoxyRest rest(screen, pos, size, focused);
    rest.CutRow(2).Draw(child1);
    rest.CutRow(2).Draw(child2);
    rest.CutRow(2).Draw(child3);
    rest.Clear();  // Automatically clears any remaining space
}
```

---

## Creating a BoxyRest

A BoxyRest is created with a screen, position, and size:

```cpp
BoxyRest rest(screen, {0, 0}, {16, 8});
```

The rest represents the entire rectangular area that you are responsible for drawing.

---

## Slicing Rows

`CutRow()` cuts off a horizontal slice from the top of the remaining area and returns a new BoxyRest representing that slice.

```cpp
// First row: 2 tiles tall
BoxyRest row1 = rest.CutRow(2);
row1.Draw(child1);

// Second row: 3 tiles tall
BoxyRest row2 = rest.CutRow(3);
row2.Draw(child2);

// Remaining space: automatic height
BoxyRest row3 = rest.CutRow(0);  // or rest.CutRow()
row3.Draw(child3);
```

**Parameters:** `CutRow(height)` — height in tiles. If `0` or omitted, uses all remaining height.

---

## Slicing Columns

`CutCol()` cuts off a vertical slice from the left of the remaining area.

```cpp
// First column: 4 tiles wide
BoxyRest col1 = rest.CutCol(4);
col1.Draw(child1);

// Second column: 6 tiles wide
BoxyRest col2 = rest.CutCol(6);
col2.Draw(child2;

// Remaining space: automatic width
BoxyRest col3 = rest.CutCol(0);  // or rest.CutCol()
col3.Draw(child3);
```

**Parameters:** `CutCol(width)` — width in tiles. If `0` or omitted, uses all remaining width.

---

## Flexible Order: Rows Then Columns, Columns Then Rows

Slicing can be performed in any order. You can slice rows first, then columns within each row. Or slice columns first, then rows within each column.
``

**Example:**

```cpp
BoxyRest rest(screen, pos, size);

// Row 1: 3 tiles tall, split into icon + control
BoxyRest row = rest.CutRow(3);
row.CutCol(3).Picto(GalleryRemixicon24::PICTO_F1F2, 0);  // Icon
row.CutCol(1).Clear();                                    // Spacer
row.Rest().Draw(tempField);                               // Control

// Row 2: clear separator
rest.CutRow(2).Clear();

// Row 3: another row with icon + control
row = rest.CutRow(3);
row.CutCol(3).Picto(GalleryRemixicon24::PICTO_EBD8, 0);  // Icon
row.CutCol(1).Clear();                                    // Spacer
row.Rest().Draw(humField);                                // Control

// Clear remaining space
rest.Clear();
```

### Visual Representation

```
┌─────────────────────────────────────────────┐
│ ┌───────┬─────┬───────────────────────────┐ │
│ │ Icon  │     │      Temp:    25.5        │ │  ← Row 1 (3 tiles)
│ └───────┴─────┴───────────────────────────┘ │
├─────────────────────────────────────────────┤
│                  CLEARED                    │  ← Row 2 (2 tiles, separator)
├─────────────────────────────────────────────┤
│ ┌───────┬─────┬───────────────────────────┐ │
│ │ Icon  │     │      Hum:      62         │ │  ← Row 3 (3 tiles)
│ └───────┴─────┴───────────────────────────┘ │
└─────────────────────────────────────────────┘
```

### Columns Then Rows

```
┌───────┬─────────────────────────────────────┐
│       │                                     │
│ Icon  │      Brightness:        75          │  ← Column 2, Row 1
│       │                                     │
│       ├─────────────────────────────────────┤
│       │      Contrast:          50          │  ← Column 2, Row 2
│       ├─────────────────────────────────────┤
│       │                                     │  ← Column 2, Rest
└───────┴─────────────────────────────────────┘
```

**Example:**

```cpp
BoxyRest rest(screen, pos, size, focused);

// Split into two columns first
BoxyRest col1 = rest.CutCol(4);
BoxyRest col2 = rest.CutCol(0);  // Remaining width

// Within left column: two rows
col1.CutRow(4).Picto(GalleryRemixicon24::PICTO_F243, 0);
col1.Clear();
ну 
// Within right column: controls stacked vertically
col2.CutRow(2).Draw(brightness);
col2.CutRow(2).Draw(contrast);
col2.Clear();

// Clear remaining space in the left column
rest.Clear();
```

---

## Drawing Elements

`Draw()` places an element into the current rest cell:

```cpp
rest.CutRow(2).Draw(myElement);
```

The element receives the cell's position and size. It is responsible for drawing itself completely within that rectangle.

---

## Clearing Space

`Clear()` clears the current cell area. This is useful for creating visual separation between elements:

```cpp
row.CutCol(1).Clear();  // Clears a 1-tile wide spacer column
rest.CutRow(2).Clear(); // Clears a 2-tile tall separator row
```

---

## The `Rest()` and `Clear()` Pattern

`Rest()` returns the original rest with remaining space. `Clear()` clears all remaining area.

```cpp
rest.CutRow(2).Draw(child1);
rest.CutRow(2).Draw(child2);
rest.Clear();  // Clears everything not used by rows above
```

This is essential for the Drawing Chain contract — any unused area must be cleared to avoid visual garbage.