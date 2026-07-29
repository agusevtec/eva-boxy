#include <evaTac.h>
#include <evaHandler.h>
#include <evaRepeatTimer.h>


#include <evabBoxy.h>
#include <evabFont8Narrow.h>
#include <evabScreenSSD1306.h>

#include <evabGalleryRemixicon24.h>
#include <evabGalleryRemixicon32.h>
#include <evabInputButtonPicto.h>
#include <evabBehavior.h>
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
#include <evabTextLabel.h>

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
  void drawer(Screen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override {
    TextLabelCenterF labelTitle(F("BOXY - DEMO"));
    TextLabelCenterF labelOption(IsFocused(&mMonitorButton) ? F("DASHBOARD") : F("SETTINGS"));

    Grid grid(aPos, aSize);
    grid.SliceRow(1).Draw(aScreen, &labelTitle);
    grid.SliceRow(1).Blank(aScreen);

    Grid row = grid.SliceRow(4);
    row.SliceCol(2).Blank(aScreen);
    row.SliceCol(4).Draw(aScreen, &mMonitorButton, IsFocused(&mMonitorButton));
    row.SliceCol(4).Blank(aScreen);
    row.SliceCol(4).Draw(aScreen, &mSettingsButton, IsFocused(&mSettingsButton));
    row.Rest().Blank(aScreen);

    grid.SliceRow(1).Blank(aScreen);
    grid.SliceRow(1).Draw(aScreen, &labelOption);
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
  void drawer(Screen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override {
    LabeledLeftF<InputFloat> tempField(F("TEMERATURE"), 23);
    LabeledLeftF<InputInt> humField(F("HUMIDITY"), 41);

    Grid grid (aPos, aSize);
    //mesh.SliceRow(1).Blank(aScreen);

    Grid row = grid.SliceRow(3);
    aScreen->Picto(row.SliceCol(3).GetPos(), GalleryRemixicon24::PICTO_F1F2, 0);
    row.SliceCol(1).Blank(aScreen);
    row.Rest().Draw(aScreen, &tempField);

    grid.SliceRow(2).Blank(aScreen);

    row = grid.SliceRow(3);
    aScreen->Picto(row.SliceCol(3).GetPos(), GalleryRemixicon24::PICTO_EBD8, 0);
    row.SliceCol(1).Blank(aScreen);
    row.Rest().Draw(aScreen, &humField);
  
    grid.Rest().Blank(aScreen);
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

  void drawer(Screen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override {
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

const unsigned char gSimulateUser[4] = { KEY_RIGHT, KEY_LEFT, KEY_ENTER, KEY_ENTER};
unsigned char gSimulateUserIndex = 0;

class App {
  RepeatTimer repeatTimer{ new Handler<App>(this, &onRepeatTimer) };
  UIGroundLayer mUIGroundLayer;
//  UIMonitoringForm mUIGroundLayer{ nullptr };

public:
  App() {
    Boxy::Begin<ScreenSSD1306, Font8Narrow>(&mUIGroundLayer);
    repeatTimer.start(2000);
    Boxy::Message(F("Information"), "started !");
  }

  void onRepeatTimer(void *, eva::CallbackInfo) {
    Boxy::Key(gSimulateUser[gSimulateUserIndex]);
    ++gSimulateUserIndex %= 4;
  }
};

void setup() {
  Serial.begin(9600);
  static App app;
}

void loop() {
  eva::tac();
}
