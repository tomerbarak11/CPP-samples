#include "Writer.h"
#include <iostream>
#include <bits/stdc++.h>
#include "Mutex.h"

Writer::Writer(ConditionalVariable& a_cvWriter
,ConditionalVariable& a_cvReader
,std::string a_string
,bool& a_gReaderArrived
,bool& a_gWriterDone
,char* a_gBuffer)

: m_cvWriter(a_cvWriter)
, m_cvReader(a_cvReader)
, m_string(a_string)
, m_gReaderArrived(a_gReaderArrived)
, m_gWriterDone(a_gWriterDone)
, m_gBuffer(a_gBuffer)
{   
}

void Writer::run()
{
    m_cvWriter.lock();
    while(!m_gReaderArrived)
    {
        m_cvWriter.wait();
    }
    myWrite();
    m_gWriterDone=true;
    m_cvWriter.unlock();
    m_cvReader.broadcast();
}

void Writer::myWrite()
{
    char* p=new char[m_string.length()+1];
    for (size_t i= 0; i < sizeof(p); i++)
    {
        p[i] = m_string[i]; 
    }
    strcat(m_gBuffer,p);
    std::cout<<"buf="<<m_gBuffer<<"\n";
    delete [] p;
}


