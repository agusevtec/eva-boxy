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
     * @brief Handles residual keys when no child handles the event
     * 
     * Override this to implement custom key handling in composites.
     * 
     * @param aKey Key code to process
     * @return true if the key was handled, false otherwise
     */
    virtual bool onResidualKey(Keys aKey);
    
    /**
     * @brief Pure virtual method to hide all children
     */
    virtual void hider() = 0;
    
    /**
     * @brief Checks if a child is currently focused
     * 
     * @param aChild Child element to check
     * @return true if the child is focused
     */
    bool IsFocused(ElementBase *aChild);

  protected:
    /**
     * @brief Sets the focused child element
     * 
     * @param aChild Child element to focus
     */
    void focusChild(ElementBase *aChild);

  private:
    /**
     * @brief Handles key events by forwarding to focused child
     * 
     * @param aKey Key code to process
     * @return true if the key was handled, false otherwise
     */
    bool Key(Keys aKey) override;

  private:
    ElementBase *mFocusedChild = nullptr;  ///< Currently focused child element
  };

}
