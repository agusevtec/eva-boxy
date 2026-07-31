

# File evabPercent.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**evabPercent.h**](evab_percent_8h.md)

[Go to the documentation of this file](evab_percent_8h.md)


```C++
// evabModifiers.h
#pragma once

#include "evabInputInt.h"
#include "evabInputFloat.h"

namespace evab
{

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
            if (kStep == 0)
            {
                mStep = 100 / TElement::Count();
                if (mStep == 0)
                    mStep = 1;
            }
            else
            {
                mStep = kStep;
            }
        }

        void SetPercent(unsigned char aPercent)
        {
            aPercent = constrain(aPercent, 0, 100);
            unsigned char index = aPercent / mStep;
            if (index >= TElement::Count())
                index = TElement::Count() - 1;
            TElement::Select(index);
        }

        unsigned char GetPercent() const
        {
            signed short selected = TElement::Selected();
            if (selected < 0)
                return 0;
            return selected * mStep;
        }

        unsigned char GetStep() const { return mStep; }
    };

}
```


