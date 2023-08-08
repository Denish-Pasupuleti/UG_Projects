// CMSC 341 - Fall 2020 - Project 3
// driver.cpp: sample driver for the PQueue class.

#include "pqueue.h"
using namespace std;
// Priority functions compute an integer priority for a patient.  Internal
// computations may be floating point, but must return an integer.

int priorityFn1(const Patient& patient);
int priorityFn2(const Patient& patient);

int main() {
	/*

	// Create a patient queue with capacity five and priority function
	// priorityFn1()

	PQueue queue1(priorityFn1);
	PQueue queue2(priorityFn1);

	// Create some test jobs and insert them into the queue
	//Patient(string name, int triage, int temp, int ox, int rr, int hr, int bp)
	Patient patient1("Sam", 1, 37, 79, 36, 133, 75);
	Patient patient2("Liz", 5, 37, 98, 26, 70, 100);
	Patient patient3("Nick", 2, 37, 85, 34, 125, 85);
	Patient patient4("Eva", 4, 37, 95, 22, 115, 95);

	queue1.insertPatient(patient3); // 2(Nick)
	queue1.insertPatient(patient1); // 1(Sam)
	queue1.insertPatient(patient2); // 5(Liz)
	queue1.insertPatient(patient4); // 4(Eva)

	std::cout << "\nqueue1 dump after inserting 4 patients (Nick, Sam, Liz, Eva):" << std::endl;
	queue1.dump();


	Patient patient5("John", 3, 39, 91, 27, 115, 110);
	Patient patient6("Mia", 3, 33, 93, 28, 118, 98);
	queue2.insertPatient(patient5);
	queue2.insertPatient(patient6);

	std::cout << "\nqueue2 dump after inserting 2 patients (John, Mia):" << std::endl;
	queue2.dump();

	queue1.mergeWithQueue(queue2);

	// Print the queue, change priority function, print again, change
	// again, print again.  Changing the priority function should cause
	// the heap to be rebuilt.

	std::cout << std::endl << "Contents of queue1 after merging with queue2:\n";
	queue1.printPatientQueue();
	std::cout << "\nDump queue1 after merging with queue2:\n";
	queue1.dump();



	queue1.setPriorityFn(priorityFn2);

	std::cout << std::endl << "Contents of queue1 after changing the priority function to priorityFn2:\n";
	queue1.printPatientQueue();
	std::cout << "\nDump queue1 after changing the priority function to priorityFn2:\n";
	queue1.dump();


	queue1.setPriorityFn(priorityFn1);

	std::cout << std::endl << "Contents of queue1 after changing the priority function back to priorityFn1:\n";
	queue1.printPatientQueue();
	std::cout << "\nDump queue1 after changing the priority function back to priorityFn1:\n";
	queue1.dump();



	// Remove and print jobs in priority order
	std::cout << "\nFinal queue1 in priority order:\n";

	while (queue1.numPatients() > 0) {
		Patient patient = queue1.getNextPatient();
		std::cout << "[" << priorityFn1(patient) << "] " << patient << std::endl;
	}

	*/

	/*
cout << endl << "copy constructor dump" << endl;
//copy constructor
PQueue queue3(queue1);
queue3.dump();

cout << endl << "assignment operator dump" << endl;
PQueue queue4 = queue1;
queue4.dump();

//empty copy constructor test
cout << endl << "Testing empty copy constructor dump:" << endl;
PQueue queue5(priorityFn1);
PQueue queue6(queue5);

queue6.dump(); //prints nothing

//empty assignment operator test
cout << endl << "Testing empty assignment operator dump:" << endl;
PQueue queue7(priorityFn1);
PQueue queue8 = queue7;

queue8.dump(); //prints nothing

cout << endl;
cout << "Testing merging with queue9 of different priority" << endl;
PQueue queue9(queue1);
queue9.setPriorityFn(priorityFn2);
try
{
	// marging with diff priorities
	queue1.mergeWithQueue(queue9);
	cout << endl;
	queue1.dump();
}
catch (exception& e) {
	cout << e.what() << endl;
}
	*/

	/*
		cout << endl;
		cout << endl;

	Patient patient10("Hamza", 1, 37, 79, 36, 133, 75);
	Patient patient20("Denish", 3, 37, 98, 26, 70, 100);
	Patient patient30("Ayo", 5, 37, 85, 34, 125, 85);
	Patient patient40("Justin", 5, 37, 95, 22, 115, 95);
	Patient patient50("Dixon", 4, 39, 91, 27, 115, 110);
	Patient patient60("Hamilton", 2, 33, 93, 28, 118, 98);
	Patient patient70("Donyaee", 1, 37, 79, 36, 133, 75);
	Patient patient80("Johnson", 1, 37, 98, 26, 70, 100);
	Patient patient90("Jules", 2, 37, 85, 34, 125, 85);
	Patient patient100("Max", 2, 37, 85, 34, 125, 85);

	PQueue queue10(priorityFn2);
	queue10.insertPatient(patient30); // 5
	queue10.insertPatient(patient20); // 3
	queue10.insertPatient(patient40); // 5
	queue10.insertPatient(patient50); // 4
	queue10.insertPatient(patient10); // 1

	queue10.dump();
	cout << endl;

	PQueue queue11(priorityFn2);
	queue11.insertPatient(patient60); // 2
	queue11.insertPatient(patient90); // 2
	queue11.insertPatient(patient70); // 1
	queue11.insertPatient(patient80); // 1
	queue11.insertPatient(patient100); // 2

	queue11.dump();
	cout << endl;

	cout << "queue1" << endl;
	queue10.printPatientQueue();

	cout << "queue2" << endl;
	queue11.printPatientQueue();

	*/

	/*
	Patient patient1("Hamza", 3, 37, 79, 36, 133, 75);
	Patient patient2("Denish", 1, 37, 98, 26, 70, 100);
	Patient patient3("Ayo", 1, 37, 85, 34, 125, 85);
	Patient patient4("Justin", 2, 37, 95, 22, 115, 95);
	Patient patient5("Dixon", 4, 39, 91, 27, 115, 110);
	Patient patient6("Hamilton", 5, 33, 93, 28, 118, 98);
	Patient patient7("Donyaee", 5, 37, 79, 36, 133, 75);
	Patient patient8("Johnson", 1, 37, 98, 26, 70, 100);
	Patient patient9("Jules", 3, 37, 85, 34, 125, 85);
	Patient patient10("Max", 3, 37, 85, 34, 125, 85);

	PQueue queue(priorityFn2);
	queue.insertPatient(patient3);
	queue.insertPatient(patient2);
	queue.insertPatient(patient4);
	queue.insertPatient(patient5);
	queue.insertPatient(patient1);
	//queue.printPatientQueue();
	cout << endl;
	queue.dump();
	cout << queue.numPatients();
	cout << endl;

	PQueue queue2(priorityFn2);
	queue2.insertPatient(patient6);
	queue2.insertPatient(patient9);
	queue2.insertPatient(patient7);
	queue2.insertPatient(patient8);
	queue2.insertPatient(patient10);
	//queue2.printPatientQueue();
	cout << endl;
	queue2.dump();
	cout << queue.numPatients();
	cout << endl;

	queue2.mergeWithQueue(queue);
	cout << queue2.numPatients();
	queue2.dump();


	cout << endl;
	//queue2.printPatientQueue();

	cout << endl;
	queue2.getNextPatient();
	queue2.getNextPatient();
	queue2.getNextPatient();
	queue2.getNextPatient();
	queue2.getNextPatient();
	queue2.dump();
	cout << queue2.numPatients();

	queue2.setPriorityFn(priorityFn1);
	cout << endl;
	queue2.dump();
	*/


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

	PQueue queue(priorityFn2);
	queue.insertPatient(patient5); //4
	queue.insertPatient(patient1); //1
	queue.insertPatient(patient3); //5
	queue.insertPatient(patient4); //5
	queue.insertPatient(patient2); //3
	queue.insertPatient(patient3);
	queue.insertPatient(patient3);
	queue.insertPatient(patient3);
	queue.insertPatient(patient12);
	queue.insertPatient(patient3);
	queue.insertPatient(patient12);
	queue.insertPatient(patient3);
	queue.insertPatient(patient3);
	queue.dump();

	return 0;
}

int priorityFn1(const Patient& patient) {
	int pri = 5;
	if ((patient.getOxygen() < 80 && (patient.getRR() > 35 || patient.getRR() < 8)) ||
		(patient.getHR() > 130 && patient.getBP() < 80))
		pri = 1;
	else if (((patient.getOxygen() >= 80 && patient.getOxygen() <= 89) &&
		(patient.getRR() >= 31 && patient.getRR() <= 35)) ||
		(patient.getTemperature() >= 40 || patient.getTemperature() <= 32))
		pri = 2;
	else if ((patient.getOxygen() >= 90 && patient.getOxygen() <= 94) &&
		(patient.getRR() >= 26 && patient.getRR() <= 30))
		pri = 3;
	else if ((patient.getOxygen() >= 95 && patient.getOxygen() <= 97) &&
		(patient.getRR() >= 21 && patient.getRR() <= 25))
		pri = 4;
	else
		pri = 5;
	return pri;
}

int priorityFn2(const Patient& patient) {
	//priority only based on triage
	//traige is set by a health care professional
	return patient.getTriage();
}