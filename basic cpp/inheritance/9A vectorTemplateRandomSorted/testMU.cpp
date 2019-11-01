#include "mu_test.h"
#include "SortedVector.h"
#include "RandomBase.h"
#include "SortedList.h"
const int TEST_SIZE = 16;

UNIT(vector_insert_size_is_empty)
	SortedVector <int> sv;
	ASSERT_THAT(sv.size()==0);
	TRACER << "Insert ";
	for (int i = TEST_SIZE; i > 0; --i)
	{
		sv.insert(i);
		TRACER << i << ' ';
	}

	TRACER << '\n';
	ASSERT_THAT(sv.size()==TEST_SIZE);

	for (size_t i = 1; i < sv.size(); ++i)
	{
		ASSERT_THAT( sv[i] >= sv[i-1] );
	}

END_UNIT

UNIT(vector_remove)
	SortedVector <int> sv;

	TRACER << "Insert ";
	for (int i = TEST_SIZE; i > 0; --i)
	{
		sv.insert(i);
		TRACER << i << ' ';
	}
	TRACER << '\n';

	for (size_t i = 1; i < sv.size(); ++i)
	{
		ASSERT_THAT( sv[i] >= sv[i-1] );
	}
	
	sv.remove(7);
	ASSERT_THAT(sv.size() == 15 );

	for (size_t i = 0; i < sv.size(); ++i)
	{
		TRACER << sv[i]<< ' ';
	}
		TRACER << '\n';

END_UNIT

UNIT(front_back)
	SortedVector <int> sv;

	TRACER << "Insert ";
	for (int i = TEST_SIZE; i > 0; --i)
	{
		sv.insert(i);
		TRACER << i << ' ';
	}
	TRACER << '\n';
	for (size_t i = 1; i < sv.size(); ++i)
	{
		ASSERT_THAT( sv[i] >= sv[i-1] );
	}
	
	sv.remove(7);
	ASSERT_THAT(sv.size() == 15 );
	
	ASSERT_THAT(sv.front() == 1 );
	ASSERT_THAT(sv.back() == TEST_SIZE );

END_UNIT

UNIT(vector_insert_size_is_empty_random)
	SortedVector <int> sv;
	RandomRange<int> rr(10,25);
	ASSERT_THAT(sv.size()==0);
	TRACER << "Insert ";
	for (int i = TEST_SIZE; i > 0; --i)
	{
		int num=rr.get();
		sv.insert(num);
		TRACER << i << ' ';
	}

	TRACER << '\n';
	ASSERT_THAT(sv.size()==TEST_SIZE);

	for (size_t i = 1; i < sv.size(); ++i)
	{
		ASSERT_THAT( sv[i] >= sv[i-1] );
	}

	for (size_t i = 1; i < sv.size(); ++i)
	{
		TRACER<<sv[i]<<"\n";
	}
	
END_UNIT


/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/


UNIT(list_insert_size_is_empty)
	SortedList <int> sv;
	ASSERT_THAT(sv.size()==0);
	TRACER << "Insert ";
	for (int i = TEST_SIZE; i > 0; --i)
	{
		sv.insert(i);
		TRACER << i << ' ';
	}

	TRACER << '\n';
	ASSERT_THAT(sv.size()==TEST_SIZE);
	
	std::list<int>::const_iterator b=sv.begin();
	std::list<int>::const_iterator e=sv.end();
	while(b!=e)
	{
		TRACER << *b<<' ';
		ASSERT_THAT(*b<=*(++b));		
	}

END_UNIT

UNIT(list_remove)
	SortedList <int> sv;

	TRACER << "Insert ";
	for (int i = TEST_SIZE; i > 0; --i)
	{
		sv.insert(i);
		TRACER << i << ' ';
	}
	TRACER << '\n';

	std::list<int>::const_iterator b=sv.begin();
	std::list<int>::const_iterator e=sv.end();
	while(b!=e)
	{
		TRACER << *b<<' ';
		ASSERT_THAT(*b<=*(++b));		
	}
	TRACER << '\n';

	sv.remove(16);
	sv.remove(15);
	sv.remove(14);
	
	b=sv.begin();
	ASSERT_THAT(sv.size() == TEST_SIZE-3 );

	while(b!=e)
	{
		TRACER << *b<<' ';
		ASSERT_THAT(*b<=*(++b));		
	}
END_UNIT

UNIT(front_back_list)
	SortedList <int> sv;

	TRACER << "Insert ";
	for (int i = TEST_SIZE; i > 0; --i)
	{
		sv.insert(i);
		TRACER << i << ' ';
	}
	TRACER << '\n';
	std::list<int>::const_iterator b=sv.begin();
	std::list<int>::const_iterator e=sv.end();
	while(b!=e)
	{
		TRACER << *b<<' ';
		ASSERT_THAT(*b<=*(++b));		
	}
	
	sv.remove(7);
	ASSERT_THAT(sv.size() == 15 );
	ASSERT_THAT(sv.front() == 1 );
	ASSERT_THAT(sv.back() == TEST_SIZE );

END_UNIT


TEST_SUITE(sorted vector of ints)

	TEST(vector_insert_size_is_empty)
	TEST(vector_remove)
	TEST(front_back)
	TEST(vector_insert_size_is_empty_random)

	TEST(list_insert_size_is_empty)
	TEST(list_remove)
	TEST(front_back_list)

END_SUITE
