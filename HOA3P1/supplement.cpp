#include <iostream>
#include "SUPPLEMENT_LL.h"

int main(){

    supplementList<const char*>* playlist = nullptr;

    // Create playlist
    insertSong("Tahanan", &playlist);
    insertSong("Kabisado", &playlist);
    insertSong("Risk it All", &playlist);

    std::cout << "Current Playlist: ";
    playSongs(playlist);

    // Add a song
    insertSong("Kalapastanganan", &playlist);
    std::cout << "After Adding a Song: ";
    playSongs(playlist);

    // Next song
    nextSong(playlist);

    // Previous song
    previousSong(playlist);

    // Remove a song
    removeSong("Kabisado", &playlist);
    std::cout << "After Removing a Song: ";
    playSongs(playlist);

    return 0;
}