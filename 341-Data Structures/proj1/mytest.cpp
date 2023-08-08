/*
	Author: Denish Pasupuleti
	Project: 1
	File: mytest.cpp
	Email: mpasupu1@umbc.edu
	Description: Personal test file for csr.h and csrlist.h
*/

#include <iostream>
#include "csrlist.h"
#include <stdexcept>

using namespace std;

// Pre: N/A Post: tests copy constructor for CSR and CSRList
// copy constructor of CSR and CSRList
void copyConstructor() {

	cout << "Testing copy constructor on 4 CSR objects" << endl;
	int array1[] = { 10,20,0,0,0,0,0,30,0,40,0,0,0,0,50,60,70,0,0,0,0,0,0,80 };
	int array2[] = { 0,0,0,0,100,200,0,0,300 };

	CSR aCSR, testCSR;
	aCSR.compress(3, 3, array2, 9);
	CSR bCSR(aCSR), cCSR(bCSR), dCSR(cCSR);
	testCSR.compress(4, 6, array1, 24);

	cout << "Dumping aCSR(original)";
	aCSR.dump();
	cout << "\nDumping bCSR(copy of a)";
	bCSR.dump();
	cout << "\nDumping cCSR(copy of b)";
	cCSR.dump();
	cout << "\nDumping dCSR(copy of c)";
	dCSR.dump();

	cout << "\n**********************************************************" << endl;
	cout << "Testing copy constructor on 3 empty CSR objects" << endl;
	CSR aEmptyCSR;
	//aEmptyCSR.compress(3, 3, array2, 9);
	CSR bEmptyCSR(aEmptyCSR);
	CSR cEmptyCSR(bEmptyCSR);

	cout << "Dumping aEmptyCSR";
	aEmptyCSR.dump();
	cout << "\nDumping bEmptyCSR";
	bEmptyCSR.dump();
	cout << "\nDumping cEmptyCSR";
	cEmptyCSR.dump();

	cout << "\n**********************************************************" << endl;
	CSRList aCSRList;
	aCSRList.insertAtHead(aCSR);
	aCSRList.insertAtHead(bCSR);
	aCSRList.insertAtHead(cCSR);
	aCSRList.insertAtHead(dCSR);
	aCSRList.insertAtHead(aEmptyCSR);
	aCSRList.insertAtHead(bEmptyCSR);
	aCSRList.insertAtHead(cEmptyCSR);
	aCSRList.insertAtHead(testCSR); // suppose to show insertAtHead works

	cout << "Dumping aCSRList" << endl;
	aCSRList.dump();

	cout << "\n**********************************************************" << endl;
	cout << "Testing copy constructor of CSRList" << endl;

	CSRList bCSRList(aCSRList);
	cout << "Dumping bCSRList(Copy of aCSRList)" << endl;
	bCSRList.dump();
}

// Pre: N/A Post: tests assignment operator for CSR and CSRList
//assignment operator of CSR and CSRList
void assignmentOperator() {

	cout << endl << "Testing assignment operator on 2 CSR objects" << endl;
	int array2[] = { 0,0,0,0,100,200,0,0,300 };
	CSR aCSR;
	aCSR.compress(3, 3, array2, 9);
	CSR bCSR = aCSR;
	CSR cCSR = bCSR;
	//empty CSR's
	CSR aEmptyCSR;
	CSR bEmptyCSR(aEmptyCSR);

	cout << "Dumping aCSR(original)";
	aCSR.dump();
	cout << "\nDumping bCSR(assignment of a)";
	bCSR.dump();
	cout << "\nDumping cCSR(assignment of b)";
	cCSR.dump();


	cout << "\n**********************************************************" << endl;
	CSRList aCSRList, bCSRList;
	aCSRList.insertAtHead(aCSR);
	aCSRList.insertAtHead(bCSR);
	aCSRList.insertAtHead(cCSR);
	aCSRList.insertAtHead(aEmptyCSR);
	aCSRList.insertAtHead(bEmptyCSR);

	bCSRList.insertAtHead(aCSR);
	bCSRList.insertAtHead(bCSR);
	bCSRList.insertAtHead(cCSR);

	cout << "Testing CSRList assignment operator" << endl;
	cout << "Dumping aCSRList" << endl;
	aCSRList.dump();

	cout << "\nDumping bCSRList" << endl;
	bCSRList.dump();

	bCSRList = aCSRList;

	cout << "\nDumping bCSRList(assignment of aCSRList)" << endl;
	bCSRList.dump();
}

