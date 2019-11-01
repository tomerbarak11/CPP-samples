#include <iostream>
#include "mu_test.h"
#include <cstddef>
#include <vector>

using std::vector;
const int TEST_SIZE=10;

void TraceVectorInts(const char* a_header,vector<int> const& a_vi)
{
	TRACER<<"Vector<int> "<<a_header<<"={";
	for(size_t i=0;i<a_vi.size();++i)
	{
		TRACER <<a_vi[i]<<" ";
	}
	TRACER<< "}" <<"\n";
}

void FillVectorInts(vector<int> & a_vi,size_t a_n)
{
	//a_vi.resize(a_n);
	for(size_t i=0;i<a_n;++i)
	{
		a_vi.push_back(i);
	}
}

UNIT(vector_ints)
	vector<int> vi;
	
	FillVectorInts(vi,TEST_SIZE);
	TraceVectorInts("Fill",vi);
	ASSERT_EQUAL(vi.size(),TEST_SIZE);
	
	for(int i=0;i<TEST_SIZE;i++)
	{
		ASSERT_EQUAL(vi[i],i);
	}
END_UNIT



void CopyVectorSquares(vector<int> & a_from,vector<int> & a_to)
{
	vector<int>::const_iterator fi = a_from.begin();
	vector<int>::const_iterator fe = a_from.end();
	
	//vector<int>::const_iterator ti = a_from.begin();
	//vector<int>::const_iterator te = a_from.end();
		
	for(;fi!=fe;++fi)
	{
		int v=*fi;
		a_to.push_back(v*v);
	}
}

UNIT(vector_ints_squared)
	vector<int> vi;
	vector<int> vs;

	FillVectorInts(vi,TEST_SIZE);
	CopyVectorSquares(vi,vs);
	TraceVectorInts("Squares",vs);
	
END_UNIT

TEST_SUITE(Stack [fixed size] of Rationals)
	TEST(vector_ints)
	TEST(vector_ints_squared)

END_SUITE
