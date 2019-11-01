#define _XOPEN_SOURCE 500
#include <pthread.h>
#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
int global=0;

static void* incFunc(void* a_struct);
#define SIZE 4
typedef struct inc
{
    size_t m_times;
    size_t m_delay;
}inc;

int main()
{
    inc myInc;
    myInc.m_times=0;
    myInc.m_delay=1;
    pthread_t t[SIZE];
    void* p=&myInc;
    char arrOfChars[SIZE];
    int i;

    for(i=0;i<SIZE;++i)
    {
       pthread_create(&t[i],NULL,incFunc,p);
    }

    for(i=0;i<SIZE;i++)
	{
		pthread_join(t[i], NULL);
	}
    printf("myInc.m_global = %d\n",global);
}

static void* incFunc(void* a_struct)
{
    
    int i;

    for(i=0;i<100;i++)
    {
        ++(((inc*)a_struct)->m_times);
        usleep(((inc*)a_struct)->m_delay);
        ++global;
    }
}
