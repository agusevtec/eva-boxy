#include <evabListBox.h>
#include <evabInputFloat.h>
#include <evaTac.h>
#include <evabBoxy.h>
#include <evabFont8Thin.h>
#include <evabLabeled.h>
#include <evabUIButton.h>
#include <evabBehaviour.h>
#include <evabProgressBar.h>

using namespace evab;

class App {
  KeyModifier<Labeled<InputFloat>, KEY_LEFT, KEY_RIGHT> item0 = {"Speed", 13};
  Labeled<InputFloat> item1 = {"Course", 37};
  Labeled<InputFloat> item2 = {"Fuel", 95};

  ElementBase *items[3] = { 
    &item0, 
    &item1, 
    &item2
    };
  KeyModifier<ListBox<ScrollSlidingMethod>, KEY_UP, KEY_DOWN>  mListbox;

// Теперь можно так:

public:
  App() {
    UseSSH1106Screen<Font8Thin>();
    mListbox.SetItems(items, 3);
    mListbox.SetItemHeight(3);
    ProgressBar pb(50);
    Boxy::Instance()->Ground(&mListbox);
    pb.Draw(Boxy::Instance()->Screen(), {14, 0}, {1,8}, 0);
    // Boxy::Instance()->Key(KEY_RIGHT);
    // Boxy::Instance()->Key(KEY_DOWN);
    // Boxy::Instance()->Key(KEY_RIGHT);
    // Boxy::Instance()->Key(KEY_DOWN);
    // Boxy::Instance()->Key(KEY_UP);
    // Boxy::Instance()->Key(KEY_UP);
    // Boxy::Instance()->ShowInt("Hi!", 5);
  }
};

void setup() {
  Serial.begin(9600);
  static App app;
}

void loop() {
  eva::tac();
}
