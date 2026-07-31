#pragma once

#include <evabElementBase.h>

namespace evab
{

  /**
   * @brief Abstract base class for composite elements that can manage child focus
   *
   * Provides focus management and key event routing for container elements.
   */
  class CompositeBase : public ElementBase
  {
  public:
    /**
     * @brief Handles key events by forwarding to focused child
     *
     * @param aKey OnKey code to process
     * @return true if the key was handled, false otherwise
     */
    bool OnKey(Keys aKey) override;

    /**
     * @brief Checks if a child is currently focused
     *
     * @param aChild Child element to check
     * @return true if the child is focused
     */
    bool IsFocused(ElementBase *aChild);

    /**
     * @brief Gets the current (focused) child
     *
     * @return Pointer to current child, or nullptr if none
     */
    ElementBase *GetFocused() const;

  protected:
    /**
     * @brief Sets the focused child element
     *
     * @param aChild Child element to focus
     */
    void focusChild(ElementBase *aChild);

  private:
    /**
     * @brief Handles residual keys when no child handles the event
     *
     * Override this to implement custom key handling in composites.
     *
     * @param aKey OnKey code to process
     * @return true if the key was handled, false otherwise
     */
    virtual bool onResidualKey(Keys aKey);

    /**
     * @brief Pure virtual method to mute all children
     */
    virtual void muter() = 0;

  private:
    ElementBase *mFocusedChild = nullptr; ///< Currently focused child element
  };

}
