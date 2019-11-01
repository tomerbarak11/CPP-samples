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


void TraceVectorInts(const char* a_header, vector<int> const& a_vi)
{
	TRACER << "Vector<int> " << a_header << "={";
	for (size_t i = 0; i < a_vi.size(); ++i)
	{
		TRACER << a_vi[i] << ' ';
	}
	TRACER << '}' << nl;
}

void FillVectorInts(vector<int>& a_vi, size_t a_size)
{
	// ensure enough space with single alloc works only with []
	//~ a_vi.reserve(a_size);

	for (size_t i = 0; i < a_size; ++i)
	{
		a_vi.push_back(i);
		//~ a_vi[i] = i;
	}

}

UNIT(vector_ints)
	vector<int>  vi;

	FillVectorInts(vi, TEST_SIZE);
	//~ TraceVectorInts("Fill", vi);
	ASSERT_EQUAL(vi.size(), TEST_SIZE);

	for (int i = 0; i < TEST_SIZE; ++i)
	{
		ASSERT_EQUAL(vi[i], i);
	}

END_UNIT

void CopyVectorSquares(vector<int> const& a_from, vector<int>& a_to)
{
	vector<int>::const_iterator bf = a_from.begin();
	vector<int>::const_iterator ef = a_from.end();

	for (; bf != ef; ++bf)
	{
//		a_to.push_back( (*bf) * (*bf));
		int val = *bf;
		a_to.push_back(val * val);
	}
}

UNIT(vector_squared_ints)
	vector<int> vi;
	vector<int> vs;

	FillVectorInts(vi, TEST_SIZE);
	CopyVectorSquares(vi, vs);

	ASSERT_EQUAL(vs.size(), TEST_SIZE);

	vector<int>::iterator bs = vs.begin();
	vector<int>::iterator es = vs.end();

	for (int val = 0; bs != es; ++val, ++bs)
	{
		ASSERT_EQUAL(*bs, val*val);
	}

END_UNIT

bool predicateCheck(int a_x)
{
	return (0 == a_x % 5) || (0 == a_x % 3);
}

void SelectVector(vector<int> const& a_from, vector<int>& a_to, bool (*a_pPf)(int))
{
	vector<int>::const_iterator bf = a_from.begin();
	vector<int>::const_iterator ef = a_from.end();

	for (; bf != ef; ++bf)
	{
		if (a_pPf(*bf)) {
			a_to.push_back(*bf);
		}
	}
}


UNIT(vector_predicate)
	vector<int> vi;
	FillVectorInts(vi, TEST_SIZE);
	ASSERT_EQUAL(vi.size(), TEST_SIZE);

	vector<int> vp;
	SelectVector(vi, vp, predicateCheck);

	ASSERT_EQUAL(vp.size(), PREDICATE_SIZE);

	vector<int>::iterator bp = vp.begin();
	vector<int>::iterator ep = vp.end();
	while (bp != ep)
	{
		ASSERT_THAT(predicateCheck(*bp++));
	}

END_UNIT

template <typename C, typename V>
class PredicateCopy {
	typedef bool (*PredicateCheck)(V a_val);
public:
	PredicateCopy(C& a_target, PredicateCheck a_pPCf)
	: m_target(a_target)
	, m_check(a_pPCf)
	{}
	void operator()(V const& a_val) const {
		if (m_check(a_val)) {
			TRACER << a_val << ' ';
			m_target.push_back(a_val);
		}
	}
private:
	C&				m_target;
	PredicateCheck	m_check;
};

UNIT(vector_copy)
	vector<int> vi;
	FillVectorInts(vi, TEST_SIZE);
	ASSERT_EQUAL(vi.size(), TEST_SIZE);

	vector<int> vp;
	PredicateCopy<vector<int>, int> pcf(vp, predicateCheck);

	TRACER << "Vector copy for_each =";
	std::for_each(vi.begin(), vi.end(), pcf);
	TRACER << nl;

	ASSERT_EQUAL(vp.size(), PREDICATE_SIZE);

	vector<int>::iterator bp = vp.begin();
	vector<int>::iterator ep = vp.end();
	while (bp != ep)
	{
		ASSERT_THAT(predicateCheck(*bp++));
	}

END_UNIT

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

	TEST(vector_ints)
	TEST(vector_squared_ints)
	TEST(vector_predicate)
	TEST(vector_copy)

	TEST(map_demo)

END_SUITE
