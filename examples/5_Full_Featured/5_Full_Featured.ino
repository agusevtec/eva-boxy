#include <evaTac.h>
#include <evaHandler.h>
#include <evaRepeatTimer.h>

#include <evabBoxy.h>
#include <evabFont8Sharp.h>
#include <evabScreenSSD1306.h>

#include <evabGalleryRemixicon24.h>
#include <evabGalleryRemixicon32.h>

#include <evabKeyCatcher.h>
#include <evabKeyModifier.h>
#include <evabTitled.h>

#include <evabAlbums.h>
#include <evabInputInt.h>
#include <evabInputFloat.h>
#include <evabInputButtonPx.h>
#include <evabInputButton.h>
#include <evabInputSelectorPx.h>
#include <evabStretchBarPx.h>

#include <evabLayoutBase.h>
#include <evabCompositeBase.h>
#include <evabGrid.h>

using namespace eva;
using namespace evab;

class UIHomeForm : public KeyModifier<LayoutBase, KEY_LEFT, KEY_RIGHT>
{
  Focusable<KeyCatcher<InputButtonPx, KEY_ENTER>> mMonitorButton;
  Focusable<KeyCatcher<InputButtonPx, KEY_ENTER>> mSettingsButton;

public:
  UIHomeForm(IHandler *aOnMonitorHandler, IHandler *aOnSettingsHandler)
      : mMonitorButton(this, aOnMonitorHandler, GalleryRemixicon32::PICTO_F243),
        mSettingsButton(this, aOnSettingsHandler, GalleryRemixicon32::PICTO_F0E4)
  {
  }

private:
  void drawer(Screen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override
  {
    Grid rest(aScreen, aPos, aSize, aIsFocused);
    rest.CutRow(1).TextCenter(F("BOXY - DEMO"));
    rest.CutRow(1).Clear();

    Grid row = rest.CutRow(4);
    row.CutCol(2).Clear();
    row.CutCol(4).Draw(mMonitorButton,  IsFocused(&mMonitorButton));
    row.CutCol(4).Clear();
    row.CutCol(4).Draw(mSettingsButton, IsFocused(&mSettingsButton));
    row.Clear();

    rest.CutRow(1).Clear();
    rest.CutRow(1).TextCenter(IsFocused(&mMonitorButton) ? F("CLIMAT") : F("SETTINGS"));
  }
};

class UIMonitoringForm : public ElementBase
{
  IHandler *mLeaveHandler;

public:
  UIMonitoringForm(IHandler *aLeaveHandler)
      : mLeaveHandler(aLeaveHandler)
  {
  }

private:
  void drawer(Screen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override
  {
    TitledLeftF<InputFloat> tempField(F("TEMERATURE"), 23);
    TitledLeftF<InputInt> humField(F("HUMIDITY"), 41);

    Grid rest(aScreen, aPos, aSize, 0);

    Grid row = rest.CutRow(3);
    row.CutCol(3).Picto(GalleryRemixicon24::PICTO_F1F2, 0);
    row.CutCol(1).Clear();
    row.Draw(tempField);

    rest.CutRow(2).Clear();

    row = rest.CutRow(3);
    row.CutCol(3).Picto(GalleryRemixicon24::PICTO_EBD8, 0);
    row.CutCol(1).Clear();
    row.Draw(humField);

    rest.Clear();
  }

  bool OnKey(Keys aKey) override
  {
    if (mLeaveHandler)
      mLeaveHandler->invoke(this, {0, 0});
    return true;
  }
};

static const char ITEM1_TEXT[] PROGMEM = "Item 1";
static const char ITEM2_TEXT[] PROGMEM = "Item 2";
static const char ITEM3_TEXT[] PROGMEM = "Item 3";

class UISettingsForm : public KeyModifier<LayoutBase, KEY_UP, KEY_DOWN>
{
  Focusable<KeyModifier<TitledLeftF<HorizontalScrollBarPx>, KEY_LEFT, KEY_RIGHT>> mItem1{this, (const __FlashStringHelper *)ITEM1_TEXT};
  Focusable<KeyModifier<TitledLeftF<InputSelectorPx<AlbumOnOff>>, KEY_LEFT, KEY_RIGHT>> mItem2{this, (const __FlashStringHelper *)ITEM2_TEXT};
  Focusable<KeyModifier<TitledLeftF<InputIntDiscrete>, KEY_LEFT, KEY_RIGHT>> mItem3{this, (const __FlashStringHelper *)ITEM3_TEXT, 100, 100, 200, 10};
  Focusable<KeyCatcher<InputButtonF, KEY_RIGHT>> mSaveButton;

public:
  UISettingsForm(IHandler *aOnSettingsSaved)
      : mSaveButton(this, aOnSettingsSaved, F("SAVE"))
  {
  }

