#include <iostream>
using namespace std;

// Constants go here
const double SCHARGE = 3.50;
const double START_BALANCE = 500;
const double START_WALLET = 75;


//Function Prototypes
void withdraw(double&, double&); //Uses pass by reference
void deposit(double*, double*); //Uses pointers

int main() {
  double balance = START_BALANCE; //Amount in user's account
  double wallet = START_WALLET;  //Amount of cash in user's wallet

  cout << "Welcome to the ATM." << endl;
  cout.precision(2); //Sets precision for currency
  cout << fixed; //Forces two decimals
  cout << "Your balance is $" << balance << endl; //Outputs balance
  cout << "Your wallet contains $" << wallet << endl; //Outputs wallet
  cout << endl;

  withdraw(balance, wallet); //Calls withdraw using pass by reference

  cout << endl;
  cout << "Your balance is $" << balance << endl; //Shows updated balance
  cout << "Your wallet contains $" << wallet << endl; //Shows updated wallet
  cout << endl;

  deposit(&balance, &wallet); //calls deposit using pointers

  cout << endl;
  cout << "Your balance is $" << balance << endl; //Shows final balance
  cout << "Wallet contains $" << wallet << endl; //Shows final wallet

  return 0;
}

// Implement withdraw and deposit here
// Do not forget to validate to make sure you can't overdraw your balance or wallet!
void withdraw(double&balance, double&wallet){
    double money;
    cout << "How much money would you like to withdraw? ";
    cin >> money;
    //input validation
    while(money >= balance or (balance - money < 3.50)){
        cin.clear();
        cout << "Cannot overdraw your account" << endl;
        cout << "How much money would you like to withdraw? ";
        cin >> money;
    }
    balance -= money + SCHARGE;
    wallet += money;
}

void deposit(double*balance, double*wallet){
    double money;
    cout << "How much money would you like to deposit? ";
    cin >> money;

    while(money >= *wallet or (*wallet - money < 3.50)){
        cin.clear();
        cout << "Not enough money for that deposit" << endl;
        cout << "How much money would you like to deposit? ";
        cin >> money;
    }
    *balance += money;
    *wallet -= money + SCHARGE;
}
