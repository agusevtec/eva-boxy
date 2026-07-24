#include <evabBoxy.h>
#include <evabFont8Narrow.h>
#include <evabScreenSSD1306.h>
#include <evaRepeatTimer.h>

#include <evabGalleryRemixicon24.h>
#include <evabInputButtonPicto.h>
#include <evabBehavior.h>
#include <evaTac.h>
#include <evabInputButton.h>
#include <evabLayoutBase.h>
#include <evabLabeled.h>
#include <evabInputAnimation.h>
#include <evabPictosets.h>

using namespace eva;
using namespace evab;

static const char OK_TEXT[] PROGMEM = "OK";

class MyLayout : public LayoutBase {
  FocusChain<InputButtonPicto> btn1{ this, GalleryRemixicon24::PICTO_EC10 };
  //InputButtonPicto btn2{ GalleryRemixicon24::PICTO_F371 };
  //FocusChain<InputButtonPicto> btn3{ this, PictosetRainbowmeter::GetTile(2) };
  InputAnimation<PictosetRoundmeter> btn2{  2};
  InputAnimation<PictosetDash> btn3{  2};
  FocusChain<InputButton> btn4{ this, (const __FlashStringHelper *)OK_TEXT };

protected:
  void drawer(IScreen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override {
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
    Boxy::Key(KEY_RIGHT);
  }
};

void setup() {
  Serial.begin(9600);
  static App app;
}

void loop() {
  eva::tac();
}
