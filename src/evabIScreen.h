#pragma once
#include <evabCoor.h>
#include <Arduino.h>

namespace evab
{
    /**
     * @brief Abstract interface for screen rendering
     * 
     * Defines the contract for display implementations,
     * supporting text, pictograms, and state serialization.
     */
    class IScreen
    {
    public:
        /**
         * @brief Draws text aligned to the left
         * 
         * @param aPosition Position on screen
         * @param aSize Size of the text area
         * @param text Null-terminated string
         * @param aColor Color/inversion flag (0 = normal, 1 = inverted)
         */
        virtual void TextLeft(Coor aPosition, Coor aSize, const char *text, unsigned char aColor) = 0;
        
        /**
         * @brief Draws text aligned to the center
         * 
         * @param aPosition Position on screen
         * @param aSize Size of the text area
         * @param text Null-terminated string
         * @param aColor Color/inversion flag (0 = normal, 1 = inverted)
         */
        virtual void TextCenter(Coor aPosition, Coor aSize, const char *text, unsigned char aColor) = 0;
        
        /**
         * @brief Draws text aligned to the right
         * 
         * @param aPosition Position on screen
         * @param aSize Size of the text area
         * @param text Null-terminated string
         * @param aColor Color/inversion flag (0 = normal, 1 = inverted)
         */
        virtual void TextRight(Coor aPosition, Coor aSize, const char *text, unsigned char aColor) = 0;

        /**
         * @brief Draws flash string text aligned to the left
         * 
         * @param aPosition Position on screen
         * @param aSize Size of the text area
         * @param text Flash string (PROGMEM)
         * @param aColor Color/inversion flag (0 = normal, 1 = inverted)
         */
        virtual void TextLeft(Coor aPosition, Coor aSize, const __FlashStringHelper *text, unsigned char aColor) = 0;
        
        /**
         * @brief Draws flash string text aligned to the center
         * 
         * @param aPosition Position on screen
         * @param aSize Size of the text area
         * @param text Flash string (PROGMEM)
         * @param aColor Color/inversion flag (0 = normal, 1 = inverted)
         */
        virtual void TextCenter(Coor aPosition, Coor aSize, const __FlashStringHelper *text, unsigned char aColor) = 0;
        
        /**
         * @brief Draws flash string text aligned to the right
         * 
         * @param aPosition Position on screen
         * @param aSize Size of the text area
         * @param text Flash string (PROGMEM)
         * @param aColor Color/inversion flag (0 = normal, 1 = inverted)
         */
        virtual void TextRight(Coor aPosition, Coor aSize, const __FlashStringHelper *text, unsigned char aColor) = 0;

        /**
         * @brief Draws a pictogram at the specified position
         * 
         * @param aPosition Position on screen
         * @param pictoData Pictogram data (first two bytes: width/height in tiles)
         * @param aColor Color/inversion flag (0 = normal, 1 = inverted)
         */
        virtual void Picto(Coor aPosition, const unsigned char *pictoData, unsigned char aColor) = 0;
        
        /**
         * @brief Clears a rectangular area on screen
         * 
         * @param aPosition Position of the area
         * @param aSize Size of the area
         * @param aColor Fill color (0 = clear, 1 = fill)
         */
        virtual void Clear(Coor aPosition, Coor aSize, unsigned char aColor = 0) = 0;
        
        /**
         * @brief Draws a single character symbol
         * 
         * @param aPosition Position on screen
         * @param aSize Size of the symbol
         * @param aSymbol Character to draw
         * @param aColor Color/inversion flag (0 = normal, 1 = inverted)
         */
        virtual void DrawSymbol(Coor aPosition, Coor aSize, char aSymbol, unsigned char aColor) = 0;
        
        /**
         * @brief Gets the screen size in tiles
         * 
         * @return Coor Screen dimensions in tiles (X, Y)
         */
        virtual Coor Size() = 0;
        
        /**
         * @brief Serializes element state into 16-bit value
         * 
         * @param aPos Position of the element
         * @param aSize Size of the element
         * @param isFocused Focus state
         * @return unsigned short Serialized state
         */
        virtual unsigned short Serialize(const Coor &aPos, const Coor &aSize, bool isFocused) = 0;
        
        /**
         * @brief Deserializes element state from 16-bit value
         * 
         * @param aSerialized Serialized state
         * @param aPos Position of the element (output)
         * @param aSize Size of the element (output)
         * @param isFocused Focus state (output)
         */
        virtual void Deserialize(unsigned short aSerialized, Coor &aPos, Coor &aSize, bool &isFocused) = 0;
    };
}
