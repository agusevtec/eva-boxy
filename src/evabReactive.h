#pragma once

#include <evaHandler.h>

namespace evab
{

  template <class T, unsigned char kKey>
  class KeyCatcher : public T
  {
  public:
    enum EventType
    {
      EVENT_CATCH_KEY = 1,
    };

    template <typename... Args>
    KeyCatcher(eva::IHandler *aListener, Args &&...args)
        : T(args...)
    {
    }

    bool Key(char aKey) override
    {
      if (T::Key(aKey))
        return true;

      if (aKey & kKey)
        if (mListener)
        {
          mListener->invoke(this, {EVENT_VALUE_CHANGED, (int)aKey});
          return true;
        }
      return false;
    }

  private:
    eva::IHandler *mListener = nullptr;
  };

  template <class T, unsigned char kDec, unsigned char kInc>
  class SilentReactor : public T
  {
  public:
    template <typename... Args>
    SilentReactor(Args &&...args)
        : T(args...)
    {
    }

    bool Key(char aKey) override
    {
      if (T::Key(aKey))
        return true;

      if (aKey & kDec)
        T::Increment(-1);
      else if (aKey & kInc)
        T::Increment(+1);
      else
        return false;

      return true;
    }

  private:
    eva::IHandler *mListener = nullptr;
  };

  template <class T, unsigned char kDec, unsigned char kInc>
  class Reactor : public T
  {
  public:
    enum EventType
    {
      EVENT_VALUE_CHANGED = 1,
    };

    template <typename... Args>
    Reactor(eva::IHandler *aListener, Args &&...args)
        : T(args...), mListener(aListener)
    {
    }

    bool Key(char aKey) override
    {
      if (T::Key(aKey))
        return true;

      if (aKey & kDec)
        T::Increment(-1);
      else if (aKey & kInc)
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
