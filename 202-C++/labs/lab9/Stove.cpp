#include "Stove.h"

Stove::Stove(){
  SetName("");
  SetPurpose("");
  SetElectric(0);
  SetOven(1);
}

Stove::Stove(string name, string purpose, bool isElectric, bool oven){
  SetName(name);
  SetPurpose(purpose);
  SetElectric(isElectric);
  SetOven(oven);
}

void Stove::UseAppliance(){
  cout << "You heated up some hot dogs on the stove." << endl;
}

bool Stove::IsOven(){
  return m_isOven;
}

void Stove::SetOven(bool isOven){
  m_isOven = isOven;
}
