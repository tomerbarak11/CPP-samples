#ifndef STARS_H
#define STARS_H

#include "thread.h"

class Stars: public Thread
{
public:
    Stars(char a_what, size_t a_count, size_t a_delay);
    virtual void run();
    
private:
    char m_what;
    size_t m_count;
    size_t m_delay;
};

#endif

