#include "Homework.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

// fill vector - fills Homework info
// vector<Homework>& - Homework Assignment for you to do
void fillVector(vector<Homework>&);

// printVectorWithIterator - prints the information
// of all Homework using the ::iterator
void printVectorWithIterator(vector<Homework>&);

// printVectorWithoutIterator - prints the information 
// of all Homework using unsigned int
void printVectorWithoutIterator(vector<Homework>&);

int main () {
  //Creates a new vector of Homework Assignments
  vector<Homework> myAssign; //Assignments

  //Populates the vector
  fillVector(myAssign);

  
  cout << endl << "Assignment list using unsigned int: " << endl;
  // Prints the contents of the vector using unsigned int
  printVectorWithoutIterator(myAssign);  

  cout << "\n";
  cout  << "Assignment list using the ::iterator:" << endl;
  // Prints the contents of the vector using ::iterator 
  printVectorWithIterator(myAssign);
  
  return 0;
}

void fillVector(vector<Homework>& newAssign) {

  // Write this function
  // Needs to ask how many homework assignments
  // Gets Homework name, if it is graded or not, and how long to complete (in hours)
  int numH = 0;
  cout << "How many homework assignments? " << endl;
  cin >> numH;
  string hwName;
  int graded;
  bool isGraded;
  int completion;
  for(int i = 1; i <= numH; i++){
    //name
    cout << "Please eneter the homework "  << i << "name ";
    cin >> hwName;
    //graded
    cout << "\nIs it graded? (0 or 1) ";
    cin >> graded;
    if(graded == 0)
      isGraded = false;
    else
      isGraded = true;
    //hours
    cout << "\nHow long to complete? ";
    cin >> completion;
    
    newAssign.push_back(Homework(hwName, isGraded, completion));
  }
}

void printVectorWithoutIterator(vector<Homework>& newAssign){
  // Write this function
  // Print out the vector using unsigned int
  for(unsigned int i = 0; i < newAssign.size(); i++){
    cout << newAssign.at(i).GetName() << " ";
    cout << newAssign.at(i).GetIsGraded() << " ";
    cout << newAssign.at(i).GetNumHoursComplete() << " hours to complete"  << endl;
  }

}
void printVectorWithIterator(vector<Homework>& newAssign){
  // Write this function
  // Print out the vector using ::iterator
  for (vector<Homework>::iterator it = newAssign.begin();
       it != newAssign.end(); ++it){
    cout << it->GetName() << " " << it->GetIsGraded() << " " << it->GetNumHoursComplete() << " hours to complete" << endl;
  }
}
