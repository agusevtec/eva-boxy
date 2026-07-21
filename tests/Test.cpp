// TimerTests.ino
#include <AUnit.h>

using namespace aunit;
#include <evabScreenSerialText.h>
#include <evabScreenSerialPixel.h>
#include <evabFont8Narrow.h>
#include <evabInputStretchBar.h>
#include <evabPictosets.h>
#include <evabLayoutPane.h>
#include <evabInputButton.h>
#include <evabInputPictogram.h>

using namespace evab;

// -------------------------------------------------------------------
// DelayTimer
// -------------------------------------------------------------------

test(delayTimer_triggers_once)
{
    //ScreenSerialText screen;
     Font8Narrow font;
     ScreenSerialPixel screen(&font);
//    evab::LayoutPane lp;
//    lp.SetItems(4321, nullptr, 0);
//    lp.Draw(&screen, {0, 0}, {16, 8}, 0);
     evab::InputButton ib(F("Restore"));
     ib.Draw(&screen, {0, 0}, {9, 8}, 0);
    // for (int i = 0; i < 4; i++)
    // {
    //     InputPictogram<PictosetBattery> pb(i);
    //     pb.Draw(&screen, {0, i}, {1, 2}, 0);
    // }

    screen.printToSerial();
    assertEqual(1, 1);
}
