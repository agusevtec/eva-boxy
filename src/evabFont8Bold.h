#pragma once

#include <Arduino.h>
#include <evabIFont.h>

namespace evab
{
    /**
     * @brief 8x8 bold font implementation
     *
     * Provides a bold 8x8 pixel font for display systems.
     */
    class Font8Bold : public IFont
    {
    public:
        /**
         * @brief Gets a vertical slice of a character
         *
         * @param aCharcode ASCII character code (32-126)
         * @param col Column index (0-7)
         * @return unsigned char Bitmap data for the specified column
         */
        unsigned char GetVerticalSlice(char aCharcode, unsigned char col) const override;

    private:
        static const unsigned char kCharmap[][8] PROGMEM; ///< Character bitmap data
    };
}
