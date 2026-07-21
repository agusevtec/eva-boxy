#pragma once

#include <evabIFont.h>
#include <Arduino.h>

namespace evab
{
    /**
     * @brief 8x8 thin font implementation
     *
     * Provides a thin 8x8 pixel font for display systems.
     */
    class Font8Narrow : public IFont
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
        static const unsigned char kCharmap[][7] PROGMEM; ///< Character bitmap data
    };
}
