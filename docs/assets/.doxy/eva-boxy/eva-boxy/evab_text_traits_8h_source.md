

# File evabTextTraits.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**evabTextTraits.h**](evab_text_traits_8h.md)

[Go to the documentation of this file](evab_text_traits_8h.md)


```C++
// evabTextTraits.h
#pragma once

#include <Arduino.h>

namespace evab
{

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
```


