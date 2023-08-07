/*
 * lab2.cpp
 * This program tests skills regarding input/output, loops, functions in C++.
 */

#include <iostream>
using namespace std;

/****************************************************************
 *   FUNCTION PROTOTYPES FOR sumInts() and isEven() GO HERE     *
 ****************************************************************/
int sumInts(int num1, int num2, int num3);
string isEven(int num);

int main() {
    /****************************************************************
     *             CODE TO INVOKE FUNCTIONS GOES HERE               *
     * Note: the user should enter 3 numbers, and the program will  *
     * display the sum of such numbers, as well as if the sum is    *
     * even/odd. MUST BE IMPLEMENTED IN ONE LINE.                   *
     ****************************************************************/
    int num1, num2, num3;
    double sum = 0.0;
    cout << "Enter a number: " << endl;
    cin >> num1;
    cout << "Enter a number: " << endl;
    cin >> num2;
    cout << "Enter a number: " << endl;
    cin >> num3;

    sum = sumInts(num1, num2, num3);
    cout << "The sum is : " << sum << endl;
    cout << "The sum is " << isEven(sum) << endl;

    return 0;
}


//Name: sumInts
//Purpose: Given the number of integers to enter as a parameter, the function
//	   will request the user to enter that many integers, displaying and
//	   returning the sum once all numbers have been entered.
/****************************************************************
 *           IMPLEMENTATION FOR sumInts() GOES HERE             *
 ****************************************************************/
int sumInts(int num1, int num2, int num3){
    return num1 + num2 + num3;
}


//Name: isEven
//Purpose: Given an integer as a parameter, the function will display whether
//	   it is even or odd.
/****************************************************************
 *           IMPLEMENTATION FOR isEven() GOES HERE              *
 ****************************************************************/
string isEven(int num) {
    if (num % 2 == 1)
        return "Not even";
    return "Is even";
}
