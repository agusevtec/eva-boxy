#pragma once
#include <evabSSH1106Screen.h>
#include <evabElementBase.h>
#include <evabIScreen.h>
#include <evaDelayTimer.h>
#include <evabInputInt.h>
#include <evabLabeled.h>

static const unsigned char KEY_SELECT = 0x01;
static const unsigned char KEY_MENU = 0x02;
static const unsigned char KEY_DOWN = 0x04;
static const unsigned char KEY_UP = 0x08;
static const unsigned char KEY_LEFT = 0x10;
static const unsigned char KEY_RIGHT = 0x20;

namespace evab
{
    class Boxy : public eva::IHandler
    {
    public:
        void SetScreen(IScreen *aScreen);
        void Ground(ElementBase *aGround);
        void ShowInt(const char *aName, int aValue);
        void invoke(void *, eva::CallbackInfo ) override;
        void Key(char aKey);
        IScreen *Screen();
        static Boxy *Instance();

    private:
        Boxy() = default; 
        IScreen *mScreen = nullptr;
        ElementBase *mGround = nullptr;
        eva::DelayTimer mModalShowTimer;
    };

    template <class TFont>
    void UseSSH1106Screen()
    {
        static TFont font;
        static SSH1106Screen screen(&font);
        Boxy *boxy = Boxy::Instance();
        boxy->SetScreen(&screen);
    }
}