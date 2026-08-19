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

using namespace eva;
using namespace evab;

class GroundLayer : public CompositeBase {
  KeyModifier<LabeledLeftF<InputInt>, KEY_LEFT, KEY_RIGHT> item0;
  KeyModifier<LabeledLeftF<InputInt>, KEY_LEFT, KEY_RIGHT> item1;
  KeyModifier<LabeledLeftF<InputInt>, KEY_LEFT, KEY_RIGHT> item2;
  KeyModifier<LabeledLeftF<HorizontalProgressBarPx>, KEY_LEFT, KEY_RIGHT> item3;
  KeyModifier<LabeledLeftF<PaddingH<InputSelectorPx<AlbumProgress>>>, KEY_LEFT, KEY_RIGHT> item4;
  KeyModifier<LabeledLeftF<PaddingH<InputSelectorPx<AlbumSpeaker>>>, KEY_LEFT, KEY_RIGHT> item5;

  ElementBase *items[6] = { &item0, &item1, &item2, &item3, &item4, &item5 };
  KeyModifier<ScrollListbox, KEY_UP, KEY_DOWN> mSimpleListbox{ 2, items };

public:
  GroundLayer()
    : item0{ F("Speed"), 13 },
      item1{ F("Course"), 37 },
      item2{ F("Fuel"), 95 },
      item3{ F("Delay"), 30 },
      item4{ F("Light"), 3 },
      item5{ F("Sound"), 1 }

  {
    focusChild(&mSimpleListbox);
  }

private:
  void drawer(Screen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override {
    aScreen->TextCenter(aPos, { aSize.X, 1 }, F("STANDART"), 0);
    aScreen->Clear({ aPos.X, aPos.Y + 1 }, { aSize.X, 1 });
    mSimpleListbox.Draw(aScreen, { aPos.X, aPos.Y + 2 }, { aSize.X, aSize.Y - 2 }, aIsFocused);
  }

  void freezer() {
    mSimpleListbox.Freeze();
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
  static App app;
}

void loop() {
  eva::tac();
}
