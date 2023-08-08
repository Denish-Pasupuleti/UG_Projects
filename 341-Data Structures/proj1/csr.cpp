// CMSC 341 - Fall 2020 - Project 1
/*
	Author: Denish Pasupuleti
	Project: 1
	File: csr.cpp
	Email: mpasupu1@umbc.edu
	Description: .cpp file for csr.h
*/
#include "csr.h"
#include <stdexcept>

using namespace std;

// Constructor inilitailzes values for variables
CSR::CSR() {
	/***********************************
	 *      To be implemented
	 * ********************************/

	 // initialize variables
	m_values = nullptr;
	m_col_index = nullptr;
	m_row_index = nullptr;
	m_nonzeros = 0;
	m_m = 0;
	m_n = 0;
	m_next = nullptr;
}

// Destructor deletes and resets
CSR::~CSR() {
	/***********************************
	 *      To be implemented
	 * ********************************/

	 //deletes lists
	delete[] m_values;
	delete[] m_col_index;
	delete[] m_row_index;

	//reset
	m_values = nullptr;
	m_row_index = nullptr;
	m_col_index = nullptr;
	m_nonzeros = 0;
	m_m = 0;
	m_n = 0;
}

// copy constructor copies values individually
CSR::CSR(const CSR& rhs) {
	/***********************************
	 *      To be implemented
	 * ********************************/

	 // initializing values to default
	m_values = nullptr;
	m_col_index = nullptr;
	m_row_index = nullptr;
	m_nonzeros = 0;
	m_m = 0;
	m_n = 0;
	m_next = nullptr;

	if (!rhs.empty())
	{
		// copy over values from rhs
		m_m = rhs.m_m;
		m_n = rhs.m_n;
		m_nonzeros = rhs.m_nonzeros;

		//initialize arrays
		m_values = new int[m_nonzeros];
		m_col_index = new int[m_nonzeros];
		m_row_index = new int[m_m + 1];

		//copy over each element individually
		for (int i = 0; i < m_nonzeros; i++) {
			m_values[i] = rhs.m_values[i];
			m_col_index[i] = rhs.m_col_index[i];
		}
		for (int i = 0; i < m_m + 1; i++)
			m_row_index[i] = rhs.m_row_index[i];

		// next to nullptr
		m_next = nullptr;
	}
}

// dumps contents of CSR object
void CSR::dump() {
	cout << endl;
	if (!empty()) {
		for (int i = 0; i < m_nonzeros; i++)
			cout << m_values[i] << " ";
		cout << endl;
		for (int i = 0; i < m_nonzeros; i++)
			cout << m_col_index[i] << " ";
		cout << endl;
		for (int i = 0; i < m_m + 1; i++)
			cout << m_row_index[i] << " ";
	}
	else
		cout << "The object is empty!";
	cout << endl;
}

// clears CSR object
void CSR::clear() {
	/***********************************
	 *      To be implemented
	 * ********************************/

	 //deletes lists
	delete[] m_values;
	delete[] m_col_index;
	delete[] m_row_index;

	//reset
	m_values = nullptr;
	m_row_index = nullptr;
	m_col_index = nullptr;
	m_nonzeros = 0;
	m_m = 0;
	m_n = 0;
}

// checks if empty
bool CSR::empty() const {
	/***********************************
	 *      To be implemented
	 * Note: to avoid warnings, a
	 * fictional return value is added,
	 * your implementaion should return
	 * a correct value.
	 * ********************************/

	if (m_values == nullptr and m_col_index == nullptr and m_row_index == nullptr)
		return true;
	return false;
}

