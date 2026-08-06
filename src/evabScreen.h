// evabScreenBase.h
#pragma once
#include "evabCoor.h"
#include <Arduino.h>
#include <evabTextTraits.h>
#include <evabTextAlign.h>

namespace evab
{
    /**
     * @brief Base class for screen implementations
     *
     * Provides low-level drawing operations and text rendering with alignment.
     */
    class Screen
    {
    public:
        /**
         * @brief Draws text with specified alignment strategy
         *
         * @tparam TAlign Alignment strategy (LeftAlign, CenterAlign, RightAlign)
         * @tparam TText Text type (char*, const char*, __FlashStringHelper*)
         * @param aPosition Position on screen
         * @param aSize Available area size
         * @param aText Text to draw
         * @param aColor Color/inversion flag
         */
        template <typename TAlign, typename TText>
        void Text(Coor aPosition, Coor aSize, TText aText, unsigned char aColor = 0)
        {
            Coor displaySize = Size();

            if (!aText || aSize.Y == 0 || aPosition.X >= displaySize.X || aPosition.Y >= displaySize.Y)
                return;

            unsigned char textLen = TextTraits::Length(aText);
            unsigned char offset = TAlign::Offset(aSize, textLen);
            unsigned char scale = aSize.Y;
            unsigned char maxSymbols = min((int)aSize.X, (int)(displaySize.X - aPosition.X)) / scale;

            for (uint8_t i = 0; i < maxSymbols; i++)
            {
                Coor symbolPos(aPosition.X + i * scale, aPosition.Y);
                uint8_t textIndex = i - offset;
                if (textIndex < textLen)
                {
                    char symbol = TextTraits::Read(aText, textIndex);
                    DrawSymbol(symbolPos, Coor(scale, scale), symbol, aColor);
                }
                else
                {
                    Clear(symbolPos, Coor(scale, scale), aColor);
                }
            }
            unsigned char drawnWidth = maxSymbols * scale;
            if (drawnWidth < aSize.X)
            {
                Coor tailPos(aPosition.X + drawnWidth, aPosition.Y);
                Coor tailSize(aSize.X - drawnWidth, aSize.Y);
                Clear(tailPos, tailSize, aColor);
            }
        }

        template <typename T>
        void TextLeft(Coor aPosition, Coor aSize, T aText, unsigned char aColor = 0)
        {
            Text<LeftAlign>(aPosition, aSize, aText, aColor);
        }

        template <typename T>
        void TextCenter(Coor aPosition, Coor aSize, T aText, unsigned char aColor = 0)
        {
            Text<CenterAlign>(aPosition, aSize, aText, aColor);
        }

        template <typename T>
        void TextRight(Coor aPosition, Coor aSize, T aText, unsigned char aColor = 0)
        {
            Text<RightAlign>(aPosition, aSize, aText, aColor);
        }

        virtual void Picto(Coor aPosition, const unsigned char *aPictogram, unsigned char aColor = 0);
        virtual void DrawSymbol(Coor aPosition, Coor aSize, char aSymbol, unsigned char aColor = 0) = 0;
        virtual void Clear(Coor aPosition, Coor aSize, unsigned char aColor = 0);
        virtual Coor Size() = 0;

        virtual unsigned short Serialize(const Coor &aPosition, const Coor &aSize, bool isFocused) = 0;
        virtual void Deserialize(unsigned short aSerialized, Coor &aPosition, Coor &aSize, bool &isFocused) = 0;

    private:
        virtual void clearTile(Coor position, unsigned char aColor);
    };
}