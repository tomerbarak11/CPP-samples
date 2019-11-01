#include "mu_test.h"
#include <vector>
#include "MusicPlayer.h"
#include "MusicProducer.h"
#include <iostream>
#include <cstring>
#include "StructForMusicPlayer.h"
#define NUMOFTHREADS 5

UNIT(MusicPlayer_one)
    std::vector<MusicProducer> vec;

    for(size_t i=0;i<1;++i)
    {
        std::string indexStr;  
        std::ostringstream convert; 
        convert << i+1; 
        indexStr = convert.str();
        std::string connectedStringSong="Song"+indexStr;
        std::string connectedStringBand="Band"+indexStr;

        CatData tempData={connectedStringSong,connectedStringBand};
        MusicProducer temp(tempData);
        vec.push_back(temp);
    }

    for(size_t i=0;i<1;++i)
    {
        vec[i].start();
    }

    for(size_t i=0;i<1;++i)
    {
        vec[i].join();
    }

    MusicPlayer mp;
    ASSERT_EQUAL(mp.getOne(),1);
    ASSERT_EQUAL(mp.getAtomicCounter(),1);
    
END_UNIT

UNIT(MusicPlayer_many)
    std::vector<MusicProducer> vec;
    for(size_t i=0;i<NUMOFTHREADS;++i)
    {
        std::string indexStr;  
        std::ostringstream convert; 
        convert << i+1; 
        indexStr = convert.str();
        std::string connectedStringSong="Song"+indexStr;
        std::string connectedStringBand="Band"+indexStr;
        CatData tempData={connectedStringSong,connectedStringBand};
        MusicProducer temp(tempData);
        vec.push_back(temp);
    }
    MusicPlayer mp;
    mp.setAtomicCounter(0);

    for(size_t i=0;i<NUMOFTHREADS;++i)
    {
        vec[i].start();
    }

    for(size_t i=0;i<NUMOFTHREADS;++i)
    {
        vec[i].join();
    }

    ASSERT_EQUAL(mp.getOne(),1);
    ASSERT_EQUAL(mp.getAtomicCounter(),NUMOFTHREADS);
    
END_UNIT


TEST_SUITE(MusicPlayerThreads Tests)
    TEST(MusicPlayer_one)
    TEST(MusicPlayer_many)

END_SUITE

