#include <cassert>
#include <iostream>

using namespace std;
class Test;
class DisjointSet {
 public:
  DisjointSet() {
    size = 0;
    capacity = 8;
    array = new int[capacity]{-1};
  }

  ~DisjointSet() { delete[] array; }

  int makeSet() {
    size++;
    if (size > capacity) {
      int *newArray = new int[capacity * 2]{-1};
      for (int i = 0; i < capacity; ++i) {
        newArray[i] = array[i];
      }
      delete[] array;
      array = newArray;
      capacity *= 2;
    }
    array[size - 1] = -1;
    return size - 1;
  }

  int setUnion(int set1, int set2) {
    // implement union by rank (size)
    if (set1 == set2) return 0;                // Self union
    int rep1 = find(set1), rep2 = find(set2);  // finding set representatives

    // get size of each rep
    int size1 = array[find(rep1)], size2 = array[find(rep2)];

    if (abs(size1) > abs(size2)) {  // size1 > size2 (set1 absorbs set2)
      array[rep1] += size2;
      array[set2] = rep1;
      return rep1;
    } else if (abs(size1) < abs(size2)) {  // size1 < size2 (set2 absorbs set1)
      array[rep2] += size1;
      array[set1] = rep2;
      return rep2;
    } else {  // size are the same
      if (set1 < set2) {
        array[rep1] += size2;
        array[set2] = rep1;
        return rep1;
      } else {
        array[rep2] += size1;
        array[set1] = rep2;
        return rep2;
      }
    }
    return 0;
  }

  int find(int set) {
    // implement find WITHOUT path compression
    // checks for negative numbers
    int num;
    if (array[set] < 0) {
      return set;
    } else if (array[set] != set) {
      num = find(array[set]);
    }
    return num;
  }

 private:
  friend Test;
  int *array;
  int size;
  int capacity;
};

class Test {
 public:
  static void run() {
    DisjointSet sets;
    bool makeSetWorks = true;
    for (int i = 0; i < 20; ++i) {
      if (sets.makeSet() != i) {
        makeSetWorks = false;
      }
    }
    assert(makeSetWorks);  // make sure that makeset returns the id of the set
                           // created

    // print the array.  should be:
    // -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
    printArray(sets);

    // unions 0 + 10, 1 + 11 ... and 9 + 19
    for (int i = 0; i < 10; ++i) {
      sets.setUnion(i, i + 10);
    }

    // should be:
    // -2 -2 -2 -2 -2 -2 -2 -2 -2 -2 0 1 2 3 4 5 6 7 8 9
    printArray(sets);

    assert(sets.setUnion(0, 0) == 0);  // check self union
    sets.setUnion(0, 1);

    // check union worked and find worked
    assert(sets.find(10) == sets.find(11));

    assert(sets.setUnion(5, 0) == 0);  // check union by rank

    // check that union correctly finds the set representative
    assert(sets.setUnion(10, 2) == 0);

    // should be:
    // -8 0 0 -2 -2 0 -2 -2 -2 -2 0 1 2 3 4 5 6 7 8 9
    printArray(sets);

    sets.setUnion(3, 4);
    sets.setUnion(0, 3);
    // should be:
    // -12 0 0 0 3 0 -2 -2 -2 -2 0 1 2 3 4 5 6 7 8 9
    printArray(sets);
  }

  static void printArray(const DisjointSet &sets) {
    for (int i = 0; i < sets.size; ++i) {
      cout << sets.array[i] << " ";
    }
    cout << endl;
  }
};

int main() { Test::run(); }
