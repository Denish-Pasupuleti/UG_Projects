#include "Homework.h"
using namespace std;

Homework::Homework() {
  m_name = "Penny";
  m_isGraded = true;
  m_numHoursComplete = 1;
}

Homework::Homework(string name, bool isGraded, int numHoursComplete){
  m_name = name;
  m_isGraded = isGraded;
  m_numHoursComplete = numHoursComplete;
}

string Homework::GetName(){
  return m_name;
}

bool Homework::GetIsGraded(){
  return m_isGraded;
}

int Homework::GetNumHoursComplete(){
  return m_numHoursComplete;
}

void Homework::SetName(string name){
  m_name = name;
}
void Homework::SetIsGraded(bool isGraded){
  m_isGraded = isGraded;
}
void Homework::SetNumHoursComplete(int numHoursComplete){
  m_numHoursComplete = numHoursComplete;
}
