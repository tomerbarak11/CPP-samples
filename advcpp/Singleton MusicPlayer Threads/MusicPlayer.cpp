#include "MusicPlayer.h"
#include <iostream>

MusicPlayer::MusicPlayer()
{
}

MusicPlayer::MusicPlayer(MusicPlayerData a_data)
: m_songName(a_data.m_songName)
, m_bandName(a_data.m_bandName)
{
}


void MusicPlayer::play(std::string const& a_song)
{
    std::cout<<a_song<<"\n\n";
}
