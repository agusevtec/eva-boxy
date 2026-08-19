#include <evaTac.h>
#include <evaRepeatTimer.h>

#include <evabBoxy.h>
#include <evabFont8Sharp.h>
#include <evabScreenSSD1306.h>

#include <evabListBox.h>
#include <evabInputInt.h>
#include <evabInputFloat.h>
#include <evabInputButton.h>
#include <evabCompositeBase.h>
#include <evabAlbums.h>
#include <evabLabeled.h>
#include <evabStretchBarPx.h>
#include <evabInputSelectorPx.h>
#include <evabStretchBar.h>
#include <evabGalleryRemixicon16.h>
#include <evabKeyModifier.h>
#include <evabPadding.h>
#include <evabPercent.h>

using namespace eva;
using namespace evab;

class CustomListbox : public Percent<ScrollListbox> {
public:
  using Percent<ScrollListbox>::Percent;

  void drawer(Screen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override {
    ScrollListbox::drawer(aScreen, { aPos.X + 1, aPos.Y }, { aSize.X - 3, aSize.Y }, aIsFocused);
    VerticalScrollBarPx pb(100 - GetPercent());
    pb.Draw(aScreen, { aPos.X + aSize.X - 1, aPos.Y }, { 1, aSize.Y }, 0);
  }
};

class GroundLayer : public CompositeBase {
  KeyModifier<LabeledLeftF<InputInt>, KEY_LEFT, KEY_RIGHT> item0;
  KeyModifier<LabeledLeftF<InputInt>, KEY_LEFT, KEY_RIGHT> item1;
  KeyModifier<LabeledLeftF<InputInt>, KEY_LEFT, KEY_RIGHT> item2;
  KeyModifier<LabeledLeftF<HorizontalProgressBarPx>, KEY_LEFT, KEY_RIGHT> item3;
  KeyModifier<LabeledLeftF<PaddingH<InputSelectorPx<AlbumProgress>>>, KEY_LEFT, KEY_RIGHT> item4;
  KeyModifier<LabeledLeftF<PaddingH<InputSelectorPx<AlbumSpeaker>>>, KEY_LEFT, KEY_RIGHT> item5;

  ElementBase *items[6] = { &item0, &item1, &item2, &item3, &item4, &item5 };
  KeyModifier<CustomListbox, KEY_UP, KEY_DOWN> mCustomListbox{ 2, items };

public:
  GroundLayer()
    : item0{ F("Speed"), 13 },
      item1{ F("Course"), 37 },
      item2{ F("Fuel"), 95 },
      item3{ F("Delay"), 30 },
      item4{ F("Light"), 3 },
      item5{ F("Sound"), 1 }

  {
    focusChild(&mCustomListbox);
  }

private:
  void drawer(Screen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override {
    aScreen->TextCenter(aPos, { aSize.X, 1 }, F("CUSTOM"), 0);
    aScreen->Clear({ aPos.X, aPos.Y + 1 }, { aSize.X, 1 });
    mCustomListbox.Draw(aScreen, { aPos.X, aPos.Y + 2 }, { aSize.X, aSize.Y - 2 }, aIsFocused);
  }

  void freezer() {
    mCustomListbox.Freeze();
  };
};

class App : public eva::IHandler {
  RepeatTimer mTimer;
  GroundLayer mGroundLayer;

  const unsigned char gSimulateUser[5] = { KEY_RIGHT, KEY_RIGHT, KEY_LEFT, KEY_LEFT, KEY_DOWN };
  unsigned char gSimulateUserIndex = 0;

public:
  App() {
    Boxy::Begin<ScreenSSD1306, Font8Sharp>(&mGroundLayer);
    mTimer.start(500, this);
  }

  void invoke(void *, CallbackInfo) {
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
