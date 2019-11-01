#include "IncThread.h"
#include <unistd.h>
#include <iostream>

IncThread::IncThread(int& global,size_t a_count, size_t a_delay)
: m_count(a_count)
, m_delay(a_delay)
, m_global(global)
{
}

void IncThread::run()
{
    for(size_t i=0;i<m_count;++i)
    {
        usleep(m_delay);
        ++(m_global);
    }
}

int IncThread::getGlobal()
{
   return m_global;
}

