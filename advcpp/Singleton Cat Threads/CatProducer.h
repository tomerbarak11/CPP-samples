#ifndef MUSICPRODUCER_H
#define MUSICPRODUCER_H
#include "Cat.h"
#include "Thread.h"
#include <string>

class CatProducer:public Thread
{
public:
    CatProducer(CatData a_data);
    void run();
private:
    CatData m_data;
};

#endif