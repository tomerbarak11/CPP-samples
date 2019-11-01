//
// Stack64 Class Exercise
//
//
#include "mu_test.h"
#include "Stack64.h"

UNIT(constructors)
	Stack64 s;

	ASSERT_THAT(s.isEmpty());
	ASSERT_THAT(s.isFull() == false);

	ASSERT_EQUAL_INT(0, s.size());

	int r = 5;
	try{
		s.pop(&r);
	}
	catch(std::exception& e)
	{
		std::cout<<"Underflaw exception\n";
	}
	ASSERT_EQUAL(r, 5);

END_UNIT

UNIT(is_lifo)
	Stack64 s;

	int a = 1;
	ASSERT_THAT(s.push(a));

	ASSERT_THAT(s.isEmpty() == false);
	ASSERT_THAT(s.isFull() == false);
	ASSERT_EQUAL(s.size(), 1);

	int b = 2;
	ASSERT_THAT(s.push(b));
	ASSERT_THAT(s.isEmpty() == false);
	ASSERT_THAT(s.isFull() == false);
	ASSERT_EQUAL(s.size(), 2);

	int c;
	ASSERT_THAT(s.pop(&c));
	ASSERT_EQUAL(s.size(), 1);
	ASSERT_EQUAL(c, b);

END_UNIT

UNIT(empty_full)
	Stack64 s;

	// push
	for (int i=0; i < static_cast<int>(s.capacity()); ++i)
	{
		ASSERT_THAT(s.push(i));
	}
	ASSERT_EQUAL(s.size(), s.capacity());

	// full
	ASSERT_THAT(s.isFull());
	try
	{
		s.push(99);
	}
	catch(std::exception& e)
	{
		std::cout<<"Overflaw exception\n";
	}	

	// pop
	for (int i=0; i < static_cast<int>(s.capacity()); ++i)
	{
		int r;
		ASSERT_THAT(s.pop(&r));
		ASSERT_EQUAL_INT(r, (s.capacity() - 1 - i));
	}
	ASSERT_EQUAL(s.size(), 0);

	// empty
	int c = -1;
	ASSERT_THAT(s.isEmpty());
	try
	{
		s.pop(&c);
	}
	catch(std::exception& e)
	{
		std::cout<<"Underflaw exception\n";
	}
	ASSERT_EQUAL(c, -1);

	ASSERT_THAT(s.top(&c) == false);
	ASSERT_EQUAL(c, -1);

END_UNIT

UNIT(empty_full_exception)
	Stack64 s;

	// push
	for (int i=0; i < static_cast<int>(s.capacity()); ++i)
	{
		ASSERT_THAT(s.push(i));
	}
	ASSERT_EQUAL(s.size(), s.capacity());

	// full
	ASSERT_THAT(s.isFull());
	try
	{
		s.push(99);
	}
	catch(std::exception& e){
		std::cout<<"Overflaw exception\n";
	}

	// pop
	for (int i=0; i < static_cast<int>(s.capacity()); ++i)
	{
		int r;
		ASSERT_THAT(s.pop(&r));
		ASSERT_EQUAL_INT(r, (s.capacity() - 1 - i));
	}
	ASSERT_EQUAL(s.size(), 0);

	// empty
	int c = -1;
	ASSERT_THAT(s.isEmpty());
	
	ASSERT_EQUAL(c, -1);

	try{
			s.pop(&c);
	}
	catch(std::exception& e){
		std::cout<<"Underflaw exception\n";

	}

	ASSERT_THAT(s.top(&c) == false);
	ASSERT_EQUAL(c, -1);

END_UNIT

TEST_SUITE(Stack [fixed size] of ints)

	TEST(constructors)
	TEST(is_lifo)
	TEST(empty_full)
	TEST(empty_full_exception)

END_SUITE
