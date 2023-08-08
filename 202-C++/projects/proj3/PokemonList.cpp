/*************************************************
  File: PokemonList.cpp
  Project: CMSC 202 Project 3, Spring 2020
  Author: Denish Pasupuleti
  Date: 3/20/2020
  Section: 15
  E-mail: mpasupu1@umbc.edu
  Description: This is the cpp file for PokemonList.h. This program will create
               a PokemonList object pointer that hold Pokemon Object pointers.
               This program has functions to iterate and modify the PokemonList,
               Display it, Remove nodes, and destruct the list.
*************************************************/

#include "PokemonList.h"
#include "Pokemon.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

//constants for damage
const int NORM_E = 3, NORM_U = 2, SPECIAL = 5;

//Default constructor for the PokemonList (linked list)
PokemonList::PokemonList() {
  m_size = 0;
  m_head = nullptr;
}

//Destructor for the PokemonList (linked list)
PokemonList::~PokemonList() {
  Pokemon* curr = m_head;

  //deletes
  while (curr != nullptr and m_head != nullptr)
    {
      m_head = m_head->GetNext();
      //delete
      delete curr;
      curr = m_head;
    }
  //resets
  m_head = nullptr;
  m_size = 0;
}

//Inserts an already dynamically allocated Pokemon to end of linked list
void PokemonList::InsertEnd(Pokemon* pokemon) {

  Pokemon* temp = m_head;
  pokemon->SetNext(nullptr);
  //base case where list is empty
  if (m_head == nullptr or m_size == 0)
    m_head = pokemon;
  //else iterates and adds at last position
  else
    {
      while (temp->GetNext() != nullptr)
	{
	  temp = temp->GetNext();
	}
      temp->SetNext(pokemon);
    }
  m_size++;
}

//Iterates over PokemonList and displays each Pokemon formatted as in output
void PokemonList::Display() {
  //points temp to m_head which is start of list
  Pokemon* temp = m_head;

  while (temp != nullptr)
    {
      cout << "Index: " << left << setw(10) << temp->GetIndex() 
	   << right << setw(5);
      cout << "Name: " << left << setw(10) << temp->GetName() 
	   << right << setw(10);
      cout << "Type: " << left << setw(15) << temp->GetType();
      cout << "Health: " << temp->GetHealth() << endl;
      //points to next pokemon
      temp = temp->GetNext();
    }
}

// Desc - Searches for a Pokemon with a specific index. If found,
// creates a new Pokemon and copies it into the PokemonList passed in
void PokemonList::Transfer(int index, PokemonList* list) {
  Pokemon* temp = m_head;
  
  //looping to find index
  while (temp != nullptr)
    {
      if (temp->GetIndex() == index)
	{
	  //inserts pokemon into passed in list
	  Pokemon* newPoke = new Pokemon(temp->GetIndex(), temp->GetName(), 
					 temp->GetType(), temp->GetStrong());
	  list->InsertEnd(newPoke);
	}
      temp = temp->GetNext();
    }
  //removes Pokemon from original list
  Remove(index);
}

// Desc - Searches for a Pokemon with a specific index. If found,
// removes it from the linked list
void PokemonList::Remove(int index) {
  //sets curr and prev to m_head for iterating
  Pokemon* curr = m_head;
  Pokemon* prev = m_head;
  //base case if only 1 object in list
  if (m_size == 1)
    {
      delete m_head;
      m_head = nullptr;
      m_size--;
    }
  //if next in lsit
  else if (curr->GetIndex() == index and curr->GetNext() != nullptr)
    {
      curr = curr->GetNext();
      delete m_head;
      m_head = curr;
      m_size--;
    }
  //else iterates until it finds desired pokemon
  else
    {
      while (curr->GetIndex() != index and curr != nullptr)
	{
	  prev = curr;
	  curr = curr->GetNext();
	}
      prev->SetNext(curr->GetNext());
      delete curr;
      m_size--;
    }
}

//Returns the size of the linked list
int PokemonList::GetSize() {
  return m_size;
}

