#include <evabFont8Narrow.h>
#include <evabScreenSSD1306.h>

// #include <evabListBox.h>
// #include <evabInputFloat.h>
// #include <evaTac.h>
// #include <evabLabeled.h>
// #include <evabInputButton.h>
// #include <evabInputStretchbar.h>
// #include <evabInputTextStretchbar.h>
// #include <evabInputSelectorPicto.h>
// #include <evabInputTextStretchBar.h>
// #include <evabAlbums.h>
// #include <evabGalleryRemixicon16.h>

using namespace evab;

// class MyListbox : public ScrollListbox {
// public:
//   void drawer(Screen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override {
//     ScrollListbox::drawer(aScreen, { aPos.X, aPos.Y + 1 }, { aSize.X - 1, aSize.Y - 1 }, aIsFocused);
//     VerticalProgressBar pb(100 * (ScrollListbox::Selected()) / (ScrollListbox::Count() - 1));
//     pb.Draw(aScreen, { aPos.X + aSize.X - 1, aPos.Y + 1 }, { 1, aSize.Y - 1 }, 0);
//   }
// };

// class MyContainer : public LayoutPane {
//   InputPictoSelector<AlbumBattery> mBattery;
//   InputPictoSelector<AlbumSignal> mSignal;
//   KeyModifier<HorizontalScrollBar, KEY_DOWN, KEY_UP> test;
//   InputAnimation<AlbumRainbowmeter, 10> mFan = {1};

// public:
//   MyContainer() {
//     LayoutPane::focusChild(&test);
//   }

//   void drawer(Screen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override {
//     mBattery.Draw(aScreen, aPos, aSize, 0);
//     mSignal.Draw(aScreen, { aPos.X + aSize.X - 2, aPos.Y }, { 2, 1 }, 0);
//     test.Draw(aScreen, { aPos.X, 2 }, { aSize.X, 1 }, 0);
//     // test.Draw(aScreen, {4, aPos.Y}, {1, aSize.Y}, 0);
//     aScreen->Picto({aPos.X, 4}, picto_remixicon16_f110, 0);
//     mFan.Draw(aScreen, { aPos.X + 10, 4}, {3, 3}, 0);
//   }
//   void hider() override {
//     mBattery.Hide();
//     mSignal.Hide();
//     test.Hide();
//   }
// };

// class App : public eva::IHandler {
//   KeyModifier<Labeled<InputFloat>, KEY_LEFT, KEY_RIGHT> item0 = { "Speed", 13 };
//   Labeled<InputFloat> item1 = { "Course", 37 };
//   Labeled<InputFloat> item2 = { "Fuel", 95 };
//   ElementBase *items[3] = {
//     &item0,
//     &item1,
//     &item2
//   };
//   KeyModifier<MyListbox, KEY_UP, KEY_DOWN> mListbox;
//   MyContainer myContainer;
//   eva::RepeatTimer timer;

// public:
//   App() {
//     mListbox.SetItems(items, 3);
//     mListbox.SetItemHeight(2);
//     ScreenSSD1306<Font8Narrow> screen;

//     timer.start(500, this);
//   }

//   void invoke(void *, eva::CallbackInfo) {
//     Boxy::Key(KEY_UP);
//   }
// };

Font8Narrow font;
ScreenSSD1306 screen(&font);

void setup() {
}

void loop() {
}
