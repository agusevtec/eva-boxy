#include <evaTac.h>
#include <evaHandler.h>
#include <evaRepeatTimer.h>

#include <evabBoxy.h>
#include <evabFont8Narrow.h>
#include <evabScreenSSD1306.h>

#include <evabGalleryRemixicon24.h>
#include <evabGalleryRemixicon32.h>

#include <evabReactions.h>
#include <evabLabeled.h>

#include <evabAlbums.h>
#include <evabInputInt.h>
#include <evabInputFloat.h>
#include <evabInputButtonPicto.h>
#include <evabInputButton.h>
#include <evabInputSelectorAlbum.h>
#include <evabInputStretchBar.h>

#include <evabLayoutBase.h>
#include <evabCompositeBase.h>
#include <evabGrid.h>

using namespace eva;
using namespace evab;

class UIHomeForm : public KeyModifier<LayoutBase, KEY_LEFT, KEY_RIGHT> {
  FocusChain<KeyCatcher<InputButtonPicto, KEY_ENTER>> mMonitorButton;
  FocusChain<KeyCatcher<InputButtonPicto, KEY_ENTER>> mSettingsButton;

public:
  UIHomeForm(IHandler *aOnMonitorHandler, IHandler *aOnSettingsHandler)
    : mMonitorButton(this, aOnMonitorHandler, GalleryRemixicon32::PICTO_F243),
      mSettingsButton(this, aOnSettingsHandler, GalleryRemixicon32::PICTO_F0E4) {
  }

private:
  void drawer(Screen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override {
    Grid grid(aScreen, aPos, aSize);
    grid.SliceRow(1).TextCenter(F("BOXY - DEMO"));
    grid.SliceRow(1).Clear();

    Grid row = grid.SliceRow(4);
    row.SliceCol(2).Clear();
    row.SliceCol(4).Draw(&mMonitorButton, aIsFocused && IsFocused(&mMonitorButton));
    row.SliceCol(4).Clear();
    row.SliceCol(4).Draw(&mSettingsButton, aIsFocused && IsFocused(&mSettingsButton));
    row.Rest().Clear();

    grid.SliceRow(1).Clear();
    grid.SliceRow(1).TextCenter(IsFocused(&mMonitorButton) ? F("CLIMAT") : F("SETTINGS"));
  }
};

class UIMonitoringForm : public ElementBase {
  IHandler *mLeaveHandler;

public:
  UIMonitoringForm(IHandler *aLeaveHandler)
    : mLeaveHandler(aLeaveHandler) {
  }

private:
  void drawer(Screen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override {
    LabeledLeftF<InputFloat> tempField(F("TEMERATURE"), 23);
    LabeledLeftF<InputInt> humField(F("HUMIDITY"), 41);

    Grid grid(aScreen, aPos, aSize);

    Grid row = grid.SliceRow(3);
    row.SliceCol(3).Picto(GalleryRemixicon24::PICTO_F1F2, 0);
    row.SliceCol(1).Clear();
    row.Rest().Draw(&tempField);

    grid.SliceRow(2).Clear();

    row = grid.SliceRow(3);
    row.SliceCol(3).Picto(GalleryRemixicon24::PICTO_EBD8, 0);
    row.SliceCol(1).Clear();
    row.Rest().Draw(&humField);

    grid.Rest().Clear();
  }

  bool OnKey(Keys aKey) override {
    if (mLeaveHandler)
      mLeaveHandler->invoke(this, { 0, 0 });
    return true;
  }
};

static const char ITEM1_TEXT[] PROGMEM = "Item 1";
static const char ITEM2_TEXT[] PROGMEM = "Item 2";
static const char ITEM3_TEXT[] PROGMEM = "Item 3";

class UISettingsForm : public KeyModifier<LayoutBase, KEY_UP, KEY_DOWN> {
  FocusChain<KeyModifier<LabeledLeftF<HorizontalScrollBar>, KEY_LEFT, KEY_RIGHT>> mItem1{ this, (const __FlashStringHelper *)ITEM1_TEXT };
  FocusChain<KeyModifier<LabeledLeftF<InputSelectorAlbum<AlbumOnOff>>, KEY_LEFT, KEY_RIGHT>> mItem2{ this, (const __FlashStringHelper *)ITEM2_TEXT };
  FocusChain<KeyModifier<LabeledLeftF<InputIntDiscrete>, KEY_LEFT, KEY_RIGHT>> mItem3{ this, (const __FlashStringHelper *)ITEM3_TEXT, 100, 11, 100, 200 };
  FocusChain<KeyCatcher<InputButton, KEY_RIGHT>> mSaveButton;

public:
  UISettingsForm(IHandler *aOnSettingsSaved)
    : mSaveButton(this, aOnSettingsSaved, F("SAVE")) {
  }

