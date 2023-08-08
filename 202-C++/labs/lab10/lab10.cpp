#include "Song.h"
#include <string>
#include <iostream>
using namespace std;

int main () {

  Song newSong ("I Don't Love You", "My Chemical Romance");
  Indie indie1("New Slang", "The Shins");
  Pop pop1("thank u, next", "Ariana Grande");

  Song * song1 = &newSong;
  Song * song2 = &indie1;
  Song * song3 = &pop1;

  cout << "Example 1 - Parent class" << endl;
  cout << "Song - I Don't Love You" << endl;
  song1->Lyrics();

  cout << "" << endl;
  cout << "Example 2 - Child Class(Indie" << endl;
  cout << "Indie - Sad Boi" << endl;
  song2->Play();
  song2->Skip();
  cout << "" << endl;
  
  cout << "Example 3 - Child Class(Pop)" << endl;
  cout << "Pop - Hot 100" << endl;
  song3->Play();
  song3->Skip();
  song3->Lyrics();

  return 0;
}
