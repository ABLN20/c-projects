#ifndef _EC_MOTOR_VEHICLE_H
#define _EC_MOTOR_VEHICLE_H

#include <vector>
#include "ECVehicleParts.h"

// Generic vehicle
class ECMotorVehicle
{
public:
  ECMotorVehicle();
  virtual ~ECMotorVehicle();
  virtual double GetPrice() const = 0;

protected:
  double CalculateComponentCost() const
  {
    double componentCost = 0;
    for(ECEngine part: engines)
    {
      componentCost += part.GetCost();
    }
    for(ECWheel part: wheels)
    {
      componentCost += part.GetCost();
    }
    for(ECLight part: lights)
    {
      componentCost += part.GetCost();
    }
    return componentCost;
  }

  std::vector<ECEngine> engines;
  std::vector<ECWheel> wheels;
  std::vector<ECLight> lights;
};

// Car
class ECCar : public ECMotorVehicle
{
public:
  ECCar(EC_ENGINE_TYPE t, int szWheel);

  double GetPrice() const override
  {
    double basePrice = CalculateComponentCost();
    return basePrice * 1.5 * 1.1;
  }
};

// Truck 
class ECTruck : public ECMotorVehicle
{
public:
  ECTruck(int numWheels, int szWheel);

  double GetPrice() const override
  {
    double basePrice = CalculateComponentCost();
    return ((basePrice * 1.5) - 1000) * 1.08;
  }
};

// Motocycle
class ECMotocycle : public ECMotorVehicle
{
public:
  ECMotocycle();

  double GetPrice() const override
  {
    double basePrice = CalculateComponentCost();
    return ((basePrice * 1.5) - 100) * 1.15;
  }
};

#endif
