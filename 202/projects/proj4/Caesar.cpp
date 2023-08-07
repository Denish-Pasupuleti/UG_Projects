/*************************************************
File: Caesar.cpp
Project: CMSC 202 Project 4, Spring 2020
Author: Denish Pasupuleti
Date: 4/20/2020
Section: 15
E-mail: mpasupu1@umbc.edu
Description: This is the cpp file for Caesar.h which is a shift cipher
             where each letter is moved a certain position to the right
	     or left. Since Caesar is a child class we use initialization
	     lists to pass in message and isEncrypted
*************************************************/

#include "Caesar.h"

//Caesar (Default Constructor)
// Desc: Constructor to build an empty Caesar Cipher (Defaults to shift 3)
Caesar::Caesar() :Cipher() {
  m_shift = 3;
}


//Caesar (Overloaded Constructor)
// Desc: Constructor to build a populated Caesar Cipher (Defaults to shift 3)
Caesar::Caesar(string message, bool isEncrypted, int shift) :Cipher(message, isEncrypted) {
  m_shift = shift;
}

//Caesar (Destructor)
// Desc: Destructor - Anything specific to Caesar to delete?
Caesar::~Caesar() { }

//Encrypt
// Desc: Shifts characters right based on shift (lower stay lower, upper stay upper)
void Caesar::Encrypt() {
  string plainText = GetMessage(), cipher = "";
  char ch;
  const int LETTERS = 26, O_BOUND = 28;
  const char L_MIN = 'a', L_MAX = 'z', U_MIN = 'A', U_MAX = 'Z';
  // loop through each char
  for (int i = 0; plainText[i] != '\0'; i++)
    {
      ch = plainText[i];
      if (ch == ' ')
	cipher += " ";
      //encrypt for lowercase letter
      else if (ch >= L_MIN && ch <= L_MAX)
	{
	  int tempShift = m_shift;
	  if (m_shift >= O_BOUND)
	    tempShift = m_shift % LETTERS;
	  if (int(ch) + tempShift <= int(L_MAX))
	    ch = int(ch) + tempShift;
	  else if (int(ch) + tempShift > int(L_MAX))
	    ch = ch - LETTERS + tempShift;
	  else if (ch < L_MIN)
	    ch = ch + LETTERS;
	  cipher += ch;
	}
      //encrypt for uppercase letter
      else if (ch >= U_MIN && ch <= U_MAX)
	{
	  int tempShift = m_shift;
	  if (m_shift >= O_BOUND)
	    tempShift = m_shift % LETTERS;
	  if (int(ch) + tempShift <= int(U_MAX))
	    ch = int(ch) + tempShift;
	  else if (int(ch) + tempShift > int(U_MAX))
	    ch = ch - LETTERS + tempShift;
	  else if (ch < U_MIN)
	    ch = ch + LETTERS;
	  cipher += ch;
	}
      else
	cipher += ch;
    }
  SetMessage(cipher);
  ToggleEncrypted();
}

//Decrypt
// Desc: Shifts characters left based on shift (lower stay lower, upper stay upper)
void Caesar::Decrypt() {
  string cipher = GetMessage(), plainText = "";
  char ch;
  const int LETTERS = 26;
  const char L_MIN = 'a', L_MAX = 'z', U_MIN = 'A', U_MAX = 'Z';

  //for loop for each letter
  for (int i = 0; cipher[i] != '\0'; i++)
    {
      ch = cipher[i];
      if (ch == ' ')
	plainText += " ";
      //decrypt for lowercase letter
      else if (ch >= L_MIN && ch <= L_MAX)
	{
	  ch = ch - m_shift;
	  if (ch < L_MIN)
	    ch = ch + L_MAX - L_MIN + 1;
	  else if (ch > L_MAX)
	    ch = ch - LETTERS;
	  plainText += ch;
	}
      //decrypt for uppercase letter
      else if (ch >= U_MIN && ch <= U_MAX)
	{
	  ch = ch - m_shift;
	  if (ch < U_MIN)
	    ch = ch + U_MAX - U_MIN + 1;
	  else if (ch > U_MAX)
	    ch = ch - LETTERS;
	  plainText += ch;
	}
      else
	plainText += ch;
    }
  SetMessage(plainText);
  ToggleEncrypted();
}

//ToString
// Desc - A function that returns the string of the object type
string Caesar::ToString() {
  return "caesar";
}

//FormatOutput()
// Desc - A function that returns the formatted output for Output function
string Caesar::FormatOutput() {
  stringstream ss;
  ss << "c" << "|" << GetIsEncrypted() << "|" << GetMessage() << "|" << m_shift;
  return ss.str();
}
