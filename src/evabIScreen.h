#pragma once
#include <evabCoor.h>
#include <Arduino.h>

namespace evab
{
    class IScreen
    {
    public:
        virtual void TextLeft(Coor aPosition, Coor aSize, const char *text, unsigned char aColor) = 0;
        virtual void TextCenter(Coor aPosition, Coor aSize, const char *text, unsigned char aColor) = 0;
        virtual void TextRight(Coor aPosition, Coor aSize, const char *text, unsigned char aColor) = 0;

        virtual void TextLeft(Coor aPosition, Coor aSize, const __FlashStringHelper *text, unsigned char aColor)  = 0;
        virtual void TextCenter(Coor aPosition, Coor aSize, const __FlashStringHelper *text, unsigned char aColor) = 0;
        virtual void TextRight(Coor aPosition, Coor aSize, const __FlashStringHelper *text, unsigned char aColor) = 0;

        virtual void Picto(Coor aPosition, const uint8_t *pictoData, unsigned char aColor) = 0;
        virtual void Clear(Coor aPosition, Coor aSize, unsigned char aColor = 0) = 0;
        virtual Coor Size() = 0;
    };
}