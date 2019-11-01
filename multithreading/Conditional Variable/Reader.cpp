#include "Reader.h"
#include <iostream>

Reader::Reader(ConditionalVariable& a_cvWriter
,ConditionalVariable& a_cvReader
, bool& a_gReaderArrived
, bool& a_gWriterDone
,char* a_gBuffer)

: m_cvWriter(a_cvWriter)
, m_cvReader(a_cvReader)
, m_gReaderArrived(a_gReaderArrived)
, m_gWriterDone(a_gWriterDone)
, m_gBuffer(a_gBuffer)
{
}

void Reader::run()
{
    m_gReaderArrived=true;
    m_cvWriter.broadcast();
    m_cvReader.lock();
    while(!m_gWriterDone)
    {
        m_cvReader.wait();
    }
    std::cout<<"The message is "<<m_gBuffer<<"\n";
    m_cvReader.unlock();
}