// Pre: N/A Post: tests clear function for CSR and CSRList
// clear in CSR and CSRList
void testingClear() {
	cout << endl << "Testing clear on CSR object" << endl;
	int array2[] = { 0,0,0,0,100,200,0,0,300 };
	CSR aCSR;
	aCSR.compress(3, 3, array2, 9);
	CSR bCSR(aCSR), cCSR(aCSR);
	cout << "Dumping aCSR";
	aCSR.dump();
	cout << "Clearing" << endl;
	aCSR.clear();
	cout << "Dumping aCSR(Cleared)";
	aCSR.dump();

	cout << "\n**********************************************************" << endl;
	cout << "Testing clear with CSRList" << endl;
	CSRList aCSRList;
	aCSRList.insertAtHead(aCSR);
	aCSRList.insertAtHead(bCSR);
	aCSRList.insertAtHead(cCSR);

	cout << "Dumping aCSRList" << endl;
	aCSRList.dump();

	cout << "\n**********************************************************" << endl;

	cout << "\nClearing aCSRList" << endl;
	aCSRList.clear();

	cout << "Dumping aCSRList" << endl;
	aCSRList.dump();
}

// Pre: N/A Post: tests compress function for CSR
// compress in CSR
void compress() {
	int array1[] = { 10,20,0,0,0,0,0,30,0,40,0,0,0,0,50,60,70,0,0,0,0,0,0,80 };
	int array2[] = { 0,0,0,0,100,200,0,0,300 };
	CSR aCSR, bCSR;
	aCSR.compress(4, 6, array1, 24);//initialize object aCSR
	bCSR.compress(3, 3, array2, 9);

	cout << "\nDumping aCSR(Original no variation)";
	aCSR.dump();
	cout << "\nDumping cCSR(Original no variation)";
	bCSR.dump();

	cout << "\nTesting recompression(aCSR should change)" << endl;
	aCSR.compress(3, 3, array2, 9);

	cout << "Dumping aCSR(Recompressed)";
	aCSR.dump();

	cout << "\n**********************************************************" << endl;
	cout << "Different cases for compress" << endl;

	cout << "Compressing array1 but since m/n are 0 will result in a empty CSR" << endl;
	aCSR.compress(0, 0, array1, 12);
	cout << "Dumping aCSR";
	aCSR.dump();

	cout << "\n**********************************************************" << endl;
	int array3[] = {};
	cout << "Compressing array1 but since arraysize is 0 will result in a zero matrix" << endl;
	aCSR.compress(3, 3, array3, 0);
	cout << "Dumping aCSR";
	aCSR.dump();

	cout << "\n**********************************************************" << endl;
	cout << "Compressing array1 but with arraySize < matrix size" << endl;
	aCSR.compress(4, 6, array1, 12);

	cout << "Dumping aCSR";
	aCSR.dump();

	cout << "\n**********************************************************" << endl;
	cout << "Compressing array1 but with arraySize > matrix size" << endl;
	aCSR.compress(3, 5, array1, 24);

	cout << "Dumping aCSR";
	aCSR.dump();
}

// Pre: N/A Post: tests getAt function for CSR and CSRList
// getAt in CSR and CSRList
void getAt() {
	int array1[] = { 10,20,0,0,0,0,0,30,0,40,0,0,0,0,50,60,70,0,0,0,0,0,0,80 };
	int array2[] = { 0,0,0,0,100,200,0,0,300 };
	CSR aCSR, bCSR;
	aCSR.compress(4, 6, array1, 24);//initialize object aCSR
	bCSR.compress(3, 3, array2, 9);

	cout << "\nTesting getAt on CSR object" << endl;
	try {
		cout << endl << aCSR.getAt(2, 4) << endl;//returns the value 70
		cout << endl << aCSR.getAt(0, 0) << endl;//returns the value 10
		cout << endl << aCSR.getAt(2, 2) << endl;//returns the value 50
		cout << endl << aCSR.getAt(0, 3) << endl;//returns 0
		//throws exception value does not exist(out of bounds)
		cout << endl << aCSR.getAt(9, 4) << endl;
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}

	cout << "\n**********************************************************" << endl;

	CSRList aCSRList;//create aCSRList
	aCSRList.insertAtHead(aCSR);
	aCSRList.insertAtHead(bCSR);

	cout << "\nInserted 2 CSR objects into aCSRList testing getAt" << endl;
	try {
		cout << endl << aCSRList.getAt(1, 2, 4) << endl;//returns the value 70
		//throws an exception(index of object out of bounds)
		cout << endl << aCSRList.getAt(5, 2, 2) << endl;
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}

	cout << "\n**********************************************************" << endl;
	cout << "Testing CSR with negative row/col" << endl;

	try {
		cout << endl << aCSRList.getAt(1, -2, -4) << endl;//throws exception
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}

	cout << "\n**********************************************************" << endl;
	cout << "Testing CSRList with negative row/col" << endl;

	try {
		cout << endl << aCSRList.getAt(-1, 2, 4) << endl;// throws exception
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}
}

