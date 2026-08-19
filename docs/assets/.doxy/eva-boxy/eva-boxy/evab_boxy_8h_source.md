

# File evabBoxy.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**evabBoxy.h**](evab_boxy_8h.md)

[Go to the documentation of this file](evab_boxy_8h.md)


```C++
#pragma once

#include <evaHandler.h>
#include <evaDelayTimer.h>

#include <evabElementBase.h>
#include <evabScreen.h>
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

        static Screen *GetScreen();

        static Boxy *Instance();

        static void Message(const __FlashStringHelper *, const char *aText);

    private:
        void invoke(void *, eva::CallbackInfo) override;

    private:
        Screen *mScreen;                        
        ElementBase *mGround;                   
        eva::DelayTimer mMessageTimer = {this}; 
    };
}
```


