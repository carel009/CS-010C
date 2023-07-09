#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <iostream>
#include <string>
using namespace std;

class PlaylistNode
{
public:
   PlaylistNode();
   PlaylistNode(string id, string songname, string artist, int length);
   void InsertAfter(PlaylistNode* ptr);
   void SetNext(PlaylistNode* ptr);
   string GetID();
   string GetSongName();
   string GetArtistName();
   int GetSongLength();
   PlaylistNode* GetNext();
   void PrintPlaylistNode();

private:
   string uniqueID;
   string songName;
   string artistName;
   int songLength;
   PlaylistNode* nextNodePtr;
};

class Playlist
{
public:
   Playlist();
   void AddSong(string id, string songname, string artistname, int length);
   void RemoveSong(string id);
   void ChangePosition(int oldPos, int newPos);
   void SongsByArtist(string artist);
   int TotalTime();
   void PrintList();
   
private:
   PlaylistNode *head;
   PlaylistNode *tail;
};

#endif