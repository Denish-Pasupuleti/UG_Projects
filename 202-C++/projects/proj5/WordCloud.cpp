/*
  File: WordCloud.cpp
  Project: CMSC 202 Project 5, Spring 2020
  Author: Denish Pasupuleti
  Section: 15
  E-mail: mpasupu1@umbc.edu
  Description: This is .cpp file for WordCloud.h which is basically a driver
  for using LL objects to sort and perform actions on data in LL
  objects.
*/

#include "WordCloud.h"
#include <string>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

// Name: WordCloud (Default Constructor)
WordCloud::WordCloud() {
  m_fileName = "proj5_test2.txt";
  m_cloud = new LL<string>();
}

// Name: WordCloud (Overloaded Constructor) - Passed filename for input
WordCloud::WordCloud(string fileName) {
  m_fileName = fileName;
  m_cloud = new LL<string>();
}

// Name: ~WordCloud (Destructor)
WordCloud::~WordCloud() {
  delete m_cloud;
  m_cloud = nullptr;
}

// Name: LoadFile()
void WordCloud::LoadFile() {
  ifstream file;
  file.open(m_fileName);
  string word;
  //gets word, removesPunct, inserts
  while (file >> word)
    {
      RemovePunct(word);
      m_cloud->Insert(word);
      if (word == "\n")
	file.ignore(256, '\n');
      if (word == " ")
	file.ignore(256, ' ');
    }
  file.close();
}

// Name: RemovePunct (passed a string
void WordCloud::RemovePunct(string& word) {
  //lowers all letters to lower case
  for (string::iterator it = word.begin(); it < word.end(); it++)
    {
      if (isupper(*it))
	*it = tolower(*it);
    }
  //remove any punctuation at beginning and end
  if (ispunct(word[0]))
    word.erase(0, 1);
  if (ispunct(word[word.size() - 1]))
    word.erase(word.size() - 1);
}

// Name: RemoveCommonT
void WordCloud::RemoveCommon() {
  //iterates through EXCLUDE_LIST and removes any matching words in m_cloud
  for (vector<string>::const_iterator it =
	 EXCLUDE_LIST.cbegin(); it != EXCLUDE_LIST.cend(); ++it)
    m_cloud->RemoveAt(*it);
}

// Name: RemoveSingles
void WordCloud::RemoveSingles() {
  string choice = "no";
  int count = 0;
  //validation
  if (m_cloud->GetSize() > 0)
    {
      cout << "Would you like to remove all words with a frequency of 1?" << endl;
      cin >> choice;
    }
  if (choice == "yes" || choice == "y" || choice == "YES" || choice == "Y")
    {
      //iterates through m_cloud
      for (int i = 1; i <= m_cloud->GetSize(); i++)
	{
	  if ((*m_cloud)[i].second == 1)
	    {
	      m_cloud->RemoveAt((*m_cloud)[i].first);
	      count++;
	      // resets i to 0 because the size was updated and also
	      // need to traverse the list from the beginning
	      i = 0;
	    }
	}
      cout << count << " words removed" << endl;
    }
  else
    cout << "0 words removed" << endl;
}

// Name: Export
void WordCloud::Export() {
  string fileName;
  cout << "What would you like to call the export file?" << endl;
  cin >> fileName;
  //writes to file
  ofstream outFile;
  outFile.open(fileName);
  //writing to file
  outFile << *m_cloud << endl;
  outFile.close();
  //end message
  cout << "Output to exportFile " << fileName << endl;
  cout << m_cloud->GetSize() << " unique words exported" << endl;
}

// Name: Start
void WordCloud::Start() {
  LoadFile();
  RemoveCommon();
  RemoveSingles();
  m_cloud->Display();
  Export();
}
