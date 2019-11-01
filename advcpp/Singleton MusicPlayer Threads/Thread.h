#ifndef THREAD_H
#define THREAD_H

#include <cstddef>
#include <pthread.h>
#include <string>

class Thread
{
public:
    Thread(size_t a_userID = 0);
    virtual ~Thread();

    bool start();
    void join();
    void cancel();
    void detach();


private:
    static void* threadMainFunction(void *);
    virtual void run() = 0;
    bool isAlive(std::string a_msg);
    
private:
    bool m_joinable;

protected:
    pthread_t m_threadID;
    size_t m_userID;
};

#endif