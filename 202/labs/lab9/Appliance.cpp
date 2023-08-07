#include "Appliance.h"

Appliance::Appliance(){
  SetName("");
  SetPurpose("");
  SetElectric(0);
}

Appliance::Appliance(string name, string purpose, bool isElectric){
  SetName(name);
  SetPurpose(purpose);
  SetElectric(isElectric);
}

string Appliance::GetName(){
  return m_name;
}

void Appliance::SetName(string name){
  m_name = name;
}

string Appliance::GetPurpose(){
  return m_purpose;
}

void Appliance::SetPurpose(string purpose){
  m_purpose = purpose;
}

bool Appliance::UsesElectricity(){
  return m_isElectric;
}

void Appliance::SetElectric(bool isElectric){
  m_isElectric = isElectric;
}

void Appliance::UseAppliance(){
  cout << "You successfully used the appliance." << endl;
}
