#include <exception>
#include "Thread.h"
#include <iostream>
Thread::Thread(size_t a_userID)
: m_joinable(true)
, m_threadID(0)
, m_userID(a_userID)
{
}

Thread::~Thread()
{
    if(m_joinable)
    {
        pthread_detach(m_threadID);
    }
}

void* Thread::threadMainFunction(void *a_thread)
{
    Thread* thread = reinterpret_cast<Thread*>(a_thread);
    try
    {
        thread->run();
    }
    catch(const std::exception& e)
    {
		std::cout<<"what exepction\n";
        std::cerr << e.what() << '\n';
    }
    catch(...)
    {
        throw;
    }
    return 0;
}

bool Thread::start()
{
    int r = pthread_create(&m_threadID, 0, threadMainFunction, this);
    return r == 0;
}

void Thread::join()
{
    if(isAlive("Thread::join on thread not started"))
    {
        void *status;
        pthread_join(m_threadID, &status);
        m_joinable = false;
    }
}

void Thread::cancel()
{
    if(isAlive("Thread::cancel on thread not started"))
    {
        pthread_cancel(m_threadID);
    }
}

void Thread::detach()
{
    if(isAlive("Thread::detach on thread not started"))
    {
        pthread_detach(m_threadID);
    }
}

bool Thread::isAlive(std::string a_msg)
{
    if(m_threadID == 0)
    {
        throw(std::runtime_error(a_msg));
        return false;
    }
    return true;
}

