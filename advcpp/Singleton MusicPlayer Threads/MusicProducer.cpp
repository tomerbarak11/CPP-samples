#include "MusicProducer.h"
#include <iostream>
MusicProducer::MusicProducer(MusicPlayerData a_data)
: m_data(a_data)
{
}

void MusicProducer::run()
{
    MusicPlayer& mp=MusicPlayer::instance(m_data);
    mp.play(m_data.m_songName);
}