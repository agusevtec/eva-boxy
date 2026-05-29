#pragma once
#include <evabSSH1106Screen.h>
#include <evabElementBase.h>
#include <evabIScreen.h>

static const unsigned char KEY_SELECT = 0x01;
static const unsigned char KEY_MENU = 0x02;
static const unsigned char KEY_DOWN = 0x04;
static const unsigned char KEY_UP = 0x08;
static const unsigned char KEY_LEFT = 0x10;
static const unsigned char KEY_RIGHT = 0x20;

namespace evab
{
    class Boxy
    {
    public:
        void UseScreen(IScreen *aScreen)
        {
            mScreen = aScreen;
        }

        void Ground(ElementBase *aGround)
        {
            mGround = aGround;
            if (mGround && mScreen)
                mGround->Draw(mScreen, {0, 0}, mScreen->Size(), 1);
        }

        void Enabled(bool aIsEnabled)
        {
            mIsEnabled = aIsEnabled;
        }

        void Key(char aKey)
        {
            if (mGround)
                mGround->Key(aKey);
        }

        IScreen *Screen()
        {
            return mScreen;
        }

        static Boxy *Instance()
        {
            static Boxy instance;
            return &instance;
        }

    private:
        IScreen *mScreen = nullptr;
        ElementBase *mGround = nullptr;
        bool mIsEnabled = true;
    };

    template <class TFont>
    void UseSSH1106Screen()
    {
        static SSH1106Screen<TFont> screen;
        Boxy *boxy = Boxy::Instance();
        boxy->UseScreen(&screen);
    }
}