// compressing input array into sparse row form
void CSR::compress(int m, int n, int array[], int arraySize) {
	/***********************************
	 *      To be implemented
	 * ********************************/

	 // safeguard for recompression
	if (m_values != nullptr or m_row_index != nullptr or m_col_index != nullptr)
		clear();
	// if no valid matrix size then object is empty
	if (m * n <= 0 or m < 0 or n < 0 or arraySize < 0)
		return;
	// if m and n and arraySize exist and are valid continue
	// new arr because of resizing
	int* newArr = new int[m * n];
	// if no valid array then populate row index with 0s of m + 1 size
	if (arraySize == 0)
	{
		for (int i = 0; i < m * n; i++)
			newArr[i] = 0;
	}
	if (m * n == arraySize)
	{
		for (int i = 0; i < arraySize; i++)
			newArr[i] = array[i];
	}
	// edge cases(arraySize < m*n initliaze rest to 0
	if (arraySize < m * n) //initialize values to 0 up till m*n
	{
		// calculating new size
		int newSize = m * n;
		for (int i = 0; i < arraySize; i++)
			newArr[i] = array[i];
		for (int i = arraySize; i < newSize; i++)
			newArr[i] = 0;
		arraySize = newSize;
	}
	// arraySize > m*n truncate at arraySize = m * n
	if (arraySize > m * n) {
		cout << "Num of data members greater than (m x n)" << endl;
		arraySize = m * n;

		for (int i = 0; i < arraySize; i++)
			newArr[i] = array[i];
	}

	// reinitalizes all members
	m_m = m;
	m_n = n;
	m_row_index = new int[m_m + 1];
	m_nonzeros = 0;

	// need to get m_nonZeros(count) for m_values array size
	for (int x = 0; x < arraySize; x++)
		if (newArr[x] != 0)
			m_nonzeros++;

	// initializes m_values and m_col_index to size m_nonzeros
	m_values = new int[m_nonzeros];
	m_col_index = new int[m_nonzeros];

	//counter for m_values array index
	int nonZeroCounter = 0;
	for (int x = 0; x < arraySize; x++)
	{
		if (newArr[x] != 0)
		{
			// putting values in m_values array
			m_values[nonZeroCounter] = newArr[x];
			nonZeroCounter++;
		}
	}

	//counter vars to keep track of position and count
	int colCounter = 0; // tracks column index array position
	int rowCounter = 0; // tracks how many non zero values in row
	int rowPosition = 1; // tracks row index array position
	m_row_index[0] = 0;
	for (int i = 0; i < arraySize; i += (n))
	{
		//cout << "Goes into first for loop" << endl;
		for (int c = 0; c < n; c++)
		{
			//checks for nonZero entry
			if (newArr[i + c] != 0)
			{
				m_col_index[colCounter] = c; // adds index[0, n-1] to column index array
				colCounter++;
				rowCounter++;
			}
		}
		m_row_index[rowPosition] = rowCounter; // adds rowCounter to row index array
		rowPosition++;
	}
	// deletes memory of newArr
	delete[] newArr;
}

// gets value at certain position
int CSR::getAt(int row, int  col) const {
	/***********************************
	 *      To be implemented
	 * Note: to avoid warnings, a
	 * fictional return value is added,
	 * your implementaion should return
	 * a correct value.
	 * ********************************/

	 // checks validity of CSR/row/col
	if (!empty() and m_nonzeros != 0 and row >= 0 and row < m_m and col >= 0 and col < m_n)
	{
		// position variables
		int rowStart = m_row_index[row];
		int rowEnd = m_row_index[row + 1];

		// rerurns value if found or throws exception if not
		for (int i = rowStart; i < rowEnd; i++)
			if (m_col_index[i] == col)
				return m_values[i];
		return 0;
	}
	// throw error if value does not exist
	throw range_error("Value does not exists!");
}

// checks equality of 2 CSR objects
bool CSR::operator==(const CSR& rhs) const {
	/***********************************
	 *      To be implemented
	 * Note: to avoid warnings, a
	 * fictional return value is added,
	 * your implementaion should return
	 * a correct value.
	 * ********************************/

	 // checks if both empty
	if (empty() && rhs.empty())
		return true;
	// checks if int vars are not the same
	else if (m_nonzeros != rhs.m_nonzeros or m_m != rhs.m_m or m_n != rhs.m_n)
		return false;
	// checks size variables and arrays individually
	else if (m_nonzeros == rhs.m_nonzeros && m_m == rhs.m_m && m_n == rhs.m_n)
	{
		for (int i = 0; i < m_nonzeros; i++)
			if (m_values[i] != rhs.m_values[i] or m_col_index[i] != rhs.m_col_index[i])
				return false;
		for (int i = 0; i < m_m + 1; i++)
			if (m_row_index[i] != rhs.m_row_index[i])
				return false;
	}
	return true;
}

// returns sparse ratio
int CSR::sparseRatio() {
	/***********************************
	 *      To be implemented
	 * Note: to avoid warnings, a
	 * fictional return value is added,
	 * your implementaion should return
	 * a correct value.
	 * ********************************/

	 // # of zero values divided by total number of values = sparsity ratio

	if (empty())
		return 0;
	double ratio = (double((m_n * m_m) - m_nonzeros) / (m_n * m_m)) * 100.0;
	return int(ratio);
}