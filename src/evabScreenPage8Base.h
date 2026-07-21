#pragma once

#include <evabCoor.h>
#include <evabScreenBase.h>
#include <evabIFont.h>

namespace evab
{
  /**
   * @brief Base class for page-based 8-bit screens
   * 
   * Provides common rendering for screens organized in 8-pixel pages.
   * Used by SSD1306, KS0108, PCD8544, and similar displays.
   */
  class ScreenPage8Base : public ScreenBase
  {
  public:
    /**
     * @brief Constructor for page-based 8-bit screen base
     * 
     * @param mFont Font to use for rendering
     */
    ScreenPage8Base(const IFont* mFont);
    
    /**
     * @brief Draws a symbol at the specified position with scaling
     * 
     * @param aPosition Position on screen
     * @param aSize Size of the symbol
     * @param aCharcode Character code
     * @param aColor Color/inversion flag
     */
    void DrawSymbol(Coor aPosition, Coor aSize, char aCharcode, unsigned char aColor);
    
    /**
     * @brief Draws a pictogram at the specified position
     * 
     * @param aPosition Position on screen
     * @param pictoData Pictogram data
     * @param aColor Color/inversion flag
     */
    void Picto(Coor aPosition, const unsigned char *pictoData, unsigned char aColor);
 
  protected:
    /**
     * @brief Pure virtual method to draw a vertical slice
     * 
     * @param aPosition Position on screen
     * @param aSliceColumn Column within the tile (0-7)
     * @param aSlice Bitmap data for the slice
     */
    virtual void DrawVerticalSlice(Coor aPosition, unsigned char aSliceColumn, unsigned char aSlice) = 0;

  private:
    const IFont* mFont;  ///< Font for text rendering
    
    /**
     * @brief Upscales a byte vertically by repeating bits
     * 
     * @param x Input byte (8 bits)
     * @param scale Scale factor
     * @return Upscaled value (up to 32 bits)
     */
    uint32_t upscaleY(uint8_t x, uint8_t scale);
  };

}
