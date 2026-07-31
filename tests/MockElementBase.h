// Tests/MockElementBase.h
#pragma once

#include <evabElementBase.h>
#include <evabScreen.h>
#include <vector>
#include <tuple>

namespace evab
{
    class MockScreen : public Screen
    {
    public:
        Coor mSize;
        std::vector<std::pair<Coor, char>> mSymbols;
        std::vector<std::tuple<Coor, Coor, unsigned char>> mCleared;
        
        MockScreen(Coor size = {16, 8}) : mSize(size) {}
        
        void DrawSymbol(Coor aPos, Coor aSize, char aSymbol, unsigned char aColor) override
        {
            mSymbols.push_back({aPos, aSymbol});
        }
        
        void Picto(Coor aPos, const unsigned char *pictoData, unsigned char aColor) override {}
        
        void Clear(Coor aPos, Coor aSize, unsigned char aColor) override
        {
            mCleared.push_back({aPos, aSize, aColor});
        }
        
        Coor Size() override { return mSize; }
        
        unsigned short Serialize(const Coor &aPos, const Coor &aSize, bool isFocused) override { return 0; }
        void Deserialize(unsigned short aSerialized, Coor &aPos, Coor &aSize, bool &isFocused) override {}
        
        void clear()
        {
            mSymbols.clear();
            mCleared.clear();
        }
    };
    
    class MockElement : public ElementBase
    {
    public:
        const char* mId;
        bool mDrawCalled = false;
        Coor mLastPos;
        Coor mLastSize;
        unsigned char mLastFocused;
        
        MockElement(const char* id = "") : mId(id) {}
        
        void drawer(Screen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override
        {
            mDrawCalled = true;
            mLastPos = aPos;
            mLastSize = aSize;
            mLastFocused = aIsFocused;
            if (mId)
                aScreen->DrawSymbol(aPos, {1, 1}, mId[0], aIsFocused);
        }
        
        void freezer() override {}
        
        void reset()
        {
            mDrawCalled = false;
        }
    };
}