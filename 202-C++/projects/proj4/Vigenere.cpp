/*************************************************
  File: Vigenere.cpp
  Project: CMSC 202 Project 4, Spring 2020
  Author: Denish Pasupuleti
  Date: 4/20/2020
  Section: 15
  E-mail: mpasupu1@umbc.edu
  Description: This is the cpp file for Vigenere.h which is a polyalphabetic
			   cipher that uses a series of intervowen caesar ciphers based on
			   the letters of a keyword stored in m_key.
*************************************************/


#include "Vigenere.h"
#include <iomanip>

using namespace std;

//Vigenere (Default Constructor)
// Desc: Constructor to build an empty Vigenere Cipher (Defaults key to "test")
Vigenere::Vigenere() :Cipher() {
  m_key = "test";
}

//Vigenere (Overloaded Constructor)
// Desc: Constructor to build a populated Vigenere Cipher
Vigenere::Vigenere(string message, bool isEncrypted, string key) :Cipher(message, isEncrypted) {
  m_key = key;
}

//Vigenere (Destructor)
// Desc: Destructor - Anything specific to delete in Vigenere?
//nothing to delete in vignere that is dynamically allocated
Vigenere::~Vigenere() { }

//Encrypt
// Desc: Encrypts using key (See project document for details)
void Vigenere::Encrypt() {
  string plainText = GetMessage(), cipher = "";
  unsigned int k_index = 0;
  const int LETTERS = 26;
  const char L_MIN = 'a', U_MIN = 'A';

  
  for (char c : plainText) { 
    // spaces
    if (c == ' ')
      cipher.push_back(' ');
    // lower case
    else if (islower(c))         //if lower case switch key to lower
      {
	cipher.push_back((tolower(m_key[k_index]) - L_MIN + c - L_MIN) % LETTERS + L_MIN);
	k_index++;
      }
    //upper case
    else if (isupper(c))  //if upper case switch key to upper
      {
	cipher.push_back((toupper(m_key[k_index]) - U_MIN + c - U_MIN) % LETTERS + U_MIN);
	k_index++;
      }
    //special characters
    else
      cipher.push_back(c);
    if (k_index == m_key.length())    //end of key, reset
      k_index = 0;
  }
  SetMessage(cipher);
  ToggleEncrypted();
}

//Decrypt
// Desc: Decrypts using key (See project document for details)
void Vigenere::Decrypt() {
  string cipher = GetMessage(), plainText = "";
  unsigned int k_index = 0;
  const int LETTERS = 26;
  const char L_MIN = 'a', U_MIN = 'A';
  
  for (char c : cipher) {    /* for each char in cipher */
    if (c == ' ')
      plainText.push_back(' ');
    else if (islower(c))
      {
	//if lower case switch key to lower
	//offset to get correct value
	int offset = c - tolower(m_key[k_index]);
	if (offset >= 0)      
	  plainText.push_back(offset % LETTERS + L_MIN);
	else                
	  plainText.push_back(offset + LETTERS + L_MIN);
	k_index++;
      }
    else if (isupper(c))
      {
	//upper case switch key to upper
	//offset to get correct value
	int offset = c - toupper(m_key[k_index]);
	if (offset >= 0)
	  plainText.push_back(offset % LETTERS + U_MIN);
	else
	  plainText.push_back(offset + LETTERS + U_MIN);
	k_index++;
      }
    else
      plainText.push_back(c);
    //resets key
    if (k_index == m_key.length())    /* if end of key, reset key index */
      k_index = 0;
  }
  SetMessage(plainText);
  ToggleEncrypted();
}

//ToString
// Desc - A function that returns the string of the object type
string Vigenere::ToString() {
  return "vigenere";
}

//FormatOutput()
// Desc - A function that returns the formatted output for Output function
// Preconditions - The object exists (use stringstream)
// Postconditions - v, delimiter, isencrypted, delimiter,
//                  message, delimiter, key are returned for output
string Vigenere::FormatOutput() {
  stringstream ss;
  ss << "v" << "|" << GetIsEncrypted() << "|" << GetMessage() << "|" << m_key;
  cout << ss.str() << endl;
  return ss.str();
}
