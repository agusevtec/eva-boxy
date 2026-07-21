

# Class evab::LayoutPane



[**ClassList**](annotated.md) **>** [**evab**](namespaceevab.md) **>** [**LayoutPane**](classevab_1_1_layout_pane.md)



_Dynamic layout pane for arranging items in a grid._ [More...](#detailed-description)

* `#include <evabLayoutPane.h>`



Inherits the following classes: [evab::ElementBase](classevab_1_1_element_base.md)






















































## Public Functions

| Type | Name |
| ---: | :--- |
|  void | [**SetItems**](#function-setitems) (unsigned short aLayout, [**LayoutPaneItem**](structevab_1_1_layout_pane_item.md) aItems, unsigned char aCount) <br>_Sets up the layout pane with items._  |


## Public Functions inherited from evab::ElementBase

See [evab::ElementBase](classevab_1_1_element_base.md)

| Type | Name |
| ---: | :--- |
|  void | [**Draw**](classevab_1_1_element_base.md#function-draw) ([**IScreen**](classevab_1_1_i_screen.md) \* aScreen, [**Coor**](structevab_1_1_coor.md) aPos, [**Coor**](structevab_1_1_coor.md) aSize, unsigned char aIsFocused) <br>_Draws the element on the specified screen._  |
|  void | [**Hide**](classevab_1_1_element_base.md#function-hide) () <br>_Hides the element from view._  |
|  bool | [**IsHidden**](classevab_1_1_element_base.md#function-ishidden) () <br>_Checks if the element is hidden._  |
| virtual bool | [**Key**](classevab_1_1_element_base.md#function-key) (Keys aKey) <br>_Handles key events for the element._  |
|  void | [**Redraw**](classevab_1_1_element_base.md#function-redraw) () <br>_Redraws the element on the current screen._  |






















































## Detailed Description


Uses a numeric layout definition to determine the grid structure. Each digit represents the number of items in that row. Currently in development (debug version). 


    
## Public Functions Documentation




### function SetItems 

_Sets up the layout pane with items._ 
```C++
void evab::LayoutPane::SetItems (
    unsigned short aLayout,
    LayoutPaneItem aItems,
    unsigned char aCount
) 
```





**Parameters:**


* `aLayout` Layout configuration (digits represent items per row) 
* `aItems` Array of layout items 
* `aCount` Number of items 




        

<hr>

------------------------------
The documentation for this class was generated from the following file `src/evabLayoutPane.h`

