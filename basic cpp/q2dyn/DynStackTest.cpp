//
// DynStack Class Exercise
//
//

#include "mu_test.h"

#include "DynStack.h"

std::ostream& operator<<(std::ostream& a_os, DynStack const& a_ds)
{
	a_ds.trace(a_os);
	return a_os;
}


UNIT(constructors)
	DynStack s;

	ASSERT_THAT(s.isEmpty());
	ASSERT_THAT(s.isFull() == false);

	ASSERT_EQUAL_INT(0, s.size());

	int r = 5;
	ASSERT_THAT(s.pop(r) == false);
	ASSERT_EQUAL(r, 5);

END_UNIT

UNIT(is_lifo)
	DynStack s;

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
	ASSERT_THAT(s.pop(c));
	ASSERT_EQUAL(s.size(), 1);
	ASSERT_EQUAL(c, b);

END_UNIT

UNIT(empty_full)
	const size_t N = 8;
	DynStack s(N);

	// push
	for (int i=0; i < static_cast<int>(s.capacity()); ++i)
	{
		ASSERT_THAT(s.push(i));
	}
	ASSERT_EQUAL(s.size(), s.capacity());

	// full
	ASSERT_THAT(s.isFull());
	ASSERT_THAT(s.push(99) == false);

	// pop
	for (int i=0; i < static_cast<int>(s.capacity()); ++i)
	{
		int r;
		ASSERT_THAT(s.pop(r));
		ASSERT_EQUAL(r, static_cast<int>(s.capacity() - 1 - i));
	}
	ASSERT_EQUAL(s.size(), 0);

	// empty
	int c = -1;
	ASSERT_THAT(s.isEmpty());
	ASSERT_THAT(s.pop(c) == false);
	ASSERT_EQUAL(c, -1);

	ASSERT_THAT(s.top(c) == false);
	ASSERT_EQUAL(c, -1);

END_UNIT

UNIT(assign)
	const int N = 10;
	DynStack s1(N);
// Fill in first stack
	for(int i = 0; i < N; ++i)
	{
		s1.push(i+1);
	}

// Assign to another stack
	// CCTOR
	DynStack s2(s1);
	// assignment
	// s2 = s1;

	TRACER << ">>After copy\n";
	TRACER << "S1=" << s1;
	TRACER << "S2=" << s2;

	int t2;
	s2.top(t2);
	ASSERT_EQUAL(t2, N);

// Do operations on s1
	TRACER << "S1 pop ";
	for (int i=0; i < N-5; ++i)
	{
		int r;
		s1.pop(r);
		TRACER << i << "= " << r << ' ';
	}
	TRACER << '\n';

	TRACER << "S1 push ";
	for (int i=0; i < N-5; ++i)
	{
		int r = i+1;
		s1.push(r);
		TRACER << i << "= " << r << ' ';
	}
	TRACER << '\n';

	TRACER << "S1=" << s1;
	TRACER << "S2=" << s2;

	s2.pop(t2);
	ASSERT_EQUAL(t2, N);

	TRACER << "Last one in S2 is " << t2 << '\n';

END_UNIT

TEST_SUITE(Dynamic Stack [fixed size] of ints)

	TEST(constructors)
	TEST(is_lifo)
	TEST(empty_full)
	TEST(assign)

END_SUITE
