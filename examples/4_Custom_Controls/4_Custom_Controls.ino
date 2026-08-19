#include <evabBoxy.h>
#include <evabCompositeBase.h>
#include <evabFont8Sharp.h>
#include <evabScreenSSD1306.h>

#include <evabInputInt.h>
#include <evabGrid.h>

using namespace evab;

template<typename TControl>
class LabeledUnitAlarm : public ElementBase {
private:
  TControl mControl;
  const __FlashStringHelper* mLabel;
  const __FlashStringHelper* mUnit;
  int mThreshold;

public:
  template<typename... Args>
  LabeledUnitAlarm(const __FlashStringHelper* aLabel, const __FlashStringHelper* aUnit, int aThreshold, Args&&... aArgs)
    : mControl(static_cast<Args&&>(aArgs)...), mLabel(aLabel), mUnit(aUnit), mThreshold(aThreshold) {}

  TControl& GetControl() {
    return mControl;
  }

  void drawer(Screen* aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override {
    int x = aPos.X;

    // 1. Conditional status indicator based on value threshold
    if (mControl.GetValue() > mThreshold) {
      aScreen->TextLeft({ x, aPos.Y }, { 1, 1 }, F("!"), aIsFocused);
    } else {
      aScreen->TextLeft({ x, aPos.Y }, { 1, 1 }, F(" "), 0);
    }
    x += 1;

    // 2. Render label
    aScreen->TextLeft({ x, aPos.Y }, { 6, 1 }, mLabel, 0);
    x += 6;

    // 3. Delegate rendering to inner control with narrowed bounding box
    int controlWidth = aSize.X - 10;
    mControl.Draw(aScreen, { x, aPos.Y }, { controlWidth, aSize.Y }, aIsFocused);
    x += controlWidth;

    // 4. Render units
    aScreen->TextLeft({ x, aPos.Y }, { 3, 1 }, mUnit, 0);
  }
};


class Form1 : public CompositeBase {
  LabeledUnitAlarm<InputInt> mCustomControl1;

public:
  Form1()
    : mCustomControl1(F("Humidity"), F("%"), 100, 123) {
    focusChild(&mCustomControl1);
  }

  void drawer(Screen* aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override {
    Grid rest(aScreen, aPos, aSize, aIsFocused);
    rest.CutRow(1).TextCenter(F("Custom control"));
    rest.CutRow(1).Clear();
    rest.CutRow(1).Draw(mCustomControl1);
    rest.Clear();
  }

  void freezer() override {
    mCustomControl1.Freeze();
  }
} ;

void setup() {
  static Form1 form1;
  
    Boxy::Begin<ScreenSSD1306, Font8Sharp>(&form1);

}

void loop() {

}
