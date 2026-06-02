// SSH1106TiledScreen.cpp
#include "..\..\src\evabScreenSSH1106.h"
#include <Wire.h>

SSH1106Screen::SSH1106Screen()
    : _address(0x3C)
{
  Wire.begin();

  // инициализация дисплея (минимальный набор команд)
  sendCommand(0xAE); // display off

  sendCommand(0xD5); // clock divide
  sendCommand(0x80);

  sendCommand(0xA8); // multiplex
  sendCommand(0x3F); // 64 lines

  sendCommand(0xD3); // display offset
  sendCommand(0x00); // start line 0

  sendCommand(0x40);

  sendCommand(0x8D); // charge pump
  sendCommand(0x14); // enable

  sendCommand(0xA1); // segment remap (normal)
  sendCommand(0xC8); // COM scan direction (normal)

  sendCommand(0xDA); // COM pins
  sendCommand(0x12);

  sendCommand(0x81); // contrast
  sendCommand(0x7F);

  sendCommand(0xD9); // precharge
  sendCommand(0xF1);

  sendCommand(0xDB); // vcom detect
  sendCommand(0x40);

  sendCommand(0xA4); // resume to RAM content
  sendCommand(0xA6); // normal display

  clearDisplay();

  sendCommand(0xAF); // display on
}

void SSH1106Screen::DrawVerticalSlice(Coor aPosition, unsigned char aSliceColumn, unsigned char aSlice)
{
  // aPosition.X: 0-15 (16 тайлов по горизонтали)
  // aPosition.Y: 0-7 (8 тайлов по вертикали)
  // aSlice: байт для записи в этот тайл (8 пикселей вертикально)

  setPage(aPosition.Y);
  setColumn(aPosition.X * 8 + aSliceColumn + 1);

  Wire.beginTransmission(_address);
  Wire.write(0x40); // data mode
  Wire.write(aSlice);
  Wire.endTransmission();
}

void SSH1106Screen::sendCommand(unsigned char cmd)
{
  Wire.beginTransmission(_address);
  Wire.write(0x00); // command mode
  Wire.write(cmd);
  Wire.endTransmission();
}

void SSH1106Screen::setPage(unsigned char page)
{
  sendCommand(0xB0 | (page & 0x07)); // page 0-7
}

void SSH1106Screen::setColumn(unsigned char col)
{
  sendCommand(0x00 | (col & 0x0F));        // lower 4 bits
  sendCommand(0x10 | ((col >> 4) & 0x07)); // higher 3 bits
}

Coor SSH1106Screen::Size()
{
  return {16, 8};
}

void SSH1106Screen::ClearTile(Coor aPosition)
{
  setPage(aPosition.Y);
  setColumn(aPosition.X * 8 + 2);

  Wire.beginTransmission(_address);
  Wire.write(0x40); // data mode

  for (unsigned char col = 0; col < 16; col++)
  {
    Wire.write(0x00);
  }

  Wire.endTransmission();
}

void SSH1106Screen::clearDisplay()
{
  for (unsigned char page = 0; page < 8; page++)
  {
    for (unsigned char seg = 0; seg < 8; seg++)
    { // 16 сегментов по 8 пикселей = 128
      setPage(page);
      setColumn(seg * 16 + 2);

      Wire.beginTransmission(_address);
      Wire.write(0x40); // data mode

      for (unsigned char col = 0; col < 16; col++)
      {
        Wire.write(0x00);
      }

      Wire.endTransmission();
    }
  }
}
