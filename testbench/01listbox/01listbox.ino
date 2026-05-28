#include <evabListBox.h>
#include <evabInputInt.h>
#include <evaTac.h>
#include <evabBoxy.h>
#include <evabFont8Thin.h>

using namespace evab;

class App {
  ListBox<ScrollSlidingMethod> mTXSettingsListbox;
  InputIntField mTXListboxItem0 = { "4WD", 1 };
  InputIntField mTXListboxItem1 = { "LOCK", 45 };
  InputIntField mTXListboxItem2 = { "GEAR", 99 };
  ElementBase *mTXSettingsElemets[3] = { &mTXListboxItem0, &mTXListboxItem1, &mTXListboxItem2};

public:
  App() {
    UseSSH1106Screen<Font8Thin>();
    mTXSettingsListbox.SetItems(mTXSettingsElemets, 3);
    mTXSettingsListbox.SetItemHeight(3);
    Boxy::Instance()->Ground(&mTXSettingsListbox);
    mTXSettingsListbox.Select(1);
    mTXSettingsListbox.Select(2);
    //mTXSettingsListbox.SetReadOnly(true);
    mTXListboxItem2.SetValue(12);
  }
};

void setup() {
  Serial.begin(9600);
  static App app;
}

void loop() {
  eva::tac();
}
