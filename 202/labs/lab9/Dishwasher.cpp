#include "Dishwasher.h"

Dishwasher::Dishwasher(){
  SetName("");
  SetPurpose("");
  SetElectric(0);
}

Dishwasher::Dishwasher(string name, string purpose, bool isElectric, int dishes){
  SetName(name);
  SetPurpose(purpose);
  SetElectric(isElectric);
  SetDishes(dishes);
}

int Dishwasher::GetDishes(){
  return m_dishes;
}

void Dishwasher::SetDishes(int dishes){
  m_dishes = dishes;
}

void Dishwasher::UseAppliance(){
  cout << "The dishwasher washed all the dishes!" << endl;
}
