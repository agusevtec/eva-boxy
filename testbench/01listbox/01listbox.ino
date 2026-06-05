#include <evabListBox.h>
#include <evabInputFloat.h>
#include <evaTac.h>
#include <evabBoxy.h>
#include <evabLabeled.h>
#include <evabUIButton.h>
#include <evabBehaviour.h>
#include <evabProgressBar.h>
#include <evabCompositeBase.h>

#include <evabFont8Bold.h>
#include <evabScreenSSH1106.h>
#include <evaRepeatTimer.h>

using namespace evab;

class MyListbox : public ScrollListbox {
public:
  void drawer(IScreen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override {
    ScrollListbox::drawer(aScreen, aPos, { aSize.X - 1, aSize.Y }, aIsFocused);
    ProgressBarV pb(100 * (ScrollListbox::Selected() + 1) / ScrollListbox::Count());
    pb.Draw(aScreen, {aPos.X + aSize.X - 1, aPos.Y}, { 1, aSize.Y }, 0);
  }
};

class App: public eva::IHandler {
  KeyModifier<Labeled<InputFloat>, KEY_LEFT, KEY_RIGHT> item0 = { "Speed", 13 };
  Labeled<InputFloat> item1 = { "Course", 37 };
  Labeled<InputFloat> item2 = { "Fuel", 95 };
  ElementBase *items[3] = {
    &item0,
    &item1,
    &item2
  };
  KeyModifier<MyListbox, KEY_UP, KEY_DOWN> mListbox;

  eva::RepeatTimer timer;

public:
  App() {
    mListbox.SetItems(items, 3);
    mListbox.SetItemHeight(3);
    Boxy::Begin<ScreenSSH1106, Font8Bold>(&mListbox);
    timer.start(2000, this);
  }

  void invoke(void *, eva::CallbackInfo)
  {
    Boxy::Key(KEY_DOWN);
  }
};

void setup() {
  Serial.begin(9600);
  static App app;
  // Boxy::Key(KEY_RIGHT);
  // Boxy::Key(KEY_DOWN);
  // Boxy::Key(KEY_RIGHT);
  // Boxy::Key(KEY_DOWN);
  // Boxy::Key(KEY_UP);
  // Boxy::Key(KEY_UP);
  //    Boxy::ShowInt("Hi!", 5);
}

void loop() {
  eva::tac();
}
