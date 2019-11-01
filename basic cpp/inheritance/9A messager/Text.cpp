/**
 * @file	Text.cpp
 *
 * @brief	Day 9 Homework 9B - Text manipulator application
 * 		Test various encoders
 *
 * Copyright 2019 Alex Katz <alex.katz.pacific@gmail.com>
 * 		Inspired by MhZ (aka TryFinally)
 *
 */
#include "mu_test.h"

#include "Lowercase.h"
#include "Uppercase.h"
#include "Rot13.h"
#include "Messager.h"

const char nl = '\n';
const char* title = "The Quick Brown Fox Jumped Over The Lazy Dog";
const char* lower = "the quick brown fox jumped over the lazy dog";
const char* upper= "THE QUICK BROWN FOX JUMPED OVER THE LAZY DOG";

UNIT(lower_encoder)
	Messager msg(title);
	TRACER	<< "Lower" << nl
			<< "Before :=" << msg.get() << nl;

	Lowercase* le = new Lowercase();
	msg.transform(le);
	TRACER  << "After  :=" << msg.get() << nl;

	ASSERT_EQUAL_STR(msg.get(), lower);
	delete le;

END_UNIT

UNIT(upper_encoder)
	Messager msg(title);
	TRACER	<< "Upper" << nl
			<< "Before :=" << msg.get() << nl;

	Uppercase ue;
	msg.transform(&ue);
	TRACER  << "After  :=" << msg.get() << nl;

	ASSERT_EQUAL_STR(msg.get(), upper);

END_UNIT

/*
UNIT(rot13_encoder)
	Messager msg(title);
	TRACER	<< "Rot13" << nl
			<< "Before :=" << msg << nl;

	Rot13* re = new Rot13Encoder();
	msg.transform(re);
	TRACER  << "After 1:=" << msg << nl;

	// two rot13 should decode back
	msg.transform(re);
	TRACER  << "After 2:=" << msg << nl;

	ASSERT_EQUAL_STR(msg.get(), title);

	delete re;
END_UNIT
*/

UNIT(two_encoders)
	Messager msg(title);
	TRACER	<< "Rot13" << nl
			<< "Before :=" << msg.get() << nl;
/*
	Rot13 re;
	msg.transform(&re);
	TRACER  << "After R:=" << msg.get() << nl;
*/
	Lowercase le;
	msg.transform(&le);
	TRACER  << "After L:=" << msg.get() << nl;
/*
	msg.transform(&re);
	TRACER  << "After R:=" << msg.get() << nl;
	ASSERT_EQUAL_STR(msg.get(), lower);
*/
END_UNIT


TEST_SUITE(Text Manipulator)

	TEST(lower_encoder)
	TEST(upper_encoder)

	//TEST(rot13_encoder)

	TEST(two_encoders)

END_SUITE
