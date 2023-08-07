/*****************************************
** File:    lab12.cpp
** Project: CMSC 202 Lab 12, Spring 2019
**
** This is the main driver file for lab 12. This will test your copy
** constructor, assignment operator, and destructor that you implemented for
** the Kennel class. You do not need to edit this file.
**
***********************************************/


#include "Kennel.h"

int main() {
  Kennel kennel1; //Constructor Called (overloaded constructor with default values)

  kennel1.Insert("Great Dane"); //Adds a Great Dane to kennel1
  kennel1.Insert("English Bulldog"); //Adds an English Bulldog to kennel1
  kennel1.Insert("Irish Wolfhound"); //Adds an Irish Wolfhound to kennel1

  cout <<"kennel1: " << kennel1 << endl; //Calls the overloaded << operator to output the Kennel List

  cout << "Kennel2 created using overloaded constructor" << endl;
  Kennel kennel2(4, "Hilltop Kennels"); //Constructor called (uses overloaded constructor)

  kennel2.Insert("Standard Poodle"); //Adds a Standard Poodle to kennel2
  kennel2.Insert("Chesapeake Bay Retriever"); //Adds a Chesapeake Bay Retriever to ken2
  cout << "kennel2: " << kennel2 << endl;//Calls overloaded << operator outputs List

  //Overloaded assignment invoked
  cout <<"Copy Constructor called to create kennel3 (copying kennel2)"<<endl;
  Kennel kennel3(kennel2);

  //Deletes entries from kennel3
  kennel3.DeleteLast();
  cout << "kennel3: " << kennel3 << endl;//Calls overloaded << operator outputs List

  cout << "Overloaded assignment invoked on kennel2 (copying kennel1)" << endl;
  kennel2 = kennel1; //Calls overloaded assignment on kennel2, setting it to kennel1

  cout << "Changing name of kennel2 to Retriever Kennels" << endl;
  kennel2.SetName("Retriever Kennels"); //Sets the name of the kennel2
  cout << "kennel2: " << kennel2 << endl;

  cout<<"=========================================="<<endl;
  cout<<"Final Lists:" <<endl;
  cout <<"kennel1: " << kennel1 << endl;
  cout << "kennel2: " << kennel2 << endl;
  cout << "kennel3: " << kennel3 << endl;

}
