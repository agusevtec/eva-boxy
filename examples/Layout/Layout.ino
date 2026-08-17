#include <evabBoxy.h>
#include <evabScreenSSD1306.h>
#include <evabFont8Narrow.h>
#include <evabLayoutBase.h>
#include <evabKeyModifier.h>
#include <evabKeyCatcher.h>
#include <evabLabeled.h>
#include <evabInputInt.h>
#include <evabInputButton.h>
#include <evabBoxyRest.h>

// EVA Core | EVA Survival kit assumed to be a source of physical keys pressures
#include <evaTac.h>

using namespace eva;
using namespace evab;

// Declare form with vertical navigation (KEY_DOWN / KEY_UP)
class SystemSettingsForm : public KeyModifier<LayoutBase, KEY_UP, KEY_DOWN> {
  // [1] InputIntDiscrete bounded to KEY_LEFT / KEY_RIGHT
  Focusable<KeyModifier<LabeledLeftF<InputIntDiscrete>, KEY_LEFT, KEY_RIGHT>> mBrightness;
  // [2] Action Button bounded to KEY_LEFT / KEY_RIGHT
  Focusable<KeyCatcher<InputButtonF, KEY_LEFT, KEY_RIGHT>> mSaveButton;

  Handler<SystemSettingsForm> onSavePressedHandler{ this, &SystemSettingsForm::onSavePressed };
  void onSavePressed(void* sender, CallbackInfo info) {
    // Form submitted
  }

public:
  SystemSettingsForm()
    : mBrightness(this, F("Brightness"), 75, 0, 100, 5),
      mSaveButton(this, &onSavePressedHandler, F("Save")) {}

  void drawer(Screen* screen, Coor pos, Coor size, unsigned char isFocused) override {
    // Grid handles coordinate slicing and clears unallocated pixels automatically
    Grid rest(screen, pos, size, isFocused);

    rest.CutRow(1).TextCenter(F("System Settings"));
    rest.CutRow(1).Clear();  // Visual separator
    rest.CutRow(1).Draw(mBrightness, IsFocused(&mBrightness));
    rest.CutRow(1).Clear();  // Visual separator
    rest.CutRow(1).Draw(mSaveButton, IsFocused(&mSaveButton));
    rest.Clear();  // Clear remaining area
  }
};


// EVA Core | EVA Survical kit key source assumed
void onKeyPressed() {
  //    if ( ... ) {
  //        Boxy::Key(KEY_UP);
  //    }
  //    if ( ... ) {
  //        Boxy::Key(KEY_LEFT);
  //    }
  // ...
}

void setup() {
  // Root Ground Layout
  static SystemSettingsForm gMainForm;
  // Initialize display driver, font, and mount root layout layer
  Boxy::Begin<ScreenSSD1306, Font8Narrow>(&gMainForm);
}

void loop() {
  // Execute frame ticking & render pipeline
  eva::tac();
}