//Returns the Pokemon at the head of the linked list
Pokemon* PokemonList::GetHead() {
  return m_head;
}

// Desc - Passes an enemy pocket to the user's pocket to attack
// User always attacks the enemy Pokemon in this game
int PokemonList::Attack(PokemonList* list) {
  //list is the enemey pocket
  //gets respective head pokemon
  Pokemon* userHead = m_head;
  Pokemon* enemyHead = list->GetHead();
  int enemy_health = enemyHead->GetHealth(),
    user_health = userHead->GetHealth();

  //user always attacks first
  //user strong against enemy attack
  if (userHead->GetStrong() == enemyHead->GetType())
    {
      cout << "User strong attack against enemy" << endl;
      //subtracts 5 from attack sets new health of pokemon
      enemyHead->SetHealth(enemy_health -= SPECIAL);

      //if enemy pokemon died
      if (enemy_health <= 0) return 2;
      //else enemy strong attack against user
      else if (enemyHead->GetStrong() == userHead->GetType())
	{
	  cout << "Enemy strong attack agaisnt user" << endl;
	  //subtracts 5 from attack and sets new health of pokemon
	  userHead->SetHealth(user_health -= SPECIAL);

	  if (user_health <= 0) return 1;
	  else return 0;
	}
      //else enemy norm attack against user
      else
	{
	  cout << "Enemy Normal enemy attack on user" << endl;
	  //subtracts 3 from attack sets new health of pokemon
	  userHead->SetHealth(user_health -= NORM_E);

	  if (user_health <= 0) return 1;
	  else return 0;
	}
    }
  else
    {
      //norm user attack on enemy
      cout << "User Normal attack on enemy" << endl;
      //subtracts 5 from attack sets new health of pokemon
      enemyHead->SetHealth(enemy_health -= NORM_U);

      //if enemy pokemon died
      if (enemy_health <= 0) return 2;
      //else strong attack against user
      else if (enemyHead->GetStrong() == userHead->GetType())
	{
	  cout << "Enemy strong attack agaisnt normal user" << endl;
	  //subtracts 5 from attack sets new health of pokemon
	  userHead->SetHealth(user_health -= SPECIAL);

	  if (user_health <= 0) return 1;
	  else return 0;
	}
      //else norm enemy attack on user
      else
	{
	  cout << "Enemy normal attack on user" << endl;
	  //subtracts 3 from attack sets new health of pokemon
	  userHead->SetHealth(user_health -= NORM_E);

	  if (user_health <= 0) return 1;
	  else return 0;
	}
    }
}

// Desc - Allows user to move a Pokemon from any position into the first position
// Special cases: Empty list, Pokemon chosen at m_head or choice doesn't exist
void PokemonList::SwapPokemon() {
  int choice;
  Pokemon* currY = m_head;
  Pokemon* prevY = nullptr;

  //if only head remaining
  if(m_size == 1)
    return;
  
  cout << "Which Pokemon would you like to choose? (Enter the index#)" << endl;
  Display();
  cin >> choice;

  //do-while loop for validation
  while (!Exist(choice))
    {
      cin.clear();
      cout << "This is not a valid index. please try again." << endl;
      cin >> choice;
    }
  //if choice is head, do nothing
  if (choice == m_head->GetIndex())
    cout << "Choice is head" << endl;
  else
    {
      //traverse list to find desired pokemon
      while (currY != nullptr and currY->GetIndex() != choice)
	{
	  prevY = currY;
	  currY = currY->GetNext();
	}
      if (prevY != nullptr)
	prevY->SetNext(m_head);
      else
	m_head = m_head;
      //swaps pokemon
      Pokemon* temp = m_head->GetNext();
      m_head->SetNext(currY->GetNext());
      currY->SetNext(temp);
    }
  m_head = currY;
}

//Iterates through linked list looking for a specific index of a Pokemon
bool PokemonList::Exist(int index) {
  Pokemon* curr = m_head;
  
  //traverses through list to find desired pokemon
  while (curr != nullptr)
    {
      if (curr->GetIndex() == index)
	return true;
      curr = curr->GetNext();
    }
  return false;
}
