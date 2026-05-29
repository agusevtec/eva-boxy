#include <evabListBox.h>
#include <evabInputFloat.h>
#include <evaTac.h>
#include <evabBoxy.h>
#include <evabFont8Thin.h>
#include <evabLabeled.h>
#include <evabUIButton.h>

using namespace evab;

class App {
  ListBox<ScrollSlidingMethod> mTXSettingsListbox;
  Labeled<InputFloat> mTXListboxItem0 = { "Value:", 4 };
  // InputInt mTXListboxItem1 = { "LOCK", 45 };
  // InputInt mTXListboxItem2 = { "GEAR", 99 };

  // ElementBase *mTXSettingsElemets[3] = { &mTXListboxItem0, &mTXListboxItem1, &mTXListboxItem2};

// Теперь можно так:

public:
  App() {
    UseSSH1106Screen<Font8Thin>();
    // mTXSettingsListbox.SetItems(mTXSettingsElemets, 3);
    // mTXSettingsListbox.SetItemHeight(3);
    Boxy::Instance()->Ground(&mTXListboxItem0);
    mTXListboxItem0.Increment(1);
    // mTXSettingsListbox.Select(1);
    // mTXSettingsListbox.Select(2);
    //mTXSettingsListbox.SetReadOnly(true);
    //mTXListboxItem2.SetValue(12);
  }
};

void setup() {
  Serial.begin(9600);
  static App app;
}

void loop() {
  eva::tac();
}
