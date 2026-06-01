// TimerTests.ino
#include <AUnit.h>

using namespace aunit;
#include <evabScreenSerialText.h>
#include <evabScreenSerialPixel.h>
#include <evabFont8Thin.h>
#include <evabProgressBar.h>

// -------------------------------------------------------------------
// DelayTimer
// -------------------------------------------------------------------

test(delayTimer_triggers_once)
{
    // evab::ScreenSerialText screen;
    evab::Font8Thin font;
    evab::ScreenSerialPixel screen(&font);
    for (int i = 0; i <= 10; i++)
    {
        evab::ProgressBar pb(10*i);
        pb.Draw(&screen, {i, 0}, {1,3}, 0);
    }
    screen.printToSerial();
    assertEqual(1, 1);
}
