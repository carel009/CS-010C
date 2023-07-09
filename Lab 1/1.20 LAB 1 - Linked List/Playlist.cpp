#include "Playlist.h"

PlaylistNode::PlaylistNode()
{
   uniqueID = "none";
   songName = "none";
   artistName = "none";
   songLength = 0;
   nextNodePtr = 0;
}

PlaylistNode::PlaylistNode(string id, string songname, string artist, int length)
{
   uniqueID = id;
   songName = songname;
   artistName = artist;
   songLength = length;
   nextNodePtr = 0;
}

void PlaylistNode::InsertAfter(PlaylistNode* ptr)
{
   PlaylistNode* temp = nextNodePtr;
   nextNodePtr = ptr;
   ptr->nextNodePtr = temp;
}

void PlaylistNode::SetNext(PlaylistNode* ptr)
{
   nextNodePtr = ptr;
}

string PlaylistNode::GetID()
{
   return uniqueID;
}

string PlaylistNode::GetSongName()
{
   return songName;
}

string PlaylistNode::GetArtistName()
{
   return artistName;
}

int PlaylistNode::GetSongLength()
{
   return songLength;
}

PlaylistNode* PlaylistNode::GetNext()
{
   return nextNodePtr;
}

void PlaylistNode::PrintPlaylistNode()
{
   cout << "Unique ID: " << uniqueID << endl;
   cout << "Song Name: " << songName << endl;
   cout << "Artist Name: " << artistName << endl;
   cout << "Song Length (in seconds): " << songLength << endl;
}

Playlist::Playlist()
{
   head = 0;
   tail = 0;
}

void Playlist::AddSong(string id, string songname, string artistname, int length)
{
   PlaylistNode* n = new PlaylistNode(id, songname, artistname, length);
   if (head == 0)
   {
       head = n;
       tail = n;
   }
   
   else
   {
       tail->InsertAfter(n);
       tail = n;
   }
}

void Playlist::RemoveSong(string id)
{
   if (head == NULL)
   {
       cout << "Playlist is empty" << endl;
   }

   PlaylistNode* curr = head;
   PlaylistNode* prev = NULL;
   
   while (curr != NULL)
   {
       if (curr->GetID() == id)
       {
           break;
       }
       prev = curr;
       curr = curr->GetNext();
   }

   if (curr != NULL)
   {
       if (prev != NULL)
       {
           prev->SetNext(curr->GetNext());
       }
       
       else
       {
           head = curr->GetNext();
       }
       
       if (tail == curr)
       {
           tail = prev;
       }
       
       cout << "\"" << curr->GetSongName() << "\" removed." << endl;
       delete curr;
   }
}

void Playlist::ChangePosition(int oldPos, int newPos)
{
   if (head == NULL)
   {
       cout << "Playlist is empty" << endl;
   }

   PlaylistNode* prev = NULL;
   PlaylistNode* curr = head;
   int pos;

   for (pos = 1; curr != NULL && pos < oldPos; pos++)
   {
       prev = curr;
       curr = curr->GetNext();
   }
   
   if (curr != NULL)
   {
       string currentSong = curr->GetSongName();

       if (prev == NULL)
       {
           head = curr->GetNext();
       }
       
       else
       {
           prev->SetNext(curr->GetNext());
       }

       if (curr == tail)
       {
           tail = prev;
       }

       PlaylistNode* curr1 = curr;
       prev = NULL;
       curr = head;

       for (pos = 1; curr != NULL && pos < newPos; pos++)
       {
           prev = curr;
           curr = curr->GetNext();
       }

       if (prev == NULL)
       {
           curr1->SetNext(head);
           head = curr1;
       }
       
       else
       {
           prev->InsertAfter(curr1);
       }

       if (curr == NULL)
       {
           tail = curr1;
       }

       cout << "\"" << currentSong << "\" moved to position " << newPos << endl;
   }
}

void Playlist::SongsByArtist(string artist)
{
   if (head == NULL)
   {
       cout << "Playlist is empty" << endl;
   }
   
   else
   {
       PlaylistNode* curr = head;
       int i = 1;
       
       while (curr != NULL)
       {
           if (curr->GetArtistName() == artist)
           {
               cout << endl << i << "." << endl;
               curr->PrintPlaylistNode();              
           }
           curr = curr->GetNext();
           i++;
       }
   }
}

int Playlist::TotalTime()
{
   int total = 0;
   PlaylistNode* curr = head;

   while (curr != NULL)
   {
       total += curr->GetSongLength();
       curr = curr->GetNext();
   }

   return total;
}

void Playlist::PrintList()
{
   if (head == NULL)
   {
       cout << endl << "Playlist is empty" << endl;
   }
   
   else
   {
       PlaylistNode* curr = head;
       int i = 1;
       
       while (curr != NULL)
       {
           cout << endl << i++ << "." << endl;
           curr->PrintPlaylistNode();          
           curr = curr->GetNext();
       }
   }
}