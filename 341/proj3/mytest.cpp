// CMSC 341 - Fall 2020 - Project 3
// mytest.cpp: mytest for the PQueue class.

/*
	File: mytest.cpp
	Author: Denish Pasupuleti
	Description: mytest.cpp tests various operations on PQueue
*/

#include "pqueue.h"
#include <string>
#include <cmath>
#include <stdio.h>      
#include <stdlib.h> 
#include <ctime>
#include <time.h>
using namespace std;
// Priority functions compute an integer priority for a patient.  Internal
// computations may be floating point, but must return an integer.

int priorityFn1(const Patient& patient);
int priorityFn2(const Patient& patient);
void runTime(int num1);

int main() {
	// Create a patient queue with capacity five and priority function
	// priorityFn1()

	PQueue queue1(priorityFn1);
	PQueue queue2(priorityFn1);

	// Create some test jobs and insert them into the queue
	//Patient(string name, int triage, int temp, int ox, int rr, int hr, int bp)
	Patient patient1("Shaniqua", 1, 37, 79, 36, 133, 75);
	Patient patient2("Ned", 5, 37, 98, 26, 70, 100);
	Patient patient3("John", 2, 37, 85, 34, 125, 85);
	Patient patient4("Bran", 4, 37, 95, 22, 115, 95);

	queue1.insertPatient(patient3);
	queue1.insertPatient(patient1);
	queue1.insertPatient(patient2);
	queue1.insertPatient(patient4);

	std::cout << "\nqueue1 dump after inserting 4 patients (Shaniqua, Ned, John, Bran):" << std::endl;
	queue1.dump();
	cout << endl << "size(should be 4): " << queue1.numPatients() << endl;


	Patient patient5("Chungus", 3, 39, 91, 27, 115, 110);
	Patient patient6("Worm", 3, 33, 93, 28, 118, 98);
	queue2.insertPatient(patient5);
	queue2.insertPatient(patient6);

	std::cout << "\nqueue2 dump after inserting 2 patients (Chungus, Worm):" << std::endl;
	queue2.dump();
	cout << endl << "size(should be 2): " << queue2.numPatients() << endl;

	queue1.mergeWithQueue(queue2);

	// Print the queue, change priority function, print again, change
	// again, print again.  Changing the priority function should cause
	// the heap to be rebuilt.

	std::cout << std::endl << "Contents of queue1 after merging with queue2:\n";
	queue1.printPatientQueue();
	std::cout << "\nDump queue1 after merging with queue2:\n";
	queue1.dump();
	cout << endl << "size(should be 6): " << queue1.numPatients() << endl;

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
	cout << endl;
	cout << "**********************************Copy Constructor****************************" << endl;


	cout << endl << "copy constructor dump" << endl;
	//copy constructor
	PQueue queue3(queue1);
	PQueue queueCopy(queue3);
	queueCopy.dump();
	cout << endl << "size(should be 6): " << queueCopy.numPatients() << endl;
	cout << endl;

	cout << "Testing deep copy(pop original queue root)" << endl;
	queue3.getNextPatient();
	cout << "original queue after popping root" << endl;
	queue3.dump();
	cout << endl;
	cout << endl;
	cout << "copy dump: should be same as before" << endl;
	queueCopy.dump();
	cout << endl;
	cout << "**********************************Assignment Operator*************************" << endl;


	cout << endl << "assignment operator dump" << endl;
	PQueue queue4 = queue1;
	PQueue queueAssign = queue4;
	queueAssign.dump();
	cout << endl << "size(should be 6): " << queueAssign.numPatients() << endl;
	cout << endl;

	cout << "Testing deep copy(pop original queue root)" << endl;
	queue4.getNextPatient();
	cout << "original queue after popping root" << endl;
	queue4.dump();
	cout << endl;
	cout << endl;
	cout << "assignment dump: should be same as before" << endl;
	queueAssign.dump();
	cout << endl;

	cout << "**********************************Empty Tests*************************" << endl;
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
	cout << "******************************************************************************" << endl;


	cout << "Testing merging with queue9 of different priority" << endl;
	PQueue queue9(queue1);
	queue9.setPriorityFn(priorityFn2);

	try
	{
		// marging with diff priorities(throws exception)
		queue1.mergeWithQueue(queue9);
		cout << endl;
		queue1.dump();
	}
	catch (exception& e) {
		cout << "Exception: " << e.what() << endl;
	}
	cout << "******************************************************************************" << endl;


	// Remove and print jobs in priority order
	std::cout << "\nFinal queue1 in priority order:\n";
	while (queue1.numPatients() > 0) {
		Patient patient = queue1.getNextPatient();
		std::cout << "[" << priorityFn1(patient) << "] " << patient << std::endl;
	}
	cout << endl;
	cout << "******************************************************************************" << endl;

	// ******************************************************************************
	cout << "Calling getNextPatient on empty queue(should throw exception)" << endl;
	try {
		// throws exception when heap is empty
		queue1.getNextPatient();
	}
	catch (exception& e) {
		cout << "Exception: " << e.what() << endl;
	}
	cout << endl;
	cout << "******************************************************************************" << endl;

	// ******************************************************************************
	cout << "Testing clear" << endl;
	cout << "Heap before clear: " << endl;
	queue3.dump();
	queue3.clear();
	cout << endl << "Heap after clear:" << endl;
	queue3.dump();
	cout << endl;
	cout << "******************************************************************************" << endl;

	// tests runTime for large queues
	// only tests with priorityFn2 cuz of worst run times
	runTime(1000000); // n patients
	runTime(50000000); // n * 2 patients
	runTime(100000000); // n * 4 patients
	return 0;
}

// runs insertion and extraction operation for num patients
void runTime(int num) {
	PQueue queue(priorityFn2);
	clock_t time_req;
	time_req = clock();

	// loads Queue20 with num patients

	for (int i = 0; i < num; i++)
	{
		srand(time(NULL));
		int triage = rand() % 5 + 1;
		Patient patient1("Denish", triage, 40, 75, 30, 125, 100);
		queue.insertPatient(patient1);
	}
	time_req = clock() - time_req;
	cout << "For: " << num << " patients insert took: "
		<< (double)time_req / CLOCKS_PER_SEC << " seconds" << endl;

	// Extracts num patients

	time_req = clock();
	for (int i = 0; i < num; i++)
		queue.getNextPatient();
	time_req = clock() - time_req;
	cout << "For: " << num << " patients extraction took: "
		<< (double)time_req / CLOCKS_PER_SEC << " seconds" << endl;
	cout << endl;
}

// function to calculate priority bases on other values
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

// function to calculate priority based on triage
int priorityFn2(const Patient& patient) {
	//priority only based on triage
	//traige is set by a health care professional
	return patient.getTriage();
}