#ifndef SONG_H
#define SONG_H

#include <string>
#include <iostream>
using namespace std;

class Song {
 public:
  Song(string songName, string artist);
  virtual void Play();
  virtual void Skip();
  virtual void Lyrics();
 protected:
  string m_artist;
  string m_songName;
};

class Indie: public Song {
public:
  Indie(string songName, string artist);
  void Play();
  void Skip();
};

class Pop: public Song {
public:
  Pop(string songName, string artist);
  void Play();
  void Skip();
  void Lyrics();
};
    
#endif
