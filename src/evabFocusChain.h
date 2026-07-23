// evabFocusChain.h
#pragma once

#include <evabElementBase.h>
#include <evabLayoutBase.h>


namespace evab
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
            if (aParent)
            {
                // Get first element from parent
                IFocusChain *first = aParent->getCurrentChild();

                if (first)
                {
                    // Insert this BEFORE first
                    // Find last element (the one whose next == first)
                    IFocusChain *last = first;
                    while (last->next() && last->next() != first)
                    {
                        last = last->next();
                    }

                    // Insert: last -> this -> first
                    last->setNext(this);
                    this->setNext(first);
                    // Parent still points to first (current)
                }
                else
                {
                    // First element - points to itself (circular)
                    this->setNext(this);
                    aParent->setCurrentChild(this);
                }
            }
        }

        // IFocusChain implementation
        IFocusChain *next() override
        {
            return mNext;
        }

        virtual void setNext(IFocusChain *aNext) override
        {
            mNext = aNext;
        }

        virtual ElementBase *asElementBase() override
        {
            return this;
        }

    private:
        IFocusChain *mNext;
    };
}
