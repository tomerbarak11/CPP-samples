#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H
#include "Atomic.h"
#include "Singleton.h"
#include "StructForMusicPlayer.h"
#include <string>

class MusicPlayer: private Singleton<MusicPlayer>
{
public:
    MusicPlayer();
    MusicPlayer(MusicPlayerData a_data);
    void play(std::string const& a_song);
    MusicPlayer* get() const;
    void set(MusicPlayer* a_mp);
    using Singleton::getOne;
    using Singleton::getAtomicCounter;
    using Singleton::instance;
    using Singleton::setAtomicCounter;
    //friend class Singleton<MusicPlayer>;

private:
    std::string m_songName;
    std::string m_bandName;    
};

#endif