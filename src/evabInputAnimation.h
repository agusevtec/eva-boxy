#pragma once

#include <evabElementBase.h>
#include <evabAlbums.h>
#include <evaTickable.h>

namespace evab
{

    /**
     * @brief Animation input element with configurable speed
     *
     * This element displays an animated pictogram where the animation speed
     * can be adjusted by the user. The animation cycles through available
     * pictograms at a speed determined by the current value.
     *
     * The element uses the eva::Tickable system for periodic updates.
     * The speed value ranges from 0 (stopped) to tMaxSpeed (maximum animation speed).
     * Animation is automatically paused when the element is hidden and resumed
     * when it becomes visible again.
     *
     * Redraws occur only on timer ticks to maintain consistent animation timing.
     *
     * @tparam TAlbum Album class providing pictogram data and count
     * @tparam tMaxSpeed Maximum speed value (must be > 0)
     *
     * @see InputPictogram For static pictogram selection
     * @see eva::Tickable Base class for periodic updates
     */
    template <class TAlbum, unsigned char tMaxSpeed = 10>
    class InputAnimation : public ElementBase, private eva::Tickable
    {
        static_assert(tMaxSpeed > 0, "tMaxSpeed must be greater than 0");

    public:
        /**
         * @brief Constructor for InputAnimation
         *
         * @param aValue Initial speed value (0 to tMaxSpeed)
         */
        InputAnimation(unsigned char aValue = 0)
            : eva::Tickable()
        {
            mValue = constrain(aValue, 0, tMaxSpeed);
            mCurrentFrame = 0;
            mLastFrameTime = 0;
        }

        /**
         * @brief Destructor - removes from Tickable list
         */
        virtual ~InputAnimation()
        {
            // Tickable destructor handles removal from list
        }

        /**
         * @brief Sets the animation speed
         *
         * @param aValue Speed value (0 = stopped, 1..tMaxSpeed = animation speed)
         */
        void Select(unsigned char aValue)
        {
            aValue = constrain(aValue, 0, tMaxSpeed); 
            if (mValue == aValue)
                return;
            mValue = aValue;

            redraw();
        }

        /**
         * @brief Gets the current speed value
         *
         * @return Current speed value (0 to tMaxSpeed)
         */
        unsigned char Selected() const
        {
            return mValue;
        }

        /**
         * @brief Increments the speed value by a delta
         *
         * @param delta Amount to add (positive or negative)
         */
        void Increment(signed char delta)
        {
            Select(mValue + delta);
        }

        unsigned char Count() const
        {
            return tMaxSpeed + 1; // 0..tMaxSpeed → tMaxSpeed+1 позиций
        }

    protected:
        /**
         * @brief Draws the animation on screen
         *
         * Resumes animation if element is visible and speed > 0.
         *
         * @param aScreen Screen to draw on
         * @param aPos Position on screen
         * @param aSize Size of the element
         * @param aIsFocused Focus state (1 = focused, 0 = not focused)
         */
        void drawer(Screen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override
        {
            // Resume animation if speed > 0 and was stopped
            if (mValue > 0 && mLastFrameTime == 0)
            {
                mLastFrameTime = millis();
            }

            aScreen->Picto(aPos, TAlbum::GetTile(mCurrentFrame), aIsFocused);
        }

        /**
         * @brief Hides the element and pauses animation
         */
        void freezer() override
        {
            mLastFrameTime = 0;
        }

    private:
        /**
         * @brief Tick method called by Tickable system
         *
         * Updates the animation frame based on current speed.
         * Called automatically by eva::tac() at regular intervals.
         * Only updates if animation is active (mLastFrameTime != 0) and speed > 0.
         */
        void tick() override
        {
            if (mLastFrameTime == 0 || mValue == 0)
                return;

            unsigned long now = millis();
            unsigned long frameDelay = calculateFrameDelay();

            if (now - mLastFrameTime >= frameDelay)
            {
                mLastFrameTime = now;
                mCurrentFrame = (mCurrentFrame + 1) % TAlbum::Count;
                redraw();
            }
        }

        /**
         * @brief Calculates frame delay from current speed
         *
         * Maps speed to frame delay: higher speed = shorter delay.
         * Range: from 1000ms (slowest) to 50ms (fastest).
         *
         * @return Frame delay in milliseconds
         */
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

    private:
        unsigned char mValue;         ///< Current speed value (0 to tMaxSpeed)
        unsigned char mCurrentFrame;  ///< Current animation frame index
        unsigned long mLastFrameTime; ///< Timestamp of last frame change (0 = stopped)
    };

}
