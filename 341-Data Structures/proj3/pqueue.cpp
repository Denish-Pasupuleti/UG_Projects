// CMSC 341 - Fall 2020 - Project 3
// PQueue: an ER triage queue using a skew heap and function pointers

/*
	File: PQueue.cpp
	Author: Denish Pasupuleti
	Description: .cpp for PQueue.h where functions are implemented
*/

#include "pqueue.h"
using namespace std;
using std::cout;
using std::domain_error;
using std::endl;

// constructor
PQueue::PQueue(prifn_t priFn)
{

	// this sets internal priority function to the function passed in
	// uses the outside function to calculate priority for patient
	_heap = nullptr;
	priority = nullptr;
	_size = 0;
	setPriorityFn(priFn);
}

// destructor
PQueue::~PQueue()
{
	clear();
}

// copy constructor
PQueue::PQueue(const PQueue &rhs)
{
	// assigns priority and calls copy helper
	_heap = nullptr;
	priority = nullptr;
	_size = 0;
	setPriorityFn(rhs.priority);

	// null check
	if (rhs._heap != nullptr)
		copyAssignHelper(_heap, rhs._heap);
}

// assignment operator
PQueue &PQueue::operator=(const PQueue &rhs)
{
	// checks for self assignment
	if (this != &rhs)
	{
		// clears heap if already populatd
		if (_heap != nullptr)
			clear();
		priority = nullptr;
		setPriorityFn(rhs.priority);

		// null check
		if (rhs._heap != nullptr)
		{
			copyAssignHelper(_heap, rhs._heap);
		}
		return *this;
	}
	return *this;
}

// helper for copy constructor and assignment assignment operator
void PQueue::copyAssignHelper(Node *&copy, Node *node)
{
	// traverses through rhs heap and recursively creates
	// and adds nodes
	// creates exact copy of tree
	if (node != nullptr)
	{
		copy = new Node(node->_patient);
		_size++;
		copyAssignHelper(copy->_left, node->_left);
		copyAssignHelper(copy->_right, node->_right);
	}
	else if (node == nullptr)
		copy = nullptr;
}

// inserts patients into the PQueue by merging
void PQueue::insertPatient(const Patient &input)
{
	// if no heap then add first node
	if (_heap == nullptr)
	{
		_size++;
		this->_heap = new Node(input);
	}
	else
	{
		// make new Pqueue and merge it with this PQueue
		// static allocation
		PQueue temp(priority);
		temp._heap = new Node(input);
		mergeWithQueue(temp);
		_size++;
	}
}

// pops the patient with highest priority and merges left and
// right subtrees
Patient PQueue::getNextPatient()
{
	// pops patient with highest priority then returns that patient
	// merges remaining left and right subtreee

	// if heap is empty then throw domain error
	if (_heap == nullptr or _size == 0)
		throw domain_error("Heap is empty already");

	Node *tempRoot = _heap;

	Node *tempL = _heap->_left;
	Node *tempR = _heap->_right;

	// sets heap to nullptr so merge will return the new root
	_heap = nullptr;
	// merges left and right subtree
	_heap = mergeHelper(tempL, tempR);

	_size -= 1;

	// deletes temp node which points to old root
	Patient patient = tempRoot->_patient;
	delete tempRoot;
	return patient;
}

// mergeWithQueue which calls mergeHelper to merge pqueues
void PQueue::mergeWithQueue(PQueue &rhs)
{
	// checks for self assignment
	if (this != &rhs)
	{
		// checks if priority is same
		if (priority != nullptr)
		{
			if (rhs.priority != priority)
				throw domain_error("Priority functions are not the same");
		}
		// checks if rhs._heap is valid
		else if (rhs._heap == nullptr)
			return;

		// merges heap
		_heap = mergeHelper(this->_heap, rhs._heap);

		// add rhs size to this queue's size
		_size += rhs._size;

		// reset rhs
		rhs._heap = nullptr;
		rhs._size = 0;
	}
}

