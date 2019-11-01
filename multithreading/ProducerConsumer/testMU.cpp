#include "mu_test.h"
#include "Producer.h"
#include "Consumer.h"
#include "WaitableQueue.h"
#include <vector>
#include <unistd.h>
#include "Item.h"

#define NUM_OF_ITEMS 16
#define DELAY 10
UNIT(producuer_consumer_1to1)
    size_t numProducers=1;
    size_t numConsumers=1;

    WaitableQueue<size_t> wq(NUM_OF_ITEMS);
    std::vector<Producer<size_t>*> producerArray;
    std::vector<Consumer<size_t>*> consumerArray;

    for(size_t i=0;i<numProducers;++i)
    {
        Producer<size_t>* tempP=new Producer<size_t>(wq,NUM_OF_ITEMS,DELAY);
        producerArray.push_back(tempP);
    }

   for(size_t i=0;i<numConsumers;++i)
    {
        Consumer<size_t>* tempP=new Consumer<size_t>(wq,DELAY);
        consumerArray.push_back(tempP);
    }

    for(size_t i=0;i<numProducers;++i)
    {
        producerArray[i]->start();
    }

    for(size_t i=0;i<numConsumers;++i)
    {
        consumerArray[i]->start();
    }

    for(size_t i=0;i<numProducers;++i)
    {
        producerArray[i]->join();
    }
    
    usleep(10000);
    for(size_t i=0;i<numConsumers;++i)
    {
        consumerArray[i]->cancel();
    }

   for(size_t i=0;i<numConsumers;++i)
    {
        consumerArray[i]->join();
    }
    
   for(size_t i=0;i<numProducers;++i)
   {
        delete producerArray[i];
   }

    for(size_t i=0;i<numConsumers;++i)
   {
        delete consumerArray[i];
   }

    ASSERT_EQUAL(0,wq.getNumOfItems());
    ASSERT_THAT(numProducers*NUM_OF_ITEMS==wq.getNumbOfProduced());
    ASSERT_THAT(numConsumers*NUM_OF_ITEMS==wq.getNumbOfConsumed());

END_UNIT

UNIT(producuer_consumer_1toN)
    size_t numProducers=1;
    size_t numConsumers=5;

    WaitableQueue<size_t> wq(NUM_OF_ITEMS);

    std::vector<Producer<size_t>*> producerArray;
    std::vector<Consumer<size_t>*> consumerArray;

    for(size_t i=0;i<numProducers;++i)
    {
        Producer<size_t>* tempP=new Producer<size_t>(wq,NUM_OF_ITEMS,DELAY);
        producerArray.push_back(tempP);
    }

   for(size_t i=0;i<numConsumers;++i)
    {
        Consumer<size_t>* tempP=new Consumer<size_t>(wq,DELAY);
        consumerArray.push_back(tempP);
    }

    for(size_t i=0;i<numProducers;++i)
    {
        producerArray[i]->start();
    }

    for(size_t i=0;i<numConsumers;++i)
    {
        consumerArray[i]->start();
    }

    for(size_t i=0;i<numProducers;++i)
    {
        producerArray[i]->join();
    }

    usleep(10000);
    for(size_t i=0;i<numConsumers;++i)
    {
        consumerArray[i]->cancel();
    }

   for(size_t i=0;i<numConsumers;++i)
    {
        consumerArray[i]->join();
    }
    
   for(size_t i=0;i<numProducers;++i)
   {
        delete producerArray[i];
   }
    for(size_t i=0;i<numConsumers;++i)
   {
        delete consumerArray[i];
   }

    ASSERT_EQUAL(0,wq.getNumOfItems());
    ASSERT_THAT(numProducers*NUM_OF_ITEMS==wq.getNumbOfProduced());
    ASSERT_THAT(numProducers*NUM_OF_ITEMS==wq.getNumbOfConsumed());

END_UNIT

UNIT(producuer_consumer_Nto1)
    size_t numProducers=5;
    size_t numConsumers=1;
    WaitableQueue<size_t> wq(NUM_OF_ITEMS);

    std::vector<Producer<size_t>*> producerArray;
    std::vector<Consumer<size_t>*> consumerArray;

    for(size_t i=0;i<numProducers;++i)
    {
        Producer<size_t>* tempP=new Producer<size_t>(wq,NUM_OF_ITEMS,DELAY);
        producerArray.push_back(tempP);
    }

   for(size_t i=0;i<numConsumers;++i)
    {
        Consumer<size_t>* tempP=new Consumer<size_t>(wq,DELAY);
        consumerArray.push_back(tempP);
    }

    for(size_t i=0;i<numProducers;++i)
    {
        producerArray[i]->start();
    }

    for(size_t i=0;i<numConsumers;++i)
    {
        consumerArray[i]->start();
    }

    for(size_t i=0;i<numProducers;++i)
    {
        producerArray[i]->join();
    }
    usleep(10000);
    for(size_t i=0;i<numConsumers;++i)
    {
        consumerArray[i]->cancel();
    }

   for(size_t i=0;i<numConsumers;++i)
    {
        consumerArray[i]->join();
    }
    
   for(size_t i=0;i<numProducers;++i)
   {
        delete producerArray[i];
   }

    for(size_t i=0;i<numConsumers;++i)
   {
        delete consumerArray[i];
   }

    ASSERT_EQUAL(0,wq.getNumOfItems());
    ASSERT_THAT(numProducers*NUM_OF_ITEMS==wq.getNumbOfProduced());
    ASSERT_THAT(numProducers*NUM_OF_ITEMS==wq.getNumbOfConsumed());

END_UNIT

UNIT(producuer_consumer_NtoN)
    size_t producersNumber=5;
    size_t consumersNumber=5;

    WaitableQueue<size_t> wq(NUM_OF_ITEMS);

    std::vector<Producer<size_t>*> producerArray;
    std::vector<Consumer<size_t>*> consumerArray;

    for(size_t i=0;i<producersNumber;++i)
    {
        Producer<size_t>* tempP=new Producer<size_t>(wq,NUM_OF_ITEMS,DELAY);
        producerArray.push_back(tempP);
    }

   for(size_t i=0;i<consumersNumber;++i)
    {
        Consumer<size_t>* tempP=new Consumer<size_t>(wq,DELAY);
        consumerArray.push_back(tempP);
    }

    for(size_t i=0;i<producersNumber;++i)
    {
        producerArray[i]->start();
    }

    for(size_t i=0;i<consumersNumber;++i)
    {
        consumerArray[i]->start();
    }

    for(size_t i=0;i<producersNumber;++i)
    {
        producerArray[i]->join();
    }
    usleep(10000);
    for(size_t i=0;i<consumersNumber;++i)
    {
        consumerArray[i]->cancel();
    }

   for(size_t i=0;i<consumersNumber;++i)
    {
        consumerArray[i]->join();
    }
    
   for(size_t i=0;i<producersNumber;++i)
   {
        delete producerArray[i];
   }

    for(size_t i=0;i<consumersNumber;++i)
   {
        delete consumerArray[i];
   }

    ASSERT_EQUAL(0,wq.getNumOfItems());
    ASSERT_THAT(producersNumber*NUM_OF_ITEMS==wq.getNumbOfProduced());
    ASSERT_THAT(producersNumber*NUM_OF_ITEMS==wq.getNumbOfConsumed());

END_UNIT

TEST_SUITE(Producer Consumer Tests)
    TEST(producuer_consumer_1to1) 
    TEST(producuer_consumer_1toN) 
    TEST(producuer_consumer_Nto1) 
    TEST(producuer_consumer_NtoN) 

END_SUITE
