#pragma once
#include "evabCoor.h"
#include <Arduino.h>

#include <evabIScreen.h>

namespace evab
{
    /**
     * @brief Base class for screen implementations
     * 
     * Provides common text rendering functionality for all screens.
     */
    class ScreenBase : public IScreen
    {
    public:
        /**
         * @brief Draws text aligned left (C-string)
         * 
         * @param aPosition Position on screen
         * @param aSize Size of the text area
         * @param text Null-terminated string
         * @param aColor Color/inversion flag
         */
        void TextLeft(Coor aPosition, Coor aSize, const char *text, unsigned char aColor) override;
        
        /**
         * @brief Draws text aligned center (C-string)
         * 
         * @param aPosition Position on screen
         * @param aSize Size of the text area
         * @param text Null-terminated string
         * @param aColor Color/inversion flag
         */
        void TextCenter(Coor aPosition, Coor aSize, const char *text, unsigned char aColor) override;
        
        /**
         * @brief Draws text aligned right (C-string)
         * 
         * @param aPosition Position on screen
         * @param aSize Size of the text area
         * @param text Null-terminated string
         * @param aColor Color/inversion flag
         */
        void TextRight(Coor aPosition, Coor aSize, const char *text, unsigned char aColor) override;
        
        /**
         * @brief Draws text aligned left (Flash string)
         * 
         * @param aPosition Position on screen
         * @param aSize Size of the text area
         * @param text Flash string
         * @param aColor Color/inversion flag
         */
        void TextLeft(Coor aPosition, Coor aSize, const __FlashStringHelper *text, unsigned char aColor) override;
        
        /**
         * @brief Draws text aligned center (Flash string)
         * 
         * @param aPosition Position on screen
         * @param aSize Size of the text area
         * @param text Flash string
         * @param aColor Color/inversion flag
         */
        void TextCenter(Coor aPosition, Coor aSize, const __FlashStringHelper *text, unsigned char aColor) override;
        
        /**
         * @brief Draws text aligned right (Flash string)
         * 
         * @param aPosition Position on screen
         * @param aSize Size of the text area
         * @param text Flash string
         * @param aColor Color/inversion flag
         */
        void TextRight(Coor aPosition, Coor aSize, const __FlashStringHelper *text, unsigned char aColor) override;
        
        /**
         * @brief Clears a rectangular area
         * 
         * @param aPosition Position of the area
         * @param aSize Size of the area
         * @param aColor Fill color (0 = clear, 1 = fill)
         */
        void Clear(Coor aPosition, Coor aSize, unsigned char aColor) override;
        
        /**
         * @brief Draws a pictogram (default implementation)
         * 
         * @param aPosition Position on screen
         * @param pictoData Pictogram data
         * @param aColor Color/inversion flag
         */
        virtual void Picto(Coor aPosition, const unsigned char *pictoData, unsigned char aColor);

    protected:
        /**
         * @brief Clears a single tile
         * 
         * @param position Position of the tile
         * @param aColor Fill color
         */
        virtual void ClearTile(Coor position, unsigned char aColor);

    private:
        /**
         * @brief Prints text in an area with offset (C-string)
         * 
         * @param aPosition Position on screen
         * @param aSize Size of the text area
         * @param text Null-terminated string
         * @param aColor Color/inversion flag
         * @param offset Character offset
         */
        void printTextInArea(Coor aPosition, Coor aSize, const char *text, unsigned char aColor, unsigned char offset);
        
        /**
         * @brief Prints text in an area with offset (Flash string)
         * 
         * @param aPosition Position on screen
         * @param aSize Size of the text area
         * @param text Flash string
         * @param aColor Color/inversion flag
         * @param offset Character offset
         */
        void printTextInArea(Coor aPosition, Coor aSize, const __FlashStringHelper *text, unsigned char aColor, unsigned char offset);

        /**
         * @brief Calculates offset for left alignment
         * 
         * @param aSize Size of the text area
         * @param textLen Length of the text
         * @return Offset
         */
        unsigned char calcLeftOffset(Coor aSize, unsigned char textLen);
        
        /**
         * @brief Calculates offset for center alignment
         * 
         * @param aSize Size of the text area
         * @param textLen Length of the text
         * @return Offset
         */
        unsigned char calcCenterOffset(Coor aSize, unsigned char textLen);
        
        /**
         * @brief Calculates offset for right alignment
         * 
         * @param aSize Size of the text area
         * @param textLen Length of the text
         * @return Offset
         */
        unsigned char calcRightOffset(Coor aSize, unsigned char textLen);

        /**
         * @brief Gets length of a Flash string
         * 
         * @param str Flash string pointer
         * @return Length of the string
         */
        unsigned char flashStrLen(const __FlashStringHelper *str);
        
        /**
         * @brief Reads a character from Flash string
         * 
         * @param str Flash string pointer
         * @param index Character index
         * @return Character at the specified position
         */
        char flashStrRead(const __FlashStringHelper *str, unsigned char index);
    };
}
