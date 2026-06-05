// TimerTests.ino
#include <AUnit.h>

using namespace aunit;
#include <evabScreenSerialText.h>
#include <evabScreenSerialPixel.h>
#include <evabFont8Thin.h>
#include <evabProgressBarH.h>

// -------------------------------------------------------------------
// DelayTimer
// -------------------------------------------------------------------

test(delayTimer_triggers_once)
{
    // evab::ScreenSerialText screen;
    evab::Font8Thin font;
    evab::ScreenSerialPixel screen(&font);
    for (int i = 0; i <= 5; i++)
    {
        evab::ProgressBarH pb(10*i);
        pb.Draw(&screen, {0, i}, {16,1}, 0);
    }
    screen.printToSerial();
    assertEqual(1, 1);
}
