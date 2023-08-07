// CMSC 341 - Fall 2020 - Project 1
/*
	Author: Denish Pasupuleti
	Project: 1
	File: csrlist.cpp
	Email: mpasupu1@umbc.edu
	Description: .cpp file for csrlist.h
*/

#include "csrlist.h"
#include <stdexcept>

// constructor
CSRList::CSRList() {
	/***********************************
	 *      To be implemented
	 * ********************************/

	 //initialize vraibles
	m_head = nullptr;
	m_size = 0;
}

// copy constructor for CSRList
CSRList::CSRList(const CSRList& rhs) {
	/***********************************
	 *      To be implemented
	 * ********************************/

	 // initialize variables
	m_head = nullptr;
	m_size = 0;

	//for iterating through source CSRList
	CSR* source = rhs.m_head;

	// while not nullpt traverse and add nodes
	while (source != nullptr)
	{
		// checks initially if m_head = nullptr
		if (m_head == nullptr)
		{
			CSR* temp = new CSR(*source);
			temp->m_next = nullptr;
			m_head = temp;
			source = source->m_next;
			m_size++;
		}
		else
		{
			//traverses through current list to the end and adds node
			CSR* last = m_head;
			CSR* temp = new CSR(*source);
			while (last->m_next != nullptr)
				last = last->m_next;
			last->m_next = temp;
			// moves source to next
			source = source->m_next;
			m_size++;
		}
	}
}

// destructor
CSRList::~CSRList() {
	/***********************************
	 *      To be implemented
	 * ********************************/

	CSR* curr = m_head;
	// traverse through and delete
	while (curr != nullptr && m_head != nullptr)
	{
		m_head = m_head->m_next;
		//deletes
		delete curr;
		curr = m_head;
	}
	// resets
	m_head = nullptr;
	m_size = 0;
}

// checks validity of list
bool CSRList::empty() const {
	/***********************************
	 *      To be implemented
	 * Note: to avoid warnings, a
	 * fictional return value is added,
	 * your implementaion should return
	 * a correct value.
	 * ********************************/

	 // checks validity of list
	if (m_size == 0 or m_head == nullptr)
		return true;
	return false;
}

// inserts at head position
void CSRList::insertAtHead(const CSR& matrix) {
	/***********************************
	 *      To be implemented
	 * ********************************/

	 //makes new CSR object
	CSR* tempCSR = new CSR(matrix);
	//if empty then m_head = matrix else traverses through
	if (m_size == 0)
	{
		m_head = tempCSR;
		m_size++;
	}
	else
	{
		tempCSR->m_next = m_head;
		m_head = tempCSR;
		m_size++;
	}
}

// clears the whole list
void CSRList::clear() {
	/***********************************
	 *      To be implemented
	 * ********************************/

	CSR* curr = m_head;

	// traverse through and delete
	while (curr != nullptr && m_head != nullptr)
	{
		m_head = m_head->m_next;
		//deletes
		delete curr;
		curr = m_head;
	}
	// resets
	m_head = nullptr;
	m_size = 0;
}

// getAt for certain index in list and CSR object
int CSRList::getAt(int CSRIndex, int row, int col) const {
	/***********************************
	 *      To be implemented
	 * Note: to avoid warnings, a
	 * fictional return value is added,
	 * your implementaion should return
	 * a correct value.
	 * ********************************/

	 // Index doesn't exist
	if (CSRIndex > m_size || CSRIndex < 0)
		throw range_error("Error: Object does not exist!");
	// traverse through to find right index
	CSR* curr = m_head;
	int counter = 0;
	while (curr != nullptr and counter != CSRIndex)
	{
		// when counter is CSRIndex it ll call getAt
		if (counter != CSRIndex)
		{
			curr = curr->m_next;
			counter++;
		}
	}
	return curr->getAt(row, col);
}

// dumps the whole list
void CSRList::dump() {
	if (!empty()) {
		CSR* temp = m_head;
		while (temp != nullptr) {
			temp->dump();
			temp = temp->m_next;
		}
	}
	else
		cout << "Error: List is empty!" << endl;
}

// checks equality
bool CSRList::operator== (const CSRList& rhs) const {
	/***********************************
	 *      To be implemented
	 * Note: to avoid warnings, a
	 * fictional return value is added,
	 * your implementaion should return
	 * a correct value.
	 * ********************************/

	CSR* curr = m_head;
	CSR* rhsNode = rhs.m_head;

	// comparing size to easily distinguish
	if (m_size != rhs.m_size)
		return false;
	//traverse through and compare each CSR object
	while (curr != nullptr && rhsNode != nullptr)
	{
		// if valid goes onto check next node
		if (*curr == *rhsNode)
		{
			curr = curr->m_next;
			rhsNode = rhsNode->m_next;
		}
		else
			return false;
	}
	return true;
}

// assignment operator basically copies values over
const CSRList& CSRList::operator=(const CSRList& rhs) {
	/***********************************
	 *      To be implemented
	 * ********************************/

	if (this != &rhs)
	{
		//delete existing nodes
		clear();

		// variable to traverse
		CSR* source = rhs.m_head;
		// Adding new CSR objects
		while (source != nullptr)
		{
			if (m_head == nullptr)
			{
				// makes new object if at m_head
				CSR* temp = new CSR(*source);
				temp->m_next = nullptr;
				m_head = temp;
				source = source->m_next;
				m_size++;
			}
			else
			{
				CSR* last = m_head;
				CSR* temp = new CSR(*source);
				// traverse to end of current list
				while (last->m_next != nullptr)
					last = last->m_next;
				last->m_next = temp;
				// moves source
				source = source->m_next;
				m_size++;
			}
		}
	}
	return *this;
}

// calculates average sparsity
int CSRList::averageSparseRatio() {
	/***********************************
	 *      To be implemented
	 * Note: to avoid warnings, a
	 * fictional return value is added,
	 * your implementaion should return
	 * a correct value.
	 * ********************************/

	int average = 0;
	int counter = 0;
	CSR* curr = m_head;
	// while not nullptr traverse
	while (curr != nullptr)
	{
		average += curr->sparseRatio();
		// if curr is empty then skip adding to counter
		// bc empty CSR objects dont count for sparsity
		if (!curr->empty())
			counter++;
		curr = curr->m_next;
	}
	return (average / counter);
}