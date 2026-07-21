#pragma once

#include <evabScreenPage8Base.h>
#include <SPI.h>

namespace evab
{

  /**
   * @brief PCD8544 screen driver (Nokia 5110 display)
   * 
   * Supports 84x48 pixel displays with SPI interface.
   */
  class ScreenPCD8544 : public ScreenPage8Base
  {
  public:
    /**
     * @brief Constructor for PCD8544 screen driver
     * 
     * @param aFont Font to use
     * @param aRST Reset pin
     * @param aCE Chip enable pin
     * @param aDC Data/Command pin
     * @param aDIN Data in pin (MOSI)
     * @param aCLK Clock pin (SCLK)
     * @param aLED Backlight pin (255 = none)
     */
    ScreenPCD8544(const IFont *aFont,
                  uint8_t aRST, uint8_t aCE, uint8_t aDC,
                  uint8_t aDIN, uint8_t aCLK,
                  uint8_t aLED = 255);

    /**
     * @brief Sets backlight state
     * 
     * @param aState 1 = on, 0 = off
     */
    void SetBacklight(uint8_t aState);
    
    /**
     * @brief Sets display contrast
     * 
     * @param aContrast Contrast value (0-127)
     */
    void SetContrast(uint8_t aContrast);
    
    /**
     * @brief Gets the screen size in tiles
     * 
     * @return Coor Screen dimensions (11x6 tiles)
     */
    Coor Size() override { return {11, 6}; }
    
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
    
    /**
     * @brief Initializes the display
     */
    void initDisplay();

    static const uint8_t CMD_FUNC_SET = 0x20;    ///< Function set command
    static const uint8_t CMD_DISP_CTRL = 0x08;   ///< Display control command
    static const uint8_t CMD_SET_Y = 0x40;       ///< Set Y address command
    static const uint8_t CMD_SET_X = 0x80;       ///< Set X address command
    static const uint8_t CMD_SET_VOP = 0x80;     ///< Set Vop (contrast) command

    uint8_t mRSTPin;  ///< Reset pin
    uint8_t mCEPin;   ///< Chip enable pin
    uint8_t mDCPin;   ///< Data/Command pin
    uint8_t mLEDPin;  ///< Backlight pin (255 = none)
  };

}
