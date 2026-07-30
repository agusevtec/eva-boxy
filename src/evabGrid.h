// evabGrid.h
#pragma once

#include <evabElementBase.h>
#include <evabScreen.h>

namespace evab
{

    /**
     * @brief Layout manager for grid-based UI arrangement
     *
     * Grid provides a fluent interface for organizing UI elements in a grid.
     * Each SliceRow()/SliceCol() returns a new Grid representing the cell.
     *
     * @code
     * Grid grid({0,0}, {16,8});
     * grid.SliceRow(2).Draw(element1);
     * grid.SliceRow(2).SliceCol(2).Draw(element2);
     * grid.SliceRow(2).SliceCol(2).Clear();
     * grid.Rest().Clear();
     * @endcode
     */
    class Grid
    {
    public:
        /**
         * @brief Constructs a Grid for a specific area
         *
         * @param aScreen Screen to draw on
         *         * @param aPos Position on screen
         * @param aSize Size of the grid area
         */
        Grid(Screen *aScreen, Coor aPos, Coor aSize);

        /**
         * @brief Creates a new Grid for the next row
         *
         * @param aHeight Height of the row (0 = use remaining height)
         * @return Grid New grid representing the row
         */
        Grid SliceRow(unsigned char aHeight = 0);

        /**
         * @brief Creates a new Grid for the next column
         *
         * @param aWidth Width of the column (0 = use remaining width)
         * @return Grid New grid representing the column
         */
        Grid SliceCol(unsigned char aWidth = 0);

        /**
         * @brief Returns the remaining space from current position
         *
         * @return Grid& Reference to this grid
         */
        Grid &Rest();

        /**
         * @brief Draws an element in the current cell
         *
         * @param aElement Element to draw
         * @param aIsFocused Focus state (1 = focused, 0 = not focused)
         */
        void Draw(ElementBase *aElement, unsigned char aIsFocused = 0);

        /**
         * @brief Draws text with specified alignment
         *
         * @tparam TAlign Alignment strategy (LeftAlign, CenterAlign, RightAlign)
         * @tparam TText Text type
         * @param aText Text to draw
         * @param aColor Color/inversion flag
         */
        template <typename TAlign, typename TText>
        void Text(TText aText, unsigned char aColor = 0)
        {
            if (mScreen)
                mScreen->Text<TAlign>(mTopLeft, GetSize(), aText, aColor);
        }

        /**
         * @brief Draws left-aligned text
         */
        template <typename T>
        void TextLeft(T aText, unsigned char aColor = 0)
        {
            if (mScreen)
                mScreen->TextLeft(mTopLeft, GetSize(), aText, aColor);
        }

        /**
         * @brief Draws center-aligned text
         */
        template <typename T>
        void TextCenter(T aText, unsigned char aColor = 0)
        {
            if (mScreen)
                mScreen->TextCenter(mTopLeft, GetSize(), aText, aColor);
        }

        /**
         * @brief Draws right-aligned text
         */
        template <typename T>
        void TextRight(T aText, unsigned char aColor = 0)
        {
            if (mScreen)
                mScreen->TextRight(mTopLeft, GetSize(), aText, aColor);
        }

        /**
         * @brief Draws a pictogram in the current cell
         *
         * @param aPictogram Pictogram data
         * @param aColor Color/inversion flag
         */
        void Picto(const unsigned char *aPictogram, unsigned char aColor = 0)
        {
            if (mScreen)
                mScreen->Picto(mTopLeft, aPictogram, aColor);
        }

        /**
         * @brief Clears the current cell area
         */
        void Clear()
        {
            if (mScreen)
                mScreen->Clear(mTopLeft, GetSize(), 0);
        }

        // ========== Getters ==========

        /**
         * @brief Gets the current position
         *
         * @return Coor Current position
         */
        Coor GetPos() const { return mTopLeft; }

        /**
         * @brief Gets the current size
         *
         * @return Coor Current size (clamped to non-negative values)
         */
        Coor GetSize() const;

        /**
         * @brief Gets the screen
         *
         * @return Screen* Current screen
         */
        Screen *GetScreen() const { return mScreen; }

    private:
        Coor mTopLeft;     ///< Top-left corner of current cell
        Coor mBottomRight; ///< Bottom-right corner of current cell
        const Screen *mScreen;   ///< Screen to draw on
    };

}