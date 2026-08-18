#pragma once

#include <evabElementBase.h>

namespace evab
{
  /**
   * @brief Abstract base class for composite elements with circular focus chain
   *
   * Manages a circular linked list of child elements for focus navigation.
   * Only stores one pointer - to the currently focused child.
   * Children must be of type Focusable<T> to form the chain.
   */
  class LayoutBase : public ElementBase
  {

    class FocusableBase
    {
    public:
      ElementBase *element;
      FocusableBase *next;
      FocusableBase(ElementBase *aElement) : element(aElement), next(nullptr) {}
    };

    /**
     * @brief Wrapper that chains elements in a circular doubly-linked list
     *
     * @tparam T Element type to wrap (must inherit ElementBase)
     */
    template <class T>
    class Focusable : public T, public FocusableBase
    {
    public:
      template <typename... Args>
      Focusable(LayoutBase *aParent, Args &&...args)
          : T(args...), FocusableBase(this)
      {
        if (!aParent)
          return;

        FocusableBase *first = aParent->mFocusedChild;
        if (first)
        {
          FocusableBase *last = first;
          while (last->next && last->next != first)
            last = last->next;

          last->next = this;
          this->next = first;
        }
        else
        {
          this->next = this;
          aParent->mFocusedChild = this;
        }
      }
    };

  public:
    /**
     * @brief Checks if a child is currently focused
     *
     * @param aChild Child element to check
     * @return true if the child is focused
     */
    bool IsFocused(FocusableBase *aChild);

    /**
     * @brief Gets the current (focused) child
     *
     * @return Pointer to current child, or nullptr if none
     */
    ElementBase *GetFocused() const;

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
    bool OnKey(Keys aKey) override;

  protected:
    /**
     * @brief Sets the current (focused) child
     *
     * @param aChild Child element to set as focused
     */
    void focusChild(FocusableBase *aChild);

  private:
    /**
     * @brief Navigate to next element in circular chain
     */
    void focusNext();

    /**
     * @brief Navigate to previous element in circular chain
     */
    void focusPrev();

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
     * @brief freezes all children
     */
    virtual void freezer();

  private:
    FocusableBase *mFocusedChild = nullptr; ///< Currently focused child element (only reference needed)
  };

}