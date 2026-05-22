#include <evabDebugPlatform.h>
#include <evabDisplayPlatform.h>
#include <evabListBox.h>
#include <evabGyver1306Platform.h>
#include <evabInputInt.h>
#include <evaTac.h>

using namespace evab;

class App {
  DebugPlatform p;
  ListBox mTXSettingsListbox = { 0, new ScrollSlidingMethod() };
  InputIntField mTXListboxItem0 = { "Dash size", 1 };
  InputIntField mTXListboxItem1 = { "Sets size ", 1 };
  ElementBase *mTXSettingsElemets[2] = { &mTXListboxItem0, &mTXListboxItem1 };
public:
  App() {
    DisplayPlatform::Instance(&p);
    mTXSettingsListbox.SetItems(mTXSettingsElemets, 2);
    DisplayPlatform::Instance()->Draw(&mTXSettingsListbox);
  }
};

void setup() {
  static App app;
}

void loop() {
  eva::tac();
}
