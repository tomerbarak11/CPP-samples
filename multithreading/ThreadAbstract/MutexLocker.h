#ifndef MUTEX_LOCKER
#define MUTEX_LOCKER
#include <pthread.h>

class MutexLocker
{
public:
    MutexLocker(pthread_mutex_t& a_locker);
    pthread_mutex_t* getLocker();
    void pthread_mutex_initFunc();
    void pthread_mutex_lockFunc();
    void pthread_mutex_unlockFunc();

private:
    pthread_mutex_t *m_locker;
};

#endif