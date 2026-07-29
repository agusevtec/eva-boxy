// evabTextLabel.h
#pragma once

#include <evabElementBase.h>
#include <evabTextTraits.h>
#include <evabTextAlign.h>

namespace evab
{
    /**
     * @brief Text label widget with alignment
     * 
     * @tparam T Text type (char*, const char*, __FlashStringHelper*)
     * @tparam TAlign Alignment strategy (LeftAlign, CenterAlign, RightAlign)
     */
    template<typename T, typename TAlign>
    class TextLabel : public ElementBase
    {
    public:
        /**
         * @brief Constructor with text
         * 
         * @param aText Text to display
         */
        explicit TextLabel(T aText) : mText(aText) {}

        /**
         * @brief Sets new text and redraws
         * 
         * @param aText New text
         */
        void SetText(T aText) 
        { 
            mText = aText; 
            Redraw(); 
        }

        /**
         * @brief Gets current text
         * 
         * @return Current text
         */
        T GetText() const { return mText; }

    protected:
        /**
         * @brief Draws the label with alignment
         * 
         * @param aScreen Screen to draw on
         * @param aPos Position on screen
         * @param aSize Size of the element
         * @param aIsFocused Focus state (1 = focused, 0 = not focused)
         */
        void drawer(Screen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override
        {
            if (!aScreen || aSize.Y == 0 || aSize.X == 0)
                return;

            // Use Screen's Text method with alignment template
            aScreen->Text<TAlign>(aPos, aSize, mText, aIsFocused);
        }

        void hider() override {}

    private:
        T mText;  ///< Text to display
    };

    // --- char* (mutable strings) ---
    using TextLabelLeft = TextLabel<char*, LeftAlign>;
    using TextLabelCenter = TextLabel<char*, CenterAlign>;
    using TextLabelRight = TextLabel<char*, RightAlign>;

    // --- const char* (string literals) ---
    using TextLabelLeftConst = TextLabel<const char*, LeftAlign>;
    using TextLabelCenterConst = TextLabel<const char*, CenterAlign>;
    using TextLabelRightConst = TextLabel<const char*, RightAlign>;

    // --- __FlashStringHelper* (Flash strings) ---
    using TextLabelLeftF = TextLabel<const __FlashStringHelper*, LeftAlign>;
    using TextLabelCenterF = TextLabel<const __FlashStringHelper*, CenterAlign>;
    using TextLabelRightF = TextLabel<const __FlashStringHelper*, RightAlign>;

}