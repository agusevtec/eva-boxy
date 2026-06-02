class IField {
public:
  virtual void Draw(int place) = 0;
};

template<class T>
class Field : public IField, public T {
public:
  void Draw(int place) override {
    T::Draw(place);
    cache = place;
  }
  void Redraw() {
    T::Draw(cache);
  }
private:
  unsigned short cache;
};

class IActor : public IField {
public:
  virtual bool Key(Keys aKey) = 0;
};

template<class T>
class Actor : public IActor, public T {
public:

  void Draw(int place) override {
    T::Draw(place);
    cache = place;
  }

  bool Key(Keys aKey) override {
    bool result  = T::Key(aKey);
    Redraw();
    return result;
  }

  void Redraw() {
    T::Draw(cache);
  }

private:
  unsigned short cache;
};

class InputInt {
public:
  void Draw(int place) {
    Serial.print("place:");
    Serial.println(place);
  }

  void Set(char *text) {
  }

  bool Key(Keys aKey) {
    Serial.println(aKey);
  }

private:
  char *text;
};

using InputIntField = Field<InputInt>;
using InputIntActor = Actor<InputInt>;

class A
{
  virtual foo1(){}
};

class B
{
  virtual foo1(){}
  virtual foo2(){}
};

void setup() {
  Serial.begin(9600);
  InputIntActor iif;
  IActor *ia = &iif;
  Serial.println(sizeof(iif));
  ia->Draw(1);
  //ia->Set("a");
  //ia->Redraw();
  ia->Key('a');
  Serial.println(sizeof(A));
  Serial.println(sizeof(B));
}

void loop() {
}