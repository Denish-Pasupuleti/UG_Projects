#include <iostream>

#include "car.h"
#include "hash.h"

// Prototype for 16 bit cyclic hash function; implementation is after
// main().
unsigned cyclic_hash16(string key);
unsigned hash_func(string key);

int main() {
  // Create a vector of cars to insert in the hash table
  vector<Car> cars;
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
  cars.push_back(Car("mkopoieyut", 15, "mega car"));
  cars.push_back(Car("miura", 99, "mega car"));

  // Create the hash table of length 10 using cyclic_hash function
  HashTable<Car> ht(10, hash_func);

  // Heap<Car> ht;

  vector<Car>::iterator itCar;
  for (itCar = cars.begin(); itCar != cars.end(); itCar++) ht.insert(*itCar);

  cout << "\nDump of ht:\n";
  ht.dump();

  // cout << "num entries: " << ht.numEntries() << endl;

  /*
  cout << "----------------------------------------" << endl;
  unsigned int size = ht.size();
  for (unsigned int i = 0; i < size; i++)
  {
          cout << "---------------------Removing: " << ht.readTop().priority()
  << endl; ht.removeTop(); ht.dump(); cout << endl;
  }


  // for removeTop
  try {
          ht.removeTop();
  }
  catch (std::range_error& e) {
          cout << "Exception caught: " << e.what() << endl;
  }


  // for readTop
  try {
          ht.readTop();
  }
  catch (std::range_error& e) {
          cout << "Exception caught: " << e.what() << endl;
  }
  */

  // test later

  Car d;
  vector<string> orders;
  orders.push_back("miura");
  orders.push_back("miura");
  orders.push_back("miura");
  // orders.push_back("challenger");
  // orders.push_back("gt500");
  // orders.push_back("stratos");
  // orders.push_back("x101");
  orders.push_back("mkopoieyut");
  orders.push_back("mkopoieyut");
  vector<string>::iterator itString;

  for (itString = orders.begin(); itString != orders.end(); itString++) {
    cout << "\nGet next '" << *itString << "' order...\n";
    if (ht.getNext(*itString, d)) {
      cout << "  " << d << endl;
    } else {
      cout << "  No " << *itString << " orders!\n";
    }
  }

  cout << endl;
  ht.dump();

  /*
  // Extract some orders

  Car d;
  vector<string> orders;

  orders.push_back("challenger");
  orders.push_back("miura");
  orders.push_back("gt500");
  orders.push_back("gt500");
  orders.push_back("gt500");

  vector<string>::iterator itString;

  for (itString = orders.begin(); itString != orders.end(); itString++) {
          cout << "\nGet next '" << *itString << "' order...\n";
          if (ht.getNext(*itString, d)) {
                  cout << "  " << d << endl;
          }
          else {
                  cout << "  No " << *itString << " orders!\n";
          }
  }

  cout << endl;

  cout << "\nDump of ht:\n";
  ht.dump();
  */

  /*
  // Simple test of copy constructor; also need to test assignment
  // operator!
  cout << "\nCreate copy of hash table, remove two 'stratos' orders from ht,
  dump both tables...\n";

  HashTable<Car> ht2(ht);

  ht.getNext("stratos", d);
  ht.getNext("stratos", d);

  cout << "\nDump of ht:\n";
  ht.dump();

  cout << "\nDump of ht2:\n";
  ht2.dump();

  // Simple test of assignment operator!
  cout << "\nAssigns ht3 to ht, remove two 'x101' orders from ht, dump both
  tables...\n";

  HashTable<Car> ht3 = ht;

  ht.getNext("x101", d);
  ht.getNext("x101", d);

  cout << "\nDump of ht:\n";
  ht.dump();

  cout << "\nDump of ht2:\n";
  ht3.dump();
  */

  return 0;
}

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

unsigned hash_func(string key) {
  unsigned int k = (int)key[0];
  k %= 10;
  return k;
}
