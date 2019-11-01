#include "mu_test.h"
#include "Producer.h"
#include "Consumer.h"
#include "WaitableQueue.h"
#include "ConditionalVariable.h"
#include "Mutex.h"
#include <vector>
#include <time.h>

#define NUM_OF_ITEMS 5
#define DELAY 100000

UNIT(producuer_consumer_conditional_1to1)
    size_t numProducers=1;
    size_t numConsumers=1;
    Mutex mutex;
    size_t size=5;
    WaitableQueue<size_t> *wq=new WaitableQueue<size_t>(size);
    std::vector<Producer<size_t> > producerArray;
    std::vector<Consumer<size_t> > consumerArray;
    Mutex numOfProducersMutex;
    srand(time(NULL));
    for(size_t i=0;i<numProducers;++i)
    {
        Producer<size_t> tempP(*wq,NUM_OF_ITEMS,DELAY);
        producerArray.push_back(tempP);
    }

    for(size_t i=0;i<numConsumers;++i)
    {
        Consumer<size_t> tempC(*wq,numProducers,numOfProducersMutex,DELAY);
        consumerArray.push_back(tempC);
    }

    for(size_t i=0;i<numProducers;++i)
    {
        producerArray[i].start();
    }

    for(size_t i=0;i<numConsumers;++i)
    {
        consumerArray[i].start();
    }

    for(size_t i=0;i<numProducers;++i)
    {
        producerArray[i].join();
    }
    usleep(100000);
    delete wq; 

   for(size_t i=0;i<numConsumers;++i)
    {
        consumerArray[i].join();
    }
END_UNIT

UNIT(producuer_consumer_conditional_1toN)
    size_t numProducers=1;
    size_t numConsumers=3;
    Mutex mutex;
    size_t size=5;
    WaitableQueue<size_t> *wq=new WaitableQueue<size_t>(size);
    std::vector<Producer<size_t> > producerArray;
    std::vector<Consumer<size_t> > consumerArray;
    Mutex numOfProducersMutex;
    srand(time(NULL));
    for(size_t i=0;i<numProducers;++i)
    {
        Producer<size_t> tempP(*wq,NUM_OF_ITEMS,DELAY);
        producerArray.push_back(tempP);
    }

    for(size_t i=0;i<numConsumers;++i)
    {
        Consumer<size_t> tempC(*wq,numProducers,numOfProducersMutex,DELAY);
        consumerArray.push_back(tempC);
    }

    for(size_t i=0;i<numProducers;++i)
    {
        producerArray[i].start();
    }

    for(size_t i=0;i<numConsumers;++i)
    {
        consumerArray[i].start();
    }

    for(size_t i=0;i<numProducers;++i)
    {
        producerArray[i].join();
    }
    usleep(100000);
    delete wq; 

   for(size_t i=0;i<numConsumers;++i)
    {
        consumerArray[i].join();
    }
END_UNIT

UNIT(producuer_consumer_conditional_Nto1)
    size_t numProducers=3;
    size_t numConsumers=1;
    Mutex mutex;
    size_t size=5;
    WaitableQueue<size_t> *wq=new WaitableQueue<size_t>(size);
    std::vector<Producer<size_t> > producerArray;
    std::vector<Consumer<size_t> > consumerArray;
    Mutex numOfProducersMutex;
    srand(time(NULL));
    for(size_t i=0;i<numProducers;++i)
    {
        Producer<size_t> tempP(*wq,NUM_OF_ITEMS,DELAY);
        producerArray.push_back(tempP);
    }

    for(size_t i=0;i<numConsumers;++i)
    {
        Consumer<size_t> tempC(*wq,numProducers,numOfProducersMutex,DELAY);
        consumerArray.push_back(tempC);
    }

    for(size_t i=0;i<numProducers;++i)
    {
        producerArray[i].start();
    }

    for(size_t i=0;i<numConsumers;++i)
    {
        consumerArray[i].start();
    }

    for(size_t i=0;i<numProducers;++i)
    {
        producerArray[i].join();
    }
    usleep(100000);
    delete wq; 

   for(size_t i=0;i<numConsumers;++i)
    {
        consumerArray[i].join();
    }
END_UNIT

UNIT(producuer_consumer_conditional_NtoN)
    size_t numProducers=3;
    size_t numConsumers=3;
    Mutex mutex;
    size_t size=5;
    WaitableQueue<size_t> *wq=new WaitableQueue<size_t>(size);
    std::vector<Producer<size_t> > producerArray;
    std::vector<Consumer<size_t> > consumerArray;
    Mutex numOfProducersMutex;
    srand(time(NULL));
    for(size_t i=0;i<numProducers;++i)
    {
        Producer<size_t> tempP(*wq,NUM_OF_ITEMS,DELAY);
        producerArray.push_back(tempP);
    }

    for(size_t i=0;i<numConsumers;++i)
    {
        Consumer<size_t> tempC(*wq,numProducers,numOfProducersMutex,DELAY);
        consumerArray.push_back(tempC);
    }

    for(size_t i=0;i<numProducers;++i)
    {
        producerArray[i].start();
    }

    for(size_t i=0;i<numConsumers;++i)
    {
        consumerArray[i].start();
    }

    for(size_t i=0;i<numProducers;++i)
    {
        producerArray[i].join();
    }
    usleep(100000);
    delete wq; 

   for(size_t i=0;i<numConsumers;++i)
    {
        consumerArray[i].join();
    }
END_UNIT

TEST_SUITE(Producer Consumer Tests)
    TEST(producuer_consumer_conditional_1to1)
    TEST(producuer_consumer_conditional_1toN)
    TEST(producuer_consumer_conditional_Nto1)
    TEST(producuer_consumer_conditional_NtoN)




END_SUITE
