/*
	File: LL.cpp
	Project: CMSC 202 Project 5, Spring 2020
	Author: Denish Pasupuleti
	Section: 15
	E-mail: mpasupu1@umbc.edu
	Description: This is the linkedlist class where templated data gets sorted
	and inserted into the linkedlist and provides various
	helper functions to access/modify the data.
*/


#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Templated Node class
// Normal node except that each node can hold a pair <T,int>
// where the first value is templated and the second value is the frequency
// (or quantity) of the first
// For example, if T was a string then it would hold string,int
template <class T>
class Node {
public:
	Node(const T& data); //Node Constructor - Assume each quan
	pair<T, int>& GetData(); //Node Data Getter
	void SetData(const pair<T, int>&); //Node Data Setter
	Node<T>* GetNext(); //Node m_next getter
	void SetNext(Node<T>* next); //Node m_next setter
private:
	pair <T, int> m_data; //Holds templated data
	Node<T>* m_next; //Pointer to next node
};

template <class T>
Node<T>::Node(const T& data) {
	m_data = make_pair(data, 1);
	m_next = nullptr;
}

template <class T>
pair<T, int>& Node<T>::GetData() {
	return m_data;
}

template <class T>
void Node<T>::SetData(const pair<T, int>& data) {
	m_data = data;
}

template <class T>
Node<T>* Node<T>::GetNext() {
	return m_next;
}

template <class T>
void Node<T>::SetNext(Node<T>* next) {
	m_next = next;
}

//Templated Linked List class
template <class T>
class LL {
public:
	// Name: LL() (Linked List) - Default Constructor
	// Desc: Used to build a new linked list
	// Preconditions: None
	// Postconditions: Creates a new linked list where m_head points to nullptr
	LL();
	// Name: ~LL() - Destructor
	// Desc: Used to destruct a LL
	// Preconditions: There is an existing LL with at least one node
	// Postconditions: A LL is deallocated (including dynamically allocated nodes)
	//                 to have no memory leaks!
	~LL();
	// Name: LL (Copy Constructor)
	// Desc: Creates a copy of existing LL
	//       Requires a LL - REQUIRED to be implemented even if not used
	// Preconditions: Source LL exists
	// Postconditions: Copy of source LL
	LL(const LL& source);
	// Name: operator= (Overloaded Assignment Operator)
	// Desc: Makes two LL of the same type have identical number of nodes and values
	// Preconditions: Requires two linked lists of the same templated type
	//                REQUIRED to be implemented even if not used
	// Postconditions: Two idenetical LL
	LL<T>& operator= (const LL&);
	// Name: Find
	// Desc: Iterates through LL and returns node if data found
	// Preconditions: LL Populated
	// Postconditions: Returns nullptr if not found OR Node pointer if found
	Node<T>* Find(const T& data);
	// Name: Insert
	// Desc: Either inserts a node to the linked list OR increments frequency of first
	//       Takes in data. If "first" (of pair) NOT in list, adds node
	//       If "first" (of pair) is already in list, increments quantity
	//       Inserts "first" in order with no duplicates
	// Preconditions: Requires a LL.
	// Postconditions: Node inserted in LL based on first value (or quantity incremented)
	void Insert(const T& data);
	// Name: RemoveAt
	// Desc: Removes a node at a particular position based on data passed (matches first)
	// Preconditions: LL with at least one node. 
	// Postconditions: Removes first node with passed value (in first)
	void RemoveAt(const T&);
	// Name: Display
	// Desc: Display all nodes in linked list
	// Preconditions: Outputs the LL
	// Postconditions: Displays the pair in each node of LL 
	void Display();
	// Name: GetSize
	// Desc: Returns the size of the LL
	// Preconditions: Requires a LL
	// Postconditions: Returns m_size
	int GetSize();
	// Name: operator<< (Overloaded << operator)
	// Desc: Returns the ostream of the data in each node
	// Preconditions: Requires a LL
	// Postconditions: Returns an ostream with the data from each node on different line
	template <class U>
	friend ostream& operator<<(ostream& output, const LL<U>&);
	// Name: Overloaded [] operator
	// Desc: When passed an integer, returns the data at that location
	// Precondition: Existing LL
	// Postcondition: Returns pair from LL using []
	pair<T, int>& operator[] (int x);//Overloaded [] operator to pull data from LL
private:
	Node <T>* m_head; //Node pointer for the head
	int m_size; //Number of nodes in queue
};

