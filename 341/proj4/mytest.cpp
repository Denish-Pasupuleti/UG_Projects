/*
Author: Denish Pasupuleti
File: mytest.cpp
Description: Driver for hashTable and heap
*/
#include <iostream>

#include "car.h"
#include "hash.h"

// Prototype for 16 bit cyclic hash function; implementation is after
// main().
unsigned cyclic_hash16(string key);
unsigned dHash(string key);
unsigned constant_hash(string key);
void heap_test(vector<Car> &cars);
void hash_test(vector<Car> &cars);

int main() {
  vector<Car> cars;  // vector of cars to be inserted
  cars.push_back(Car("x101", 5, "super car"));
  cars.push_back(Car("x101", 12, "mega car"));
  cars.push_back(Car("x101", 4, "shack of cars"));
  cars.push_back(Car("challenger", 10, "mega car"));
  cars.push_back(Car("challenger", 5, "car world"));
  cars.push_back(Car("stratos", 7, "car world"));
  cars.push_back(Car("stratos", 15, "super car"));
  cars.push_back(Car("stratos", 8, "shack of cars"));
  cars.push_back(Car("challenger", 3, "car joint"));
  cars.push_back(Car("gt500", 3, "shack of cars"));
  cars.push_back(Car("miura", 28, "mega car"));
  cars.push_back(Car("gt500", 11, "super car"));

  // heap testing
  heap_test(cars);
  cout << endl << endl;
  cout << "*************************Testing HashTable*************************"
       << endl;
  // hash/heap testing
  hash_test(cars);
  return 0;
}

// testing heap class individually
void heap_test(vector<Car> &cars) {
  Heap<Car> heap;  // Heap object
  // inserting all cars into heap
  vector<Car>::iterator itCar;
  for (itCar = cars.begin(); itCar != cars.end(); itCar++) heap.insert(*itCar);

  cout << "Cars inserted!" << endl;
  // expected output in array form
  cout << "Expected Output(priority): 28, 15, 12, 8, 10, 11, 7, 5, 3, 3, 5, 4"
       << endl;
  cout << "\nDump of heap:\n";
  heap.dump();
  cout << endl;

  // ReadTop test
  cout << "********************************************" << endl;
  cout << "readTop test; Expected OutPut: miura, 28, mega car" << endl;
  Car top = heap.readTop();
  cout << "Output: " << top << endl;
  cout << endl;

  // RemoveTop test
  cout << "********************************************" << endl;
  heap.removeTop();
  cout << "removeTop test" << endl;
  cout << "Expected Output(priority): 15, 10, 12, 8, 5, 11, 7, 5, 3, 3, 4"
       << endl;
  cout << "\nDump of heap:\n";
  heap.dump();
  cout << endl;

  // Remove all car objects
  cout << "********************************************" << endl;
  cout << "Removing all elements from heap" << endl;
  // Removing all elements from heap
  unsigned int size = heap.size();
  for (unsigned int i = 0; i < size; i++) heap.removeTop();

  cout << "\nDump of heap(should be empty):\n";
  heap.dump();
  cout << endl;

  // Calling readTop on an empty heap
  cout << "********************************************" << endl;
  cout << "calling readTop on an empty heap(should throw exception)" << endl;
  try {
    heap.readTop();
  } catch (std::range_error &e) {
    cout << "Exception caught: " << e.what() << endl;
    cout << endl;
  }

  // Calling removeTop on an empty heap
  cout << "********************************************" << endl;
  cout << "calling removeTop on an empty heap(should throw exception)" << endl;
  try {
    heap.removeTop();
  } catch (std::range_error &e) {
    cout << "Exception caught: " << e.what() << endl;
    cout << endl;
  }
}

