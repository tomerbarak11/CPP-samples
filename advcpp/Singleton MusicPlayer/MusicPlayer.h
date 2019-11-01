#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H
#include "Atomic.h"
#include "Uncopyable.h"
#include "Singleton.h"
#include<string>

typedef struct MusicPlayerData
{
    std::string songName;
    std::string bandName;
}MusicPlayerData;

class MusicPlayer: private Singleton<MusicPlayer>
{
public:
    MusicPlayer(MusicPlayerData a_data);
    void play() const;
    using Singleton::getOne;
    using Singleton::getAtomicCounter;
    using Singleton::setAtomicCounter;

private:
    std::string songName;
    std::string bandName;
};

#endif
