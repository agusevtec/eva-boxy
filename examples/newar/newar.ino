#include "ScreenBase.h"
#include "Page8ScreenBase.h"
#include "SSH1106Screen.h"
#include "Font8Compact.h"

class SlicerStub : public ScreenBase
{
    char mScreen[8][16];

public:
    SlicerStub()
    {
        for (int i = 0; i < 8; i++)
            strcpy(mScreen[i], "***************");
    }
    virtual void DrawSymbol(Coor aPosition, Coor aSize, char aSymbol, unsigned char aColor) override
    {
        mScreen[aPosition.Y][aPosition.X] = aSymbol;
    };

    virtual void Picto(Coor aPosition, Coor aSize, uint8_t aPictoIndex, unsigned char aColor) {
    };

    void Show()
    {
        for (int j = 0; j < 8; j++)
            Serial.println(mScreen[j]);
    }
    Coor Size()
    {
        return {15, 7};
    }
};

class DisplayStub : public Page8ScreenBase<Font8Bold>
{
    char mTile[24][25];

public:
    DisplayStub()
    {
        for (int i = 0; i < 24; i++)
            strcpy(mTile[i], "                        ");
    }
    void DrawVerticalSlice(Coor aPosition, unsigned char aColumn, unsigned char aSlice) override
    {
        for (int i = 0; i < 8; i++)
            if (aSlice & (1 << i))
                mTile[8 * aPosition.Y + i][8 * aPosition.X + aColumn] = 'x';
    };

    void Show()
    {
        Serial.println(" ------------------------");
        for (int j = 0; j < 24; j++)
        {
            Serial.print("|");
            Serial.print(mTile[j]);
            Serial.println("|");
        }
        Serial.println(" ------------------------");
    }
    Coor Size()
    {
        return {3, 3};
    }
};


void setup()
{
    // Serial.begin(9600);
    // SlicerStub stub;
    // stub.TextCenter({ 1, 0 }, { 13, 1 }, "hello", 1);
    // stub.TextRight({ 1, 1 }, { 13, 1 }, "hello", 1);
    // stub.Show();

    // DisplayStub ds;
    // ds.TextRight({0,0},{3,2}, "a", 1);
    // ds.TextLeft({0, 1}, {3, 1}, "def", 1);
    // ds.TextLeft({0, 2}, {3, 1}, "jhk", 1);
    // ds.DrawSymbol({0,0}, {3,3}, 'W', 1);
    // ds.DrawVerticalSlice({0,0}, 1, 0xff);
    // ds.DrawVerticalSlice({0,0}, 2, 0x04);
    // ds.DrawVerticalSlice({0,0}, 3, 0xff);
    // ds.Show();

    static SSH1106Screen displ;
    // for (int i = 0; i < 8; i++)
    //   displ.TextLeft({ 0, i }, { 16, 1 }, "MMMMMMMMMMMMMMMM", 1);
    //displ.clearDisplay();

    displ.TextCenter({0, 0}, {16, 1}, F("Dashboard"), 1);
    displ.TextCenter({0, 2}, {10, 1}, F("R.P.M."), 1);
    displ.TextCenter({10, 2}, {6, 2}, F("1.7"), 1);
    displ.TextCenter({0, 4}, {10, 1}, F("SPEED"), 1);
    displ.TextCenter({10, 4}, {6, 2}, F("127"), 1);
    displ.TextCenter({0, 6}, {10, 1}, F("TEMP"), 1);
    displ.TextCenter({10, 6}, {6, 2}, F("32"), 1);

    delay(1000);
    displ.TextCenter({10, 2}, {6, 2}, F("2.3"), 1);
    delay(1000);
    displ.TextCenter({10, 2}, {6, 2}, F("5.5"), 1);
    delay(1000);
    displ.TextCenter({10, 2}, {6, 2}, F("4.1"), 1);
    delay(1000);
    displ.TextCenter({10, 2}, {6, 2}, F("3.8"), 1);
    delay(1000);
    displ.TextCenter({10, 2}, {6, 2}, F("4.4"), 1);
    delay(1000);
}

void loop()
{
}