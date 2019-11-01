#include "mu_test.h"
#include "Writer.h"
#include "Reader.h"
#include "ConditionalVariable.h"
#include "Mutex.h"
#define SIZE 3

UNIT(producuer_consumer)
    Mutex mutexWrite;
    Mutex mutexRead;
    bool g_writerDone=false;
    bool g_readerArrived=false;
    ConditionalVariable cvWriter(mutexWrite);
    ConditionalVariable cvReader(mutexRead);
    Mutex mutexWriter;    
    Mutex mutexReader;
    char buffer[10000];
    std::string sharedString="WRITER\n";
    Writer w(cvWriter,cvReader,sharedString,g_writerDone,g_readerArrived,buffer);
    Reader* rArr[SIZE];

    for(int i=0;i<SIZE;++i)
    {
        rArr[i]=new Reader(cvWriter,cvReader,g_writerDone,g_readerArrived,buffer);
    }

    w.start();
    std::cout<<"Writer started\n";

    for(int i=0;i<SIZE;++i)
    {
        rArr[i]->start();
    }

    w.join();
    std::cout<<"Writer joined\n";

   for(int i=0;i<SIZE;++i)
    {
        rArr[i]->join();
    }  
    std::cout<<"Reader joined\n";

    for(int i=0;i<SIZE;++i)
    {
        delete rArr[i];
    }
    std::cout<<"Reader deleted\n";      

END_UNIT

TEST_SUITE(Producer Consumer Tests)
    TEST(producuer_consumer) 
END_SUITE
