#include <iostream>
#include <string>
using namespace std;

/*
 * Lab 7: Debugging
 * There are three errors - one is a runtime that causes a segmentation fault
 * The other two are logical errors. Find them using gdb.
 *
 * You MUST find the errors using gdb
 */

int main(){

  // Initialize string pointer
  string *name = new string("Nadja");


  // Print contents of string pointer
  cout << *name << endl;


  int size = 3;
  string *listNames = new string[3]();

  // Fill listNames
  listNames[0] = "Krish";
  listNames[1] = "Beter";
  listNames[2] = "Cara";

  // Print contents of listNames
  for(int i = 0; i < size; i++){

    cout << "My name is " << listNames[i] << endl;

  }

  delete name;
}

