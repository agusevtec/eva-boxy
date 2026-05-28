#pragma once
#include <evabSSH1106Screen.h>
#include <evabCompositeBase.h>
#include <evabIScreen.h>

namespace evab
{
    class Boxy
    {
    public:
        void UseScreen(IScreen *aScreen)
        {
            mScreen = aScreen;
        }

        void Ground(CompositeBase *aGround)
        {
            mGround = aGround;
            if (mGround && mScreen)
                mGround->Draw(mScreen, {0, 0}, mScreen->Size(), 0);
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
        CompositeBase *mGround = nullptr;
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
