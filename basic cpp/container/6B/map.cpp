#include "mu_test.h"

#include <cstddef>
#include <algorithm>
#include <vector>
#include "map.h"
using std::vector;

const char nl = '\n';
// Test and Predicate sizes are coupled
const int TEST_SIZE = 100;
const int PREDICATE_SIZE = 47;
const int TBR = TEST_SIZE - PREDICATE_SIZE;

using std::vector;

// Map
UNIT(map_demo)
	Map <std::string,int> m;
	std::string names[] = {"John", "Jack", "Angela", "Donald", "Beni", "Bibi"};
	int grades[] = {75, 58, 95, 20, 30, 36};
		
	for (size_t i = 0; i < sizeof(grades)/sizeof (*grades); ++i)
	{
		//m.myInsert(names[i],grades[i]);
	}

END_UNIT

TEST_SUITE(In-class example of STL containers)

	TEST(map_demo)

END_SUITE
