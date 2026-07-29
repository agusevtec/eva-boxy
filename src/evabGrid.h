// evabMesh.h
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
     * Grid mesh({0,0}, {16,8});
     * mesh.SliceRow(2).Draw(screen, element1);
     * mesh.SliceRow(2).SliceCol(2).Draw(screen, element2);
     * mesh.SliceRow(2).SliceCol(2).Clean(screen);
     * mesh.Rest().Clean(screen);
     * @endcode
     */
    class Grid
    {
    public:
        /**
         * @brief Constructs a Grid for a specific area
         * 
         * @param aPos Position on screen
         * @param aSize Size of the mesh area
         */
        Grid(Coor aPos, Coor aSize);

        /**
         * @brief Creates a new Grid for the next row
         * 
         * @param aHeight Height of the row (0 = use remaining height)
         * @return Grid New mesh representing the row
         */
        Grid SliceRow(unsigned char aHeight = 0);

        /**
         * @brief Creates a new Grid for the next column
         * 
         * @param aWidth Width of the column (0 = use remaining width)
         * @return Grid New mesh representing the column
         */
        Grid SliceCol(unsigned char aWidth = 0);

        /**
         * @brief Returns the remaining space from current position
         * 
         * @return Grid New mesh representing the remaining space
         */
        Grid& Rest();

        /**
         * @brief Draws an element in the current cell
         * 
         * @param aScreen Screen to draw on
         * @param aElement Element to draw
         * @param aIsFocused Focus state (1 = focused, 0 = not focused)
         */
        void Draw(Screen *aScreen, ElementBase *aElement, unsigned char aIsFocused = 0);

        /**
         * @brief Clears the current cell area
         * 
         * @param aScreen Screen to draw on
         */
        void Blank(Screen *aScreen);

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

    private:
        Coor mTopLeft;      ///< Top-left corner of current cell
        Coor mBottomRight;  ///< Bottom-right corner of current cell
    };

}