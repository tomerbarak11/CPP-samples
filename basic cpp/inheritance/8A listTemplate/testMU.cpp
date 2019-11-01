#include "mu_test.h"
#include "SortedList.h"

const int TEST_SIZE = 16;

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

UNIT(front_back)
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

	TEST(list_insert_size_is_empty)
	TEST(list_remove)
	TEST(front_back)
	
END_SUITE
