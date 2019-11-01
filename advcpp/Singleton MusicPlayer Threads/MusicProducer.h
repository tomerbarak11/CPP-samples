#ifndef MUSICPRODUCER_H
#define MUSICPRODUCER_H
#include "MusicPlayer.h"
#include "Thread.h"
#include <string>

class MusicProducer:public Thread
{
public:
    MusicProducer(MusicPlayerData a_data);
    void run();
private:
    MusicPlayerData m_data;
};

#endif