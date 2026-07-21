#pragma once

#include <evabScreenPage8Base.h>
#include <evabIFont.h>

namespace evab
{
    /**
     * @brief Debug screen that renders pixels to serial output
     * 
     * Used for debugging UI layout without physical hardware.
     */
    class ScreenSerialPixel : public ScreenPage8Base
    {
    public:
        /**
         * @brief Constructor for serial pixel screen
         * 
         * @param aFont Font to use
         */
        ScreenSerialPixel(IFont *aFont);

        /**
         * @brief Clears the pixel buffer
         */
        void clear();
        
        /**
         * @brief Prints the pixel buffer to serial for debugging
         */
        void printToSerial();

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
         * @brief Draws a vertical slice in the pixel buffer
         * 
         * @param aPosition Position on screen
         * @param aSliceColumn Column within the tile (0-7)
         * @param aSlice Bitmap data for the slice
         */
        void DrawVerticalSlice(Coor aPosition, unsigned char aSliceColumn, unsigned char aSlice) override;

    private:
        uint8_t mBuffer[1024]; // 8 pages * 128 bytes = 1024 bytes
    };
}
