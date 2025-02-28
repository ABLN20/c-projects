#include "ECMotorVehicle.h"

// Generic vehicle
ECMotorVehicle :: ECMotorVehicle() 
{
}
ECMotorVehicle ::  ~ECMotorVehicle()
{
  // delete all parts
  // your code
}


// Car
ECCar :: ECCar(EC_ENGINE_TYPE t, int szWheel)
{
  ECEngine engine(t);
  engines.push_back(engine);

  for (int i = 0; i < 4; ++i) 
  {
      ECWheel wheel(szWheel);
      wheels.push_back(wheel);
  }

  for (int i = 0; i < 4; ++i) 
  {
      ECLight light;
      lights.push_back(light);
  }
}

// Truck 
ECTruck :: ECTruck(int numWheels, int szWheel)
{
  ECEngine engine(EC_ENGINE_6CYL);
  engines.push_back(engine);

  for (int i = 0; i < numWheels; ++i) 
  {
      ECWheel wheel(szWheel);
      wheels.push_back(wheel);
  }

  for (int i = 0; i < 8; ++i) 
  {
      ECLight light;
      lights.push_back(light);
  }
  
}

// Motocycle
ECMotocycle :: ECMotocycle()
{
  // your code here
  ECEngine engine(EC_ENGINE_4CYL);
  engines.push_back(engine);

  for (int i = 0; i < 2; ++i) 
  {
      ECWheel wheel(17);
      wheels.push_back(wheel);
  }

  for (int i = 0; i < 2; ++i) 
  {
      ECLight light;
      lights.push_back(light);
  }
}


