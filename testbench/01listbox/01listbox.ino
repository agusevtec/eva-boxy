#include <evabListBox.h>
#include <evabInputInt.h>
#include <evaTac.h>
#include <evabBoxy.h>
#include <evabFont8Thin.h>

using namespace evab;

class App {
  ListBox<ScrollSlidingMethod> mTXSettingsListbox = { 0 };
  InputIntField mTXListboxItem0 = { "Dash size", 1 };
  InputIntField mTXListboxItem1 = { "Sets size ", 1 };
  ElementBase *mTXSettingsElemets[2] = { &mTXListboxItem0, &mTXListboxItem1 };
public:
  App() {
    UseSSH1106Screen<Font8Thin>();
    mTXSettingsListbox.SetItems(mTXSettingsElemets, 2);
    Boxy::Instance()->Ground(&mTXSettingsListbox);
  }
};

void setup() {
  static App app;
}

void loop() {
  eva::tac();
}
