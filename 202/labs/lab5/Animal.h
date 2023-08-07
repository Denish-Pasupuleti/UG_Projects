/**********
* File: Animal.h
* Intended for Lab 5: Classes
**********/

#ifndef ANIMAL_H //Header or Include Guards
#define ANIMAL_H //Header or Include Guards

#include <iostream>
#include <string>
using namespace std;

class Animal {
public:
  //Default constructor, already implemented.
  Animal();
  
  //**Student Requirement**
  //Do the prototype for each of the functions described in the lab document
  
  //Returns species of animal
  string GetSpecies();
  
  //Sets species of animal
  void SetSpecies(string species);
  
  //Returns the animal's age
  int Get_Age();
  
  //Sets the animal's age
  void SetAge(int age);
  
  //Returns whether or not creature is hostile
  bool IsHostile();
  
  //Sets creature hostility
  void SetHostility(bool hostile);
  
  //Force the creature to attack, if hostile
  void Attack();
  
  //Age the creature by 1 year
  int age();
  
private:
  //**Student Requirement**
  //Create the member variables below as described in the lab document
    //species of creature
    //age of creature
    //whether or not creature is hostile
  string m_species;
  int m_age;
  bool m_isHostile;
};

#endif //End of Header Guard
