#include <evabElementBase.h>
#include <evabBoxy.h>
namespace evab
{

  void ElementBase::Redraw()
  {
    if (IsHidden())
      return;

    IScreen *screen = Boxy::Instance()->Screen();
    if (screen)
    {
      Coor pos, sz;
      bool focused;
      deserialize(pos, sz, focused);
      drawer(screen, pos, sz, focused);
    }
  }

  bool ElementBase::IsHidden()
  {
    return !((serialized >> 0) & 1);
  }

  void ElementBase::Hide()
  {
    hider();
    serialized = 0;
  }

  void ElementBase::Draw(IScreen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused)
  {
    if (!aScreen)
      return;

    if (aSize.X == 0 || aSize.Y == 0)
    {
      hider();
      return;
    }
    drawer(aScreen, aPos, aSize, aIsFocused);
    serialize(aPos, aSize, aIsFocused);
  }

  bool ElementBase::Key(char aKey)
  {
    return false;
  }

  void ElementBase::serialize(const Coor &aPos, const Coor &aSize, bool isFocused)
  {
    serialized = 0;

    // Бит 0: isVisible
    if (aSize.X > 0 || aSize.Y > 0)
      serialized |= (1 << 0);

    // Бит 1: isFocused
    if (isFocused)
      serialized |= (1 << 1);

    // Биты 2-5: aPos.X (0..15) - 4 бита
    serialized |= ((aPos.X & 0x0F) << 2);

    // Биты 6-8: aPos.Y (0..7) - 3 бита
    serialized |= ((aPos.Y & 0x07) << 6);

    // Биты 9-12: aSize.X (1..16) -> храним как (value-1) для 0..15 - 4 бита
    serialized |= (((aSize.X - 1) & 0x0F) << 9);

    // Биты 13-15: aSize.Y (1..8) -> храним как (value-1) для 0..7 - 3 бита
    serialized |= (((aSize.Y - 1) & 0x07) << 13);
  }

  // Десериализация: распаковка из unsigned short
  void ElementBase::deserialize(Coor &aPos, Coor &aSize, bool &isFocused)
  {
    // Бит 0
    if ((serialized >> 0) & 1)
    {
      // Биты 9-12 (прибавляем 1 обратно)
      aSize.X = ((serialized >> 9) & 0x0F) + 1;

      // Биты 13-15 (прибавляем 1 обратно)
      aSize.Y = ((serialized >> 13) & 0x07) + 1;
    }
    else
    {
      aSize.X = 0;
      aSize.Y = 0;
    }

    // Бит 1
    isFocused = (serialized >> 1) & 1;

    // Биты 2-5
    aPos.X = (serialized >> 2) & 0x0F;

    // Биты 6-8
    aPos.Y = (serialized >> 6) & 0x07;
  }
}
