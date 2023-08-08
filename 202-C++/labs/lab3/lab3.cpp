#include <iostream>
using namespace std;

//Name: divFour
//Preconditions: requires an array of integers and the size of the array
//Postcondition: if a value in the array is not cleanly divisible by 4, does nothing
//               if the value is cleanly divisible by 4, divides by 4
int divFour(int[], int);

int main(){
  const int MAXSIZE = 100; //Constant max size of array
  int myArray[MAXSIZE] = {0}; //Declares and initializes the array to hold 100 zeros
  int currSize = 0; //Keeps track of current size of array;
  int inputValue; //Used to get input to populate array

  //Code to take in values, call divFour, and print results goes here
  int x = 0;
  cout << "Enter another number (0 when done): " << endl;
  cin >> inputValue;
  if(inputValue != 0)
  {
      myArray[x] = inputValue;
      currSize++;
      x++;
  }

  while(inputValue != 0)
  {

      cout << "Enter an;other number (0 when done): " << endl;
      cin >> inputValue;
      if(inputValue != 0) {
          myArray[x] = inputValue;
          currSize++;
          x++;
      }
  }
    cout << "Original Array: ";
    for(int i = 0; i < currSize; i++)
    {
        cout << myArray[i] << " ";
    }

    cout << "The array contains " << divFour(myArray, currSize) <<  " numbers divisible by 4" << endl;
    cout << "Modified Array: ";
    for(int i = 0; i < currSize; i++)
    {
        cout << myArray[i] << " ";
    }
    return 0;
}

//implement divFour here
int divFour(int array[], int numValues){

    int counter = 0;
    for(int x = 0; x < numValues; x++)
    {
        if(array[x] % 4 == 0)
        {
            counter++;
            array[x] = array[x] / 4;
        }
    }

    return counter;

}
