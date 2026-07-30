// // Tests/WindowAlgorithmTests.cpp
// #include <AUnit.h>
// #include <evabWindowAlgorithms.h>

// using namespace evab;

// // ========== Test Fixture для WindowAlgorithmBase ==========
// class TestableWindowAlgorithm : public WindowAlgorithmBase
// {
// public:
//     // Делаем protected методы публичными для тестирования
//     using WindowAlgorithmBase::indexInWindow;
//     using WindowAlgorithmBase::setCount;
//     using WindowAlgorithmBase::resizeWindow;
    
//     // Реализуем pure virtual Select
//     void Select(unsigned char aIndex) override
//     {
//         if (mCount == 0 || mWindowSize == 0)
//             return;
//         mSelected = ((aIndex % mCount) + mCount) % mCount;
//         mWindowStart = (mSelected / mWindowSize) * mWindowSize;
//     }
    
//     // Геттеры для проверки состояния
//     signed char getSelected() const { return mSelected; }
//     signed char getWindowStart() const { return mWindowStart; }
//     signed char getWindowSize() const { return mWindowSize; }
//     signed char getCount() const { return mCount; }
// };

// // ========== Тесты для WindowAlgorithmBase ==========
// test(WindowAlgorithmTests, Base_IndexInWindow_ReturnsCorrectVisualIndex)
// {
//     TestableWindowAlgorithm algo;
//     algo.setCount(10);
//     algo.resizeWindow(4);
//     algo.Select(5);
    
//     int index = algo.indexInWindow(5);
//     assertEqual(1, index); // 5 - 4 = 1
    
//     index = algo.indexInWindow(8);
//     assertEqual(-1, index); // Outside window
// }

// test(WindowAlgorithmTests, Base_IndexInWindow_WithOffset_ReturnsCorrectIndex)
// {
//     TestableWindowAlgorithm algo;
//     algo.setCount(10);
//     algo.resizeWindow(4);
//     algo.Select(7);
    
//     // После Select(7), windowStart = 4
//     int index = algo.indexInWindow(5);
//     assertEqual(1, index); // 5 - 4 = 1
    
//     index = algo.indexInWindow(7);
//     assertEqual(3, index); // 7 - 4 = 3
    
//     index = algo.indexInWindow(4);
//     assertEqual(0, index);
// }

// test(WindowAlgorithmTests, Base_SetCount_ZeroCount_SelectReturnsMinusOne)
// {
//     TestableWindowAlgorithm algo;
//     algo.setCount(0);
//     algo.resizeWindow(4);
    
//     algo.Select(5);
//     assertEqual(-1, algo.getSelected());
// }

// // ========== Тесты для FlipWindowAlgorithm ==========
// class TestableFlipWindowAlgorithm : public FlipWindowAlgorithm
// {
// public:
//     // Делаем protected методы публичными
//     using FlipWindowAlgorithm::getWindowStart;
//     using FlipWindowAlgorithm::getSelected;
//     using FlipWindowAlgorithm::setCount;
//     using FlipWindowAlgorithm::resizeWindow;
// };

// test(WindowAlgorithmTests, Flip_SelectValidIndex_CalculatesCorrectWindow)
// {
//     TestableFlipWindowAlgorithm algo;
//     algo.setCount(10);
//     algo.resizeWindow(4);
    
//     algo.Select(7);
    
//     assertEqual(7, algo.getSelected());
//     assertEqual(4, algo.getWindowStart()); // Should be 4 (page 2)
// }

// test(WindowAlgorithmTests, Flip_SelectInvalidIndex_WrapsAround)
// {
//     TestableFlipWindowAlgorithm algo;
//     algo.setCount(10);
//     algo.resizeWindow(4);
    
//     algo.Select(12); // Out of range
    
//     assertEqual(2, algo.getSelected()); // 12 % 10 = 2
// }

// test(WindowAlgorithmTests, Flip_SelectNegativeIndex_WrapsCorrectly)
// {
//     TestableFlipWindowAlgorithm algo;
//     algo.setCount(10);
//     algo.resizeWindow(4);
    
//     algo.Select(-3);
    
//     assertEqual(7, algo.getSelected()); // -3 % 10 = 7
// }

// test(WindowAlgorithmTests, Flip_SelectWithWindowSize_CorrectPageCalculation)
// {
//     TestableFlipWindowAlgorithm algo;
//     algo.setCount(10);
//     algo.resizeWindow(4);
    
//     // Page 0: items 0-3
//     algo.Select(2);
//     assertEqual(0, algo.getWindowStart());
    
//     // Page 1: items 4-7
//     algo.Select(5);
//     assertEqual(4, algo.getWindowStart());
    
