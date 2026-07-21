#pragma once

#include <evabScreenBase.h>

namespace evab
{

    /**
     * @brief Debug screen that renders text to serial output
     * 
     * Used for debugging UI layout without physical hardware.
     * Displays characters in a 16x8 grid.
     */
    class ScreenSerialText : public ScreenBase
    {
    public:
        /**
         * @brief Constructor for serial text screen
         */
        ScreenSerialText();

        /**
         * @brief Clears the text buffer
         */
        void clear();
        
        /**
         * @brief Prints the text buffer to serial for debugging
         */
        void printToSerial();

        /**
         * @brief Gets the screen size in characters
         * 
         * @return Coor Screen dimensions (16x8 chars)
         */
        Coor Size() override;
        
        /**
         * @brief Serializes element state for 16x8 screen
         * 
         * @param aPos Position of the element
         * @param aSize Size of the element
         * @param isFocused Focus state
         * @return unsigned short Serialized state
         */
        unsigned short Serialize(const Coor &aPos, const Coor &aSize, bool isFocused);
        
        /**
         * @brief Deserializes element state for 16x8 screen
         * 
         * @param aSerialized Serialized state
         * @param aPos Position of the element (output)
         * @param aSize Size of the element (output)
         * @param isFocused Focus state (output)
         */
        void Deserialize(unsigned short aSerialized, Coor &aPos, Coor &aSize, bool &isFocused);

    protected:
        /**
         * @brief Draws a symbol in the text buffer
         * 
         * @param aPosition Position on screen
         * @param aSize Size of the symbol
         * @param aCharcode Character code
         * @param aColor Color/inversion flag
         */
        void DrawSymbol(Coor aPosition, Coor aSize, char aCharcode, unsigned char aColor) override;

    private:
        char mBuffer[128];  ///< Text buffer (16x8 characters)
    };

}
