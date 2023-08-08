#ifndef APPLIANCE_H
#define APPLIANCE_H

#include <string>
#include <iostream>
using namespace std;

class Appliance {
 public:
  Appliance();
  Appliance(string name, string purpose, bool isElectric); //Constructor

  string GetName(); //Getter for name
  void SetName(string name); //Setter for name
  string GetPurpose(); //Getter for appliance purpose (cooking/cleaning)
  void SetPurpose(string purpose); //Setter for purpose
  bool UsesElectricity(); //Returns if the appliance uses electricity or not
  void SetElectric(bool isLit); //Updates if the appliance uses electricity
  void UseAppliance(); //Uses the appliance
 protected:
  string m_name;
  string m_purpose;
  bool m_isElectric;
};

#endif
