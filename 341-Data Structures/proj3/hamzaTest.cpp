#include "pqueue.h"
#include <ctime>
#include <cmath>
#include <string>
#include <stdio.h>   
#include <stdlib.h>     
#include <time.h> 
using namespace std;

int priorityFn1(const Patient& patient);
int priorityFn2(const Patient& patient);
int main() {
    
    Patient patient1("Hamza", 1, 37, 79, 36, 133, 75);
Patient patient2("Denish", 3, 37, 98, 26, 70, 100);
Patient patient3("Ayo", 5, 37, 85, 34, 125, 85);
Patient patient4("Justin", 5, 37, 95, 22, 115, 95); 
Patient patient5("Dixon", 4, 39, 91, 27, 115, 110);
Patient patient6("Hamilton", 2, 33, 93, 28, 118, 98);
Patient patient7("Donyaee", 1, 37, 79, 36, 133, 75);
Patient patient8("Johnson", 1, 37, 98, 26, 70, 100);
Patient patient9("Jules", 2, 37, 85, 34, 125, 85);
Patient patient10("Max", 2, 37, 85, 34, 125, 85);
Patient patient11("Dan", 5, 37, 85, 34, 125, 85);
Patient patient12("Me", 2, 37, 85, 34, 125, 85);

PQueue queue1(priorityFn2);
PQueue queue2(priorityFn2);

queue1.insertPatient(patient1);
queue1.insertPatient(patient4);
queue1.insertPatient(patient5);
queue1.insertPatient(patient12);

cout << queue1.numPatients() << endl;

queue2.insertPatient(patient8);
queue2.insertPatient(patient9);
queue2.insertPatient(patient10);
queue2.insertPatient(patient3);

cout << queue2.numPatients() << endl;

cout << endl;

queue2.mergeWithQueue(queue1);


cout << queue1.numPatients() << endl;
cout << queue2.numPatients() << endl;
queue2.dump();
cout << endl;
queue2.setPriorityFn(priorityFn1);
queue2.dump();
cout << endl;
cout << queue2.numPatients() << endl;

cout << "changing!" << endl;
queue2 = queue1;
cout << queue2.numPatients() << endl;


    return 0;
}
int priorityFn1(const Patient&patient) {
  return 1;
}

int priorityFn2(const Patient&patient) {
  //priority only based on triage
  //traige is set by a health care professional
  return patient.getTriage();
}