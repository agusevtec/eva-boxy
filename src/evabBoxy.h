#pragma once

#include <evabElementBase.h>
#include <evabIScreen.h>
#include <evaHandler.h>
#include <evaDelayTimer.h>
#include <evabKeys.h>


namespace evab
{
    /**
     * @brief Main application controller managing screen, input, and modal overlays
     * 
     * Boxy is a singleton that provides global access to the display system,
     * manages the current screen, and handles modal popups.
     */
    class Boxy : public eva::IHandler
    {
    public:
        /**
         * @brief Initializes the Boxy system with a screen and ground element
         * 
         * @tparam TScreen Screen type to use
         * @tparam TFont Font type to use
         * @tparam Args Additional arguments for screen constructor
         * @param aGround Base element to display
         * @param args Arguments forwarded to screen constructor
         */
        template <class TScreen, class TFont, typename... Args>
        static void Begin(ElementBase *aGround, Args &&...args)
        {
            static TFont font;
            static TScreen screen(&font, args...);
            auto instance = Instance();
            instance->mScreen = &screen;
            instance->mGround = aGround;
            if (instance->mGround)
                instance->mGround->Draw(instance->mScreen, {0, 0}, instance->mScreen->Size(), 1);
        }

        /**
         * @brief Forwards key events to the ground element
         * 
         * @param aKey Key code to process
         */
        static void Key(Keys aKey);

        /**
         * @brief Gets the current screen pointer
         * 
         * @return Pointer to current screen, or nullptr if modal is active
         */
        static IScreen *Screen();

        /**
         * @brief Gets the singleton instance
         * 
         * @return Pointer to the Boxy singleton
         */
        static Boxy *Instance();

        /**
         * @brief Displays a temporary modal with a named integer value
         * 
         * @param aName Label text
         * @param aValue Integer value to show
         */
        static void ShowInt(const char *aName, int aValue);

    private:
        /**
         * @brief IHandler callback implementation
         * 
         * @param void* Unused
         * @param eva::CallbackInfo Callback information
         */
        void invoke(void *, eva::CallbackInfo) override;

    private:
        IScreen *mScreen;                          ///< Current screen instance
        ElementBase *mGround;                      ///< Ground element being displayed
        eva::DelayTimer mModalShowTimer = {this};  ///< Timer for modal visibility
    };
}
