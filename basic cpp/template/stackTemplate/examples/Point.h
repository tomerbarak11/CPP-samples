#ifndef POINT_H
#define POINT_H
/**
 * @file	Point.h
 *
 * Copyright 2019 Alex-the-Teacher <alex.katz.pacific@gmail.com>
 * Inspired by MhZ (a.k.a. TryFinally)

 * @brief	Day 5 - Templates: Class Demo
 *
 *		Demonstrate definitions and use of class template.
 * 	This file define a Point (two coordinates: x & y) of some type T
 *
 *	Operations:
 * 		move (dx, dy)	move a point by a specified
 * 		move (d)		dx = dx = d
 *		distance(Point)	calculate distance to another point
 *
 * 	@warning	Class T has to support arithmetic operations +,-,*,/
 *
 */

#include <cmath>
#include <iostream>

template <typename T>
class Point
{
public:
	Point(T const&, T const&);

	void move(T const&);
	void move(T const&, T const&);

	T distance(Point const&) const;

	void print(std::ostream& = std::cout) const;

private:
	T	x;
	T	y;
};

template <typename T>
Point<T>::Point(T const& a_x, T const& a_y)
: x(a_x)
, y(a_y)
{}

template <typename T>
void Point<T>::move(T const& d)
{
	x += d;
	y += d;
}

template <typename T>
void Point<T>::move(T const& dx, T const& dy)
{
	x += dx;
	y += dy;
}

template <typename T>
T Point<T>::distance(Point const& a_o) const
{
	return std::sqrt((x - a_o.x) * (x - a_o.x) + (y - a_o.y) * (y - a_o.y) ) ;
}

template <typename T>
void Point<T>::print(std::ostream& a_os) const
{
	a_os << '{' << x << ',' << y << '}';
}

template <typename T>
std::ostream& operator<<(std::ostream& a_os, Point<T> a_p)
{
	a_p.print(a_os);
	return a_os;
}

#endif // POINT_H