  void Reset()
  {
    focusChild(&mItem1);
  }

private:
  void drawer(Screen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override
  {
    Grid rest(aScreen, aPos, aSize, aIsFocused);
    rest.CutRow(1).Draw(mItem1,  IsFocused(&mItem1));
    rest.CutRow(1).Clear();
    rest.CutRow(1).Draw(mItem2,  IsFocused(&mItem2));
    rest.CutRow(1).Clear();
    rest.CutRow(1).Draw(mItem3,  IsFocused(&mItem3));
    rest.CutRow(1).Clear();
    rest.CutRow(1).Draw(mSaveButton,  IsFocused(&mSaveButton));
    rest.Clear();
  }
};

class UIGroundLayer : public CompositeBase
{
  UIHomeForm mUIHome{&onGotoMonitoringHandler, &onGotoSettingsHandler};
  UIMonitoringForm mUIMonitoring{&onHomeHandler};
  UISettingsForm mUISettingsForm{&onHomeHandler};

public:
  UIGroundLayer()
  {
    focusChild(&mUIHome);
  }

private:
  Handler<UIGroundLayer> onGotoMonitoringHandler{this, &UIGroundLayer::onGotoMonitoring};
  void onGotoMonitoring(void *aSender, CallbackInfo aCallbackInfo)
  {
    focusChild(&mUIMonitoring);
  }

  Handler<UIGroundLayer> onGotoSettingsHandler{this, &UIGroundLayer::onGotoSettings};
  void onGotoSettings(void *aSender, CallbackInfo aCallbackInfo)
  {
    mUISettingsForm.Reset();
    focusChild(&mUISettingsForm);
  }

  Handler<UIGroundLayer> onHomeHandler{this, &onBackHome};
  void onBackHome(void *aSender, CallbackInfo aCallbackInfo)
  {
    focusChild(&mUIHome);
  }

  void drawer(Screen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override
  {
    if (IsFocused(&mUIHome))
      mUIHome.Draw(aScreen, aPos, aSize, aIsFocused);

    if (IsFocused(&mUIMonitoring))
      mUIMonitoring.Draw(aScreen, aPos, aSize, aIsFocused);

    if (IsFocused(&mUISettingsForm))
      mUISettingsForm.Draw(aScreen, aPos, aSize, aIsFocused);
  }

  void freezer() override
  {
    mUIHome.Freeze();
    mUIMonitoring.Freeze();
    mUISettingsForm.Freeze();
  }
};

const unsigned char gSimulateUser[14] = {KEY_RIGHT, KEY_LEFT, KEY_ENTER, KEY_ENTER, KEY_RIGHT, KEY_ENTER, KEY_RIGHT, KEY_DOWN, KEY_RIGHT, KEY_DOWN, KEY_RIGHT, KEY_DOWN, KEY_ENTER, KEY_LEFT};
unsigned char gSimulateUserIndex = 0;

class App
{
  RepeatTimer repeatTimer{new Handler<App>(this, &onRepeatTimer)};
  UIGroundLayer mUIGroundLayer;
  // UISettingsForm mUIGroundLayer{ nullptr };

public:
  App()
  {
    Boxy::Begin<ScreenSSD1306, Font8Sharp>(&mUIGroundLayer);
    repeatTimer.start(2000);
    // Boxy::Message(F("Information"), "started !");
  }

  void onRepeatTimer(void *, CallbackInfo)
  {
    Boxy::Key(gSimulateUser[gSimulateUserIndex]);
    ++gSimulateUserIndex %= 14;
  }
};

void setup()
{
  Serial.begin(9600);
  static App app;
}

void loop()
{
  eva::tac();
}
