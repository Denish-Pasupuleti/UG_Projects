#include <time.h>

#include <iostream>

#include "car.h"
#include "hash.h"

unsigned cyclic_hash16(string key);
unsigned const_hash(string key);
Heap<Car> makeCarHeap(string car, int n);
void getAllCars(Heap<Car> *h);

int main() {
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

  {  // driver testing: ht insert(), ht dump(), ht copy(), ht getNext()
    cout << endl << "*******Begin driver.cpp Tests*******" << endl;
    HashTable<Car> ht(10, cyclic_hash16);

    vector<Car>::iterator itCar;
    for (itCar = cars.begin(); itCar != cars.end(); itCar++) ht.insert(*itCar);

    cout << "\nDump of ht:\n";
    ht.dump();

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
      } else {
        cout << "  No " << *itString << " orders!\n";
      }
    }

    cout << endl;

    cout << "\nDump of ht:\n";
    ht.dump();

    cout << "\nCreate copy of hash table, remove two 'stratos' orders, dump "
            "both tables...\n";

    HashTable<Car> ht2(ht);

    ht2.getNext("stratos", d);
    ht2.getNext("stratos", d);

    cout << "\nDump of ht:\n";
    ht.dump();

    cout << "\nDump of ht2:\n";
    ht2.dump();

    cout << endl << "*******driver.cpp Tests Complete*******" << endl;
  }  // driver.cpp testing complete

  {  // mytest testing: heap insertion, heap removal, heap property after
     // insertion and removal,
    // ht insert() into full ht, ht copy() and = overload,
    // time complexity of insertion into an empty heap, and removal of a heap
    // with one element.

    cout << endl << "*******Begin mytest.cpp Testing*******" << endl;

    // ------------------------ Heap Testing ------------------------
    cout << endl << "=======Heap Testing=======" << endl;
    Heap<Car> h;
    for (unsigned int i = 0; i < cars.size() - 1; i++) {
      h.insert(cars[i]);
    }
    cout << endl << "Dump of h:" << endl;
    h.dump();

    cout << endl << "Removing max..." << endl;
    h.removeTop();
    cout << endl << "Dump of h:" << endl;
    h.dump();

    cout << endl << "------------------------" << endl;
    Car temp = Car("rx7", 42, "yeehaw cars");
    cout << endl << "Inserting new max..." << temp << endl;
    h.insert(temp);
    cout << endl << "Dump of h:" << endl;
    h.dump();

    cout << endl << "------------------------" << endl;
    cout << endl << "Removing all elements..." << endl;
    while (!h.empty()) h.removeTop();
    cout << endl << "Dump of h:" << endl;
    h.dump();

    cout << endl << "------------------------" << endl;
    // readTop() on empty heap
    cout << endl << "Calling readTop() on an empty heap..." << endl;
    try {
      cout << h.readTop() << endl;
    } catch (range_error &e) {
      cout << "WARNING:exception-thrown=(" << typeid(e).name()
           << ") what():" << e.what() << endl;
    }
    cout << "Call complete." << endl;

    // removeTop() on empty heap
    cout << endl << "Calling removeTop() on an empty heap..." << endl;
    try {
      h.removeTop();
    } catch (range_error &e) {
      cout << "WARNING:exception-thrown=(" << typeid(e).name()
           << ") what():" << e.what() << endl;
    }
    cout << "Call complete." << endl;
    // ------------------------ Heap Testing Complete ------------------------

    // ------------------------ HashTable Testing ------------------------
    cout << endl
         << "=======HashTable Linear Probing with a Constant hash_fn======="
         << endl;
    HashTable<Car> ht(10, const_hash);
    for (unsigned int i = 0; i < cars.size() - 1; i++) {
      ht.insert(cars[i]);
    }
    ht.insert(temp);
    cout << endl << "Dump of ht:" << endl;
    ht.dump();

    cout << endl << "------------------------" << endl;
    // full ht insertion
    cout << endl << "Inserting f150 into a full ht..." << endl;
    ht.insert(Car("supra", 14, "blarksburg auto"));
    ht.insert(Car("s2000", 2, "balti cars"));
    ht.insert(Car("s15 silvia", 24, "world auto"));
    ht.insert(Car("nsx", 19, "used JDM"));

    cout << endl << "Dump of ht:" << endl;
    ht.dump();

    cout << endl << "------------------------" << endl;
    Car extra("f150", 1, "big truck co");
    cout << endl << "Trying to insert extra car: " << (extra) << "..." << endl;
    if (ht.insert(extra))
      cout << endl << "Extra car inserted!" << endl;
    else
      cout << "Extra car ignored!" << endl;

    // getNext() on nonexistent car
    cout << endl << "Calling getNext() on f150 (not in ht)..." << endl;
    cout << "Trying to get extra car: " << (extra) << "..." << endl;
    if (ht.getNext("f150", extra))
      cout << endl << "f150 found!" << endl;
    else
      cout << "f150 not found!" << endl;

    Car a;
    cout << endl
         << "=======Testing Copy Constructor and = Assignment Overload======="
         << endl;
    // copy and = assignment
    HashTable<Car> ht2(ht), ht3 = ht;
    cout << endl << "Clearing ht..." << endl;
    for (unsigned int i = 0; i < cars.size() - 1; i++) {
      ht.getNext(cars[i].key(), a);
    }
    ht.getNext("supra", a);
    ht.getNext("s2000", a);
    ht.getNext("s15 silvia", a);
    ht.getNext("nsx", a);
    ht.getNext("rx7", a);

    cout << endl << "Dump of ht:" << endl;
    ht.dump();
    cout << endl;

    cout << endl << "------------------------" << endl;
    cout << "Removing x101 from ht2..." << endl;
    ht2.getNext("x101", a);
    cout << "Removing x101 from ht2..." << endl;
    ht2.getNext("x101", a);
    cout << endl << "Dump of ht2 (copy'ed):" << endl;
    ht2.dump();
    cout << endl;

    cout << endl << "------------------------" << endl;
    cout << "Inserting rx7 to ht3..." << endl;
    ht3.insert(Car("rx7", 4, "world auto"));
    cout << endl << "Dump of ht3 (= assigned):" << endl;
    ht3.dump();

    cout << endl
         << "=======Testing Reinsertion of a Key to a Used and Empty "
            "Bucket======="
         << endl;
    cout << endl << "Removing s15 silvia from ht3..." << endl;
    ht3.getNext("s15 silvia", a);
    cout << endl << "Dump of ht3 (s15 silvia removed):" << endl;
    ht3.dump();
    cout << endl << "------------------------" << endl;
    ht3.insert(Car("s15 silvia", 1, "car"));
    cout << endl << "Dump of ht3 (attempted s15 reinsertion):" << endl;
    ht3.dump();

    cout << endl << "------------------------" << endl;
    {  // empty copy constructor
      HashTable<Car> empty(0, const_hash);
      HashTable<Car> emptyHt = HashTable<Car>(empty);
      cout << endl << "Dump of ht (empty copy):" << endl;
      emptyHt.dump();
    }

    {  // empty = assignment
      HashTable<Car> empty(0, const_hash);
      HashTable<Car> emptyHt = empty;
      cout << endl << "Dump of ht (empty = assignment):" << endl;
      emptyHt.dump();
    }

    cout << endl << "*******mytest.cpp Testing Complete*******" << endl;
  }
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

// for linear probing purposes
unsigned const_hash(string key) { return 3; }