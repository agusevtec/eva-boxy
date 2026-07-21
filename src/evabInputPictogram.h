#include "evabElementBase.h"
#pragma once

namespace evab
{

    /**
     * @brief Pictogram-based input element
     * 
     * Displays a pictogram from a pictoset and manages its index value.
     * 
     * @tparam TPictoset Pictoset class providing pictogram data and count
     */
    template <class TPictoset>
    class InputPictogram : public ElementBase
    {
    public:
        /**
         * @brief Constructor for InputPictogram
         * 
         * @param aValue Initial pictogram index (0 to TPictoset::Count - 1)
         */
        InputPictogram(int aValue = 0)
        {
            mValue = constrain(aValue, 0, TPictoset::Count - 1);
        }
        
        /**
         * @brief Sets the pictogram index and redraws
         * 
         * @param aValue New pictogram index
         */
        void SetValue(int aValue)
        {
            mValue = constrain(aValue, 0, TPictoset::Count - 1);
            Redraw();
        }
        
        /**
         * @brief Gets the current pictogram index
         * 
         * @return Current pictogram index
         */
        signed char GetValue() const
        {
            return mValue;
        }

        /**
         * @brief Sets value as percentage (0-100)
         * 
         * Maps percentage to pictogram index range.
         * 
         * @param aValue Percentage value (0-100)
         */
        void SetValuePercent(int aValue)
        {
            SetValue(map(aValue, 0, 100, 0, TPictoset::Count - 1));
        }

        /**
         * @brief Gets value as percentage
         * 
         * @return Percentage value (0-100)
         */
        signed char GetValuePercent() const
        {
            return map(mValue, 0, TPictoset::Count - 1, 0, 100);
        }

        /**
         * @brief Increments the pictogram index
         * 
         * @param delta Amount to increment (positive or negative)
         */
        void Increment(signed char delta)
        {
            SetValue(mValue + delta);
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
        void drawer(IScreen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override
        {
            aScreen->Picto(aPos, TPictoset::GetTile(mValue), aIsFocused);
        }

    private:
        signed char mValue;  ///< Current pictogram index
    };

}
