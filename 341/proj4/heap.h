// CMSC 341 - Fall 2020 - Project 4
// heap.h
// Templated, vector-based heap implementation

// To work with Heap, the template class T must provide the following:
//  (a) Default constructor
//  (b) priority function (unsigned priority())
//  (c) overloaded insertion operator
// To work with Heap *and* HashTable, it also needs:
//  (d) key function (string key())

#ifndef _HEAP_H
#define _HEAP_H

#include <exception>
#include <iostream>
#include <utility>  // swap
#include <vector>

using std::cout;
using std::endl;
using std::range_error;
using std::swap;
using std::vector;

// To work with Heap and HashTable, class T must provide the
// following:
//  (a) Default constructor
//  (b) priority function (unsigned priority())
//  (c) key function (string key())
//  (d) overloaded insertion operator

class Grader;

template <class T>
class Heap {
  friend Grader;

 public:
  // Constructor
  Heap();

  // Inline functions: size, empty, used
  unsigned size() const { return _heap.size() - 1; }
  bool empty() const { return _heap.size() <= 1; }
  bool used() const { return _used; }

  // Main heap operations: insert, read, remove
  void insert(const T &object);
  T readTop() const;
  void removeTop();

  // Dump the entire heap
  void dump() const;

  // Root node always has index 1
  static const unsigned ROOT = 1;

 private:
  vector<T> _heap;  // Vector-based heap
  bool _used;       // Has the heap ever been used?  Needed for
                    // linear probing.

  // *********************************************
  // Private helper function declarations go here!
  // *********************************************
};

// ***************************************
// Templated function definitions go here!
// ***************************************

// constructor
template <class T>
Heap<T>::Heap() {
  _used = false;
  // empty object at 0th index
  T empty;
  _heap.push_back(empty);
}

// inserts car object and amintains max heap property
template <class T>
void Heap<T>::insert(const T &object) {
  // oth position is garbage
  // adds object to vector
  _heap.push_back(object);

  int end = 0;
  int current = ((_heap.size() - 1) / 2);

  // change to see if u can reduce to 1 if
  if (_heap.size() > 3) {
    // while loop to traverse vector
    while (end != 1) {
      int hSize = _heap.size();
      int left = current * 2;
      int right = current * 2 + 1;

      // check left child
      if (left < hSize and
          (_heap.at(current)).priority() < (_heap.at(left)).priority())
        std::swap(_heap.at(current), _heap.at(left));
      // check right child
      if (right < hSize and
          (_heap.at(current)).priority() < (_heap.at(right)).priority())
        std::swap(_heap.at(current), _heap.at(right));

      // checking only parents
      current /= 2;
      if (current < 1) end = 1;
    }
  } else if (_heap.size() == 3) {
    if ((_heap.at(1)).priority() < (_heap.at(2)).priority())
      swap(_heap.at(1), _heap.at(2));
  }
  _used = true;
}

// reads top if siz > 1
template <class T>
T Heap<T>::readTop() const {
  // if size > 1 then return heap root else throw
  if (_heap.size() > 1) return _heap.at(ROOT);
  throw range_error("readTop was called on an empty heap!");
}

// removs ROOT node and maintains max heap property
template <class T>
void Heap<T>::removeTop() {
  // empty check
  if (_heap.size() <= 1)
    throw range_error("removeTop was called on an empty heap!");

  // swaps ROOT and last element
  swap(_heap.at(ROOT), _heap.at(_heap.size() - 1));

  // deletes last element
  _heap.pop_back();

  // end = termination, current = start position,
  // factor determines left or right
  int end = 0, current = 1, factor = 0;

  if (_heap.size() > 3) {
    while (end != 1) {
      int hSize = _heap.size(), left = current * 2, right = (current * 2) + 1;
      factor = 0;

      // if both left and right exist
      if (left < hSize and right < hSize) {
        // check left child
        if (left < hSize and
            ((_heap.at(current)).priority() < (_heap.at(left)).priority()) and
            ((_heap.at(left)).priority() >= (_heap.at(right)).priority())) {
          std::swap(_heap.at(current), _heap.at(left));
          factor = 1;
        }
        // check right child
        if (right < hSize and
            ((_heap.at(current)).priority() < (_heap.at(right)).priority()) and
            ((_heap.at(right)).priority() >= (_heap.at(left)).priority())) {
          std::swap(_heap.at(current), _heap.at(right));
          factor = 2;
        }
      }
      // left exists but right doesnt
      else if (left < hSize and right >= hSize) {
        if ((_heap.at(current)).priority() < (_heap.at(left)).priority()) {
          std::swap(_heap.at(current), _heap.at(left));
          factor = 1;
        }
      }
      // right exists but left doesnt
      else if (right < hSize and left >= hSize) {
        if ((_heap.at(current)).priority() < (_heap.at(right)).priority()) {
          std::swap(_heap.at(current), _heap.at(right));
          factor = 2;
        }
      }

      // based on factor either go left or right
      if (factor == 0)
        end = 1;
      else if (factor == 1)
        current *= 2;
      else if (factor == 2)
        current = (current * 2) + 1;
    }
  }
  // need to add remove portion to this
  else if (_heap.size() == 3) {
    if ((_heap.at(1)).priority() < (_heap.at(2)).priority())
      swap(_heap.at(1), _heap.at(2));
  }
}

// dumps contents of vector
template <class T>
void Heap<T>::dump() const {
  // dumps contents of heap
  for (unsigned int i = ROOT; i < _heap.size(); i++)
    cout << _heap.at(i) << endl;
}
#endif