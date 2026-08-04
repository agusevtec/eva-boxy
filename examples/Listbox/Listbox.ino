#include <evabListBox.h>
#include <evabInputFloat.h>
#include <evaTac.h>
#include <evabBoxy.h>
#include <evabLabeled.h>
#include <evabInputButton.h>
#include <evabReactions.h>
#include <evabCompositeBase.h>
#include <evabFont8Narrow.h>
#include <evabScreenSSD1306.h>
#include <evaRepeatTimer.h>
#include <evabInputStretchbar.h>
#include <evabInputTextStretchbar.h>
#include <evabInputSelectorAlbum.h>
#include <evabInputTextStretchBar.h>
#include <evabAlbums.h>
#include <evabGalleryRemixicon16.h>
#include <evabInputAnimation.h>
#include <evabPercent.h>
#include <evabPadding.h>

using namespace eva;
using namespace evab;


template <class T, typename TAlign, typename TText>
class CustomLabeled : public T
{
private:
  TText mName;

public:
  template <typename... Args>
  CustomLabeled(TText aName, Args &&...args)
      : T(args...), mName(aName)
  {
  }

protected:
  void drawer(Screen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override
  {
    unsigned char labelWidth = 2 * aSize.X / 3;
    unsigned char inputWidth = aSize.X - labelWidth;
    aScreen->Text<TAlign>(aPos, {labelWidth, 1}, mName, aIsFocused);
    aScreen->Clear({aPos.X, aPos.Y + 1}, {labelWidth, aSize.Y - 1}, aIsFocused);
    T::drawer(aScreen, {aPos.X + labelWidth, aPos.Y}, {inputWidth, aSize.Y}, aIsFocused);
  }
};

template <class TT>
using CustomLabeledLeftF = CustomLabeled<TT, LeftAlign, const __FlashStringHelper *>;

class CustomListbox : public Percent<ScrollListbox>
{
public:
  using Percent<ScrollListbox>::Percent;

  void drawer(Screen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override
  {
    ScrollListbox::drawer(aScreen, {aPos.X + 1, aPos.Y}, {aSize.X - 3, aSize.Y}, aIsFocused);
    VerticalScrollBar pb(100 - GetPercent());
    pb.Draw(aScreen, {aPos.X + aSize.X - 1, aPos.Y}, {1, aSize.Y}, 0);
  }
};

class GroundLayer : public CompositeBase
{
  KeyModifier<CustomLabeledLeftF<InputInt>, KEY_LEFT, KEY_RIGHT> item0;
  KeyModifier<CustomLabeledLeftF<InputInt>, KEY_LEFT, KEY_RIGHT> item1;
  KeyModifier<CustomLabeledLeftF<InputInt>, KEY_LEFT, KEY_RIGHT> item2;
  KeyModifier<CustomLabeledLeftF<HorizontalProgressBar>, KEY_LEFT, KEY_RIGHT> item3;
  KeyModifier<CustomLabeledLeftF<PaddingH<InputSelectorAlbum<AlbumProgress>>>, KEY_LEFT, KEY_RIGHT> item4;
  KeyModifier<CustomLabeledLeftF<PaddingH<InputSelectorAlbum<AlbumSpeaker>>>, KEY_LEFT, KEY_RIGHT> item5;

  ElementBase *items[6] = {&item0, &item1, &item2, &item3, &item4, &item5};
  KeyModifier<ScrollListbox, KEY_UP, KEY_DOWN> mSimpleListbox{2, items};
  KeyModifier<CustomListbox, KEY_UP, KEY_DOWN> mCustomListbox{2, items};

public:
  GroundLayer()
      : item0{F("Speed"), 13},
        item1{F("Course"), 37},
        item2{F("Fuel"), 95},
        item3{F("Delay"), 30},
        item4{F("Light"), 3},
        item5{F("Sound"), 1}

  {
    focusChild(&mSimpleListbox);
//    focusChild(&mCustomListbox);
  }

private:
  void drawer(Screen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override
  {
    if (IsFocused(&mSimpleListbox))
    {
      aScreen->TextCenter(aPos, {aSize.X, 1}, F("STANDART"), 0);
      mSimpleListbox.Draw(aScreen, {aPos.X, aPos.Y + 2}, {aSize.X, aSize.Y - 2}, aIsFocused);
    }
    if (IsFocused(&mCustomListbox))
    {
      aScreen->TextCenter(aPos, {aSize.X, 1}, F("CUSTOM"), 0);
      mCustomListbox.Draw(aScreen, {aPos.X, aPos.Y + 2}, {aSize.X, aSize.Y - 2}, aIsFocused);
    }
  }

  void freezer()
  {
    mSimpleListbox.Freeze();
    mCustomListbox.Freeze();
  };
};

class App : public eva::IHandler
{
  RepeatTimer mTimer;
  GroundLayer mGroundLayer;

const unsigned char gSimulateUser[5] = { KEY_RIGHT, KEY_RIGHT, KEY_LEFT, KEY_LEFT, KEY_DOWN};
unsigned char gSimulateUserIndex = 0;

public:
  App()
  {
    Boxy::Begin<ScreenSSD1306, Font8Narrow>(&mGroundLayer);
    mTimer.start(500, this);
  }

  void invoke(void *, CallbackInfo)
  {
    Boxy::Key(gSimulateUser[gSimulateUserIndex]);
    ++gSimulateUserIndex %= 5;
  }
};

void setup()
{
  Serial.begin(9600);
  static App app;
}

void loop()
{
  eva::tac();
}
