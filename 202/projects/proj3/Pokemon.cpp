/*************************************************
  File: Pokemon.cpp
  Project: CMSC 202 Project 3, Spring 2020
  Author: Denish Pasupuleti
  Date: 3/20/2020
  Section: 15
  E-mail: mpasupu1@umbc.edu
  Description: This is the cpp file for Pokemon.h and the program basically
               creates a Pokemon Object pointer with attributes either default or
	       with the ones that are passed in through the overloadec
	       constructor.Setter and Getter functions for attributes are
	       also defined.
*************************************************/

#include "Pokemon.h"
#include <string>
#include <iostream>
using namespace std;

//default constructor
Pokemon::Pokemon() {
  m_name = "Default";
  m_index = 0;
  m_type = "Grass";
  m_strong = "Fire";
  m_health = MAX_HEALTH;
}

//overloaded constructor
Pokemon::Pokemon(int index, string name, string type, string typeStrong) {
  m_name = name;
  m_index = index;
  m_type = type;
  m_strong = typeStrong;
  m_health = MAX_HEALTH;
}

//Returns pointer to next pokemon
Pokemon* Pokemon::GetNext() {
  return m_next;
}

//Returns Name
string Pokemon::GetName() {
  return m_name;
}

//Returns index
int Pokemon::GetIndex() {
  return m_index;
}

//Returns type
string Pokemon::GetType() {
  return m_type;
}

//Returns health
int Pokemon::GetHealth() {
  return m_health;
}

//Returns type of pokemon this pokemon is strong against
string Pokemon::GetStrong() {
  return m_strong;
}

//sets health of pokemon
void Pokemon::SetHealth(int health) {
  m_health = health;
}

//Sets the pointer to the next pokemon in the list
void Pokemon::SetNext(Pokemon* pokemon) {
  m_next = pokemon;
}

//allows us to cout a pokemon object
ostream& operator << (ostream& output, Pokemon& P) {
  return output << " " << P.GetName() << "(" << P.GetType()
		<< ":" << P.GetHealth() << " health)" << endl;
}
