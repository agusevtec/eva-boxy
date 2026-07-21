#pragma once

namespace evab
{
    /**
     * @brief Abstract interface for font providers
     * 
     * Defines the contract for font implementations that can
     * provide vertical slices of character bitmaps.
     */
    class IFont
    {
    public:
        /**
         * @brief Gets a vertical slice (column) of a character
         * 
         * @param aCharcode ASCII character code
         * @param col Column index
         * @return unsigned char Bitmap data for the specified column
         */
        virtual unsigned char GetVerticalSlice(char aCharcode, unsigned char col) const = 0;
    };

}
