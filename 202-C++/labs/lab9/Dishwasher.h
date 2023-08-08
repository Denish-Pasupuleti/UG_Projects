#ifndef DISHWASHER_H
#define DISHWASHER_H

#include "Appliance.h"
#include <string>
#include <iostream>
using namespace std;

class Dishwasher: public Appliance {
 public:
  Dishwasher();
  Dishwasher(string name, string purpose, bool isElectric, int dishes);

  int GetDishes();
  void SetDishes(int dishes);
  void UseAppliance(); //Uses the appliance
protected:
  int m_dishes;
};

#endif
