// light bulb problem as taught in class. Don't change this class
#include <iostream>
using namespace std;
class LightBulb
{
public:
  LightBulb() : isOn(false) {}
  bool IsOn() const { return isOn; }
  void SetOn(bool f) { isOn = f; }
  
private:
  bool isOn;
};

// Pump class: don't change this class
class Pump
{
public:
  Pump() : isOn(false) {}
  bool IsOn() const { return isOn; }
  void SetOn(bool f) { isOn = f; }
  
private:
  bool isOn;
};

// Button server class: stuff controlled by the button. Don't change this class
class ButtonServer
{
public:
  // notify button has been pushed
  virtual void Pushed() = 0;
};

// Button class: abstract
class Button
{
public:
  Button(ButtonServer *ps) : pServer(ps) {}
  void SetServer(ButtonServer *ps) { pServer = ps; }
  void Push()
  {
    if (pServer)
      pServer->Pushed();
  }
  
private:
  ButtonServer *pServer;
};

// a button for controlling lightbulb
class LightBulbButtonServer : public ButtonServer
{
public:
  LightBulbButtonServer(LightBulb &b) : bulb(b) {}
  void Pushed() override
  {
    bulb.SetOn(!bulb.IsOn());
    cout << "LightBulb state: " << (bulb.IsOn() ? "On" : "Off") << endl;
  }
private:
  LightBulb &bulb;
};

// a button for controlling pump
class PumpButtonServer : public ButtonServer
{
public:
  PumpButtonServer(Pump &p) : pump(p) {}
  void Pushed() override
  {
    pump.SetOn(!pump.IsOn());
    cout << "Pump state: " << (pump.IsOn() ? "On" : "Off") << endl;
  }
private:
  Pump &pump;
};

