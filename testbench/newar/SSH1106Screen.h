// SSH1106_128x64.h
#pragma once

#include "Coor.h"
#include "..\..\src\evabFont8Narrow.h"
#include "..\..\src\evabFont8Compact.h"
#include "..\..\src\evabFont8Bold.h"
#include "..\..\src\evabScreenPage8Base.h"


class SSH1106Screen : public Page8ScreenBase<Font8Narrow>
{
public:
    SSH1106Screen();
    void clearDisplay();

protected:
    void DrawVerticalSlice(Coor aPosition, unsigned char aSliceColumn, unsigned char aSlice) override;
    void ClearTile(Coor aPosition) override;
    Coor Size() override;

private:
    void sendCommand(unsigned char cmd);
    void sendData(unsigned char data);
    void setPage(unsigned char page);
    void setColumn(unsigned char col);

    uint8_t _address;
};
