#pragma once

#include "evabElementBase.h"

namespace evab
{
  /**
   * @brief Button input element (label in RAM)
   * 
   * Displays a button with a label enclosed in parentheses.
   * The Increment method is a placeholder that does nothing.
   */

  class InputButton : public ElementBase
  {
  public:
    /**
     * @brief Constructs a InputButton with a RAM string
     * @param aText Label text (const char*)
     */
    InputButton(const char *aText = "");

    /**
     * @brief Gets the current label text
     */
    const char *GetName() const;

    /**
     * @brief Sets new label text and redraws
     */
    void SetName(const char *aText);

  protected:
    void drawer(Screen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override;

  private:
    const char *mName;
  };

  /**
   * @brief Button input element (label in PROGMEM)
   * 
   * Displays a button with a label enclosed in parentheses.
   * The Increment method is a placeholder that does nothing.
   */
  class InputButtonF : public ElementBase
  {
  public:
    /**
     * @brief Constructs a InputButton with a Flash string macro F("Text")
     * @param aText Label text in PROGMEM
     */
    InputButtonF(const __FlashStringHelper *aText);

    /**
     * @brief Gets the current Flash label pointer
     */
    const __FlashStringHelper *GetName() const;

    /**
     * @brief Sets new Flash label text and redraws
     */
    void SetName(const __FlashStringHelper *aText);

  protected:
    void drawer(Screen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override;

  private:
    const __FlashStringHelper *mName;
  };

}