// evabTextTraits.h
#pragma once

#include <Arduino.h>

namespace evab
{

    /**
     * @brief Traits for C-string (char*)
     */
    struct TextTraits
    {

        static unsigned char Length(const char* aText)
        {
            return strlen(aText);
        }

        static char Read(const char* aText, unsigned char aIndex)
        {
            return aText[aIndex];
        }

        static unsigned char Length(char* aText)
        {
            return strlen(aText);
        }

        static char Read(char* aText, unsigned char aIndex)
        {
            return aText[aIndex];
        }

        static unsigned char Length(const __FlashStringHelper* aText)
        {
            return strlen_P((const char*)aText);
        }

        static char Read(const __FlashStringHelper* aText, unsigned char aIndex)
        {
            return pgm_read_byte((const char*)aText + aIndex);
        }

        static unsigned char Length(__FlashStringHelper* aText)
        {
            return strlen_P((const char*)aText);
        }

        static char Read(__FlashStringHelper* aText, unsigned char aIndex)
        {
            return pgm_read_byte((const char*)aText + aIndex);
        }
    };
}