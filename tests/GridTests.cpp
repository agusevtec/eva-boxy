// Tests/BoxyRestTests.cpp
#include <AUnit.h>
#include <evabGrid.h>
#include "MockElementBase.h"

using namespace evab;

test(BoxyRestTests, CutRow_FirstRow_SetsCorrectPosition)
{
    MockScreen screen({16, 8});
    Grid rest(Coor(0, 0), Coor(16, 8));
    
    auto row = rest.CutRow(2);
    
    Coor pos = row.GetPos();
    Coor size = row.GetSize();
    
    assertEqual(0, pos.X);
    assertEqual(0, pos.Y);
    assertEqual(16, size.X);
    assertEqual(2, size.Y);
}

test(BoxyRestTests, CutRow_MultipleRows_AdvancesPositionCorrectly)
{
    MockScreen screen({16, 8});
    Grid rest(Coor(0, 0), Coor(16, 8));
    
    auto row1 = rest.CutRow(2);
    auto row2 = rest.CutRow(3);
    
    Coor pos2 = row2.GetPos();
    Coor size2 = row2.GetSize();
    
    assertEqual(0, pos2.X);
    assertEqual(2, pos2.Y);
    assertEqual(16, size2.X);
    assertEqual(3, size2.Y);
}

test(BoxyRestTests, CutCol_WithinRow_SetsCorrectPosition)
{
    MockScreen screen({16, 8});
    Grid rest(Coor(0, 0), Coor(16, 8));
    
    auto row = rest.CutRow(2);
    auto col = row.CutCol(6);
    
    Coor pos = col.GetPos();
    Coor size = col.GetSize();
    
    assertEqual(0, pos.X);
    assertEqual(0, pos.Y);
    assertEqual(6, size.X);
    assertEqual(2, size.Y);
}

test(BoxyRestTests, CutCol_MultipleCols_AdvancesPositionCorrectly)
{
    MockScreen screen({16, 8});
    Grid rest(Coor(0, 0), Coor(16, 8));
    
    auto row = rest.CutRow(2);
    auto col1 = row.CutCol(6);
    auto col2 = row.CutCol(4);
    
    Coor pos2 = col2.GetPos();
    Coor size2 = col2.GetSize();
    
    assertEqual(6, pos2.X);
    assertEqual(0, pos2.Y);
    assertEqual(4, size2.X);
    assertEqual(2, size2.Y);
}

test(BoxyRestTests, Rest_UsesRemainingSpace)
{
    MockScreen screen({16, 8});
    Grid rest(Coor(0, 0), Coor(16, 8));
    
    auto row = rest.CutRow(2);
    auto col = row.CutCol(6);
    auto rest = row.Rest();
    
    Coor pos = rest.GetPos();
    Coor size = rest.GetSize();
    
    assertEqual(6, pos.X);
    assertEqual(0, pos.Y);
    assertEqual(10, size.X);
    assertEqual(2, size.Y);
}

test(BoxyRestTests, Draw_Element_DrawsAtCorrectPosition)
{
    MockScreen screen({16, 8});
    Grid rest(Coor(0, 0), Coor(16, 8));
    MockElement element("A");
    screen.clear();
    
    auto row = rest.CutRow(2);
    row.Draw(&screen, &element, 1);
    
    assertTrue(element.mDrawCalled);
    assertEqual(0, element.mLastPos.X);
    assertEqual(0, element.mLastPos.Y);
    assertEqual(16, element.mLastSize.X);
    assertEqual(2, element.mLastSize.Y);
    assertEqual(1, element.mLastFocused);
}

// test(BoxyRestTests, Blank_ClearsArea)
// {
//     MockScreen screen({16, 8});
//     Grid rest(Coor(0, 0), Coor(16, 8));
//     screen.clear();
    
//     auto row = rest.CutRow(2);
//     row.Blank(&screen);
    
//     assertEqual(1, screen.mCleared.size());
//     auto &cleared = screen.mCleared[0];
//     assertEqual(0, std::get<0>(cleared).X);
//     assertEqual(0, std::get<0>(cleared).Y);
//     assertEqual(16, std::get<1>(cleared).X);
//     assertEqual(2, std::get<1>(cleared).Y);
// }

test(BoxyRestTests, CutRow_RowHeightZero_UsesRemainingHeight)
{
    MockScreen screen({16, 8});
    Grid rest(Coor(0, 0), Coor(16, 8));
    
    auto row1 = rest.CutRow(2);
    auto row2 = rest.CutRow(0); // Should use remaining
    
    Coor size2 = row2.GetSize();
    assertEqual(6, size2.Y); // 8 - 2 = 6
}

test(BoxyRestTests, CutCol_ColWidthZero_UsesRemainingWidth)
{
    MockScreen screen({16, 8});
    Grid rest(Coor(0, 0), Coor(16, 8));
    
    auto row = rest.CutRow(2);
    auto col1 = row.CutCol(6);
    auto col2 = row.CutCol(0); // Should use remaining
    
    Coor size2 = col2.GetSize();
    assertEqual(10, size2.X); // 16 - 6 = 10
}

test(BoxyRestTests, NestedBoxyRests_NestedSlicing_WorksCorrectly)
{
    MockScreen screen({16, 8});
    Grid rest(Coor(0, 0), Coor(16, 8));
    
    auto row = rest.CutRow(4);
    auto col = row.CutCol(8);
    auto nestedRow = col.CutRow(2);
    auto nestedCol = nestedRow.CutCol(4);
    
    Coor pos = nestedCol.GetPos();
    Coor size = nestedCol.GetSize();
    
    assertEqual(0, pos.X);
    assertEqual(0, pos.Y);
    assertEqual(4, size.X);
    assertEqual(2, size.Y);
}