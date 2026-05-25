#pragma once
#include "Coor.h"
#include <Arduino.h>

class TileScreenBase
{
public:
    virtual Coor Size() = 0;
    virtual void DrawSymbol(Coor position, Coor size, char symbol, unsigned char color) = 0;
    virtual void ClearTile(Coor position);

    // Обычные строки
    void TextLeft(Coor aPosition, Coor aSize, const char *text, unsigned char aColor);
    void TextCenter(Coor aPosition, Coor aSize, const char *text, unsigned char aColor);
    void TextRight(Coor aPosition, Coor aSize, const char *text, unsigned char aColor);

    // F-строки (PROGMEM)
    void TextLeft(Coor aPosition, Coor aSize, const __FlashStringHelper *text, unsigned char aColor);
    void TextCenter(Coor aPosition, Coor aSize, const __FlashStringHelper *text, unsigned char aColor);
    void TextRight(Coor aPosition, Coor aSize, const __FlashStringHelper *text, unsigned char aColor);

    void Clear(Coor aPosition, Coor aSize);

private:
    // Базовые методы печати
    void printTextInArea(Coor aPosition, Coor aSize, const char *text,
                         unsigned char aColor, uint8_t offset);
    void printTextInArea(Coor aPosition, Coor aSize, const __FlashStringHelper *text,
                         unsigned char aColor, uint8_t offset);

    // Универсальные методы расчёта смещения (работают с длиной строки)
    uint8_t calcLeftOffset(Coor aSize, uint8_t textLen);
    uint8_t calcCenterOffset(Coor aSize, uint8_t textLen);
    uint8_t calcRightOffset(Coor aSize, uint8_t textLen);

    // Вспомогательные методы для работы с F-строками
    uint8_t flashStrLen(const __FlashStringHelper *str);
    char flashStrRead(const __FlashStringHelper *str, uint8_t index);
};