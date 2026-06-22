#include <evabListBox.h>
#include <evabInputFloat.h>
#include <evaTac.h>
#include <evabBoxy.h>
#include <evabLabeled.h>
#include <evabInputButton.h>
#include <evabBehavior.h>
#include <evabCompositeBase.h>
#include <evabFont8Thin.h>
#include <evabScreenSSD1306.h>
#include <evaRepeatTimer.h>
#include <evabInputStretchbar.h>
#include <evabInputPictogram.h>
#include <evabInputTextStretchBar.h>
#include <evabTilesets.h>

using namespace evab;

class MyListbox : public ScrollListbox {
public:
  void drawer(IScreen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override {
    ScrollListbox::drawer(aScreen, { aPos.X, aPos.Y + 1 }, { aSize.X - 1, aSize.Y - 1 }, aIsFocused);
    VerticalProgressBar pb(100 * (ScrollListbox::Selected()) / (ScrollListbox::Count() - 1));
    pb.Draw(aScreen, { aPos.X + aSize.X - 1, aPos.Y + 1 }, { 1, aSize.Y - 1 }, 0);
  }
};

class MyContainer : public CompositeBase {
  InputPictogram<TilesetBattery> mBattery;
  InputPictogram<TilesetSignal> mSignal;
  KeyModifier<HorizontalScrollBar, KEY_DOWN, KEY_UP> test;

public:
  MyContainer() {
    CompositeBase::focusChild(&test);
  }

  void drawer(IScreen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override {
    mBattery.Draw(aScreen, aPos, aSize, 0);
    mSignal.Draw(aScreen, { aPos.X + aSize.X - 2, aPos.Y }, { 2, 1 }, 0);
    test.Draw(aScreen, { aPos.X, 4 }, { aSize.X, 1 }, 0);
    // test.Draw(aScreen, {4, aPos.Y}, {1, aSize.Y}, 0);
  }
  void hider() override {
    mBattery.Hide();
    mSignal.Hide();
    test.Hide();
  }
};

class App : public eva::IHandler {
  KeyModifier<Labeled<InputFloat>, KEY_LEFT, KEY_RIGHT> item0 = { "Speed", 13 };
  Labeled<InputFloat> item1 = { "Course", 37 };
  Labeled<InputFloat> item2 = { "Fuel", 95 };
  ElementBase *items[3] = {
    &item0,
    &item1,
    &item2
  };
  KeyModifier<MyListbox, KEY_UP, KEY_DOWN> mListbox;
  MyContainer myContainer;
  eva::RepeatTimer timer;

public:
  App() {
    mListbox.SetItems(items, 3);
    mListbox.SetItemHeight(2);
    Boxy::Begin<ScreenSSD1306, Font8Thin>(&myContainer);
    timer.start(500, this);
  }

  void invoke(void *, eva::CallbackInfo) {
    Boxy::Key(KEY_UP);
  }
};

void setup() {
  Serial.begin(9600);
  static App app;
}

void loop() {
  eva::tac();
}
