#ifndef HASHINSERTERTHREAD_H
#define HASHINSERTERTHREAD_H
#include "SafeHash.h"
#include "Thread.h"
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

template<typename K,typename V,typename H>
class hashInserterThread:public Thread
{
public:
    hashInserterThread(SafeHash<K,V,H>& a_sh);
    void run();
    size_t randomGenerator() const;
private:
    SafeHash<K,V,H>& m_sh;
};

template<typename K,typename V,typename H>
hashInserterThread<K,V,H>::hashInserterThread(SafeHash<K,V,H>& a_sh)
: m_sh(a_sh)
{
}

template<typename K,typename V,typename H>
void hashInserterThread<K,V,H>::run()
{
    while(1)
    {
        size_t itemToInsert=randomGenerator();
        if(m_sh.updateIf(itemToInsert,itemToInsert))
        {
            std::cout<<"Inserted item = "<<itemToInsert<<"\n";
        }
    }
}

template<typename K,typename V,typename H>
size_t hashInserterThread<K,V,H>::randomGenerator() const
{
    return rand()%(m_sh.getCapacity());
}

#endif
