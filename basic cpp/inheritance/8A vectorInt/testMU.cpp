#include "mu_test.h"
#include "SortedVector.h"

const int TEST_SIZE = 16;

UNIT(vector_insert_size_is_empty)
	SortedVector sv;
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
	SortedVector sv;

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
	SortedVector sv;

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

TEST_SUITE(sorted vector of ints)

	TEST(vector_insert_size_is_empty)
	TEST(vector_remove)
	TEST(front_back)
	
END_SUITE
