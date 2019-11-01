#ifndef INCTHREAD_H
#define INCTHREAD_H
#include "thread.h"

class IncThread: public Thread
{
public:
    IncThread(int& global,size_t a_count,size_t m_delay);
    virtual void run();
    int getGlobal();

protected:
    size_t m_count;
    size_t m_delay; 
    int& m_global;
 
private:
};

#endif