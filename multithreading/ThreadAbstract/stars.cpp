#include "stars.h"

#include <unistd.h>


Stars::Stars(char a_what, size_t a_count, size_t a_delay)
: Thread()
, m_what(a_what)
, m_count(a_count)
, m_delay(a_delay)
{
}

void Stars::run()
{
    for(size_t i = 0 ; i < m_count ; ++i)
    {
        write(0, &m_what, 1);
        if(m_delay)
        {
            usleep(m_delay);
        }
    }
}