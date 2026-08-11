# Grid

Grid is a layout helper that provides a fluent interface for slicing rectangular areas into rows and columns, and automatically handles the clearing of unused space.

## The EVA Boxy Drawing Contract

In Boxy, there is a fundamental rule: every element has to completely draw its rectangle, including clearing any unused areas. An element that fails to do so will leave visual garbage from previously drawn content.

This rule applies to all elements. All ready-made elements of the library implement it. When you create custom elements, they must implement it too.

The need to fulfill this contract consistently led to the creation of Grid — a helper that makes the contract easy to implement.

Grid is equally useful whether you are building a complex declarative form or drawing directly on the screen. Even in imperative style, Grid helps organize your layout and automatically handles the cleanup that would otherwise require manual calculations.

## The Problem Grid Solves

Consider a typical container with three children. Without Grid, you would need to manually calculate positions, sizes, and clear unused space:

```cpp
// Without Grid — manual and error-prone
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

With Grid, the same logic becomes clean and self-documenting:

```cpp
// With Grid — clear and maintainable
void drawer(Screen* screen, Coor pos, Coor size, bool focused) {
    Grid grid(screen, pos, size, focused);
    grid.SliceRow(2).Draw(child1);
    grid.SliceRow(2).Draw(child2);
    grid.SliceRow(2).Draw(child3);
    grid.Rest().Clear();  // Automatically clears any remaining space
}
```

---

## Creating a Grid

A Grid is created with a screen, position, and size:

```cpp
Grid grid(screen, {0, 0}, {16, 8});
```

The grid represents the entire rectangular area that you are responsible for drawing.

---

## Slicing Rows

`SliceRow()` cuts off a horizontal slice from the top of the remaining area and returns a new Grid representing that slice.

```cpp
// First row: 2 tiles tall
Grid row1 = grid.SliceRow(2);
row1.Draw(child1);

// Second row: 3 tiles tall
Grid row2 = grid.SliceRow(3);
row2.Draw(child2);

// Remaining space: automatic height
Grid row3 = grid.SliceRow(0);  // or grid.SliceRow()
row3.Draw(child3);
```

**Parameters:** `SliceRow(height)` — height in tiles. If `0` or omitted, uses all remaining height.

---

## Slicing Columns

`SliceCol()` cuts off a vertical slice from the left of the remaining area.

```cpp
// First column: 4 tiles wide
Grid col1 = grid.SliceCol(4);
col1.Draw(child1);

// Second column: 6 tiles wide
Grid col2 = grid.SliceCol(6);
col2.Draw(child2;

// Remaining space: automatic width
Grid col3 = grid.SliceCol(0);  // or grid.SliceCol()
col3.Draw(child3);
```

**Parameters:** `SliceCol(width)` — width in tiles. If `0` or omitted, uses all remaining width.

---

## Flexible Order: Rows Then Columns, Columns Then Rows

Slicing can be performed in any order. You can slice rows first, then columns within each row. Or slice columns first, then rows within each column.

### Rows Then Columns

```
┌─────────────────────────────────────────────┐
│ ┌───────┬─────────────────────────────────┐ │
│ │ Icon  │      OriginalControl            │ │  ← Row 1
│ └───────┴─────────────────────────────────┘ │
├─────────────────────────────────────────────┤
│ ┌───────┬─────────────────────────────────┐ │
│ │ Icon  │      OriginalControl            │ │  ← Row 2
│ └───────┴─────────────────────────────────┘ │
└─────────────────────────────────────────────┘
```

**Example:**

```cpp
Grid grid(screen, pos, size);

// Row 1: 3 tiles tall, split into icon + control
Grid row = grid.SliceRow(3);
row.SliceCol(3).Picto(GalleryRemixicon24::PICTO_F1F2, 0);  // Icon
row.SliceCol(1).Clear();                                    // Spacer
row.Rest().Draw(tempField);                               // Control

// Row 2: clear separator
grid.SliceRow(2).Clear();

// Row 3: another row with icon + control
row = grid.SliceRow(3);
row.SliceCol(3).Picto(GalleryRemixicon24::PICTO_EBD8, 0);  // Icon
row.SliceCol(1).Clear();                                    // Spacer
row.Rest().Draw(humField);                                // Control

// Clear remaining space
grid.Rest().Clear();
```

### Visual Representation

```
┌─────────────────────────────────────────────┐
│ ┌───────┬─────┬───────────────────────────┐ │
│ │ Icon  │     │      Temp:    25.5°C      │ │  ← Row 1 (3 tiles)
│ └───────┴─────┴───────────────────────────┘ │
├─────────────────────────────────────────────┤
│                  CLEARED                    │  ← Row 2 (2 tiles, separator)
├─────────────────────────────────────────────┤
│ ┌───────┬─────┬───────────────────────────┐ │
│ │ Icon  │     │      Hum:      62%        │ │  ← Row 3 (3 tiles)
│ └───────┴─────┴───────────────────────────┘ │
└─────────────────────────────────────────────┘
```

### Columns Then Rows

```
┌───────┬─────────────────────────────────────┐
│       │                                     │
│ Icon  │      Brightness:        75%         │  ← Column 2, Row 1
│       │                                     │
│       ├─────────────────────────────────────┤
│       │      Contrast:          50          │  ← Column 2, Row 2
│       ├─────────────────────────────────────┤
│       │                                     │  ← Column 2, Rest
└───────┴─────────────────────────────────────┘
```

**Example:**

```cpp
Grid grid(screen, pos, size, focused);

// Split into two columns first
Grid col1 = grid.SliceCol(4);
Grid col2 = grid.SliceCol(0);  // Remaining width

// Within left column: two rows
col1.SliceRow(4).Picto(GalleryRemixicon24::PICTO_F243, 0);
col1.Rest().Clear();
ну 
// Within right column: controls stacked vertically
col2.SliceRow(2).Draw(brightness);
col2.SliceRow(2).Draw(contrast);
col2.Rest().Clear();

// Clear remaining space in the left column
grid.Rest().Clear();
```

---

## Drawing Elements

`Draw()` places an element into the current grid cell:

```cpp
grid.SliceRow(2).Draw(myElement);
```

The element receives the cell's position and size. It is responsible for drawing itself completely within that rectangle.

---

## Clearing Space

`Clear()` clears the current cell area. This is useful for creating visual separation between elements:

```cpp
row.SliceCol(1).Clear();  // Clears a 1-tile wide spacer column
grid.SliceRow(2).Clear(); // Clears a 2-tile tall separator row
```

---

## The `Rest()` and `Clear()` Pattern

`Rest()` returns the original grid with remaining space. `Clear()` clears all remaining area.

```cpp
grid.SliceRow(2).Draw(child1);
grid.SliceRow(2).Draw(child2);
grid.Rest().Clear();  // Clears everything not used by rows above
```

This is essential for the Drawing Chain contract — any unused area must be cleared to avoid visual garbage.