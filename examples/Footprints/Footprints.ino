#include <evabFont8Bold.h>
#include <evabScreenSSD1306.h>
#include <evabAlbums.h>
#include <evabInputInt.h>
#include <evabInputFloat.h>
#include <evabInputSelectorPx.h>
#include <evabInputButton.h>
#include <evabInputButtonPx.h>
#include <evabInputAnimationPx.h>
#include <evabStretchBarPx.h>
#include <evabStretchBar.h>
#include <evabGalleryRemixicon16.h>
#include <evabGalleryRemixicon24.h>
#include <evabGalleryRemixicon32.h>

using namespace evab;
using namespace eva;

/**
 * @brief Clears the screen and displays a label.
 *
 * @param aScreen Pointer to the screen object.
 * @param aLabel  Label text to display at the top.
 */
void showScreen(Screen *aScreen, const char *aLabel) {
    delay(2000);
    aScreen->Clear({0, 0}, aScreen->Size(), 0);
    aScreen->TextLeft({0, 0}, {16, 1}, aLabel, 0);
}

void setup() {
    Serial.begin(9600);
    Serial.println("=== EVA Boxy Imperative Demo ===");

    static Font8Bold font;
    static ScreenSSD1306 screen(&font);
    
    // ============================================
    // SCREEN METHODS
    // ============================================
    
    showScreen(&screen, "TextLeft:");
    screen.TextLeft({0, 2}, {16, 1}, "Hello Left", 0);

    showScreen(&screen, "TextCenter:");
    screen.TextCenter({0, 2}, {16, 1}, "Hello Center", 0);

    showScreen(&screen, "TextRight:");
    screen.TextRight({0, 2}, {16, 1}, "Hello Right", 0);

    // ============================================
    // TEXTCENTER IN DIFFERENT SCALES
    // ============================================

    showScreen(&screen, "TextCenter 1x1:");
    screen.TextCenter({0, 2}, {16, 1}, "Size 1", 0);

    showScreen(&screen, "TextCenter 2x1:");
    screen.TextCenter({0, 2}, {16, 2}, "Size 2", 0);

    showScreen(&screen, "TextCenter 3x1:");
    screen.TextCenter({0, 2}, {16, 3}, "Size3", 0);

    showScreen(&screen, "F-string");
    screen.TextCenter({0, 2}, {16, 1}, F("F-string"), 0);

    // ============================================
    // DRAW SYMBOL
    // ============================================

    showScreen(&screen, "DrawSymbol:");
    for (int i = 0; i < 8; i++) {
        screen.DrawSymbol({i, 3}, {1, 1}, 'A' + i, 0);
    }

    // ============================================
    // REMIXICON ICONS (16x16, 24x24, 32x32)
    // ============================================

    showScreen(&screen, "Remixicon 16x16:");
    screen.Picto({0, 3}, GalleryRemixicon16::PICTO_F243, 0);
    screen.Picto({3, 3}, GalleryRemixicon16::PICTO_F0E4, 0);
    screen.Picto({6, 3}, GalleryRemixicon16::PICTO_F1F2, 0);

    showScreen(&screen, "Remixicon 24x24:");
    screen.Picto({0, 3}, GalleryRemixicon24::PICTO_F243, 0);
    screen.Picto({4, 3}, GalleryRemixicon24::PICTO_F0E4, 0);
    screen.Picto({8, 3}, GalleryRemixicon24::PICTO_F1F2, 0);

    showScreen(&screen, "Remixicon 32x32:");
    screen.Picto({0, 3}, GalleryRemixicon32::PICTO_F243, 0);
    screen.Picto({5, 3}, GalleryRemixicon32::PICTO_F0E4, 0);
    screen.Picto({10, 3}, GalleryRemixicon32::PICTO_F1F2, 0);

    // ============================================
    // ALL Input#### ELEMENTS
    // ============================================
    
    showScreen(&screen, "InputButton:");
    InputButton button(F("OK"));
    button.Draw(&screen, {0, 4}, {16, 1}, 1);

    showScreen(&screen, "InputButtonPx:");
    InputButtonPx buttonPicto(GalleryRemixicon24::PICTO_F243);
    buttonPicto.Draw(&screen, {6, 4}, {3, 3}, 1);

    // InputInt: 42 → 99
    showScreen(&screen, "InputInt");
    InputInt intVal(42);
    intVal.Draw(&screen, {0, 4}, {16, 1}, 0);
    delay(1000);
    intVal.SetValue(99);
    intVal.Draw(&screen, {0, 4}, {16, 1}, 0);

    // InputFloat: 3.14 → 1.23
    showScreen(&screen, "InputFloat");
    InputFloat floatVal(3.14);
    floatVal.Draw(&screen, {0, 4}, {16, 1}, 0);
    delay(1000);
    floatVal.SetValue(1.23);
    floatVal.Draw(&screen, {0, 4}, {16, 1}, 0);

    // InputSelectorPx: 3/7 → 6/7
     showScreen(&screen, "AlbumOnOff:");
    InputSelectorPx<AlbumOnOff> selOnOff(0);
    selOnOff.Draw(&screen, {7, 4}, {2, 1}, 0);
    delay(1000);
    selOnOff.Select(1);
    selOnOff.Draw(&screen, {7, 4}, {2, 1}, 0);

    showScreen(&screen, "InputSelectorPx");
    InputSelectorPx<AlbumBattery> selector(1);
    selector.Draw(&screen, {7, 4}, {2, 1}, 0);
    delay(1000);
    selector.Select(4);
    selector.Draw(&screen, {7, 4}, {2, 1}, 0);

    showScreen(&screen, "AlbumRainbowmeter:");
    InputSelectorPx<AlbumRainbowmeter> selRainbow(2);
    selRainbow.Draw(&screen, {6, 4}, {4, 2}, 0);
    delay(1000);
    selRainbow.Select(5);
    selRainbow.Draw(&screen, {6, 4}, {4, 2}, 0);


    showScreen(&screen, "AlbumLamp:");
    InputSelectorPx<AlbumLamp> selLamp(2);
    selLamp.Draw(&screen, {7, 4}, {2, 2}, 0);
    delay(1000);
    selLamp.Select(4);
    selLamp.Draw(&screen, {7, 4}, {2, 2}, 0);

    showScreen(&screen, "AlbumProgress:");
    InputSelectorPx<AlbumProgress> selProgress(2);
    selProgress.Draw(&screen, {7, 4}, {2, 2}, 0);
    delay(1000);
    selProgress.Select(6);
    selProgress.Draw(&screen, {7, 4}, {2, 2}, 0);

    showScreen(&screen, "AlbumSpeaker:");
    InputSelectorPx<AlbumSpeaker> selSpeaker(1);
    selSpeaker.Draw(&screen, {7, 4}, {2, 2}, 0);
    delay(1000);
    selSpeaker.Select(3);
    selSpeaker.Draw(&screen, {7, 4}, {2, 2}, 0);

    showScreen(&screen, "AlbumSignal:");
    InputSelectorPx<AlbumSignal> selSignal(2);
    selSignal.Draw(&screen, {7, 4}, {2, 1}, 0);
    delay(1000);
    selSignal.Select(3);
    selSignal.Draw(&screen, {7, 4}, {2, 1}, 0);

    showScreen(&screen, "AlbumRoundmeter:");
    InputSelectorPx<AlbumRoundmeter> selRound(3);
    selRound.Draw(&screen, {7, 4}, {3, 3}, 0);
    delay(1000);
    selRound.Select(9);
    selRound.Draw(&screen, {7, 4}, {3, 3}, 0);
    // ============================================
    // ALL 4 STRETCHBAR TYPES
    // ============================================

    showScreen(&screen, "VerticalProgressBarPx:");
    VerticalProgressBarPx vProgress(50);
    vProgress.Draw(&screen, {8, 2}, {2, 5}, 0);
    delay(1000);
    vProgress.SetPercent(75);
    vProgress.Draw(&screen, {8, 2}, {2, 5}, 0);

    // HorizontalScrollBarPx: 50% → 75%
    showScreen(&screen, "HorizontalProgressBarPx");
    HorizontalProgressBarPx hProgress(50);
    hProgress.Draw(&screen, {1, 3}, {14, 1}, 0);
    delay(1000);
    hProgress.SetPercent(75);
    hProgress.Draw(&screen, {1, 3}, {14, 1}, 0);

    showScreen(&screen, "VerticalScrollBarPx:");
    VerticalScrollBarPx vScroll(50);
    vScroll.Draw(&screen, {8, 2}, {2, 5}, 0);
    delay(1000);
    vScroll.SetPercent(75);
    vScroll.Draw(&screen, {8, 2}, {2, 5}, 0);

    // HorizontalScrollBarPx: 50% → 75%
    showScreen(&screen, "HorizontalScrollBarPx");
    HorizontalScrollBarPx scrollBar(50);
    scrollBar.Draw(&screen, {1, 3}, {14, 1}, 0);
    delay(1000);
    scrollBar.SetPercent(75);
    scrollBar.Draw(&screen, {1, 3}, {14, 1}, 0);

    // ============================================
    // ALL 4 TEXTSTRETCHBAR TYPES
    // ============================================

    showScreen(&screen, "VerticalProgressBar:");
    VerticalProgressBar vtProgress(50);
    vtProgress.Draw(&screen, {8, 2}, {2, 5}, 0);
    delay(1000);
    vtProgress.SetPercent(75);
    vtProgress.Draw(&screen, {8, 2}, {2, 5}, 0);

    showScreen(&screen, "HorizontalProgressBar");
    HorizontalProgressBar htProgress(50);
    htProgress.Draw(&screen, {1, 3}, {14, 1}, 0);
    delay(1000);
    htProgress.SetPercent(75);
    htProgress.Draw(&screen, {1, 3}, {14, 1}, 0);

    showScreen(&screen, "VerticalScrollBar:");
    VerticalScrollBar vtScroll(50);
    vtScroll.Draw(&screen, {8, 2}, {2, 5}, 0);
    delay(1000);
    vtScroll.SetPercent(75);
    vtScroll.Draw(&screen, {8, 2}, {2, 5}, 0);

    // HorizontalScrollBarPx: 50% → 75%
    showScreen(&screen, "HorizontalScrollBar");
    HorizontalScrollBar tscrollBar(50);
    tscrollBar.Draw(&screen, {1, 3}, {14, 1}, 0);
    delay(1000);
    tscrollBar.SetPercent(75);
    tscrollBar.Draw(&screen, {1, 3}, {14, 1}, 0);

   // ============================================
    // FINAL SCREEN
    // ============================================
    
    showScreen(&screen, "Demo Complete!");
    screen.TextCenter({0, 2}, {16, 1}, "All elements", 0);
    screen.TextCenter({0, 3}, {16, 1}, "demonstrated", 0);
    delay(2000);

    Serial.println("=== Demo Complete ===");
}

void loop() {
}