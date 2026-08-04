// evabTextAlign.h
#pragma once

#include <evabCoor.h>
#include <evabTextTraits.h>

namespace evab
{

    /**
     * @brief Left alignment strategy
     */
    struct LeftAlign
    {
        /**
         * @brief Calculates offset for left alignment
         * @param aSize Available area size
         * @param textLen Text length in characters
         * @return Always 0 (left alignment)
         */
        static unsigned char Offset(Coor aSize, unsigned char textLen);
    };

    /**
     * @brief Center alignment strategy
     */
    struct CenterAlign
    {
        /**
         * @brief Calculates offset for center alignment
         * @param aSize Available area size
         * @param textLen Text length in characters
         * @return Offset to center the text
         */
        static unsigned char Offset(Coor aSize, unsigned char textLen);
    };

    /**
     * @brief Right alignment strategy
     */
    struct RightAlign
    {
        /**
         * @brief Calculates offset for right alignment
         * @param aSize Available area size
         * @param textLen Text length in characters
         * @return Offset to right-align the text
         */
        static unsigned char Offset(Coor aSize, unsigned char textLen);
    };

} // namespace evab