// mergeHelper merges two PQueues
Node *PQueue::mergeHelper(Node *&heap1, Node *&heap2)
{

	// if either heap is empty returns the other
	if (heap1 == nullptr)
		return heap2;
	else if (heap2 == nullptr)
		return heap1;

	// gets priority
	int firstPriority = priority(heap1->_patient);
	int secondPriority = priority(heap2->_patient);

	// make sure that heap 1 priority <= heap 2 priority
	if (firstPriority <= secondPriority)
	{
		// swaps heap1 left and right
		Node *tempHeap = heap1->_right;
		heap1->_right = heap1->_left;
		heap1->_left = tempHeap;
		// adds nodes to the left subtree
		heap1->_left = mergeHelper(heap1->_left, heap2);
		return heap1;
	}
	else
		return mergeHelper(heap2, heap1);
}

// deletes all nodes in PQueue
void PQueue::clear()
{
	// clears and resets heap
	if (_heap != nullptr)
	{
		clearHelper(_heap);
		_heap = nullptr;
		_size = 0;
	}
}

// helper for clear which traverses tree
void PQueue::clearHelper(Node *node)
{
	// traverses left subtree and right subtree and deletes node
	if (node != nullptr)
	{
		clearHelper(node->_left);
		clearHelper(node->_right);
		delete node;
	}
}

// returns num patients in PQueue
int PQueue::numPatients() const
{
	return _size;
}

// printPatientQueue prints in priority order
void PQueue::printPatientQueue() const
{

	// calls preOrder
	if (_heap != nullptr)
		preOrder(_heap);
}

// helper for printPatientQueue
void PQueue::preOrder(Node *node) const
{
	// pre order traversal
	if (node != nullptr)
	{
		cout << "[" << priority(node->_patient) << "] ";
		cout << node->_patient << endl;
		preOrder(node->_left);
		preOrder(node->_right);
	}
}

// returns priority
prifn_t PQueue::getPriorityFn() const
{
	if (priority != nullptr)
		return priority;
	return nullptr;
}

// setPriorityFn sets priority and or rebuilds heap
void PQueue::setPriorityFn(prifn_t priFn)
{
	// if priority function is diff rebuild heap
	if (priority == nullptr)
		priority = priFn;
	else if (priority == priFn)
		return;
	else
	{
		// sets priority
		priority = priFn;
		// temp points to heap
		Node *temp = _heap;
		// resets heap so it can be rebuilt
		_heap = nullptr;
		_size = 0;

		if (temp != nullptr)
			priorityHelper(temp);
	}
}

// helper for priorityHelper which traverses and inserts patients
void PQueue::priorityHelper(Node *&node)
{
	// traverses through tree and inserts nodes to rebuild
	if (node != nullptr)
	{
		// inserts patient
		insertPatient(node->_patient);
		priorityHelper(node->_left);
		priorityHelper(node->_right);
		delete node;
	}
}

// dumps tree
void PQueue::dump() const
{
	// calls inOrder
	if (_heap != nullptr)
		inOrder(this->_heap);
}

// helper for dump
void PQueue::inOrder(Node *node) const
{
	// in order traversal
	if (node != nullptr)
	{
		cout << "(";
		inOrder(node->_left);
		cout << priority(node->_patient) << ":" << node->_patient.getPatient();
		inOrder(node->_right);
		cout << ")";
	}
}

ostream &operator<<(ostream &sout, const Patient &patient)
{
	sout << "Patient: " << patient.getPatient() << ", triage: " << patient.getTriage()
			 << ", temperature: " << patient.getTemperature() << ", oxygen: " << patient.getOxygen() << ", RR: "
			 << patient.getRR() << ", HR: " << patient.getHR() << ", BP: " << patient.getBP();
	return sout;
}

ostream &operator<<(ostream &sout, const Node &node)
{
	sout << node.getPatient();
	return sout;
}