#pragma once

#include <evaHandler.h>

namespace evab
{

  template <class T, Keys... KEYS>
  class KeyCatcher : public T
  {
  public:
    enum EventType
    {
      EVENT_CATCH_KEY = 1,
    };

    template <typename... Args>
    KeyCatcher(eva::IHandler *aListener, Args &&...args)
        : T(args...), mListener(aListener)
    {
    }

    bool Key(Keys aKey) override
    {
      if (T::Key(aKey))
        return true;

      if ((... || (aKey == KEYS)))
      {
        if (mListener)
        {
          mListener->invoke(this, {EVENT_CATCH_KEY, (int)aKey});
          return true;
        }
      }
      return false;
    }

  private:
    eva::IHandler *mListener = nullptr;
  };

  template <class T, unsigned char kDec, unsigned char kInc>
  class KeyModifier : public T
  {
  public:
    template <typename... Args>
    KeyModifier(Args &&...args)
        : T(args...)
    {
    }

    bool Key(Keys aKey) override
    {
      if (T::Key(aKey))
        return true;

      if (aKey == kDec)
        T::Increment(-1);
      else if (aKey == kInc)
        T::Increment(+1);
      else
        return false;

      return true;
    }
  };

  template <class T, unsigned char kDec, unsigned char kInc>
  class KeyReactor : public T
  {
  public:
    enum EventType
    {
      EVENT_VALUE_CHANGED = 1,
    };

    template <typename... Args>
    KeyReactor(eva::IHandler *aListener, Args &&...args)
        : T(args...), mListener(aListener)
    {
    }

    bool Key(Keys aKey) override
    {
      if (T::Key(aKey))
        return true;

      if (aKey == kDec)
        T::Increment(-1);
      else if (aKey == kInc)
        T::Increment(+1);
      else
        return false;

      if (mListener)
        mListener->invoke(this, {EVENT_VALUE_CHANGED, (int)T::GetValue()});
      return true;
    }

  private:
    eva::IHandler *mListener = nullptr;
  };

}
