#pragma once

#include <evabIFont.h>
#include <Arduino.h>

namespace evab
{
    /**
     * @brief 8x8 compact font implementation
     * 
     * Provides a compact 8x8 pixel font that saves memory
     * by storing only 5 columns per character.
     */
    class Font8Compact: public IFont
    {
    public:
        /**
         * @brief Gets a vertical slice of a character
         * 
         * @param aCharcode ASCII character code (32-126)
         * @param aSliceColumn Column index (0-7)
         * @return unsigned char Bitmap data for the specified column
         */
        unsigned char GetVerticalSlice(char aCharcode, unsigned char aSliceColumn) const override;

    private:
        static const unsigned char kCharmap[][5] PROGMEM;  ///< Character bitmap data
    };
}
