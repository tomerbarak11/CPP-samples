/**
 * @file	RationalStackTest.cpp
 *
 * @brief	Day 1 - Homework 1C Unit Test
 *
 * 		Demonstrates the calls to Rational CTORs and DTOR, creation
 * 	of temporary objects, and cleanup
 *
 * @author	Alex-The-Teacher (inspired by MhZ alias TryFinally)
 */
#include "mu_test.h"
#include "RationalStack.h"

UNIT(constructors)
	RationalStack s;

	ASSERT_THAT(s.isEmpty());
	ASSERT_THAT(s.isFull() == false);

	ASSERT_EQUAL_INT(s.size(), 0);

END_UNIT

UNIT(is_lifo)
	RationalStack s;

	Rational a(1);
	ASSERT_THAT(s.push(a));

	ASSERT_THAT(s.isEmpty() == false);
	ASSERT_THAT(s.isFull() == false);
	ASSERT_EQUAL(s.size(), 1);


	Rational b(5, 9);
	ASSERT_THAT(s.push(b));
	ASSERT_THAT(s.isEmpty() == false);
	ASSERT_THAT(s.isFull() == false);
	ASSERT_EQUAL(s.size(), 2);

	Rational c = s.top();
	ASSERT_EQUAL(s.size(), 2);
	ASSERT_EQUAL(c.numerator(), b.numerator());
	ASSERT_EQUAL(c.denominator(), b.denominator());

	c = s.pop();
	ASSERT_EQUAL(s.size(), 1);
	ASSERT_EQUAL(c.numerator(), b.numerator());
	ASSERT_EQUAL(c.denominator(), b.denominator());

END_UNIT

UNIT(print)
	RationalStack s;
	s.print();
	printf("\n");	
	s.trace();
	printf("\n");
	s.push(Rational(1,1));
	s.print();
	printf("\n");
	s.trace();
	printf("\n");	
	const int N = RATIONAL_STACK_SIZE;

	for(int i = 1; i < N; ++i)
	{
		s.push(Rational(i, i+1));
	}

	s.print();
	s.trace();
	ASSERT_EQUAL(s.size(), N);

	Rational r = s.pop();
	ASSERT_EQUAL(s.size(), N-1);
	s.print();
	s.trace();

	r = s.pop();
	ASSERT_EQUAL(s.size(), N-2);
	s.print();
	s.trace();
END_UNIT

TEST_SUITE(Stack [fixed size] of Rationals)

	TEST(constructors)
	TEST(is_lifo)
	TEST(print)

END_SUITE
