#include <evabBoxy.h>
#include <evabFont8Narrow.h>
#include <evabScreenSSD1306.h>
#include <evaRepeatTimer.h>

#include <evabGalleryRemixicon24.h>
#include <evabGalleryRemixicon32.h>
#include <evabInputButtonPicto.h>
#include <evabBehavior.h>
#include <evaTac.h>
#include <evaHandler.h>
#include <evabInputButton.h>
#include <evabLayoutBase.h>
#include <evabLabeled.h>
#include <evabInputAnimation.h>
#include <evabPictosets.h>
#include <evabCompositeBase.h>
#include <evabInputSelectorPicto.h>
#include <evabInputInt.h>
#include <evabInputFloat.h>
#include <evabGrid.h>

using namespace eva;
using namespace evab;

class UIHomeForm : public KeyModifier<LayoutBase, KEY_LEFT, KEY_RIGHT> {
  FocusChain<KeyCatcher<InputButtonPicto, KEY_ENTER>> mMonitorButton;
  FocusChain<KeyCatcher<InputButtonPicto, KEY_ENTER>> mSettingsButton;

public:
  UIHomeForm(IHandler *aOnMonitorHandler, IHandler *aOnSettingsHandler)
    : mMonitorButton(this, aOnMonitorHandler,  GalleryRemixicon32::PICTO_EC12),
      mSettingsButton(this, aOnSettingsHandler, GalleryRemixicon32::PICTO_F0E4) {
  }

private:
  void drawer(IScreen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override {
    Grid mesh(aPos, aSize);

    aScreen->TextCenter(aPos, mesh.NextRow(1).GetSize(), F("BOXY - DEMO"), 0);
    mesh.NextRow(1).Clean(aScreen);

    Grid row = mesh.NextRow(4);
    row.NextCol(2).Clean(aScreen);
    row.NextCol(4).Draw(aScreen, &mMonitorButton, IsFocused(&mMonitorButton));
    row.NextCol(2).Clean(aScreen);
    row.NextCol(4).Draw(aScreen, &mSettingsButton, IsFocused(&mSettingsButton));
    row.Rest().Clean(aScreen);

    mesh.NextRow(1).Clean(aScreen);

    row = mesh.NextRow(1);
    aScreen->TextCenter(row.GetPos(), row.GetSize(), IsFocused(&mMonitorButton) ? F("DASHBOARD") : F("SETTINGS"), 0);
  }
};

class UIMonitoringForm : public ElementBase {
  IHandler *mLeaveHandler;
  InputAnimation<PictosetFan> mFanIndicator{ 2 };
  InputSelectorPicto<PictosetRoundmeter> mMeterIndicator{ 2 };

public:
  UIMonitoringForm(IHandler *aLeaveHandler)
    : mLeaveHandler(aLeaveHandler) {
  }

private:
  void drawer(IScreen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override {
    


    aScreen->Clear({ aPos.X, aPos.Y }, { aSize.X, 1 });
    aScreen->Clear({ aPos.X, aPos.Y + 4 }, { aSize.X, 1 });
    aScreen->Clear({ aPos.X + 3, aPos.Y}, { 1, aSize.Y });

    aScreen->Picto({ aPos.X, aPos.Y + 1 }, GalleryRemixicon24::PICTO_F1F2, 0);
    LabeledF<InputFloat> tempField(F("TEMERATURE"), 23);
    tempField.Draw(aScreen, { aPos.X + 4, aPos.Y + 1 }, { aSize.X - 4, 3 }, 0);
    aScreen->Picto({ aPos.X, aPos.Y + 5 }, GalleryRemixicon24::PICTO_EBD8, 0);
    LabeledF<InputInt> humField(F("HUMIDITY"), 41);
    humField.Draw(aScreen, { aPos.X + 4, aPos.Y + 5 }, { aSize.X - 4, 3 }, 0);
  }

  bool Key(Keys aKey) override {
    if (mLeaveHandler)
      mLeaveHandler->invoke(this, { 0, 0 });
    return true;
  }
};

// static const char OK_TEXT[] PROGMEM = "OK";
//   FocusChain<InputButton> btn4{ this, (const __FlashStringHelper *)OK_TEXT };

class UIGroundLayer : public CompositeBase {
  UIHomeForm mUIHome{
    new Handler<UIGroundLayer>(this, &UIGroundLayer::onGotoMonitoring),
    new Handler<UIGroundLayer>(this, &UIGroundLayer::onGotoSettings)
  };

  UIMonitoringForm mUIMonitoring{ &onHomeHandler };

public:
  UIGroundLayer() {
    focusChild(&mUIHome);
  }

private:
  void onGotoMonitoring(void *aSender, CallbackInfo aCallbackInfo) {
    Serial.println("Monitor!");
    focusChild(&mUIMonitoring);
    Redraw();
  }

  void onGotoSettings(void *aSender, CallbackInfo aCallbackInfo) {
    Serial.println("Settings!");
  }

  Handler<UIGroundLayer> onHomeHandler{ this, &onBackHome };
  void onBackHome(void *aSender, CallbackInfo aCallbackInfo) {
    Serial.println("Back home!");
    focusChild(&mUIHome);
    Redraw();
  }

  void drawer(IScreen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override {
    if (IsFocused(&mUIHome))
      mUIHome.Draw(aScreen, aPos, aSize, aIsFocused);
    else
      mUIHome.Hide();

    if (IsFocused(&mUIMonitoring))
      mUIMonitoring.Draw(aScreen, aPos, aSize, aIsFocused);
    else
      mUIMonitoring.Hide();
  }

  void hider() override {
    mUIHome.Hide();
  }
};

const unsigned char gSimulateUser[5] = { KEY_RIGHT, KEY_LEFT, KEY_ENTER, KEY_ENTER};
unsigned char gSimulateUserIndex = 0;

class App {
  RepeatTimer repeatTimer{ new Handler<App>(this, &onRepeatTimer) };
  UIGroundLayer mUIGroundLayer;
  //UIMonitoringForm mUIGroundLayer{ nullptr };

public:
  App() {
    Boxy::Begin<ScreenSSD1306, Font8Narrow>(&mUIGroundLayer);
    repeatTimer.start(2000);
  }

  void onRepeatTimer(void *, eva::CallbackInfo) {
    Boxy::Key(gSimulateUser[gSimulateUserIndex]);
    ++gSimulateUserIndex %= 5;
  }
};

void setup() {
  Serial.begin(9600);
  static App app;
}

void loop() {
  eva::tac();
}
