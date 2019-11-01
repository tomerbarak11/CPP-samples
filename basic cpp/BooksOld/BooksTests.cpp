#include "mu_test.h"
#include "Loader.h"

UNIT(load_test)
	const char* fileName="books-tiny.txt";
	Loader l;
	l.load(fileName);
END_UNIT

TEST_SUITE(Text Manipulator)
	TEST(load_test)
END_SUITE
