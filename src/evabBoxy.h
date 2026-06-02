#pragma once

#include <evabElementBase.h>
#include <evabIScreen.h>
#include <evaHandler.h>
#include <evaDelayTimer.h>
#include <evabKeys.h>


namespace evab
{
    class Boxy : public eva::IHandler
    {
    public:
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

        static void Key(Keys aKey);

        static IScreen *Screen();

        static Boxy *Instance();

        static void ShowInt(const char *aName, int aValue);

    private:
        void invoke(void *, eva::CallbackInfo) override;

    private:
        IScreen *mScreen;
        ElementBase *mGround;
        eva::DelayTimer mModalShowTimer = {this};
    };
}
