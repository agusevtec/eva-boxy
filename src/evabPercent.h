#pragma once

#include "evabInputInt.h"
#include "evabInputFloat.h"

namespace evab
{
    /**
     * @brief Percent modifier for discrete inputs
     *
     * Adds percent-based control (0-100) to any discrete input.
     *
     * @tparam TElement Base element type (must have Select, Selected, Count methods)
     * @tparam kStep Step size in percent (default: 100 / Count)
     */
    template <typename TElement, unsigned char kStep = 0>
    class Percent : public TElement
    {
        static_assert(kStep <= 50, "kStep must be <= 50");

        unsigned char mStep;

    public:
        template <typename... Args>
        Percent(Args &&...args)
            : TElement(args...)
        {
            if (kStep > 0)
                mStep = kStep;
            else if (TElement::Count() > 1)
                mStep = max(1, 100 / (TElement::Count() - 1));
            else
                mStep = 1;
        }

        /**
         * @brief Sets value by percent (0-100)
         */
        void SetPercent(unsigned char aPercent)
        {
            aPercent = constrain(aPercent, 0, 100);
            unsigned char index = aPercent / mStep;
            if (index >= TElement::Count())
                index = TElement::Count() - 1;
            TElement::Select(index);
        }

        /**
         * @brief Gets current value as percent (0-100)
         */
        unsigned char GetPercent() const
        {
            signed short selected = TElement::Selected();
            if (selected < 0)
                return 0;
            return selected * mStep;
        }

        /**
         * @brief Gets the step size in percent
         */
        unsigned char GetStep() const { return mStep; }
    };

}