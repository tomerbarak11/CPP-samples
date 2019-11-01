#include "mu_test.h"
#include "stars.h"
#include "IncThread.h"
#include "IncMutex.h"
#include <iostream>
#include "MutexLocker.h"

UNIT(stars)
    Stars a('!', 100, 10);
    Stars b('@', 100, 10);
    Stars c('#', 100, 10);

    a.start();
    b.start();
    c.start();

    a.join();
    b.join();
    c.join();
END_UNIT

UNIT(only_thread)
    int global=0;
    IncThread inc1(global,10000, 10);
    IncThread inc2(global,10000, 10);
    
    inc1.start();
    inc2.start();
  
    inc1.join();
    inc2.join();
    std::cout<<global;
    ASSERT_THAT(inc1.getGlobal()<=20000);
    ASSERT_THAT(inc2.getGlobal()<=20000);
    
END_UNIT

UNIT(mutex)
    int global=0;
    pthread_mutex_t locker;
    MutexLocker ml(locker);
    IncMutex incMutex1(global,20000,10,ml);
    IncMutex incMutex2(global,20000,10,ml);

    incMutex1.start();
    incMutex2.start();
  
    incMutex1.join();
    incMutex2.join();
    std::cout<<global<<"\n";
    ASSERT_EQUAL(incMutex1.getGlobal(),40000);
    ASSERT_EQUAL(incMutex2.getGlobal(),40000);

END_UNIT

TEST_SUITE(Hash Tests)
    //TEST(stars)
    //TEST(only_thread)
    TEST(mutex) 
END_SUITE