//Implement LL here

//default constructor
template <class T>
LL<T>::LL() {
	m_head = nullptr;
	m_size = 0;
}

//destructor
template <class T>
LL<T>::~LL() {
	Node<T>* curr = m_head;

	if (curr == nullptr)
	{
		m_size = 0;
		return;
	}
	while (curr != nullptr && m_head != nullptr)
	{
		m_head = m_head->GetNext();
		//delete
		delete curr;
		curr = m_head;
	}
	//resets
	m_head = nullptr;
	m_size = 0;
}

//LL copy constructor
template <class T>
LL<T>::LL(const LL& source) {
	m_size = 0;
	m_head = nullptr;

	Node<T>* oldList = source.m_head;
	//make new list
	while (oldList != nullptr)
	{
		Insert((oldList->GetData()).first);
		// sets data
		Node<T>* temp = Find((oldList->GetData()).first);
		temp->SetData(oldList->GetData());
		oldList = oldList->GetNext();
	}
}

//overloaded assignment operator
template <class T>
LL<T>& LL<T>::operator= (const LL& source) {
	if (this != &source)
	{
		Node<T>* curr = m_head;
		//delete existing nodes
		while (curr != nullptr)
		{
			m_head = m_head->GetNext();
			delete curr;
			curr = m_head;
		}
		m_size = 0;
		m_head = nullptr;

		Node<T>* oldList = source.m_head;
		//make new list
		while (oldList != nullptr)
		{
			Insert((oldList->GetData()).first);
			Node<T>* temp = Find((oldList->GetData()).first);
			temp->SetData(oldList->GetData());
			oldList = oldList->GetNext();
		}
	}
	return *this;
}

//Find
template <class T>
Node<T>* LL<T>::Find(const T& data) {
	Node<T>* temp = m_head;
	// traverses through and find object pointer
	while (temp != nullptr)
	{
		if ((temp->GetData()).first == data)
			return temp;
		temp = temp->GetNext();
	}
	return nullptr;
}

//insert
template <class T>
void LL<T>::Insert(const T& data) {

	// 4 cases
	// 1) if linkedlist is empty then add string as head
	// 2) if data already in list
	// 3) if given string is less than head then add new string as new head
	// 4) if given string is anywhere but the above mentioned positions

	Node <T>* curr = m_head;
	pair<T, int> dataPair = make_pair(data, 1);

	//case 1
	if (m_head == nullptr || m_size == 0)
	{
		m_head = new Node<T>(data);
		m_size++;
	}
	//case 2
	else if (Find(data) != nullptr)
	{
		Node<T>* temp = Find(data);
		pair<T, int> newData =
			make_pair((temp->GetData()).first, ((temp->GetData()).second) + 1);
		temp->SetData(newData);
	}
	//case 3
	else if (data < (m_head->GetData()).first)
	{
		Node <T>* temp = new Node<T>(data);
		temp->SetNext(m_head);
		m_head = temp;
		m_size++;
	}
	//case 4
	else
	{
		Node <T>* newNode = new Node<T>(data);
		//finds prev node of where newNode is suppose to be
		while (curr->GetNext() != nullptr && (curr->GetNext()->GetData()).first < data)
			curr = curr->GetNext();
		newNode->SetNext(curr->GetNext());
		curr->SetNext(newNode);
		m_size++;
	}
}

