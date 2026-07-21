#pragma once

#include <evabScreenBase.h>
#include <Wire.h>

namespace evab
{

  /**
   * @brief I2C LCD screen driver (HD44780 with PCF8574 I2C expander)
   * 
   * Supports standard 16x2, 20x4 LCD displays with I2C backpack.
   */
  class ScreenLCD_I2C : public ScreenBase
  {
  public:
    /**
     * @brief Constructor for I2C LCD screen driver
     * 
     * @param aAddress I2C address
     * @param aCols Number of columns
     * @param aRows Number of rows
     * @param aBacklightPin Backlight pin in the PCF8574 expander
     */
    ScreenLCD_I2C(uint8_t aAddress, uint8_t aCols, uint8_t aRows, uint8_t aBacklightPin);

    /**
     * @brief Sets backlight state
     * 
     * @param aState 1 = on, 0 = off
     */
    void SetBacklight(uint8_t aState);
    
    /**
     * @brief Gets the screen size
     * 
     * @return Coor Screen dimensions (cols, rows)
     */
    Coor Size() override { return {mCols, mRows}; }
    
    /**
     * @brief Serializes element state for 32x4 screen
     * 
     * @param aPos Position of the element
     * @param aSize Size of the element
     * @param isFocused Focus state
     * @return unsigned short Serialized state
     */
    unsigned short Serialize(const Coor &aPos, const Coor &aSize, bool isFocused);
    
    /**
     * @brief Deserializes element state for 32x4 screen
     * 
     * @param aSerialized Serialized state
     * @param aPos Position of the element (output)
     * @param aSize Size of the element (output)
     * @param isFocused Focus state (output)
     */
    void Deserialize(unsigned short aSerialized, Coor &aPos, Coor &aSize, bool &isFocused);

  protected:
    /**
     * @brief Draws a symbol at the specified position
     * 
     * @param aPosition Position on screen
     * @param aSize Size of the symbol
     * @param aCharcode Character code
     * @param aColor Color/inversion flag
     */
    void DrawSymbol(Coor aPosition, Coor aSize, char aCharcode, unsigned char aColor) override;

  private:
    /**
     * @brief Clears the entire display
     */
    void clearDisplay();
    
    /**
     * @brief Sends a byte to the LCD
     * 
     * @param aData Byte to send
     * @param aIsCommand true for command, false for data
     */
    void sendByte(uint8_t aData, bool aIsCommand);
    
    /**
     * @brief Sends a 4-bit nibble to the LCD
     * 
     * @param aData 4-bit data
     * @param aIsCommand true for command, false for data
     */
    void sendNibble(uint8_t aData, bool aIsCommand);
    
    /**
     * @brief Sets cursor position
     * 
     * @param aCol Column (0-based)
     * @param aRow Row (0-based)
     */
    void setCursor(uint8_t aCol, uint8_t aRow);

    uint8_t mAddress;          ///< I2C address
    uint8_t mCols;             ///< Number of columns
    uint8_t mRows;             ///< Number of rows
    uint8_t mBacklightPin;     ///< Backlight pin
    uint8_t mBacklightMask;    ///< Backlight bitmask
  };

}
