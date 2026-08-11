#include <evabBoxy.h>
#include <evabFont8Narrow.h>
#include <evabScreenSSD1306.h>
#include <evaRepeatTimer.h>

#include <evabGalleryRemixicon24.h>
#include <evabInputButtonPx.h>
#include <evabBehavior.h>
#include <evaTac.h>
#include <evabInputButton.h>
#include <evabLayoutBase.h>
#include <evabLabeled.h>
#include <evabInputAnimationPx.h>
#include <evabAlbums.h>

using namespace eva;
using namespace evab;

static const char OK_TEXT[] PROGMEM = "OK";

class MyLayout : public LayoutBase {
  Focusable<InputButtonPx> btn1{ this, GalleryRemixicon24::PICTO_EC10 };
  //InputButtonPx btn2{ GalleryRemixicon24::PICTO_F371 };
  //Focusable<InputButtonPx> btn3{ this, AlbumRainbowmeter::GetTile(2) };
  InputAnimationPx<AlbumProgress> btn2{  2};
  InputAnimationPx<AlbumRoundmeter> btn3{  2};
  Focusable<InputButton> btn4{ this, (const __FlashStringHelper *)OK_TEXT };

protected:
  void drawer(Screen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override {
    btn1.Draw(aScreen, aPos, { 4, 4 }, IsFocused(&btn1));
    btn2.Draw(aScreen, { aPos.X + 4, aPos.Y + 4 }, { 4, 4 }, 0);
    btn3.Draw(aScreen, { aPos.X + 8, aPos.Y + 0 }, { 4, 4 }, 0);
    btn4.Draw(aScreen, { aPos.X + 12, aPos.Y + 4 }, { 4, 4 }, IsFocused(&btn4));
  }
};

class App {

  RepeatTimer repeatTimer { new Handler<App>(this, &onRepeatTimer) };
  KeyModifier<MyLayout, KEY_LEFT, KEY_RIGHT> myLayout;

public:
  App() {
    Boxy::Begin<ScreenSSD1306, Font8Narrow>(&myLayout);
    repeatTimer.start(1000);
  }

  void onRepeatTimer(void *, eva::CallbackInfo) {
    Boxy::OnKey(KEY_RIGHT);
  }
};

void setup() {
  Serial.begin(9600);
  static App app;
}

void loop() {
  eva::tac();
}
