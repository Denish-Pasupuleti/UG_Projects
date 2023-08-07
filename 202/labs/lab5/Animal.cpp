#include "Animal.h"

//Constructor -- Already Implemented
Animal::Animal() {
  cout << "Creating an animal..." << endl;
  m_species = "goat";
  m_age = 7;
  m_isHostile = false;
}

//Here is an example for a getter and a setter

string Animal::GetSpecies() {
  return m_species;
}

void Animal::SetSpecies(string species) {
  m_species = species;
}

//**Student Requirement**
//Implement getters and setters for age and hostile here
int Animal::Get_Age(){
  return m_age;
}

void Animal::SetAge(int age){
  m_age = age;
}

bool Animal::IsHostile(){
  return m_isHostile;
}

void Animal::SetHostility(bool hostile){
  m_isHostile = hostile;
}

 
//**Student Requirement**
//Custom Functions -- Implement Attack and Age here
int Animal::age(){
 return  m_age += 1;
}

void Animal::Attack(){
  if(IsHostile())
    cout << GetSpecies() << " attacks you!" << endl;
  else
    cout << GetSpecies() << " approaches you and nuzzles you." << endl;
}
