#ifndef _EC_STUDENT_H
#define _EC_STUDENT_H

#include <string>

// Student class
class ECStudent
{
public:
  ECStudent(const std::string &nameIn) {name = nameIn;} 
  double GetMT() const { return MT; }
  void SetMT(double s) { MT = s; }
  double GetFinal() const { return final; }
  void SetFinal(double s) { final = s; }
  double GetHW() const { return HW; }
  void SetHW(double s) { HW = s; }
  std::string GetName() const { return name; }
  // ave score: 20% HW, 30% Midterm, 50% Final
  double GetAve() const 
  {
    return 0.2 * HW + 0.3 * MT + 0.5 * final;
  }

private:
  // ???
  std::string name;
  double MT;
  double final;
  double HW;
};


#endif
