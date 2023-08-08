#ifndef HOMEWORK_H
#define HOMEWORK_H

#include <iostream>
#include <string>
using namespace std;

class Homework {
 public:
  //Default Constructor
  Homework();
  //Overload Constructor
  Homework(string name, bool isGraded, int numHoursComplete);

  string GetName(); //Returns Name
  bool GetIsGraded(); //Returns true if graded
  int GetNumHoursComplete(); //Returns number of hours to complete

  void SetName(string name);
  void SetIsGraded(bool graded);
  void SetNumHoursComplete(int numHours);

 private:
  string m_name;
  bool m_isGraded;
  int m_numHoursComplete;
};

#endif
