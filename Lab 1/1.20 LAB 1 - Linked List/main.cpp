#include "Playlist.h"

void PrintMenu(string title)
{
   Playlist playlist;
   string sId;
   string sName;
   string aName;
   int sLength;
   int oldPos;
   int newPos;
   char choice;

   while (true)
   {
       cout << endl << title << " PLAYLIST MENU" << endl;
       cout << "a - Add song" << endl;
       cout << "d - Remove song" << endl;
       cout << "c - Change position of song" << endl;
       cout << "s - Output songs by specific artist" << endl;
       cout << "t - Output total time of playlist (in seconds)" << endl;
       cout << "o - Output full playlist" << endl;
       cout << "q - Quit" << endl << endl;

       cout << "Choose an option:" << endl;
       cin >> choice;
       cin.ignore();

       if (choice == 'q' || choice == 'Q')
       {
           exit(0);
       }
       else if (choice == 'a' || choice == 'A')
       {
           cout << endl << "ADD SONG" << endl;
           cout << "Enter song's unique ID:" << endl;
           cin >> sId;
	   cin.ignore();
           cout << "Enter song's name:" << endl;
           getline(cin, sName);
           cout << "Enter artist's name:" << endl;
           getline(cin, aName);
           cout << "Enter song's length (in seconds):" << endl;
           cin >> sLength;
           playlist.AddSong(sId, sName, aName, sLength);
       }
       else if (choice == 'd' || choice == 'D')
       {
           cout << endl << "REMOVE SONG" << endl;
           cout << "Enter song's unique ID:" << endl;
           cin >> sId;
           playlist.RemoveSong(sId);
       }
       else if (choice == 'c' || choice == 'C')
       {
           cout << endl << "CHANGE POSITION OF SONG" << endl;
           cout << "Enter song's current position:" << endl;
           cin >> oldPos;
           cout << "Enter new position for song:" << endl;
           cin >> newPos;
           playlist.ChangePosition(oldPos, newPos);
       }
       else if (choice == 's' || choice == 'S')
       {
           cout << endl << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
           cout << "Enter artist's name:" << endl;
           getline(cin, aName);
           playlist.SongsByArtist(aName);
       }
       else if (choice == 't' || choice == 'T')
       {
           cout << endl << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
           cout << "Total time: " << playlist.TotalTime() << " seconds" << endl;
       }
       else if (choice == 'o' || choice == 'O')
       {
           cout << title << " - OUTPUT FULL PLAYLIST";
           playlist.PrintList();
       }
       else
       {
           cout << "Invalid menu choice! Please try again." << endl;
       }
   }
}

int main()
{
   string playlistTitle;

   cout << "Enter playlist's title:" << endl;
   getline(cin, playlistTitle);
   PrintMenu(playlistTitle);  
  
   return 0;
}