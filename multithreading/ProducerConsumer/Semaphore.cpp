#include "Semaphore.h"
#include "errno.h"

Semaphore::Semaphore(size_t a_value)
{
    sem_init(&m_sem,0,a_value);
}

Semaphore::~Semaphore()
{
    sem_destroy(&m_sem);
}

void Semaphore::up()
{
    if(sem_post(&m_sem)!=0)
    {
        throw errno;
    }
}

void Semaphore::down()
{
    if(sem_wait(&m_sem)!=0)
    {
        throw errno;
    }
}