#ifndef SEMAPHORE_H
#define SEMAPHORE_H
#include <cstddef>
#include <semaphore.h>
class Semaphore
{
public: 
    Semaphore(size_t a_size);
    ~Semaphore();
    void up();
    void down();

private:
    sem_t m_sem;
};

#endif