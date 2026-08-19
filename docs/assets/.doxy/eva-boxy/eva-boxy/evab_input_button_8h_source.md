

# File evabInputButton.h

[**File List**](files.md) **>** [**src**](dir_68267d1309a1af8e8297ef4c3efbcdba.md) **>** [**evabInputButton.h**](evab_input_button_8h.md)

[Go to the documentation of this file](evab_input_button_8h.md)


```C++
#pragma once

#include <evabElementBase.h>

namespace evab
{

  class InputButton : public ElementBase
  {
  public:
    InputButton(const char *aText = "");

    const char *GetName() const;

    void SetName(const char *aText);

  protected:
    void drawer(Screen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override;

  private:
    const char *mName;
  };

  class InputButtonF : public ElementBase
  {
  public:
    InputButtonF(const __FlashStringHelper *aText);

    const __FlashStringHelper *GetName() const;

    void SetName(const __FlashStringHelper *aText);

  protected:
    void drawer(Screen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override;

  private:
    const __FlashStringHelper *mName;
  };

}
```


