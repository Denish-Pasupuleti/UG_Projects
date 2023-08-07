/*****************************************
** File:    Kennel.h
** Project: CMSC 202 Lab 11, Spring 2019
**
** This is the header file for the Kennel class in Lab 11.
**
***********************************************/

#ifndef KENNEL_H
#define KENNEL_H

#include <iostream>
#include <string>
using namespace std;

static const int MAX_NO_OF_ITEM =5;

class Kennel {
 public:
  //Overloaded Constructor
  //**Notice** this constructor has a name and capacity with default values, therefore,
  //a default constructor is not required (and it will cause a ambiguity error)
  Kennel(int capacity = MAX_NO_OF_ITEM, string name = "True Grit Kennels");

  //Copy Constructor
  Kennel(const Kennel& source);

  //Overloaded Assignment Operator
  Kennel& operator=(const Kennel& source);

  //Destructor
  ~Kennel();

  //Inserts an animal onto a kennel
  void Insert(const string& kennel);

  //Removes the last animal from the Kennel
  void DeleteLast();

  //Sets the name of the Kennel
  void SetName(const string& name);

  //Friend Function that is an overloaded << operator
  friend ostream& operator<<(ostream& os, const Kennel& rg); //Overloaded << Operator

private:
  int m_capacity; //Max capacity of the kennel
  int m_used; //Current used capacity of kennel
  string m_kennelName; //String name of the kennel
  string* m_kennelAnimals; //Array of names of animals in kennel
};

#endif // KENNEL_H