// Pre: N/A Post: tests equality function for CSR and CSRList
// == operator in CSR and CSRList
void equal() {

	int array1[] = { 10,20,0,0,0,0,0,30,0,40,0,0,0,0,50,60,70,0,0,0,0,0,0,80 };
	int array2[] = { 0,0,0,0,100,200,0,0,300 };
	CSR aCSR, bCSR, cCSR, dCSR, eCSR;
	aCSR.compress(4, 6, array1, 24);//initialize object aCSR
	bCSR.compress(3, 3, array2, 9);
	cCSR.compress(4, 6, array1, 24);//initialize object aCSR

	cout << "\nDumping aCSR";
	aCSR.dump();

	cout << "\nDumping bCSR";
	bCSR.dump();

	cout << "\nDumping cCSR";
	cCSR.dump();

	cout << "\nDumping dCSR";
	dCSR.dump();

	cout << "\nDumping eCSR";
	eCSR.dump();

	cout << "\nTesting = operator for CSR object" << endl;
	if (aCSR == bCSR)
		cout << "aCSR and bCSR are equal" << endl;
	else
		cout << "aCSR and bCSR are not equal" << endl; //this is correct

	cout << "\n**********************************************************" << endl;

	if (aCSR == cCSR)
		cout << "aCSR and cCSR are equal" << endl; //this is correct
	else
		cout << "aCSR and cCSR are not equal" << endl;

	cout << "\n**********************************************************" << endl;
	if (dCSR == eCSR)
		cout << "dCSR and eCSR are equal cuz both empty" << endl; // this is correct
	else
		cout << "dCSR and eCSR are not equal" << endl;

	cout << "\n**********************************************************" << endl;
	cout << "Testing = operator on CSRLists" << endl;

	CSRList aCSRList, bCSRList;
	aCSRList.insertAtHead(aCSR);
	aCSRList.insertAtHead(bCSR);
	bCSRList.insertAtHead(aCSR);
	bCSRList.insertAtHead(bCSR);

	cout << "\nDumping aCSRList";
	aCSRList.dump();

	cout << "\nDumping bCSRList";
	bCSRList.dump();

	if (aCSRList == bCSRList)
		cout << "aCSRList and bCSRList are equal" << endl; //this is correct
	else
		cout << "aCSRList and bCSRList are not equal" << endl;

	cout << "\n**********************************************************" << endl;

	CSRList cCSRList, dCSRList;

	cout << "\nDumping cCSRList";
	cCSRList.dump();

	cout << "\nDumping dCSRList";
	dCSRList.dump();

	cout << "\n**********************************************************" << endl;

	if (cCSRList == dCSRList)
		cout << "cCSRList and dCSRList are equal" << endl; //this is correct
	else
		cout << "cCSRList and dCSRList are not equal" << endl;
}

// Pre: N/A Post: tests sparseRatio and averageSparseRatio function for CSR and CSRList
// sparseRation in CSR and averageSparseRation in CSRList
void sparseRatio() {
	cout << "\nTesting SparsityRatio of CSR object" << endl;
	int array1[] = { 10,20,0,0,0,0,0,30,0,40,0,0,0,0,50,60,70,0,0,0,0,0,0,80 };
	int array2[] = { 0,0,0,0,100,200,0,0,300 };
	CSR aCSR, bCSR, cCSR;
	aCSR.compress(4, 6, array1, 24);//initialize object aCSR
	bCSR.compress(3, 3, array2, 9);


	cout << "Dumping aCSR";
	aCSR.dump();

	cout << "\nDumping bCSR";
	bCSR.dump();

	cout << "\n**********************************************************" << endl;

	cout << "Sparsity of aCSR: " << aCSR.sparseRatio() << endl; //should be 66
	cout << "Sparsity of bCSR: " << bCSR.sparseRatio() << endl; //should be 66

	cout << "\n**********************************************************" << endl;

	CSRList aCSRList;
	aCSRList.insertAtHead(aCSR);
	aCSRList.insertAtHead(bCSR);
	aCSRList.insertAtHead(cCSR);


	cout << "\nDumping aCSRList";
	aCSRList.dump();

	cout << "\n**********************************************************" << endl;
	cout << "Arverage Sparsity of aCSRList: " << aCSRList.averageSparseRatio() << endl;
	cout << "Even though aCSRList had 3 objects because 1 is empty it wont count " << endl;
	cout << "toward calculation of average sparse ratio" << endl;
}


int main()
{
	cout << "FUNCTION CALLS COMMENTED OUT FOR CONVENIENCE TO THE GRADER" << endl;

	//testing
	cout << "\n---------FUNCTION: COPY CONSTRUCTOR---------" << endl;
	copyConstructor();
	cout << "\n---------FUNCTION: ASSIGNMENT OPERATOR---------" << endl;
	assignmentOperator();
	cout << "\n---------FUNCTION: CLEAR---------" << endl;
	testingClear();
	cout << "\n---------FUNCTION: COMPRESS---------" << endl;
	compress();
	cout << "\n---------FUNCTION: GET AT---------" << endl;
	getAt();
	cout << "\n---------FUNCTION: EQUALITY---------" << endl;
	equal();
	cout << "\n---------FUNCTION: SPARSE RATIO---------" << endl;
	sparseRatio();

	return 0;
}