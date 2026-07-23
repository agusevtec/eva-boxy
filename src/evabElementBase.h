#pragma once
#include <evabCoor.h>
#include <evabIScreen.h>
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
    virtual bool Key(Keys aKey);

    /**
     * @brief Hides the element from view
     */
    void Hide();

    /**
     * @brief Draws the element on the specified screen
     *
     * @param aScreen Screen to draw on
     * @param aPos Position on screen
     * @param aSize Size of the element
     * @param aIsFocused Focus state (1 = focused, 0 = not focused)
     */
    void Draw(IScreen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused);

    /**
     * @brief Redraws the element on the current screen
     */
    void Redraw();

    /**
     * @brief Checks if the element is hidden
     *
     * @return true if hidden, false otherwise
     */
    bool IsHidden();

  private:
    /**
     * @brief Pure virtual method for drawing the element
     *
     * @param aScreen Screen to draw on
     * @param aPos Position on screen
     * @param aSize Size of the element
     * @param aIsFocused Focus state (1 = focused, 0 = not focused)
     */
    virtual void drawer(IScreen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) = 0;

    /**
     * @brief Virtual method for hiding the element
     *
     * Override to implement custom hiding behavior.
     */
    virtual void hider() {};

  private:
    unsigned short mSerialized = 0; ///< Serialized state (position, size, visibility, focus)
  };

}
