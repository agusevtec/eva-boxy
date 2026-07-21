

# File evabInputAnimation.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**evabInputAnimation.h**](evab_input_animation_8h.md)

[Go to the documentation of this file](evab_input_animation_8h.md)


```C++
#pragma once

#include <evabElementBase.h>
#include <evabPictosets.h>
#include <evaTickable.h>

namespace evab
{

    template <class TPictoset, unsigned char tMaxSpeed = 10>
    class InputAnimation : public ElementBase, private eva::Tickable
    {
        static_assert(tMaxSpeed > 0, "tMaxSpeed must be greater than 0");

    public:
        InputAnimation(unsigned char aValue = 0)
            : eva::Tickable()
        {
            mValue = constrain(aValue, 0, tMaxSpeed);
            mCurrentFrame = 0;
            mLastFrameTime = 0;
        }

        virtual ~InputAnimation()
        {
            // Tickable destructor handles removal from list
        }

        void SetValue(unsigned char aValue)
        {
            mValue = constrain(aValue, 0, tMaxSpeed);
        }

        unsigned char GetValue() const
        {
            return mValue;
        }

        unsigned char GetValuePercent() const
        {
            return map(mValue, 0, tMaxSpeed, 0, 100);
        }

        void SetValuePercent(unsigned char aValue)
        {
            SetValue(map(constrain(aValue, 0, 100), 0, 100, 0, tMaxSpeed));
        }

        void Increment(signed char delta)
        {
            SetValue(mValue + delta);
        }

    protected:
        void drawer(IScreen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override
        {
            // Resume animation if speed > 0 and was stopped
            if (mValue > 0 && mLastFrameTime == 0)
            {
                mLastFrameTime = millis();
            }

            aScreen->Picto(aPos, TPictoset::GetTile(mCurrentFrame), aIsFocused);
        }

        void hider() override
        {
            mLastFrameTime = 0;
        }

    private:
        void tick() override
        {
            if (mLastFrameTime == 0 || mValue == 0)
                return;

            unsigned long now = millis();
            unsigned long frameDelay = calculateFrameDelay();

            if (now - mLastFrameTime >= frameDelay)
            {
                mLastFrameTime = now;
                mCurrentFrame = (mCurrentFrame + 1) % TPictoset::Count;
                Redraw();
            }
        }

        unsigned long calculateFrameDelay() const
        {
            if (mValue == 0 || tMaxSpeed == 0)
                return 0;

            // Map speed to delay: speed 1 = 1000ms, speed tMaxSpeed = 50ms
            unsigned long minDelay = 50;
            unsigned long maxDelay = 1000;

            // Linear interpolation between min and max delay
            unsigned long delay = maxDelay - ((mValue - 1) * (maxDelay - minDelay)) / (tMaxSpeed - 1);
            return delay;
        }

        unsigned char mValue;         
        unsigned char mCurrentFrame;  
        unsigned long mLastFrameTime; 
    };

}
```