// Testing hash class
void hash_test(vector<Car> &cars) {
  // Insert Test
  cout << endl
       << "Insert Test(provided hash function doesnt provide many collisions)"
       << endl;
  HashTable<Car> ht(10, cyclic_hash16);
  // inserting cars into hashTable
  vector<Car>::iterator itCar;
  for (itCar = cars.begin(); itCar != cars.end(); itCar++) ht.insert(*itCar);
  cout << "\nDump of ht:\n";
  ht.dump();

  // getNext test
  cout << "********************************************" << endl;
  cout << endl << "getNext Test" << endl;

  // Extract some orders
  Car d;
  vector<string> orders;
  orders.push_back("challenger");
  orders.push_back("miura");
  orders.push_back("gt500");
  orders.push_back("gt500");
  orders.push_back("gt500");
  orders.push_back("miura");
  orders.push_back("challenger");
  orders.push_back("challenger");
  orders.push_back("challenger");

  vector<string>::iterator itString;

  for (itString = orders.begin(); itString != orders.end(); itString++) {
    cout << "\nGet next '" << *itString << "' order...\n";
    if (ht.getNext(*itString, d))
      cout << "  " << d << endl;
    else
      cout << "  No " << *itString << " orders!\n";
  }

  cout << endl;
  cout << "\nDump of ht:\n";
  ht.dump();
  cout << endl;

  // Insert with collisions
  cout << "********************************************" << endl;
  cout << "Insert Test(personal hash function has collisions)" << endl;
  HashTable<Car> collisionHT(10, constant_hash);
  for (itCar = cars.begin(); itCar != cars.end(); itCar++)
    collisionHT.insert(*itCar);
  cout << "\nDump of collisionHT:\n";
  collisionHT.dump();
  cout << endl;

  cout << "Added more cars to show index wraps around" << endl;
  // adding few more cars so we can see index wraps around
  collisionHT.insert(Car("mkopoieyut", 15, "mega car"));
  collisionHT.insert(Car("adder", 99, "omega car"));
  collisionHT.insert(Car("diamond", 4, "super car"));
  collisionHT.insert(Car("grader", 8, "bumper car"));
  collisionHT.insert(Car("chevy", 20, "normal car"));

  cout << "Dump of collisionHT:\n";
  collisionHT.dump();

  // Testing fully loaded hash table
  cout << "********************************************" << endl;
  cout << "Hash Table is full" << endl;
  cout << endl;

  // inserting existsing key when hash table is full
  cout << "Inserting car with already existing key" << endl;
  if (collisionHT.insert(Car("chevy", 89, "super car")))
    cout << "Insert Successfull(matching key in hash table)" << endl;
  else
    cout << "Insert Failed" << endl;
  cout << endl;

  // inserting unique key when hash table is full
  cout << "Trying insert operation with unique key" << endl;
  if (collisionHT.insert(Car("mercedes", 100, "awesome car")))
    cout << "Insert Successfull" << endl;
  else
    cout << "Insert Failed; HashTable is full" << endl;

  cout << endl;
  // edge case
  cout << "********************************************" << endl;
  HashTable<Car> edgeCase(10, constant_hash);
  edgeCase.insert((Car("x101", 5, "super car")));
  edgeCase.insert(Car("meek", 12, "mega car"));
  edgeCase.insert(Car("gay", 4, "shack of cars"));
  edgeCase.insert(Car("challenger", 10, "mega car"));

  cout << endl;
  cout << "original" << endl;
  edgeCase.dump();

  edgeCase.getNext("meek", d);
  edgeCase.insert(Car("justin", 10, "mega car"));
  edgeCase.insert(Car("challenger", 10, "mega car"));

  cout << endl;
  cout << "Edge case dump" << endl;
  edgeCase.dump();

  // copy constructor
  cout << endl;
  cout << "********************************************" << endl;
  cout << "Testing copy constructor" << endl;
  HashTable<Car> copy(collisionHT);
  cout << "Dump of copy:\n";
  copy.dump();

  // testing for deep copy
  cout << endl;
  cout << "calling getNext on original(chevy)" << endl;
  collisionHT.getNext("chevy", d);
  cout << "Dump of original:\n";
  collisionHT.dump();
  // dump of copy after getnext on original
  cout << "\nDump of copy:\n";
  copy.dump();

  cout << "Testing empty copy constructor" << endl;
  HashTable<Car> empty1(10, constant_hash);
  HashTable<Car> empty2(empty1);
  cout << "dump of empty hashTable" << endl;
  empty2.dump();

  // assignment operator
  cout << "********************************************" << endl;
  cout << "Testing assingment operator" << endl;
  HashTable<Car> assign = copy;
  cout << "\nDump of assign:\n";
  assign.dump();

  // testing for deep copy
  cout << endl;
  cout << "calling getNext on original(chevy)" << endl;
  copy.getNext("chevy", d);
  cout << "Dump of copy(original):\n";
  copy.dump();
  // dump of assign
  cout << "\nDump of assign:\n";
  assign.dump();
  cout << endl;

  cout << "Testing for self assignment" << endl;
  assign = assign;
  cout << endl;

  cout << "Testing empty assignment operator" << endl;
  collisionHT = empty1;
  cout << "Dump of collisionHT(after setting to empty):\n";
  collisionHT.dump();

  HashTable<Car> zero(0, constant_hash);
  zero.insert(Car("justin", 10, "mega car"));

  cout << "hash of zero" << endl;
  zero.dump();
}

// provided hash func
unsigned cyclic_hash16(string key) {
  unsigned usize = 16;
  unsigned s = 5;  // shift by 5
  unsigned h = 0;
  for (unsigned int i = 0; i < key.length(); i++) {
    h = ((h << s) | (h >> (usize - s)));
    h += key[i];
    h = h & 0xffff;
  }
  return h;
}

// constant hash for easy collisions
unsigned constant_hash(string key) {
  unsigned int k = 3;
  return k;
}