  void Reset() {
    focusChild(&mItem1);
  }

private:
  void drawer(Screen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override {
    Grid grid(aScreen, aPos, aSize);
    grid.SliceRow(1).Draw(&mItem1, aIsFocused && IsFocused(&mItem1));
    grid.SliceRow(1).Clear();
    grid.SliceRow(1).Draw(&mItem2, aIsFocused && IsFocused(&mItem2));
    grid.SliceRow(1).Clear();
    grid.SliceRow(1).Draw(&mItem3, aIsFocused && IsFocused(&mItem3));
    grid.SliceRow(1).Clear();
    grid.SliceRow(1).Draw(&mSaveButton, aIsFocused && IsFocused(&mSaveButton));
    grid.Rest().Clear();
  }
};

class UIGroundLayer : public CompositeBase {
  UIHomeForm mUIHome{ &onGotoMonitoringHandler, &onGotoSettingsHandler };
  UIMonitoringForm mUIMonitoring{ &onHomeHandler };
  UISettingsForm mUISettingsForm{ &onHomeHandler };

public:
  UIGroundLayer() {
    focusChild(&mUIHome);
  }

private:
  Handler<UIGroundLayer> onGotoMonitoringHandler{ this, &UIGroundLayer::onGotoMonitoring };
  void onGotoMonitoring(void *aSender, CallbackInfo aCallbackInfo) {
    focusChild(&mUIMonitoring);
  }

  Handler<UIGroundLayer> onGotoSettingsHandler{ this, &UIGroundLayer::onGotoSettings };
  void onGotoSettings(void *aSender, CallbackInfo aCallbackInfo) {
    mUISettingsForm.Reset();
    focusChild(&mUISettingsForm);
  }

  Handler<UIGroundLayer> onHomeHandler{ this, &onBackHome };
  void onBackHome(void *aSender, CallbackInfo aCallbackInfo) {
    focusChild(&mUIHome);
  }

  void drawer(Screen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override {
    if (IsFocused(&mUIHome))
      mUIHome.Draw(aScreen, aPos, aSize, aIsFocused);
    else
      mUIHome.Mute();

    if (IsFocused(&mUIMonitoring))
      mUIMonitoring.Draw(aScreen, aPos, aSize, aIsFocused);
    else
      mUIMonitoring.Mute();
    if (IsFocused(&mUISettingsForm))
      mUISettingsForm.Draw(aScreen, aPos, aSize, aIsFocused);
    else
      mUISettingsForm.Mute();
  }

  void muter() override {
    mUIHome.Mute();
    mUIMonitoring.Mute();
    mUISettingsForm.Mute();
  }
};

// const unsigned char gSimulateUser[4] = { KEY_RIGHT, KEY_RIGHT, KEY_RIGHT, KEY_RIGHT };
const unsigned char gSimulateUser[14] = { KEY_RIGHT, KEY_LEFT, KEY_ENTER, KEY_ENTER, KEY_RIGHT, KEY_ENTER, KEY_RIGHT, KEY_DOWN, KEY_RIGHT, KEY_DOWN, KEY_RIGHT, KEY_DOWN, KEY_ENTER, KEY_LEFT };
unsigned char gSimulateUserIndex = 0;

class App {
  RepeatTimer repeatTimer{ new Handler<App>(this, &onRepeatTimer) };
  UIGroundLayer mUIGroundLayer;
  // UISettingsForm mUIGroundLayer{ nullptr };

public:
  App() {
    Boxy::Begin<ScreenSSD1306, Font8Narrow>(&mUIGroundLayer);
    repeatTimer.start(2000);
    // Boxy::Message(F("Information"), "started !");
  }

  void onRepeatTimer(void *, CallbackInfo) {
    Boxy::Key(gSimulateUser[gSimulateUserIndex]);
    ++gSimulateUserIndex %= 14;
  }
};

void setup() {
  Serial.begin(9600);
  static App app;
}

void loop() {
  eva::tac();
}
