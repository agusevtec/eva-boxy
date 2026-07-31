#pragma once
#include <evabCoor.h>
#include <evabScreen.h>
#include <evabKeys.h>

namespace evab
{

  /**
   * @brief Abstract base class for all UI elements
   *
   * Provides the core functionality for rendering, state management,
   * and key event handling for visual elements.
   */
  class ElementBase
  {
  public:
    /**
     * @brief Handles key events for the element
     *
     * Override to implement custom key handling.
     *
     * @param aKey Key code to process
     * @return true if the key was handled, false otherwise
     */
    virtual bool OnKey(Keys aKey);

    /**
     * @brief Draws the element on the specified screen
     *
     * @param aScreen Screen to draw on
     * @param aPos Position on screen
     * @param aSize Size of the element
     * @param aIsFocused Focus state (1 = focused, 0 = not focused)
     */
    void Draw(Screen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused);

    /**
     * @brief Make element insensitive to redraw method
     */
    void Mute();

  protected:
    /**
     * @brief Checks if the element is currently muted.
     *
     * @return true if the element is muted and ignores redraw requests, false otherwise.
     */
    bool isMuted();
    /**
     * @brief Pure virtual method for drawing the element
     *
     * @param aScreen Screen to draw on
     * @param aPos Position on screen
     * @param aSize Size of the element
     * @param aIsFocused Focus state (1 = focused, 0 = not focused)
     */
    virtual void drawer(Screen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) = 0;

    /**
     * @brief Virtual method for muting the element
     *
     * Override to implement custom muting behavior.
     */
    virtual void muter() {};

    /**
     * @brief Redraws the element on the current screen
     */
    void redraw();

  private:
    unsigned short mSerialized = 0; ///< Serialized state (position, size, visibility, focus)
  };

}
