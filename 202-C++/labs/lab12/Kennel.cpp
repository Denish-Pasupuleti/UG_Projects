/*****************************************
** File:    Kennel.cpp
** Project: CMSC 202 Lab 11, Spring 2019
**
** This is the cpp file for the Kennel class in Lab 11. You will need to
** implement the Copy constructor, overloaded assignment operator, and
** the destructor in this file.
**
***********************************************/

#include "Kennel.h"

//Overloaded constructor
Kennel::Kennel(int cap, string name) {
  cout << "Kennel Constructor: Capacity=" << cap << " Name=" << name << endl;
  m_capacity = cap;
  m_used = 0;
  m_kennelName = name;
  m_kennelAnimals = new string[cap];
}


//Implement Copy Constructor Here
Kennel::Kennel(const Kennel& source){
  m_capacity = source.m_capacity;
  m_used = source.m_used;
  m_kennelName = source.m_kennelName;
  m_kennelAnimals = new string[m_capacity];
  for(int i = 0; i < m_used; i++){
    m_kennelAnimals[i] = source.m_kennelAnimals[i];
  }
  delete[] source.m_kennelAnimals;
}

//Implement Overloaded Assignment Operator Here
Kennel& Kennel::operator=(const Kennel& source){
  m_capacity = source.m_capacity;
  m_used = source.m_used;
  m_kennelName = source.m_kennelName;

  m_kennelAnimals = new string[m_capacity];
  for(int i = 0; i < m_used; i++){
    m_kennelAnimals[i] = source.m_kennelAnimals[i];
  }
  return *this;
}

//Implement Destructor Here
Kennel::~Kennel(){
  delete[] m_kennelAnimals;
  m_kennelAnimals = nullptr;
}

//Inserting a new subject into our subject array
void Kennel::Insert(const string& itemName) {
  if(m_used == m_capacity) {
    cout<<"The kennel is full. Cannot add any additional animals."<<endl;
  }
  else  {
    m_kennelAnimals[m_used] = itemName;
    m_used++;
    cout << "Animal:" << itemName << " added to the kennel." << endl;
  }
}

void Kennel::DeleteLast(){
  if (m_used == 0){
    cout <<"The kennel is Empty!" <<endl;
  }
  else{
    m_used--;
    cout <<"Animal:" <<m_kennelAnimals[m_used] <<" removed from the kennel." <<endl;
    m_kennelAnimals[m_used] = "";
  }
}

void Kennel::SetName(const string& name){
  m_kennelName = name;
}

ostream& operator <<(ostream& os, const Kennel& fm) {
  os << "m_capacity: " <<fm.m_capacity <<endl;
  os << "m_used: " <<fm.m_used <<endl;

  os << fm.m_kennelName << " has the following animals:" << endl << " | ";
  for(int i=0;i<fm.m_used; i++) {
    os <<fm.m_kennelAnimals[i] + " | ";
  }
  return os << endl;
}
