// CMSC 341 - Fall 2020 - Project 4
// hash.h

// Templated, hash table implementation.  Each buckets is a heap.  A
// bucket contains objects with the same key values stored as a
// max-heap based on priority.  Collisions are resolved by linear
// probing.

// To work with Heap and HashTable, the template class T must provide
// the following:
//  (a) Default constructor
//  (b) priority function (unsigned priority())
//  (c) key function (string key())
//  (d) overloaded insertion operator

#ifndef _HASH_H
#define _HASH_H

#include <string>

#include "heap.h"

using std::string;

// Hash function typedef.  The hash function must return an 'unsigned
// int' value.  Reduction mod N is the responsiblity of the caller,
// not the hash function.
typedef unsigned (*hash_fn)(string);

class Grader;

template <class T>
class HashTable {
  friend Grader;

 public:
  // Constructor.  Requires table size and hash function.
  HashTable(unsigned size, hash_fn hash);

  // Destructor, copy, and assignment
  ~HashTable();
  HashTable(const HashTable<T> &ht);
  const HashTable<T> &operator=(const HashTable<T> &ht);

  // In-line functions

  // Table size; set by constructor
  unsigned tableSize() const { return _N; }
  // Number of entries in the table
  unsigned numEntries() const { return _n; }
  // Load factor
  float lambda() const { return ((float)_n) / _N; }

  // Main hash table functions

  // insert returns 'true' if successful; 'false' otherwise
  bool insert(const T &object);
  // getNext retrieves **and removes** the highest priority order of
  // type indicated by key.  It returns 'true' if successful; 'false'
  // otherwise.
  bool getNext(string key, T &obj);

  // Dump the entire hash table
  void dump() const;

 private:
  unsigned _N;      // hash table size
  unsigned _n;      // current number of entries
  hash_fn _hash;    // hash function
  Heap<T> *_table;  // array of heaps

  // ***********************************************
  // Private helper function declarations go here! *
  // ***********************************************
};

// *****************************************
// Templated function definitions go here! *
// *****************************************
// constructor
template <class T>
HashTable<T>::HashTable(unsigned size, hash_fn hash) {
  // sets size and hash function
  _N = size;
  _n = 0;
  _hash = hash;
  if (_N == 0) _table = nullptr;
  // allocates memory for heap
  _table = new Heap<T>[_N];
}

// destructor
template <class T>
HashTable<T>::~HashTable() {
  // deletes table and resets vars
  if (_table != nullptr) delete[] _table;
  _N = 0;
  _n = 0;
  _hash = nullptr;
  _table = nullptr;
}

// copy constructor
template <class T>
HashTable<T>::HashTable(const HashTable<T> &ht) {
  // sets vars
  _hash = ht._hash;
  _N = ht._N;
  _n = ht._n;
  // creates new heap of size _N
  _table = new Heap<T>[_N];
  // copies over contents
  for (unsigned int i = 0; i < _N; i++) _table[i] = ht._table[i];
}

// assignmnet operator
template <class T>
const HashTable<T> &HashTable<T>::operator=(const HashTable<T> &ht) {
  // self assignment check
  if (this != &ht) {
    // delete table and set vars to ht vars
    delete[] _table;
    _N = ht._N;
    _n = ht._n;
    _hash = ht._hash;
    if (_N == 0) _table = nullptr;
    _table = new Heap<T>[_N];
    // copy over heaps of ht table
    if (ht._table != nullptr) {
      for (unsigned int i = 0; i < _N; i++) _table[i] = ht._table[i];
    }
    return *this;
  }
  cout << "Tried to self assign; action did not run" << endl;
  return *this;
}

// inserts into empty and unused bucket in hash table
template <class T>
bool HashTable<T>::insert(const T &object) {
  if (_N == 0) return false;
  // gets hashIndex to insert object
  unsigned int hashIndex = _hash(object.key());
  hashIndex %= _N;

  // if heap at hashIndex not empty
  if (_table[hashIndex].size() > 0) {
    // if object key doesnt match heap key
    if (_table[hashIndex].readTop().key() != object.key()) {
      // end = termination var
      int end = 0;
      unsigned int index = hashIndex;
      index++;

      while (end != 1) {
        // if index reaches table size mod by _N
        if (index >= _N) index %= _N;
        // if index probes all the to its self
        if (index == hashIndex) {
          end = 1;
          return false;
        }
        // insert on empty table
        // if used and empty skip bucket
        if (_table[index].used() == true and _table[index].size() == 0)
          index++;
        else if (_table[index].size() > 0 and
                 _table[index].readTop().key() == object.key()) {
          _table[index].insert(object);
          end = 1;
          return true;
        } else if (_table[index].size() == 0) {
          _table[index].insert(object);
          end = 1;
          _n++;
          return true;
        }
        // insert object into existing heap with matching key
        index++;
      }
    }
  }
  // if tables is empty increase _n
  if (_table[hashIndex].size() == 0) _n++;
  _table[hashIndex].insert(object);
  return true;
}

// removes bucket's(root) with key
template <class T>
bool HashTable<T>::getNext(string key, T &obj) {
  // empty hashTable
  if (_n <= 0) return false;
  // get hash index
  unsigned int hashIndex = _hash(key);
  hashIndex %= _N;
  T temp;

  // if heap at hashIndex has cars and key matches obj key
  if (_table[hashIndex].size() > 0 and
      (_table[hashIndex].readTop().key()).compare(key) == 0) {
    // store top in temp
    temp = _table[hashIndex].readTop();
    // remove top
    _table[hashIndex].removeTop();
    obj = temp;
    // if heap is empty then reduce numEntries
    if (_table[hashIndex].size() == 0) _n--;
    return true;
  }
  // if heap key doesnt match with object key
  else {
    int end = 0;
    unsigned int index = hashIndex;
    index++;

    // traverse until find key
    while (end != 1) {
      if (index >= _N) index %= _N;
      // check for end linear probing
      if (index == hashIndex) {
        end = 1;
        return false;
      }
      if (_table[index].used() == false) {
        // linear probing will stop because it hit in unused bucket
        end = 1;
        return false;
      }
      // if the heap has objects the compare to obj key
      if (_table[index].size() > 0) {
        if ((_table[index].readTop().key()).compare(key) == 0) {
          temp = _table[index].readTop();
          _table[index].removeTop();

          obj = temp;

          if (_table[index].size() == 0) _n--;
          end = 1;
          return true;
        }
      }
      // increase index
      index++;
    }
  }
  return false;
}

// dumps contents of hashtable
template <class T>
void HashTable<T>::dump() const {
  if (_table != nullptr) {
    for (unsigned int i = 0; i < _N; i++) {
      cout << "[" << i << "]:" << endl;
      _table[i].dump();
    }
    cout << endl;
  }
}
#endif
