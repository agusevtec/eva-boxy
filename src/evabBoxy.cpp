// evabBoxy.cpp
#include <evabBoxy.h>
#include <evaDelayTimer.h>

using namespace eva;
using namespace evab;

void Boxy::Key(Keys aKey)
{
    auto instance = Instance();
    if (instance->mGround)
        instance->mGround->Key(aKey);
}

Boxy *Boxy::Instance()
{
    static Boxy instance;
    return &instance;
}
Screen *Boxy::GetScreen()
{
    auto instance = Instance();
    if (instance->mMessageTimer.isRunning())
        return nullptr;
    return instance->mScreen;
}

void Boxy::Message(const __FlashStringHelper * aTitle, const char *aText)
{
    auto instance = Instance();
    if (!instance->mScreen)
        return;

    Coor ps(0, 0);
    Coor sz = instance->mScreen->Size();

    if (sz.X > 2)
    {
        ps.X += 1;
        sz.X -= 2;
    }
    if (sz.Y > 2)
    {
        ps.Y += 1;
        sz.Y -= 2;
    }
    instance->mScreen->TextCenter(ps, {sz.X, 1}, aTitle, 1);
    for (unsigned char i = 1; i < sz.Y; i++)
        if (i == sz.Y / 2)
            instance->mScreen->TextCenter({ps.X, ps.Y + i}, {sz.X, 1}, aText, 1);
        else
            instance->mScreen->Clear({ps.X, ps.Y + i}, {sz.X, 1}, 1);
    instance->mMessageTimer.start(1200);
}

void Boxy::invoke(void *, eva::CallbackInfo)
{
    if (mGround && mScreen)
        mGround->Draw(mScreen, {0, 0}, mScreen->Size(), 1);
}