//RemoveAt
template <class T>
void LL<T>::RemoveAt(const T& data) {
	Node<T>* curr = m_head;
	Node<T>* prev = m_head;

	if (m_size < 1 || Find(data) == nullptr)
		return;
	else if ((curr->GetData()).first == data)
	{
		curr = curr->GetNext();
		delete m_head;
		m_head = curr;
		m_size--;
	}
	else
	{
		while (((curr->GetData()).first) != data && curr != nullptr)
		{
			prev = curr;
			curr = curr->GetNext();
		}
		prev->SetNext(curr->GetNext());
		delete curr;
		m_size--;
	}
}

//Display
template <class T>
void LL<T>::Display() {
	Node <T>* temp = m_head;

	while (temp != nullptr)
	{
		pair<T, int> dataPair = temp->GetData();
		cout << dataPair.first << ":" << dataPair.second << endl;
		temp = temp->GetNext();
	}
	cout << "END" << endl;
}

//GetSize
template <class T>
int LL<T>::GetSize() {
	return m_size;
}

//friend ostream
template <class U>
ostream& operator<<(ostream& output, const LL<U>& source) {
	Node<U>* temp = source.m_head;

	while (temp != nullptr)
	{
		output << (temp->GetData()).first << ":" << (temp->GetData()).second << endl;
		temp = temp->GetNext();
	}
	return output;
}

//overloaded array operator
template <class T>
pair<T, int>& LL<T>::operator[] (int x) {
	Node<T>* curr = m_head;
	int count = 1;

	while (curr != nullptr && count != x)
	{
		curr = curr->GetNext();
		count++;
	}
	return curr->GetData();
}

//****************************************************************
// To test just LL follow these instructions:
//   1.  Uncomment out int main below
//   2.  make LL
//   3.  ./LL (try valgrind too!)

/*
	int main() {
	//Test 1 - Default Constructor and Push
	cout << "Test 1 - Default Constructor and Push Running" << endl;
	//Test Default Constructor
	LL <string>* newLL1 = new LL<string>();
	//Push 4 nodes into LL
	newLL1->Insert("candy");
	newLL1->Insert("cookies");
	newLL1->Insert("candy");
	newLL1->Insert("bananas");
	newLL1->Insert("dogs");
	newLL1->Insert("apples");
	newLL1->Insert("elephants");
	newLL1->Insert("barf");
	newLL1->Insert("candy");
	newLL1->Insert("cookies");
	newLL1->Insert("candy");
	newLL1->Insert("bananas");
	newLL1->Insert("dogs");
	newLL1->Insert("apples");
	newLL1->Insert("elephants");
	newLL1->Insert("barf");
	newLL1->Display();

	//Test 2 - Copy Constructor and Assignment Operator
	cout << "Test 2 - Copy Constructor and Assignment Operator Running" << endl;
	//Test Copy constructor
	LL <string>* newLL2 = new LL<string>(*newLL1);
	cout << "*******Original*********" << endl;
	newLL1->Display();
	cout << "*******Copy*********" << endl;
	newLL2->Display();

	cout << "RemoveAt(candy)" << endl;
	newLL1->RemoveAt("candy");
	cout << "newLL1 Display Function" << endl;
	newLL1->Display();

	//Test Overloaded Assignment Operator
	LL <string>* newLL3 = new LL<string>();
	*newLL3 = *newLL1;
	cout << "*******Assignment*********" << endl;
	newLL3->Display();
	cout << endl;

	//Test 3 - Test Display and Overloaded <<
	cout << "Test 3 - Display and Overloaded << Running" << endl;
	cout << "newLL1 Display Function" << endl;
	newLL1->Display();
	cout << "newLL1 Overloaded" << endl;
	cout << *newLL1;
	cout << "newLL1 Display Function" << endl;
	newLL1->Display();

	cout << "Deleting all lists" << endl;
	delete newLL1;
	delete newLL2;
	delete newLL3;

	return 0;
	}
*/

