#ifndef STOVE_H
#define STOVE_H

#include "Appliance.h"
#include <string>
#include <iostream>
using namespace std;

class Stove: public Appliance {
 public:
  Stove();
  Stove(string name, string purpose, bool isElectric, bool oven); //Constructor

  void UseAppliance();
  bool IsOven();
  void SetOven(bool IsOven);
 protected:
  bool m_isOven;
};

#endif
