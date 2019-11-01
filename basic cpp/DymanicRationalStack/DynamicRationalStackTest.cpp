/**
 * @file	DynamicRationalStackTest.cpp
 *
 * @brief	Day 1 - Homework 1C Unit Test
 *
 * 		Demonstrates the calls to Rational CTORs and DTOR, creation
 * 	of temporary objects, and cleanup
 *
 * @author	Alex-The-Teacher (inspired by MhZ alias TryFinally)
 */
#include "mu_test.h"
#include "DynamicRationalStack.h"
#include "Rational.h"

UNIT(constructors)
	DynamicRationalStack s;

	ASSERT_THAT(s.isEmpty());
	ASSERT_THAT(s.isFull() == false);

	ASSERT_EQUAL_INT(s.size(), 0);

END_UNIT

UNIT(is_lifo)
	DynamicRationalStack s;

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

	Rational c;
	s.top(c);
	ASSERT_EQUAL(s.size(), 2);
	ASSERT_EQUAL(c.numerator(), b.numerator());
	ASSERT_EQUAL(c.denominator(), b.denominator());

	s.pop(c);
	ASSERT_EQUAL(s.size(), 1);
	ASSERT_EQUAL(c.numerator(), b.numerator());
	ASSERT_EQUAL(c.denominator(), b.denominator());

END_UNIT

UNIT(print)
	DynamicRationalStack s;
	s.print();
	std::cout<<"\n";
	s.trace();

	s.push(Rational(1,1));
	s.print();
	std::cout<<"\n";
	s.trace();
	std::cout<<"\n";
	const int N = s_DEFAULT_STACK_INITIAL_SIZE;

	for(int i = 1; i < N; ++i)
	{
		s.push(Rational(i, i+1));
	}

	s.print();
	std::cout<<"\n";	
	s.trace();
	std::cout<<"\n";	
	ASSERT_EQUAL(s.size(), N);

	Rational r;
 	s.pop(r);
	ASSERT_EQUAL(s.size(), N-1);
	s.print();
	std::cout<<"\n";	
	s.trace();
	std::cout<<"\n";
	s.pop(r);
	ASSERT_EQUAL(s.size(), N-2);
	s.print();
	std::cout<<"\n";	
	s.trace();
	std::cout<<"\n";	

END_UNIT

UNIT(drain_test)
	DynamicRationalStack s;
	s.print();
	std::cout<<"\n";
	s.trace();

	s.push(Rational(1,1));
	const int N = s_DEFAULT_STACK_INITIAL_SIZE;

	for(int i = 1; i < N; ++i)
	{
		s.push(Rational(i, i+1));
	}

	s.print();
	std::cout<<"\n";	
	s.trace();
	std::cout<<"\n";	
	ASSERT_EQUAL(s.size(), N);

	DynamicRationalStack d;
	
	s.print();
	ASSERT_EQUAL(s.drain(d),s.size());	
	s.print();
	d.print();
END_UNIT

TEST_SUITE(Stack [fixed size] of Rationals)

	TEST(constructors)
	TEST(is_lifo)
	TEST(print)
	TEST(drain_test)
END_SUITE
