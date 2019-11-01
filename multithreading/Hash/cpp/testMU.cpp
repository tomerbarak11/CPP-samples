#include "mu_test.h" 
#include "SafeHash.h"
#include "hashInserterThread.h"
#include "hashRemoverThread.h"
#define SIZEOFHASH 7
#define NUMBEROFMUTEXES 5
#define SIZE 3

class HasherForSize_t
{
public:
	size_t operator()(int a_key)
	{
		return a_key;
	}
};

UNIT(crt_test_1to1)
	size_t numberOfInserters=1;
	size_t numberOfRemovers=1;

	srand(time(0));
	SafeHash<size_t,size_t,HasherForSize_t> safeHash = SafeHash<size_t,size_t,HasherForSize_t> (SIZEOFHASH,NUMBEROFMUTEXES);
	std::vector<hashInserterThread<size_t,size_t,HasherForSize_t> >inserter;
	std::vector<hashRemoverThread<size_t,size_t,HasherForSize_t> >remover;

	for(size_t i=0;i<numberOfInserters;++i)
	{
		inserter.push_back(safeHash);
	}

	for(size_t i=0;i<numberOfRemovers;++i)
	{
		remover.push_back(safeHash);
	}

	for(size_t i=0;i<numberOfInserters;++i)
	{
		inserter[i].start();
	}

	for(size_t i=0;i<numberOfRemovers;++i)
	{
		remover[i].start();
	}

	for(size_t i=0;i<numberOfInserters;++i)
	{
		inserter[i].join();
	}

	for(size_t i=0;i<numberOfRemovers;++i)
	{
		remover[i].join();
	}

END_UNIT

UNIT(crt_test_1toN)
	size_t numberOfInserters=1;
	size_t numberOfRemovers=SIZE;

	srand(time(0));
	SafeHash<size_t,size_t,HasherForSize_t> safeHash = SafeHash<size_t,size_t,HasherForSize_t> (SIZEOFHASH,NUMBEROFMUTEXES);
	std::vector<hashInserterThread<size_t,size_t,HasherForSize_t> >inserter;
	std::vector<hashRemoverThread<size_t,size_t,HasherForSize_t> >remover;

	for(size_t i=0;i<numberOfInserters;++i)
	{
		inserter.push_back(safeHash);
	}

	for(size_t i=0;i<numberOfRemovers;++i)
	{
		remover.push_back(safeHash);
	}

	for(size_t i=0;i<numberOfInserters;++i)
	{
		inserter[i].start();
	}

	for(size_t i=0;i<numberOfRemovers;++i)
	{
		remover[i].start();
	}

	for(size_t i=0;i<numberOfInserters;++i)
	{
		inserter[i].join();
	}

	for(size_t i=0;i<numberOfRemovers;++i)
	{
		remover[i].join();
	}
	
END_UNIT
UNIT(crt_test_Nto1)
	size_t numberOfInserters=SIZE;
	size_t numberOfRemovers=1;

	srand(time(0));
	SafeHash<size_t,size_t,HasherForSize_t> safeHash = SafeHash<size_t,size_t,HasherForSize_t> (SIZEOFHASH,NUMBEROFMUTEXES);
	std::vector<hashInserterThread<size_t,size_t,HasherForSize_t> >inserter;
	std::vector<hashRemoverThread<size_t,size_t,HasherForSize_t> >remover;

	for(size_t i=0;i<numberOfInserters;++i)
	{
		inserter.push_back(safeHash);
	}

	for(size_t i=0;i<numberOfRemovers;++i)
	{
		remover.push_back(safeHash);
	}

	for(size_t i=0;i<numberOfInserters;++i)
	{
		inserter[i].start();
	}

	for(size_t i=0;i<numberOfRemovers;++i)
	{
		remover[i].start();
	}

	for(size_t i=0;i<numberOfInserters;++i)
	{
		inserter[i].join();
	}

	for(size_t i=0;i<numberOfRemovers;++i)
	{
		remover[i].join();
	}
	
END_UNIT

UNIT(crt_test_NtoN)
	size_t numberOfInserters=SIZE;
	size_t numberOfRemovers=SIZE;

	srand(time(0));
	SafeHash<size_t,size_t,HasherForSize_t> safeHash = SafeHash<size_t,size_t,HasherForSize_t> (SIZEOFHASH,NUMBEROFMUTEXES);
	std::vector<hashInserterThread<size_t,size_t,HasherForSize_t> >inserter;
	std::vector<hashRemoverThread<size_t,size_t,HasherForSize_t> >remover;

	for(size_t i=0;i<numberOfInserters;++i)
	{
		inserter.push_back(safeHash);
	}

	for(size_t i=0;i<numberOfRemovers;++i)
	{
		remover.push_back(safeHash);
	}

	for(size_t i=0;i<numberOfInserters;++i)
	{
		inserter[i].start();
	}

	for(size_t i=0;i<numberOfRemovers;++i)
	{
		remover[i].start();
	}

	for(size_t i=0;i<numberOfInserters;++i)
	{
		inserter[i].join();
	}

	for(size_t i=0;i<numberOfRemovers;++i)
	{
		remover[i].join();
	}
	
END_UNIT


TEST_SUITE(Hash Tests)
	TEST(crt_test_1to1) 
	TEST(crt_test_1toN) 
	TEST(crt_test_Nto1) 
	TEST(crt_test_NtoN) 

END_SUITE
  