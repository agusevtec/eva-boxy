// evabTextTraits.h
#pragma once

#include <Arduino.h>

namespace evab
{

    /**
     * @brief Traits for C-string (char*)
     */
    template<typename T>
    struct TextTraits;

    template<>
    struct TextTraits<const char*>
    {
        static unsigned char Length(const char* aText)
        {
            return strlen(aText);
        }

        static char Read(const char* aText, unsigned char aIndex)
        {
            return aText[aIndex];
        }
    };

    template<>
    struct TextTraits<char*>
    {
        static unsigned char Length(char* aText)
        {
            return strlen(aText);
        }

        static char Read(char* aText, unsigned char aIndex)
        {
            return aText[aIndex];
        }
    };

    /**
     * @brief Traits for Flash string (__FlashStringHelper*)
     */
    template<>
    struct TextTraits<const __FlashStringHelper*>
    {
        static unsigned char Length(const __FlashStringHelper* aText)
        {
            return strlen_P((const char*)aText);
        }

        static char Read(const __FlashStringHelper* aText, unsigned char aIndex)
        {
            return pgm_read_byte((const char*)aText + aIndex);
        }
    };

    template<>
    struct TextTraits<__FlashStringHelper*>
    {
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