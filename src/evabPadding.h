#pragma once

#include <evabScreen.h>

namespace evab
{
    /**
     * @brief Decorator that adds vertical padding (top and bottom) to any element.
     *
     * This class wraps an element and adds empty space at the top and bottom,
     * effectively centering the content vertically within the available area.
     *
     * The padding is applied as follows:
     * - Top: 1 tile cleared
     * - Content: drawn in the middle rows
     * - Bottom: 1 tile cleared
     *
     * @tparam T Base element type to decorate
     *
     * @note The element must be at least 3 tiles tall to have visible content.
     *       If the height is less than 3, the content may be clipped.
     *
     * @see PaddingH For horizontal padding (left and right)
     *
     * @code
     * // Add vertical padding to an InputInt
     * PaddingV<InputInt> paddedInput(42);
     *
     * // Use with Labeled decorator
     * PaddingV<LabeledLeft<InputInt>> paddedLabel("Value", 42);
     * @endcode
     */
    template <class T>
    class PaddingV : public T
    {
    public:
        /**
         * @brief Constructor forwarding all arguments to the base element.
         *
         * @tparam Args Types of the constructor arguments
         * @param args Arguments forwarded to the base element constructor
         */
        template <typename... Args>
        PaddingV(Args &&...args)
            : T(args...)
        {
        }

    protected:
        /**
         * @brief Draws the element with vertical padding.
         *
         * Clears one tile at the top and bottom, then draws the base element
         * in the remaining vertical space.
         *
         * @param aScreen Screen to draw on
         * @param aPos Position on screen
         * @param aSize Size of the element
         * @param aIsFocused Focus state (1 = focused, 0 = not focused)
         */
        void drawer(Screen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override
        {
            // Clear top padding
            aScreen->Clear(aPos, {aSize.X, 1}, aIsFocused);

            // Draw base element with vertical padding
            T::drawer(aScreen, {aPos.X, aPos.Y + 1}, {aSize.X, aSize.Y - 2}, aIsFocused);

            // Clear bottom padding
            aScreen->Clear({aPos.X, aPos.Y + aSize.Y - 1}, {aSize.X, 1}, aIsFocused);
        }
    };

    /**
     * @brief Decorator that adds horizontal padding (left and right) to any element.
     *
     * This class wraps an element and adds empty space at the left and right,
     * effectively centering the content horizontally within the available area.
     *
     * The padding is applied as follows:
     * - Left: 1 tile cleared
     * - Content: drawn in the middle columns
     * - Right: 1 tile cleared
     *
     * @tparam T Base element type to decorate
     *
     * @note The element must be at least 3 tiles wide to have visible content.
     *       If the width is less than 3, the content may be clipped.
     *
     * @see PaddingV For vertical padding (top and bottom)
     *
     * @code
     * // Add horizontal padding to an InputInt
     * PaddingH<InputInt> paddedInput(42);
     *
     * // Use with Labeled decorator
     * PaddingH<LabeledLeft<InputInt>> paddedLabel("Value", 42);
     *
     * // Combine vertical and horizontal padding (center element)
     * PaddingV<PaddingH<InputInt>> centeredInput(42);
     * @endcode
     */
    template <class T>
    class PaddingH : public T
    {
    public:
        /**
         * @brief Constructor forwarding all arguments to the base element.
         *
         * @tparam Args Types of the constructor arguments
         * @param args Arguments forwarded to the base element constructor
         */
        template <typename... Args>
        PaddingH(Args &&...args)
            : T(args...)
        {
        }

    protected:
        /**
         * @brief Draws the element with horizontal padding.
         *
         * Clears one tile at the left and right, then draws the base element
         * in the remaining horizontal space.
         *
         * @param aScreen Screen to draw on
         * @param aPos Position on screen
         * @param aSize Size of the element
         * @param aIsFocused Focus state (1 = focused, 0 = not focused)
         */
        void drawer(Screen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override
        {
            // Clear left padding
            aScreen->Clear(aPos, {1, aSize.Y}, aIsFocused);

            // Draw base element with horizontal padding
            T::drawer(aScreen, {aPos.X + 1, aPos.Y}, {aSize.X - 2, aSize.Y}, aIsFocused);

            // Clear right padding
            aScreen->Clear({aPos.X + aSize.X - 1, aPos.Y}, {1, aSize.Y}, aIsFocused);
        }
    };

} // namespace evab