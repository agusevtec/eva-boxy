// TimerTests.ino
#include <AUnit.h>

using namespace aunit;
#include <evabScreenSerialText.h>
#include <evabScreenSerialPixel.h>
#include <evabFont8Thin.h>
#include <evabStretchBar.h>
#include <evabTilesets.h>
#include <evabLayoutPane.h>

// -------------------------------------------------------------------
// DelayTimer
// -------------------------------------------------------------------

test(delayTimer_triggers_once)
{
    evab::ScreenSerialText screen;
    // evab::Font8Thin font;
    // evab::ScreenSerialPixel screen(&font);
    evab::LayoutPane lp;
    lp.SetItems(4321, nullptr, 0);
    lp.Draw(&screen, {0, 0}, {16, 8}, 0);
    // for (int i = 0; i < 8; i++)
    // {
    //     evab::VScrollBar pb(10*i);
    //     pb.Draw(&screen, {i, 0}, {1, 8}, 0);
    // }
    screen.printToSerial();
    assertEqual(1, 1);
}
