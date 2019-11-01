#include "mu_test.h"
#include "Producer.h"
#include "Consumer.h"
#include "WaitableQueue.h"
#define SIZE 3
#define NUM_OF_ITEMS 16

UNIT(producuer_consumer)

    std::deque<int> m_deq;
    Mutex mutex;
    Semaphore empty(NUM_OF_ITEMS);
    Semaphore full(0);
    size_t numOfItemsToProduce=NUM_OF_ITEMS;
    size_t delay=10;

    Producer* producerArray[SIZE];
    Consumer* consumerArray[SIZE];

    for(int i=0;i<SIZE;++i)
    {
        producerArray[i]=new Producer(m_deq,mutex,empty,full,numOfItemsToProduce,delay);
    }

   for(int i=0;i<SIZE;++i)
    {
        consumerArray[i]=new Consumer(m_deq,mutex,empty,full,delay);
    }

    for(int i=0;i<SIZE;++i)
    {
        producerArray[i]->start();
    }

    for(int i=0;i<SIZE;++i)
    {
        consumerArray[i]->start();
    }

    for(int i=0;i<SIZE;++i)
    {
        producerArray[i]->join();
    }

    for(int i=0;i<SIZE;++i)
    {
        consumerArray[i]->cancel();
    }

   for(int i=0;i<SIZE;++i)
    {
        consumerArray[i]->join();
    }
    
   for(int i=0;i<SIZE;++i)
   {
        delete producerArray[i];
   }

    for(int i=0;i<SIZE;++i)
   {
        delete consumerArray[i];
   }
  
END_UNIT

TEST_SUITE(Producer Consumer Tests)
    TEST(producuer_consumer) 
END_SUITE
