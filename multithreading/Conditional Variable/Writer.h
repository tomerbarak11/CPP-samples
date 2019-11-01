#ifndef WRITER_H
#define WRITER_H
#include "Thread.h"
#include "ConditionalVariable.h"
#include <cstring>
#include "Mutex.h"
class Writer: public Thread
{
public:
    Writer(ConditionalVariable& a_cvWriter
    ,ConditionalVariable& a_cvReader
    ,std::string a_string
    ,bool& a_gReaderArrived
    ,bool& a_gWriterDone
    ,char* a_gBuffer);
    void run();
    void myWrite();
private:
    ConditionalVariable& m_cvWriter;
    ConditionalVariable& m_cvReader;
    std::string m_string;
    bool& m_gReaderArrived;
    bool& m_gWriterDone;    
    char* m_gBuffer;
};

#endif