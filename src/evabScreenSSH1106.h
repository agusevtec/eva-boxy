#pragma once

#include <evabCoor.h>
#include <evabScreenPage8Base.h>
#include <Wire.h>

namespace evab
{
    /**
     * @brief SSH1106 screen driver for OLED displays
     * 
     * Supports 128x64 OLED displays with I2C interface.
     * Similar to SSD1306 but with different initialization sequence.
     */
    class ScreenSSH1106 : public ScreenPage8Base
    {
    public:
        /**
         * @brief Constructor for SSH1106 screen driver
         * 
         * @param font Font to use
         * @param aWireClock I2C clock speed (default 800000)
         */
        ScreenSSH1106(const IFont* font, unsigned long aWireClock = 800000L);
        
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
         * @brief Draws a vertical slice at the specified position
         * 
         * @param aPosition Position on screen
         * @param aSliceColumn Column within the tile (0-7)
         * @param aSlice Bitmap data for the slice
         */
        void DrawVerticalSlice(Coor aPosition, unsigned char aSliceColumn, unsigned char aSlice) override;
        
        /**
         * @brief Clears a tile at the specified position
         * 
         * @param aPosition Position of the tile
         * @param aColor Fill color
         */
        void ClearTile(Coor aPosition, unsigned char aColor) override;
        
        /**
         * @brief Gets the screen size in tiles
         * 
         * @return Coor Screen dimensions (16x8 tiles)
         */
        Coor Size() override;

    private:
        /**
         * @brief Clears the entire display
         */
        void clearDisplay();
        
        /**
         * @brief Sends a command to the display
         * 
         * @param cmd Command byte
         */
        void sendCommand(unsigned char cmd);
        
        /**
         * @brief Sets the current page
         * 
         * @param page Page index (0-7)
         */
        void setPage(unsigned char page);
        
        /**
         * @brief Sets the current column
         * 
         * @param col Column index (0-127)
         */
        void setColumn(unsigned char col);

        uint8_t mAddress;  ///< I2C address
    };
}
