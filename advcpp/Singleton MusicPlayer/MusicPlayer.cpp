#include "MusicPlayer.h"
#include <iostream>

MusicPlayer::MusicPlayer(MusicPlayerData a_data)
: songName(a_data.songName)
, bandName(a_data.bandName)
{ 
}


void MusicPlayer::play() const
{
    std::cout<<bandName<<" "<<"is playing the song: "<<songName<<"\n";
}