//     // Page 2: items 8-9
//     algo.Select(9);
//     assertEqual(8, algo.getWindowStart());
// }

// // ========== Тесты для ScrollWindowAlgorithm ==========
// class TestableScrollWindowAlgorithm : public ScrollWindowAlgorithm
// {
// public:
//     // Делаем protected методы публичными
//     using ScrollWindowAlgorithm::getWindowStart;
//     using ScrollWindowAlgorithm::getSelected;
//     using ScrollWindowAlgorithm::setCount;
//     using ScrollWindowAlgorithm::resizeWindow;
// };

// test(WindowAlgorithmTests, Scroll_SelectValidIndex_MaintainsVisibility)
// {
//     TestableScrollWindowAlgorithm algo;
//     algo.setCount(10);
//     algo.resizeWindow(4);
    
//     algo.Select(7);
    
//     assertEqual(7, algo.getSelected());
//     // Window should start at 5 or 6 to keep 7 visible
//     assertTrue(algo.getWindowStart() <= 7);
//     assertTrue(algo.getWindowStart() + 4 > 7);
// }

// test(WindowAlgorithmTests, Scroll_SelectFirstItem_StartsAtZero)
// {
//     TestableScrollWindowAlgorithm algo;
//     algo.setCount(10);
//     algo.resizeWindow(4);
    
//     algo.Select(0);
    
//     assertEqual(0, algo.getSelected());
//     assertEqual(0, algo.getWindowStart());
// }

// test(WindowAlgorithmTests, Scroll_SelectLastItem_MaintainsVisibility)
// {
//     TestableScrollWindowAlgorithm algo;
//     algo.setCount(10);
//     algo.resizeWindow(4);
    
//     algo.Select(9);
    
//     assertEqual(9, algo.getSelected());
//     // Window should start at 6 so last item is visible
//     assertEqual(6, algo.getWindowStart());
// }

// test(WindowAlgorithmTests, Scroll_SelectSecondItem_StartsAtZero)
// {
//     TestableScrollWindowAlgorithm algo;
//     algo.setCount(10);
//     algo.resizeWindow(4);
    
//     algo.Select(1);
    
//     assertEqual(1, algo.getSelected());
//     assertEqual(0, algo.getWindowStart());
// }

// test(WindowAlgorithmTests, Scroll_SelectItemNearEnd_CorrectWindowPosition)
// {
//     TestableScrollWindowAlgorithm algo;
//     algo.setCount(10);
//     algo.resizeWindow(4);
    
//     // When selecting item 8, window should show 6-9
//     algo.Select(8);
//     assertEqual(8, algo.getSelected());
//     assertEqual(6, algo.getWindowStart());
    
//     // When selecting item 7, window should show 5-8
//     algo.Select(7);
//     assertEqual(7, algo.getSelected());
//     assertEqual(5, algo.getWindowStart());
// }

// test(WindowAlgorithmTests, Scroll_SelectItemWithSmallCount_CorrectWindow)
// {
//     TestableScrollWindowAlgorithm algo;
//     algo.setCount(3);
//     algo.resizeWindow(4); // Window bigger than count
    
//     algo.Select(2);
    
//     assertEqual(2, algo.getSelected());
//     assertEqual(0, algo.getWindowStart()); // Should start at 0
// }

// test(WindowAlgorithmTests, Scroll_SelectItemWithWindowSizeOne_ScrollingWorks)
// {
//     TestableScrollWindowAlgorithm algo;
//     algo.setCount(10);
//     algo.resizeWindow(1);
    
//     algo.Select(5);
//     assertEqual(5, algo.getSelected());
//     assertEqual(4, algo.getWindowStart()); // Show item 4,5,6? No, window size 1
//     // Actually with window size 1, windowStart should be 5
//     assertEqual(5, algo.getWindowStart());
// }

// test(WindowAlgorithmTests, Scroll_ConsecutiveSelections_MaintainsSmoothScrolling)
// {
//     TestableScrollWindowAlgorithm algo;
//     algo.setCount(10);
//     algo.resizeWindow(4);
    
//     // Scroll down one by one
//     algo.Select(0);
//     assertEqual(0, algo.getWindowStart());
    
//     algo.Select(1);
//     assertEqual(0, algo.getWindowStart());
    
//     algo.Select(2);
//     assertEqual(0, algo.getWindowStart());
    
//     algo.Select(3);
//     assertEqual(0, algo.getWindowStart());
    
//     algo.Select(4);
//     assertEqual(1, algo.getWindowStart()); // Should start scrolling
    
//     algo.Select(5);
//     assertEqual(2, algo.getWindowStart());
    
//     algo.Select(6);
//     assertEqual(3, algo.getWindowStart());
// }
