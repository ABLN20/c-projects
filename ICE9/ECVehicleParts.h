#ifndef _EC_VEHICLE_PARTS_H
#define _EC_VEHICLE_PARTS_H
#include <string>
// Engine type
enum EC_ENGINE_TYPE
{
  EC_ENGINE_4CYL = 0,
  EC_ENGINE_6CYL = 1,
  EC_ENGINE_ELECTRIC = 2
};

// Engine
class ECEngine 
{
public:
  ECEngine(EC_ENGINE_TYPE type ) : type(type) {}
  // what to put here?
  double GetCost() const 
  {
    switch (type) {
        case EC_ENGINE_4CYL: return 1000;
        case EC_ENGINE_6CYL: return 1500;
        case EC_ENGINE_ELECTRIC: return 3000;
        default:
          throw std::string("Invalid engine type");
    }
  }
private:
  EC_ENGINE_TYPE type;
};

// Wheel
class ECWheel 
{
public:
  ECWheel(int size) : size(size) {}
  double GetCost() const 
  {
    switch (size) 
    {
        case 17: return 100;
        case 19: return 150;
        default:
          throw std::string("Invalid wheel type");
    }
  }
private:
  int size;
};

// light
class ECLight 
{
public:
  ECLight() {}
  double GetCost() const 
  {
    return 50;
  }
};

#endif
