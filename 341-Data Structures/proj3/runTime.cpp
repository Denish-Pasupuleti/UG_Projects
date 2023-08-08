#include "pqueue.h"
#include <ctime>
#include <cmath>
#include <string>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>
using namespace std;

int priorityFn1(const Patient& patient);
int priorityFn2(const Patient& patient);
int main() {
	PQueue queue(priorityFn2);
	PQueue queue2(priorityFn2);
	int N = 1000000;
	clock_t time_req;

	// Using pow function
	time_req = clock();

	for (int i = 0; i < N; i++) {
		srand(time(NULL));
		int triage = rand() % 5 + 1;
		Patient patient1("Denish", triage, 40, 75, 30, 125, 100);
		queue.insertPatient(patient1);
		//queue2.insertPatient(patient1);
	}
	time_req = clock() - time_req;
	cout << "Insert: it took " << (float)time_req / CLOCKS_PER_SEC << " seconds" << endl;
	// ***********************************************************

	time_req = clock();
	queue.mergeWithQueue(queue2);
	time_req = clock() - time_req;

	cout << "Merge: it took " << (float)time_req / CLOCKS_PER_SEC << " seconds" << endl;

	// ***********************************************************
	time_req = clock();
	//for (int i = 0; i < N; i++) {
	queue.clear();
	//}
	time_req = clock() - time_req;
	cout << "Remove: it took " << (float)time_req / CLOCKS_PER_SEC << " seconds" << endl;

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