/**
 * @file	demo.cpp
 *
 * Copyright 2019 Alex-the-Teacher <alex.katz.pacific@gmail.com>
 * Inspired by MhZ (a.k.a. TryFinally)

 * @brief	Day 5 - Templates: Class Demo
 *
 *		Demonstrate instantiation of templated:
 * 		* function	- mini(T a, T b)
 * 		* class		- Point(T)
 *
 * 	@warning	Class T has to support arithmetic operations +,-,*,/
 *
 */
#include <iostream>
#include <string>
#include <cmath>

#include "Rational.h"
#include "Point.h"

static const char nl = '\n';

void Points()
{
	std::cout << "\nPoint: template use" << nl;

	Point<short int> sP(1, 2), ssP(6, 9);
	std::cout << "<short int>=" << sP << nl;

	Point<float> fP(-1.5, -2.5), ffP(1.5, 2.5);
	std::cout << "<float>=" << fP << nl;

	Rational x(10), y(60);
	Point<Rational> rP(x, y);
	Point<Rational> xP(1, 2);
	std::cout << "<Rational>(10,60)=" << rP << nl;
	std::cout << "<Rational>(1,2)=" << xP << nl;

	std::string  sx("Maor"), sy("Ittay");
	Point<std::string> strP1(sx, sy);
	Point<std::string> strP2 = strP1;

	strP2.move("Alex");
	std::cout << "Point strP1 = " << strP1 << nl;
	std::cout << "Point strP2 = " << strP2 << nl;

	std::cout << "Distance s=" << sP.distance(ssP) << nl;
	std::cout << "Distance f=" << fP.distance(ffP) << nl;

	//~ std::cout << "Distance str=" << strP1.distance(strP2) << nl;

	std::cout << nl;
}

// template function
template <typename T>
T mini(T a, T b)
{
	return (a < b) ? a : b;
}

/*
template <typename T, typename U>
T mini(T const& a, U const& b)
{
//	return (a < static_cast<T>(b)) ? a : static_cast<T>(b);
	return (a < b) ? a : b;
}
*/

// non-type template parameter
template <typename T, int U>
T& get(T* array)
{
	return *(array + U);
}

int main(int argc, char* argv[])
{
// template function use
	const int a = 1, b = 2 ;
	std::cout << "ints " << mini(a, b) << nl;

	size_t sa = 2, sb = 1;
	std::cout << "size_t " << mini(sa, sb) << nl;

	float fa = 1.5, fb = -1.5;
	std::cout << "float " << mini(fa, fb) << nl;

	std::string ra("the quick"), rb("lorem ipsum");
	std::cout << "std::string " << mini(ra, rb) << nl;

	std::cout << "mixed " << mini<float>(a, fb) << nl;
	std::cout << "mixed " << mini<int>(a, sb) << nl;

// non-type template parameter use
	int intA[] = {0, 1, 2, 3, 4, 5, 6};
	float floatA[15] = {12};

	std::cout << "int array[5] " << get<int,5>(intA) << nl;
	std::cout << "int array[a] " << get<int,a>(intA) << nl;
	std::cout << "float array[8] " << get<float,0>(floatA) << nl;

	Points();

	return 0;
}
