#include "mu_test.h"
#include <vector>
#include "Cat.h"
#include "CatProducer.h"
#include <iostream>
#include <cstring>
#include "StructForCat.h"

#define NUMOFTHREADS 5

UNIT(MusicPlayer_one)
    std::vector<CatProducer> vec;
    for(size_t i=0;i<1;++i)
    {
        std::string str;  
        std::ostringstream convert; 
        convert << i+1; 
        str = convert.str();
        std::string connectedString="Song"+str;
        CatData tempData={connectedString,(int)i+3};
        CatProducer temp(tempData);
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

    Cat c1;
    ASSERT_EQUAL(c1.getOne(),1);
    ASSERT_EQUAL(c1.getAtomicCounter(),1);

END_UNIT

UNIT(MusicPlayer_many)
    std::vector<CatProducer> vec;
    for(size_t i=0;i<NUMOFTHREADS;++i)
    {
        std::string str;  
        std::ostringstream convert; 
        convert << i+1; 
        str = convert.str();
        std::string connectedString="Song"+str;
        CatData tempData={connectedString,(int)i+3};
        CatProducer temp(tempData);
        vec.push_back(temp);
    }
    Cat c1;
    c1.setAtomicCounter(0);

    for(size_t i=0;i<NUMOFTHREADS;++i)
    {
        vec[i].start();
    }

    for(size_t i=0;i<NUMOFTHREADS;++i)
    {
        vec[i].join();
    }

    ASSERT_EQUAL(c1.getOne(),1);
    ASSERT_EQUAL(c1.getAtomicCounter(),NUMOFTHREADS);
    
END_UNIT


TEST_SUITE(MusicPlayerThreads Tests)
    TEST(MusicPlayer_one)
    TEST(MusicPlayer_many)

END_SUITE

