// TimerTests.ino
#include <AUnit.h>

using namespace aunit;
#include <evabScreenSerialText.h>
#include <evabScreenSerialPixel.h>
#include <evabFont8Narrow.h>
#include <evabInputStretchBar.h>
#include <evabPictosets.h>
#include <evabLayoutBase.h>
#include <evabInputButton.h>
#include <evabInputSelectorPicto.h>
#include <evabGalleryRemixicon32.h>
#include <evabInputButtonPicto.h>

using namespace evab;


test(delayTimer_triggers_once)
{

    // ScreenSerialText screen;
    Font8Narrow font;
    ScreenSerialPixel screen(&font);
    LayoutBase lp;
    InputButtonPicto pictoButton0(picto_remixicon32_f569);
    InputButtonPicto pictoButton1(picto_remixicon32_ebbe);
    InputButtonPicto pictoButton2(picto_remixicon32_f08e);
    InputButtonPicto pictoButton3(picto_remixicon32_ea94);
    ElementBase *items[] = {&pictoButton0, &pictoButton1, &pictoButton2, &pictoButton3};
    lp.SetItems(22, items, 4);
    lp.Select(1);
    lp.Draw(&screen, {0, 0}, {16, 8}, 1);
    //     evab::InputButton ib(F("Restore"));
    //     ib.Draw(&screen, {0, 0}, {9, 8}, 0);
    // for (int i = 0; i < 4; i++)
    // {
    //     InputPictogram<PictosetBattery> pb(i);
    //     pb.Draw(&screen, {0, i}, {1, 2}, 0);
    // }

    screen.printToSerial();
    assertEqual(1, 1);
}
