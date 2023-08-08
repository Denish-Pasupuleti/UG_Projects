/*
	FileName:   mytest.cpp
	Author:     Denish Pasupuleti
	Date:       9/8/20
	Class:      CMSC 341 Benj
	Assignment: Project0

	Test file for functions of Queue.h assignment operator, copy constructor
	and destructor.

*/
#include <iostream>
#include "queue.h"

using namespace std;

void copyConstructor();
void assignmentOp();
void emptyCopy();

/*
	copyConstructor()
	Tests the copyConstructor and checks for shallow copying

*/
void copyConstructor() {

	Queue<int>* intQueue = new Queue<int>();
	//loading values into queue
	cout << "Pushing values onto original queue" << endl;
	for (int i = 1; i <= 10; i++)
		intQueue->enqueue(i);
	//display
	intQueue->dump();

	//Testing copy constructor
	Queue<int>* intQueueCopy = new Queue<int>(*intQueue);
	//Display after copying
	cout << "\nCopy constructor Queue" << endl;
	intQueueCopy->dump();

	//dequeue from original queue to test shallow copy
	cout << "\nDequeued 2 values from original queue" << endl;
	intQueue->dequeue();
	intQueue->dequeue();
	intQueue->dump();

	cout << "\nCopy Constructor Testing shallow copy" << endl;
	//displaying copy queue to test shallow copy
	intQueueCopy->dump();

	//freeing mem
	delete intQueue;
	delete intQueueCopy;
}

/*
	assignmentOp()
	Tests the assignment operator and checks for shallow copying

*/
void assignmentOp() {

	//original queue for assignment operator testing
	Queue<int>* originalQueue = new Queue<int>();
	for (int i = 10; i >= 1; i--)
		originalQueue->enqueue(i);

	cout << "\nTesting assignment operator" << endl;
	Queue<int>* intQueueAssign = new Queue<int>();
	*intQueueAssign = *originalQueue;

	//dump original queue
	cout << "Original Queue" << endl;
	originalQueue->dump();

	//dump assignment queue for verification
	cout << "\nAssignment Operator Queue" << endl;
	intQueueAssign->dump();

	//dequeued from original queue to test shallow copy
	cout << "\nDequeued 2 more values from original queue" << endl;
	originalQueue->dequeue();
	originalQueue->dequeue();
	cout << "Original Queue:" << endl;
	originalQueue->dump();
	cout << "\nAssignment operator Testing shallow copy" << endl;
	intQueueAssign->dump();

	//freeing mem
	delete intQueueAssign;
	delete originalQueue;
}

/*
	emptyQueue()
	Tests copyConstructor on empty queues
*/
void emptyCopy() {

	cout << "\nTesting Copy Constructor with empty queues" << endl;
	//testing copy constrcutor with empty queues
	Queue<int>* emptyQueue = new Queue<int>();
	Queue<int>* emptyQueueCopy = new Queue<int>(*emptyQueue);

	cout << "Printing Original Empty Queue(Nothing will be printed bc list is empty): " << endl;
	emptyQueue->dump();

	cout << "Printing Empty Queue Copy(Nothing will be printed bc list is empty): " << endl;
	emptyQueueCopy->dump();

	//freeing mem
	delete emptyQueue;
	delete emptyQueueCopy;
}


int main() {
	//Tests various functions of Queue.h
	copyConstructor();
	assignmentOp();
	emptyCopy();

	return 0;
}