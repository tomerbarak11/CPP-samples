/**
 * @file	RationalTest.cpp
 *
 * @brief	Rational Class Exercise full unit-test
 *
 * @author	Alex-The-Teacher
 */

#include "mu_test.h"
#include "Rational.h"


UNIT(constructors)
	Rational a;
	Rational b(369);
	Rational c(369, 148);

	ASSERT_EQUAL(a.numerator(), 0);
	ASSERT_EQUAL(a.denominator(), 1);

	ASSERT_EQUAL(b.numerator(), 369);
	ASSERT_EQUAL(b.denominator(), 1);

	ASSERT_EQUAL(c.numerator(), 369);
	ASSERT_EQUAL(c.denominator(), 148);

END_UNIT

UNIT(multiply_test)
	Rational a(3, 4);
	Rational b(15, 12);

	a.mul(3);
	ASSERT_EQUAL(a.numerator(), 9);
	ASSERT_EQUAL(a.denominator(), 4);

	a.mul(b);
	ASSERT_EQUAL(a.numerator(), 135);
	ASSERT_EQUAL(a.denominator(), 48);

	a.reduce();
	ASSERT_EQUAL(a.numerator(), 45);
	ASSERT_EQUAL(a.denominator(), 16);

END_UNIT

UNIT(divide_test)
	Rational a(9, 4);
	Rational b(15, 12);

	a.div(3);
	ASSERT_EQUAL(a.numerator(), 3);
	ASSERT_EQUAL(a.denominator(), 4);

	a.div(b);
	ASSERT_EQUAL(a.numerator(), 36);
	ASSERT_EQUAL(a.denominator(), 60);

	a.reduce();
	ASSERT_EQUAL(a.numerator(), 3);
	ASSERT_EQUAL(a.denominator(), 5);

END_UNIT


UNIT(add_test)
	Rational a(1, 2);
	Rational b(1, 3);

	a.add(1);
	ASSERT_EQUAL(a.numerator(), 3);
	ASSERT_EQUAL(a.denominator(), 2);

	a.add(b);
	ASSERT_EQUAL(a.numerator(), 11);
	ASSERT_EQUAL(a.denominator(), 6);
END_UNIT

UNIT(subtract_test)
	Rational a(1, 2);
	Rational b(1, 3);

	a.sub(1);
	ASSERT_EQUAL(a.numerator(), -1);
	ASSERT_EQUAL(a.denominator(), 2);

	a.sub(b);
	ASSERT_EQUAL(a.numerator(), -5);
	ASSERT_EQUAL(a.denominator(), 6);

	a.reduce();
	ASSERT_EQUAL(a.numerator(), -5);
	ASSERT_EQUAL(a.denominator(), 6);

END_UNIT

UNIT(reduce_test)
	Rational a(24,36);
	Rational b(82, 369);

	a.reduce();
	ASSERT_EQUAL(a.numerator(), 2);
	ASSERT_EQUAL(a.denominator(), 3);

	b.reduce();
	ASSERT_EQUAL(b.numerator(), 2);
	ASSERT_EQUAL(b.denominator(), 9);

END_UNIT


UNIT(operations_comparison_test)

	Rational a(1,2);
	Rational b(1,3);
	Rational c(5,6);
	Rational d(1,6);
	Rational e(3,2);
	Rational f(4,6);
	Rational g(12,12);	
	Rational h(3,1);	


	ASSERT_THAT (a + b == c);
	ASSERT_THAT (b + a == c);
	ASSERT_THAT (c == a + b);
	
	ASSERT_THAT (a - b == d);
	ASSERT_THAT (d == a - b);
	
	ASSERT_THAT (a * b == d);
	ASSERT_THAT (b * a == d);
	ASSERT_THAT (d == a * b);
	
	ASSERT_THAT (a / b == e);
	ASSERT_THAT (e == a / b);
	
	a += b;
	ASSERT_EQUAL (a,c);
	
	a -= d;
	ASSERT_EQUAL (a,f);
	
	a *= e;
	ASSERT_EQUAL (a,g);
	
	a /= b;           //  a==3/1
	ASSERT_EQUAL (a,h);
	
	ASSERT_THAT (a > g);
	std::cout<<"b = ";
	b.print(std::cout);
	std::cout<<"\n";
	
	std::cout<<"c = ";
	c.print(std::cout);
	std::cout<<"\n";
	ASSERT_THAT (b < c);
	ASSERT_THAT (a == h);
	ASSERT_THAT (b != h);	
	ASSERT_THAT (h != b);		

END_UNIT


UNIT(out_stream_test)

	Rational a(1,2);
	ASSERT_EQUAL(std::cout<<a, std::cout);

END_UNIT

TEST_SUITE(Rational Class Test)

	TEST(constructors)
	TEST(reduce_test)
	TEST(multiply_test)
	TEST(divide_test)
	TEST(add_test)
	TEST(subtract_test)
	TEST(operations_comparison_test)
	TEST(out_stream_test)

END_SUITE
