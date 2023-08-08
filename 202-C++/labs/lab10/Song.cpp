#include "Song.h"

Song::Song(string songName, string artist){
  m_artist = artist;
  m_songName = songName;
}

void Song::Play(){
  cout << "You play your favorite song, I Don't Love You by Chemical Romance" << endl;
}

void Song::Skip(){
  cout << "You are not in the mood to listern to the song I Son't Love You" << endl;
}

void Song::Lyrics(){
  cout << "You love the song lyrics in I Don't Love You by My Chemical Romance" << endl;
}

Indie::Indie(string songName, string artist):Song(songName, artist){
  m_artist = artist;
  m_songName = songName;
}

void Indie::Play(){
  cout << "You play your favorite indie song, New Slang by The Shins." << endl;
}

void Indie:: Skip(){
  cout << "You are not in the mood to listen to the indie song New Slang." << endl;
}

Pop::Pop(string songName, string artist):Song(songName, artist) {
  m_artist = artist;
  m_songName = songName;
}

void Pop::Play(){
  cout << "You play your favorite pop song, thank u, next by Ariana Grande" << endl;
}

void Pop::Skip(){
  cout << "After hearing the pop song thank u, next so often, you skip to another song." << endl;
}

void Pop::Lyrics(){
  cout << "You love the lyrics in the pop song thank u, next by Ariana Grande" << endl;
}
