

# File evabPadding.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**evabPadding.h**](evab_padding_8h.md)

[Go to the documentation of this file](evab_padding_8h.md)


```C++
#pragma once

#include <evabScreen.h>

namespace evab
{
    template <class T>
    class PaddingV : public T
    {
    public:
        template <typename... Args>
        PaddingV(Args &&...args)
            : T(args...)
        {
        }

    protected:
        void drawer(Screen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override
        {
            // Clear top padding
            aScreen->Clear(aPos, {aSize.X, 1}, aIsFocused);

            // Draw base element with vertical padding
            T::drawer(aScreen, {aPos.X, aPos.Y + 1}, {aSize.X, aSize.Y - 2}, aIsFocused);

            // Clear bottom padding
            aScreen->Clear({aPos.X, aPos.Y + aSize.Y - 1}, {aSize.X, 1}, aIsFocused);
        }
    };

    template <class T>
    class PaddingH : public T
    {
    public:
        template <typename... Args>
        PaddingH(Args &&...args)
            : T(args...)
        {
        }

    protected:
        void drawer(Screen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override
        {
            // Clear left padding
            aScreen->Clear(aPos, {1, aSize.Y}, aIsFocused);

            // Draw base element with horizontal padding
            T::drawer(aScreen, {aPos.X + 1, aPos.Y}, {aSize.X - 2, aSize.Y}, aIsFocused);

            // Clear right padding
            aScreen->Clear({aPos.X + aSize.X - 1, aPos.Y}, {1, aSize.Y}, aIsFocused);
        }
    };

} // namespace evab
```


