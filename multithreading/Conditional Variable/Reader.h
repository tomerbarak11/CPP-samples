#ifndef READER_H
#define READER_H
#include "Thread.h"
#include "ConditionalVariable.h"
#include <cstring>

class Reader: public Thread
{
public:
    Reader(ConditionalVariable& a_cvWriter,ConditionalVariable& a_cvReader, bool& a_gReaderArrived, bool& a_gWriterDone,char* a_gBuffer);
    void run();
private:
    ConditionalVariable& m_cvWriter;
    ConditionalVariable& m_cvReader;
    bool& m_gReaderArrived;
    bool& m_gWriterDone;
    char* m_gBuffer;
};

#endif