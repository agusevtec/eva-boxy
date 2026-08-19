

# File evabTextLabel.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**evabTextLabel.h**](evab_text_label_8h.md)

[Go to the documentation of this file](evab_text_label_8h.md)


```C++
#pragma once

#include <evabElementBase.h>
#include <evabTextTraits.h>
#include <evabTextAlign.h>

namespace evab
{
    template <typename T, typename TAlign>
    class TextLabel : public ElementBase
    {
    public:
        explicit TextLabel(T aText) : mText(aText) {}

        void SetText(T aText)
        {
            mText = aText;
            redraw();
        }

        T GetText() const { return mText; }

    protected:
        void drawer(Screen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override
        {
            if (!aScreen || aSize.Y == 0 || aSize.X == 0)
                return;

            aScreen->Text<TAlign>(aPos, aSize, mText, aIsFocused);
        }

        void freezer() override {}

    private:
        T mText; 
    };

    // --- char* (mutable strings) ---
    using TextLabelLeft = TextLabel<char *, LeftAlign>;
    using TextLabelCenter = TextLabel<char *, CenterAlign>;
    using TextLabelRight = TextLabel<char *, RightAlign>;

    // --- const char* (string literals) ---
    using TextLabelLeftConst = TextLabel<const char *, LeftAlign>;
    using TextLabelCenterConst = TextLabel<const char *, CenterAlign>;
    using TextLabelRightConst = TextLabel<const char *, RightAlign>;

    // --- __FlashStringHelper* (Flash strings) ---
    using TextLabelLeftF = TextLabel<const __FlashStringHelper *, LeftAlign>;
    using TextLabelCenterF = TextLabel<const __FlashStringHelper *, CenterAlign>;
    using TextLabelRightF = TextLabel<const __FlashStringHelper *, RightAlign>;

}
```


