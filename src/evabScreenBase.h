// evabScreenBase.h
#pragma once
#include "evabCoor.h"
#include <Arduino.h>
#include <evabIScreen.h>
#include <evabTextTraits.h>

namespace evab
{
    /**
     * @brief Base class for screen implementations
     *
     * Provides common aText rendering functionality for all screens.
     */
    class ScreenBase : public IScreen
    {
    public:
        /**
         * @brief Draws aText aligned left (C-string)
         */
        void TextLeft(Coor aPosition, Coor aSize, const char *aText, unsigned char aColor) override;

        /**
         * @brief Draws aText aligned center (C-string)
         */
        void TextCenter(Coor aPosition, Coor aSize, const char *aText, unsigned char aColor) override;

        /**
         * @brief Draws aText aligned right (C-string)
         */
        void TextRight(Coor aPosition, Coor aSize, const char *aText, unsigned char aColor) override;

        /**
         * @brief Draws aText aligned left (Flash string)
         */
        void TextLeft(Coor aPosition, Coor aSize, const __FlashStringHelper *aText, unsigned char aColor) override;

        /**
         * @brief Draws aText aligned center (Flash string)
         */
        void TextCenter(Coor aPosition, Coor aSize, const __FlashStringHelper *aText, unsigned char aColor) override;

        /**
         * @brief Draws aText aligned right (Flash string)
         */
        void TextRight(Coor aPosition, Coor aSize, const __FlashStringHelper *aText, unsigned char aColor) override;

        /**
         * @brief Clears a rectangular area
         */
        void Clear(Coor aPosition, Coor aSize, unsigned char aColor) override;

        /**
         * @brief Draws a pictogram (default implementation)
         */
        virtual void Picto(Coor aPosition, const unsigned char *aPictogramm, unsigned char aColor);

    protected:
        /**
         * @brief Clears a single tile
         */
        virtual void ClearTile(Coor position, unsigned char aColor);

    private:
        /**
         * @brief Template method for printing aText in area
         */
        template <typename T>
        void printTextInArea(Coor aPosition, Coor aSize, T aText,
                             unsigned char aColor, unsigned char offset)
        {
            Coor displaySize = Size();
            unsigned char scale = aSize.Y;
            unsigned char maxSymbols = min((int)aSize.X, (int)(displaySize.X - aPosition.X)) / scale;
            unsigned char textLen = TextTraits<T>::Length(aText);

            for (unsigned char i = 0; i < maxSymbols; i++)
            {
                Coor symbolPos(aPosition.X + i * scale, aPosition.Y);
                unsigned char textIndex = i - offset;
                if (textIndex < textLen)
                {
                    char symbol = TextTraits<T>::Read(aText, textIndex);
                    DrawSymbol(symbolPos, Coor(scale, scale), symbol, aColor);
                }
                else
                {
                    DrawSymbol(symbolPos, Coor(scale, scale), ' ', aColor);
                }
            }
        }

        /**
         * @brief Calculates offset for left alignment
         */
        unsigned char calcLeftOffset(Coor aSize, unsigned char textLen);

        /**
         * @brief Calculates offset for center alignment
         */
        unsigned char calcCenterOffset(Coor aSize, unsigned char textLen);

        /**
         * @brief Calculates offset for right alignment
         */
        unsigned char calcRightOffset(Coor aSize, unsigned char textLen);
    };
}