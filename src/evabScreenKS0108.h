#pragma once

#include <evabScreenPage8Base.h>
#include <evabIFont.h>

namespace evab
{

    /**
     * @brief KS0108-based GLCD screen driver
     * 
     * Supports 128x64 pixel displays with two KS0108 chips.
     */
    class ScreenKS0108 : public ScreenPage8Base
    {
    public:
        /**
         * @brief Constructor for KS0108 screen driver
         * 
         * @param aFont Font to use
         * @param aRS Register select pin
         * @param aRW Read/Write pin
         * @param aE Enable pin
         * @param aCS1 Chip select 1 pin
         * @param aCS2 Chip select 2 pin
         * @param aDB0-DB7 Data bus pins
         * @param aLED Backlight pin (255 = none)
         */
        ScreenKS0108(const IFont *aFont,
                     uint8_t aRS, uint8_t aRW, uint8_t aE,
                     uint8_t aCS1, uint8_t aCS2,
                     uint8_t aDB0, uint8_t aDB1, uint8_t aDB2, uint8_t aDB3,
                     uint8_t aDB4, uint8_t aDB5, uint8_t aDB6, uint8_t aDB7,
                     uint8_t aLED = 255);
        ~ScreenKS0108();

        /**
         * @brief Sets backlight state
         * 
         * @param aState 1 = on, 0 = off
         */
        void SetBacklight(uint8_t aState);
        
        /**
         * @brief Clears the entire display
         */
        void clearDisplay();
        
        /**
         * @brief Gets the screen size in tiles
         * 
         * @return Coor Screen dimensions (16x8 tiles)
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

    private:
        /**
         * @brief Sends a command to the specified chip
         * 
         * @param aCmd Command byte
         * @param aChip Chip index (0 or 1)
         */
        void sendCommand(uint8_t aCmd, uint8_t aChip);
        
        /**
         * @brief Sends data to the specified chip
         * 
         * @param aData Data byte
         * @param aChip Chip index (0 or 1)
         */
        void sendData(uint8_t aData, uint8_t aChip);
        
        /**
         * @brief Selects a chip for communication
         * 
         * @param aChip Chip index (0 or 1)
         */
        void setChip(uint8_t aChip);
        
        /**
         * @brief Sets the current page
         * 
         * @param aPage Page index (0-7)
         */
        void setPage(uint8_t aPage);
        
        /**
         * @brief Sets the current column
         * 
         * @param aCol Column index (0-63)
         */
        void setColumn(uint8_t aCol);
        
        /**
         * @brief Initializes the display
         */
        void initDisplay();

        /**
         * @brief Writes a byte to the data bus
         * 
         * @param aByte Byte to write
         */
        void writeByte(uint8_t aByte);
        
        /**
         * @brief Pulses the enable pin
         */
        void pulseE();

        uint8_t mRSPin;          ///< Register select pin
        uint8_t mRWPin;          ///< Read/Write pin
        uint8_t mEPin;           ///< Enable pin
        uint8_t mCS1Pin;         ///< Chip select 1 pin
        uint8_t mCS2Pin;         ///< Chip select 2 pin
        uint8_t mDataPins[8];    ///< Data bus pins
        uint8_t mLEDPin;         ///< Backlight pin (255 = none)
        uint8_t mCurrentChip;    ///< Currently selected chip
    };

}
