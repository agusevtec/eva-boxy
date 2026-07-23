// evabCompositeBase.h
#pragma once

#include <evabElementBase.h>

namespace evab
{

  class IFocusChain
  {
  public:
    /**
     * @brief Gets the next element in the chain
     *
     * @return Pointer to next element, or nullptr if none
     */
    virtual IFocusChain *next() = 0;

    /**
     * @brief Sets the next element in the chain
     *
     * @param aNext Pointer to next element
     */
    virtual ElementBase *asElementBase() = 0;

    virtual void setNext(IFocusChain *aNext) = 0;
  };

  /**
   * @brief Abstract base class for composite elements with circular focus chain
   *
   * Manages a circular linked list of child elements for focus navigation.
   * Only stores one pointer - to the currently focused child.
   * Children must be of type FocusChain<T> to form the chain.
   */
  class LayoutBase : public ElementBase
  {
  public:
    LayoutBase();

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
    virtual void hider();

    /**
     * @brief Checks if a child is currently focused
     *
     * @param aChild Child element to check
     * @return true if the child is focused
     */
    bool IsFocused(IFocusChain *aChild);

    /**
     * @brief Sets the current (focused) child
     *
     * @param aChild Child element to set as focused
     */
    void setCurrentChild(IFocusChain *aChild);

    /**
     * @brief Gets the current (focused) child
     *
     * @return Pointer to current child, or nullptr if none
     */
    IFocusChain *getCurrentChild() const;

    /**
     * @brief Increments the selection by a delta
     *
     * Positive delta moves forward (next), negative moves backward (prev)
     *
     * @param delta Amount to increment (positive or negative)
     */
    void Increment(signed char delta);

    /**
     * @brief Handles key events by forwarding to focused child
     *
     * @param aKey Key code to process
     * @return true if the key was handled, false otherwise
     */
    bool Key(Keys aKey) override;

  protected:
    /**
     * @brief Navigate to next element in circular chain
     */
    void focusNext();

    /**
     * @brief Navigate to previous element in circular chain
     */
    void focusPrev();

  protected:
    IFocusChain *mCurrentChild; ///< Currently focused child element (only reference needed)
  };

}