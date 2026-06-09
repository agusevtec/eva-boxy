#include <evabScreenPCD8544.h>
#include <evabFont8Bold.h>

                  // uint8_t aRST, uint8_t aCE, uint8_t aDC, 
                  // uint8_t aDIN, uint8_t aCLK,
                  // uint8_t aLED = 255);

void setup() {
static evab::Font8Bold font;
  static evab::ScreenPCD8544 screen(&font, 7, 6, 5, 4, 3);
  screen.TextCenter({0,0},{16,1},"abc", 0);
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
