#pragma once

#include <evabScreenPage8Base.h>
#include <evabIFont.h>
#include <Wire.h>

namespace evab
{

  /**
   * @brief SSD1306 screen driver for OLED displays
   * 
   * Supports 128x64 and 128x32 OLED displays with I2C interface.
   */
  class ScreenSSD1306 : public ScreenPage8Base
  {
  public:
    /**
     * @brief Constructor for SSD1306 screen driver
     * 
     * @param aFont Font to use
     * @param aWireClock I2C clock speed (default 800000)
     * @param aHeightPx Display height in pixels (default 64)
     */
    ScreenSSD1306(const IFont *aFont, unsigned long aWireClock = 800000L, uint8_t aHeightPx = 64);
    ~ScreenSSD1306();

    /**
     * @brief Sets display contrast
     * 
     * @param aContrast Contrast value
     */
    void SetContrast(uint8_t aContrast);
    
    /**
     * @brief Gets the screen size in tiles
     * 
     * @return Coor Screen dimensions (16 x pages)
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
    
    /**
     * @brief Initializes the display
     */
    void initDisplay();

  private:
    /**
     * @brief Clears the entire display
     */
    void clearDisplay();
    
    /**
     * @brief Sends a command to the display
     * 
     * @param aCmd Command byte
     */
    void sendCommand(uint8_t aCmd);
    
    /**
     * @brief Sends data to the display
     * 
     * @param aData Data byte
     */
    void sendData(uint8_t aData);

    uint8_t mAddress;  ///< I2C address
    uint8_t mWidth;    ///< Width in pixels
    uint8_t mHeight;   ///< Height in pixels
    uint8_t mPages;    ///< Number of pages
  };

}
