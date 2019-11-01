#include "mu_test.h"

#include <cstddef>
#include <algorithm>
#include <vector>
#include <map>

const char nl = '\n';
// Test and Predicate sizes are coupled
const int TEST_SIZE = 100;
const int PREDICATE_SIZE = 47;
const int TBR = TEST_SIZE - PREDICATE_SIZE;

using std::vector;

// Map
UNIT(map_demo)
	std::string names[] = {"John", "Jack", "Angela", "Donald", "Beni", "Bibi"};
	int grades[] = {75, 58, 95, 20, 30, 36};
	std::map<std::string, int> mg;

	for (size_t i = 0; i < sizeof(grades)/sizeof (*grades); ++i)
	{
		// op[] does acces by key, and creates a new entry implicitly
		mg[names[i]] = grades[i];
	}

	std::map<std::string, int>::const_iterator bm = mg.begin();
	std::map<std::string, int>::const_iterator em = mg.end();

	std::cout << ">>>Map\n";
	while (bm != em)
	{
		std::cout << '{' << bm->first << ',' << bm->second << "}\n";
		++bm;
	}

	std::cout << "Donald's grade is " << mg["Donald"] << nl;

END_UNIT



TEST_SUITE(In-class example of STL containers)

	TEST(map_demo)

END_SUITE
