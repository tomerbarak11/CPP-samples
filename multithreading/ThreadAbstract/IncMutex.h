#ifndef INCMUTEX_H
#define INCMUTEX_H
#include "IncThread.h"
#include "MutexLocker.h"
class IncMutex: public IncThread
{
public:
    IncMutex(int& a_mutex,size_t a_count,size_t, MutexLocker &a_locker);
    virtual void run();
private:
    MutexLocker& m_locker;
private:
};

#endif