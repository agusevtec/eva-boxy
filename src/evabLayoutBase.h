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
    virtual IFocusChain *Next() = 0;

    /**
     * @brief Sets the next element in the chain
     *
     * @param aNext Pointer to next element
     */
    virtual ElementBase *AsElementBase() = 0;

    virtual void SetNext(IFocusChain *aNext) = 0;

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
    /**
     * @brief Wrapper that chains elements in a circular doubly-linked list
     *
     * @tparam T Element type to wrap (must inherit ElementBase)
     */
    template <class T>
    class FocusChain : public T, public IFocusChain
    {
    public:
      template <typename... Args>
      FocusChain(LayoutBase *aParent, Args &&...args)
          : T(args...), mNext(nullptr)
      {
        if (!aParent)
          return;
        IFocusChain *first = aParent->mFocusedChild;
        if (first)
        {
          IFocusChain *last = first;
          while (last->Next() && last->Next() != first)
            last = last->Next();

          last->SetNext(this);
          this->SetNext(first);
        }
        else
        {
          this->SetNext(this);
          aParent->mFocusedChild = this;
        }
      }

      IFocusChain *Next() override
      {
        return mNext;
      }

      virtual void SetNext(IFocusChain *aNext) override
      {
        mNext = aNext;
      }

      virtual ElementBase *AsElementBase() override
      {
        return this;
      }

    private:
      IFocusChain *mNext;
    };

  public:
    /**
     * @brief Checks if a child is currently focused
     *
     * @param aChild Child element to check
     * @return true if the child is focused
     */
    bool IsFocused(IFocusChain *aChild);

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
    bool Key(Keys aKey) override;

  protected:
    /**
     * @brief Sets the current (focused) child
     *
     * @param aChild Child element to set as focused
     */
    void focusChild(IFocusChain *aChild);

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
     * @brief Pure virtual method to hide all children
     */
    virtual void hider();

  private:
    IFocusChain *mFocusedChild = nullptr; ///< Currently focused child element (only reference needed)
  };

}