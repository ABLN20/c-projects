// Code for modeling a university's various units: department, office,
// college, etc
#include <iostream>
#include <vector>
using namespace std;
// Generic interface. 
class ECUnit
{
public:
  virtual double GetBudget() const = 0;
  virtual ~ECUnit() = default;
};

// Department
class ECDepartment : public ECUnit
{
public:
  ECDepartment(double b) : budget(b) {}
  
  double GetBudget() const override 
  {
    return budget;
  }

private:
  double budget;
};

// Office
class ECOffice : public ECUnit
{
public:
  ECOffice(double b) : budget(b) {}
  
  double GetBudget() const override 
  {
    return budget;
  }

private:
  double budget;
};

// Composite
class ECCompositeUnit : public ECUnit
{
public:
  ECCompositeUnit()  {}
  ~ECCompositeUnit() 
  {
    for (ECUnit* unit : children) 
    {
      delete unit;
    }
  }
  
  double GetBudget() const override
  {
    double totalBudget = 0;
    for (const ECUnit* unit : children)
    {
      totalBudget += unit->GetBudget();
    }
    return totalBudget;
  }
  void AddChild(ECUnit *pUnit)
  {
    children.push_back(pUnit);
  }

private:
  // your code here
  vector<ECUnit*> children; 
};

