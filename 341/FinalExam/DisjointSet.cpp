#include <cassert>
#include <iostream>
#include <stdexcept>
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
    if (set1 >= size || set2 >= size) {
      throw range_error("Invalid set(s)");
    }
    set1 = find(set1);
    set2 = find(set2);
    if (set1 == set2) {
      return set1;
    }
    if (array[set1] <= array[set2]) {
      array[set1] += array[set2];
      array[set2] = set1;
      return set1;
    } else {
      array[set2] += array[set1];
      array[set1] = set2;
      return set2;
    }
  }

  int find(int id) {
    // cout << "ID: " << id << endl;
    if (id >= size) {
      throw range_error("Invalid set");
    }
    int target = id;
    while (array[target] >= 0) {
      cout << "Target set before: " << target << endl;
      target = array[target];
      cout << "Target set after: " << target << endl;
      cout << endl;
    }

    int temp_target = id, prevTarget = 0;
    while (array[temp_target] >= 0) {
      prevTarget = array[temp_target];
      array[temp_target] = target;
      temp_target = prevTarget;
    }
    return target;
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

    // unions 0 + 10, 1 + 11 ... and 9 + 19
    for (int i = 0; i < 10; ++i) {
      sets.setUnion(i, i + 10);
    }

    // 1st set
    sets.setUnion(0, 1);   // union (0, 1)
    sets.setUnion(0, 2);   // union (0, 2)
    sets.setUnion(10, 0);  // union (0, 10)
    sets.setUnion(0, 9);   // union (0, 9)

    // 2nd set
    sets.setUnion(3, 4);  // union (3, 4)
    sets.setUnion(5, 6);  // union (5, 6)
    sets.setUnion(3, 5);  // union (3, 5)

    // union both sets into 1 (size of set1 is bigger so it will absorb set2)
    sets.setUnion(0, 3);  // union (0, 3)

    printArray(sets);

    cout << endl << "******Please ignore everything above*******" << endl;
    cout << endl << "*************************************************" << endl;

    printArray(sets);

    // find operation for 6
    cout << endl << "Find operation for 6: " << endl;
    sets.find(6);
    cout << "Hop size to root is 3 because (6->5->3->0)" << endl;

    cout << "*************************************************" << endl;
    cout << "***After path compression***: " << endl;
    printArray(sets);
    sets.find(6);
    cout << "Hop size to root is 1 because (6->0)" << endl;

    // find operation for 5
    cout << "*************************************************" << endl;
    cout << endl << "Find operation for 5: " << endl;
    printArray(sets);
    sets.find(5);
    cout << "Hop size to root is 1 because (5->0)" << endl;

    cout << "*************************************************" << endl;
    cout << endl
         << "As we can see path compression works 6 and 5 point to 0" << endl;

    printArray(sets);
    cout << "            ^ ^" << endl;
  }

  static void printArray(const DisjointSet &sets) {
    for (int i = 0; i < sets.size; ++i) {
      cout << sets.array[i] << " ";
    }
    cout << endl;
  }
};

int main() { Test::run(); }
