// Title: mytest.cpp
// Author: Hamza Asad
// Date: 11/12/2020
// Description: This is part of Project 4 (Hash Table of Heaps) in CMSC 341.
// This is the cpp file that tests functions in hash.h and heap.h

#include "car.h"
#include "hash.h"

unsigned cyclic_hash16(string key);
unsigned firstLetterHash(string key);

int main() {
  // Creating empty heap and dumping
  Heap<Car> testHeap;
  cout << "Output When Test Heap is Empty: " << endl;
  testHeap.dump();
  cout << endl;

  // Setting up vector of 10 cars that will be inserted into heap
  vector<Car> heapTestCars;
  heapTestCars.push_back(Car("test", 6, "TestCars"));
  heapTestCars.push_back(Car("test", 3, "TestCars"));
  heapTestCars.push_back(Car("test", 8, "TestCars"));
  heapTestCars.push_back(Car("test", 22, "TestCars"));
  heapTestCars.push_back(Car("test", 27, "TestCars"));
  heapTestCars.push_back(Car("test", 15, "TestCars"));
  heapTestCars.push_back(Car("test", 18, "TestCars"));
  heapTestCars.push_back(Car("test", 26, "TestCars"));
  heapTestCars.push_back(Car("test", 15, "TestCars"));
  heapTestCars.push_back(Car("test", 23, "TestCars"));

  // Inserting vector cars into heap via vector iterator
  cout << "Inserting 10 cars into Test Heap..." << endl;
  vector<Car>::iterator currHeapTest;
  for (currHeapTest = heapTestCars.begin(); currHeapTest != heapTestCars.end();
       currHeapTest++)
    testHeap.insert(*currHeapTest);

  // Dump Heap
  cout << "Dumping Populated Heap: " << endl;
  testHeap.dump();
  cout << endl;

  // Call RemoveTop on Test Heap 5 times
  cout << "Removing max 5 times...." << endl;
  for (int i = 0; i < 5; i++) {
    testHeap.removeTop();
  }

  // Dump Heap after removals
  cout << "Dumping Heap after removals: " << endl;
  testHeap.dump();

  // Remove remaining cars
  cout << "Removing remaining cars...." << endl;
  for (int i = 0; i < 5; i++) {
    testHeap.removeTop();
  }

  // Dump Heap after all cars have been removed
  cout << "Dumping Heap after all cars have been removed: " << endl;
  testHeap.dump();
  cout << endl;

  // Calling readTop and removeTop on now empty Heap
  cout << "Calling readTop and removeTop on now empty Heap:" << endl;

  try {
    testHeap.readTop();
  } catch (std::range_error &e) {
    cout << e.what() << endl;
  }

  try {
    testHeap.removeTop();
  } catch (std::range_error &e) {
    cout << e.what() << endl;
  }
  cout << endl;

  // Creating an empty hash with 10 indicies and then dumping it
  cout << "Creating empty hash with 10 buckets ([0]-[9])and then dumping it"
       << endl;
  HashTable<Car> testHash(10, firstLetterHash);
  testHash.dump();
  cout << endl;

  // Setting up vector of 5 cars that will be inserted into hash
  vector<Car> hashTestCars;
  hashTestCars.push_back(Car("mustang", 6, "TestCars"));
  hashTestCars.push_back(Car("darer", 3, "TestCars"));
  hashTestCars.push_back(Car("darer", 8, "TestCars"));
  hashTestCars.push_back(Car("mustang", 22, "TestCars"));
  hashTestCars.push_back(Car("darer", 27, "TestCars"));

  // Inserting vector cars into hashtable via vector iterator (no collisions
  // yet)
  cout << "Inserting test cars into Test Hash Table (no collisions will "
          "occur)...."
       << endl;
  vector<Car>::iterator currHashTest;
  for (currHashTest = hashTestCars.begin(); currHashTest != hashTestCars.end();
       currHashTest++)
    testHash.insert(*currHashTest);

  // Dump Hash
  cout << "Dumping Hash Table: " << endl;
  testHash.dump();
  cout << endl;
  cout << "_N: " << testHash.tableSize() << endl;
  cout << "_n: " << testHash.numEntries() << endl;
  cout << "load Factor: " << testHash.lambda() << endl;
  cout << endl;

  // Setting up vector of another 5 cars that will be inserted into hash
  vector<Car> hashTestCars2;
  hashTestCars2.push_back(Car("gased", 19, "TestCars"));
  hashTestCars2.push_back(Car("darer", 7, "TestCars"));
  hashTestCars2.push_back(Car("master", 29, "TestCars"));
  hashTestCars2.push_back(Car("master", 30, "TestCars"));
  hashTestCars2.push_back(Car("mancar", 12, "TestCars"));

  // Inserting vector cars into hashtable via vector iterator (collisions will
  // occur now)
  cout << "Inserting test cars into Test Hash Table (collisions will occur)...."
       << endl;
  vector<Car>::iterator currHashTest2;
  for (currHashTest2 = hashTestCars2.begin();
       currHashTest2 != hashTestCars2.end(); currHashTest2++)
    testHash.insert(*currHashTest2);

  // Dump Hash
  cout << "Dumping Hash Table: " << endl;
  testHash.dump();
  cout << endl;
  cout << "_N: " << testHash.tableSize() << endl;
  cout << "_n: " << testHash.numEntries() << endl;
  cout << "load Factor: " << testHash.lambda() << endl;
  cout << endl;

  // Setting up a vector of another 6 cars to fill all buckets in hash
  vector<Car> hashTestCars3;
  hashTestCars3.push_back(Car("hater", 1, "TestCars"));
  hashTestCars3.push_back(Car("ionater", 16, "TestCars"));
  hashTestCars3.push_back(Car("jester", 14, "TestCars"));
  hashTestCars3.push_back(Car("killer bee", 3, "TestCars"));
  hashTestCars3.push_back(Car("lover", 17, "TestCars"));
  hashTestCars3.push_back(Car("master", 33, "TestCars"));

  // Inserting vector cars into hashtable via vector iterator (no collisions
  // here)
  cout << "Inserting test cars into Test Hash Table to fill buckets (no "
          "collisions here)...."
       << endl;
  vector<Car>::iterator currHashTest3;
  for (currHashTest3 = hashTestCars3.begin();
       currHashTest3 != hashTestCars3.end(); currHashTest3++)
    testHash.insert(*currHashTest3);

  // Dump Hash
  cout << "Dumping Hash Table: " << endl;
  testHash.dump();
  cout << endl;
  cout << "_N: " << testHash.tableSize() << endl;
  cout << "_n: " << testHash.numEntries() << endl;
  cout << "load Factor: " << testHash.lambda() << endl;
  cout << endl;

  // Trying to insert a new car with a new key into already full hash table
  // (will cause a collision)!
  cout << "Inserting a car with a new key into already full hash table (will "
          "cause a collision) : "
       << endl;
  Car newCar("apple", 20, "TestCars");
  if (testHash.insert(newCar)) {
    cout << "insertion successful" << endl;
  } else {
    cout << "insertion unsuccessful" << endl;
  }

  // Dump Hash
  cout << "Dumping Hash Table: " << endl;
  testHash.dump();
  cout << endl;
  cout << "_N: " << testHash.tableSize() << endl;
  cout << "_n: " << testHash.numEntries() << endl;
  cout << "load Factor: " << testHash.lambda() << endl;
  cout << endl;

  // Calling getNext on hash table that won't cause collision
  cout << "Calling getNext on hash table that won't cause collision: " << endl;
  Car aCar;
  if (testHash.getNext("darer", aCar)) {
    cout << aCar << " was successfully removed" << endl;
  } else {
    cout << "darer"
         << " was not successfully removed" << endl;
  }

  // Dump Hash
  cout << "Dumping Hash Table: " << endl;
  testHash.dump();
  cout << endl;
  cout << "_N: " << testHash.tableSize() << endl;
  cout << "_n: " << testHash.numEntries() << endl;
  cout << "load Factor: " << testHash.lambda() << endl;
  cout << endl;

  // Calling getNext on hash that will cause collision
  cout << "Calling getNext on hash table that will cause collision: " << endl;
  if (testHash.getNext("mancar", aCar)) {
    cout << aCar << " was successfully removed" << endl;
  } else {
    cout << "mancar"
         << " was not successfully removed" << endl;
  }

  // Dump Hash
  cout << "Dumping Hash Table: " << endl;
  testHash.dump();
  cout << endl;
  cout << "_N: " << testHash.tableSize() << endl;
  cout << "_n: " << testHash.numEntries() << endl;
  cout << "load Factor: " << testHash.lambda() << endl;
  cout << endl;

  // Calling getNext on hash on car that doesn't exist that will cause collision
  cout << "Calling getNext on hash table on car that doesn't exist that will "
          "cause collision: "
       << endl;
  if (testHash.getNext("mancar", aCar)) {
    cout << aCar << " was successfully removed" << endl;
  } else {
    cout << "mancar"
         << " was not successfully removed" << endl;
  }

  // Dump Hash
  cout << "Dumping Hash Table: " << endl;
  testHash.dump();
  cout << endl;
  cout << "_N: " << testHash.tableSize() << endl;
  cout << "_n: " << testHash.numEntries() << endl;
  cout << "load Factor: " << testHash.lambda() << endl;
  cout << endl;

  // Copy constructor test on Hash Table + removing lover to test for deep copy
  cout << "Copy Constructor Test On Hash Table and remove lover!" << endl;
  HashTable<Car> testHash2(testHash);
  testHash2.getNext("lover", aCar);

  cout << "Dumping Original Hash Table: " << endl;
  testHash.dump();
  cout << endl;
  cout << "_N: " << testHash.tableSize() << endl;
  cout << "_n: " << testHash.numEntries() << endl;
  cout << "load Factor: " << testHash.lambda() << endl;
  cout << endl;

  cout << "Dumping copy Hash Table: " << endl;
  testHash2.dump();
  cout << endl;
  cout << "_N: " << testHash2.tableSize() << endl;
  cout << "_n: " << testHash2.numEntries() << endl;
  cout << "load Factor: " << testHash2.lambda() << endl;
  cout << endl;

  // Assignment operator test on Hash Table + removing ionator to test for deep
  // copy
  cout << "Assignment Operator Test On Hash Table and remove ionater!" << endl;
  testHash2 = testHash;
  testHash2.getNext("ionater", aCar);

  cout << "Dumping Original Hash Table: " << endl;
  testHash.dump();
  cout << endl;
  cout << "_N: " << testHash.tableSize() << endl;
  cout << "_n: " << testHash.numEntries() << endl;
  cout << "load Factor: " << testHash.lambda() << endl;
  cout << endl;

  cout << "Dumping copy via assigmnent operator Hash Table: " << endl;
  testHash2.dump();
  cout << endl;
  cout << "_N: " << testHash2.tableSize() << endl;
  cout << "_n: " << testHash2.numEntries() << endl;
  cout << "load Factor: " << testHash2.lambda() << endl;
  cout << endl;

  // Copy and Assignment Operator Test on 10 bucket empty hash table! Insert
  // different car in both
  cout << "Creating copies via copy constructor and assignment operator of "
          "empty hash table and inserting different car in each:"
       << endl;
  HashTable<Car> emptyHash(10, firstLetterHash);
  HashTable<Car> emptyHash2(emptyHash);
  emptyHash2.insert(newCar);
  HashTable<Car> emptyHash3 = emptyHash;
  Car newCar2("menace", 9, "TestCars");
  emptyHash3.insert(newCar2);

  // Dumping original empty hash table and copies
  cout << "Dumping Original Hash Table: " << endl;
  emptyHash.dump();
  cout << endl;
  cout << "_N: " << emptyHash.tableSize() << endl;
  cout << "_n: " << emptyHash.numEntries() << endl;
  cout << "load Factor: " << emptyHash.lambda() << endl;
  cout << endl;

  cout << "Dumping Copy Constructor copied Hash Table: " << endl;
  emptyHash2.dump();
  cout << endl;
  cout << "_N: " << emptyHash2.tableSize() << endl;
  cout << "_n: " << emptyHash2.numEntries() << endl;
  cout << "load Factor: " << emptyHash2.lambda() << endl;
  cout << endl;

  cout << "Dumping assignment operator copied Hash Table: " << endl;
  emptyHash3.dump();
  cout << endl;
  cout << "_N: " << emptyHash3.tableSize() << endl;
  cout << "_n: " << emptyHash3.numEntries() << endl;
  cout << "load Factor: " << emptyHash3.lambda() << endl;
  cout << endl;

  // Self Assignment Test
  emptyHash3 = emptyHash3;
  cout << "Dumping Hash Table: " << endl;
  emptyHash3.dump();
  cout << endl;
  cout << "_N: " << emptyHash3.tableSize() << endl;
  cout << "_n: " << emptyHash3.numEntries() << endl;
  cout << "load Factor: " << emptyHash3.lambda() << endl;
  cout << endl;

  return 0;
}

unsigned cyclic_hash16(string key) {
  unsigned usize = 16;
  unsigned s = 5;  // shift by 5
  unsigned h = 0;
  for (unsigned i = 0; i < key.length(); i++) {
    h = ((h << s) | (h >> (usize - s)));
    h += key[i];
    h = h & 0xffff;
  }
  return h;
}

unsigned firstLetterHash(string key) {
  unsigned int h = (int)key[0];
  return h;
}
