#include <iostream>
using namespace std;

// Use this file to implement two functions.
// Function 1: A templated function to display information about two variables
//             and the results of a function all to a templated IsDivisible function
//             Should display "IsDivisible(10, 5): (then the results of isDivisible)"
// Function 2: A templated IsDivisible function
//             IsDivisible function returns an int (either -1, 0, or 1):
//             -1 if a is not evenly divisible by b
//             0 if a==b
//             1 if a is evenly divisible by b
// Both functions take two args:
//   a: object of type T (where T is the templated class type)
//   b: object of type T (where T is the templated class type)
//

// Implement the templated IsDivisible function here:


//Implement the templated DisplayInfo here:






int main(){
  DisplayInfo(10,5);
  DisplayInfo(20,20);
  DisplayInfo(5,10);
  DisplayInfo('a','b');
  DisplayInfo(true,true);
  return 0;
}
