#ifndef HASHREMOVERTHREAD_H
#define HASHREMOVERTHREAD_H
#include "SafeHash.h"
#include "Thread.h"
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

template<typename K,typename V,typename H>
class hashRemoverThread:public Thread
{
public:
    hashRemoverThread(SafeHash<K,V,H>& a_sh);
    void run();
    size_t randomGenerator() const;

private:
    SafeHash<K,V,H>& m_sh;
};

template<typename K,typename V,typename H>
hashRemoverThread<K,V,H>::hashRemoverThread(SafeHash<K,V,H>& a_sh)
: m_sh(a_sh)
{
}

template<typename K,typename V,typename H>
void hashRemoverThread<K,V,H>::run()
{
    while(1)
    {
        size_t itemToRemove;
        size_t value;
        std::cout<<"Enter an item to remove\n";
        std::cin>>itemToRemove;
        if(m_sh.remove(itemToRemove,value))
        {
            std::cout<<"Removed item = "<<itemToRemove<<"\n";
        }
    }
}

#endif
