#include "evabBoxy.h"

namespace evab
{
    void Boxy::SetScreen(IScreen *aScreen)
    {
        mScreen = aScreen;
    }

    void Boxy::Ground(ElementBase *aGround)
    {
        mGround = aGround;
        if (mGround && mScreen)
            mGround->Draw(mScreen, {0, 0}, mScreen->Size(), 1);
    }

    void Boxy::ShowInt(const char *aName, int aValue)
    {
        if (!mScreen)
            return;
        Coor sz = mScreen->Size();
        Labeled<InputInt> drawer(aName, aValue);
        drawer.Draw(mScreen, {0, sz.Y / 2}, {sz.X, 1}, 0);
        mModalShowTimer.start(1200, this);
    }

    void Boxy::invoke(void *, eva::CallbackInfo )
    {
        if (mGround && mScreen)
            mGround->Draw(mScreen, {0, 0}, mScreen->Size(), 1);
    }

    void Boxy::Key(char aKey)
    {
        if (mGround)
            mGround->Key(aKey);
    }

    IScreen *Boxy::Screen()
    {
        if (mModalShowTimer.isRunning())
            return nullptr;
        return mScreen;
    }

    Boxy *Boxy::Instance()
    {
        static Boxy instance;
        return &instance;
    }
}