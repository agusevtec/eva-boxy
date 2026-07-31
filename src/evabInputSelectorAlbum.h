#include "evabElementBase.h"
#pragma once

namespace evab
{

    /**
     * @brief Pictogram-based input element
     *
     * Displays a pictogram from a pictoset and manages its index value.
     *
     * @tparam TAlbum Album class providing pictogram data and count
     */
    template <class TAlbum>
    class InputSelectorAlbum : public ElementBase
    {
    public:
        /**
         * @brief Constructor for InputPictogram
         *
         * @param aValue Initial pictogram index (0 to TAlbum::Count - 1)
         */
        InputSelectorAlbum(int aValue = 0)
        {
            mValue = constrain(aValue, 0, TAlbum::Count - 1);
        }

        /**
         * @brief Sets the pictogram index and redraws
         *
         * @param aValue New pictogram index
         */
        void Select(int aValue)
        {
            aValue = constrain(aValue, 0, TAlbum::Count - 1);
            if (mValue == aValue)
                return;
            mValue = aValue;
            redraw();
        }

        /**
         * @brief Gets the current pictogram index
         *
         * @return Current pictogram index
         */
        signed char Selected() const
        {
            return mValue;
        }

        /**
         * @brief Increments the pictogram index
         *
         * @param delta Amount to increment (positive or negative)
         */
        void Increment(signed char delta)
        {
            Select(mValue + delta);
        }

        unsigned char Count() const
        {
            return TAlbum::Count;
        }

    protected:
        /**
         * @brief Draws the pictogram on screen
         *
         * @param aScreen Screen to draw on
         * @param aPos Position on screen
         * @param aSize Size of the element
         * @param aIsFocused Focus state (1 = focused, 0 = not focused)
         */
        void drawer(Screen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override
        {
            aScreen->Clear(aPos, aSize, aIsFocused);
            aScreen->Picto(aPos, TAlbum::GetTile(mValue), aIsFocused);
        }

    private:
        signed char mValue; ///< Current pictogram index
    };

}
