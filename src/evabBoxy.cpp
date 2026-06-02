// evabBoxy.cpp
#include <evabBoxy.h>
#include <evaDelayTimer.h>
#include <evabInputInt.h>
#include <evabLabeled.h>

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
IScreen *Boxy::Screen()
{
    auto instance = Instance();
    if (instance->mModalShowTimer.isRunning())
        return nullptr;
    return instance->mScreen;
}

void Boxy::ShowInt(const char *aName, int aValue)
{
    auto instance = Instance();
    if (!instance->mScreen)
        return;

    Coor sz = instance->mScreen->Size();
    Labeled<InputInt> drawer(aName, aValue);
    drawer.Draw(instance->mScreen, {0, sz.Y / 2}, {sz.X, 1}, 0);
    instance->mModalShowTimer.start(1200);
}

void Boxy::invoke(void *, eva::CallbackInfo)
{
    if (mGround && mScreen)
        mGround->Draw(mScreen, {0, 0}, mScreen->Size(), 1);
}

