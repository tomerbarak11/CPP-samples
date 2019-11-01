#include "mu_test.h" 
#include "container_util.h"
#include <vector>
#include <time.h>

UNIT(first_unique_test_random)
	std::vector<int> v;
	srand(time(0));
	for(int i=0;i<10;i++)
	{
		int num=rand()%10;
		v.push_back(num);
		std::cout<<"i = "<<i<<"\n";
		std::cout<<"v[i] = "<<v[i]<<"\n";
		std::cout<<"\n";
	}
	firstUnique(v);
END_UNIT

UNIT(first_unique_test1)
	std::vector<int> v;
	v.push_back(1);
	v.push_back(1);
	v.push_back(2);
	ASSERT_EQUAL(*firstUnique(v),2);
	v.push_back(2);
	ASSERT_EQUAL(*firstUnique(v),0);
END_UNIT

UNIT(first_unique_test2)
	std::vector<int> v;
	v.push_back(2);
	v.push_back(1);
	ASSERT_EQUAL(*firstUnique(v),2);
END_UNIT
/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/
UNIT(first_unique_test_random_C)
	std::vector<int> v;
	srand(time(0));
	for(int i=0;i<10;i++)
	{
		int num=rand()%10;
		v.push_back(num);
		std::cout<<"i = "<<i<<"\n";
		std::cout<<"v[i] = "<<v[i]<<"\n";
		std::cout<<"\n";
	}
	firstUniqueContainer(v);
END_UNIT

UNIT(first_unique_test1_C)
	std::vector<int> v;
	v.push_back(1);
	v.push_back(1);
	v.push_back(2);
	ASSERT_EQUAL(*firstUniqueContainer(v),2);
	v.push_back(2);
	ASSERT_EQUAL(*firstUnique(v),0);
END_UNIT

UNIT(first_unique_test2_C)
	std::vector<int> v;
	v.push_back(2);
	v.push_back(1);
	ASSERT_EQUAL(*firstUniqueContainer(v),2);
END_UNIT
/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/
UNIT(first_duplicate_test_random)
	std::vector<int> v;
	srand(time(0));
	for(int i=0;i<10;i++)
	{
		int num=rand()%10;
		v.push_back(num);
		std::cout<<"i = "<<i<<"\n";
		std::cout<<"v[i] = "<<v[i]<<"\n";
		std::cout<<"\n";
	}
	firstDuplicate(v);
END_UNIT

UNIT(first_duplicate_test1)
	std::vector<int> v;
	v.push_back(1);
	v.push_back(1);
	v.push_back(2);
	ASSERT_EQUAL(*firstDuplicate(v),1);
	v.push_back(2);
	ASSERT_EQUAL(*firstDuplicate(v),1);
	v.push_back(2);
	ASSERT_EQUAL(*firstDuplicate(v),1);

END_UNIT

UNIT(first_duplicate_test2)
	std::vector<int> v;
	v.push_back(2);
	v.push_back(2);
	v.push_back(1);
	ASSERT_EQUAL(*firstDuplicate(v),2);
END_UNIT
/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/
UNIT(first_duplicate_test_random_C)
	std::vector<int> v;
	srand(time(0));
	for(int i=0;i<10;i++)
	{
		int num=rand()%10;
		v.push_back(num);
		std::cout<<"i = "<<i<<"\n";
		std::cout<<"v[i] = "<<v[i]<<"\n";
		std::cout<<"\n";
	}
	firstDuplicate(v);
END_UNIT

UNIT(first_duplicate_test1_C)
	std::vector<int> v;
	v.push_back(1);
	v.push_back(1);
	v.push_back(2);
	ASSERT_EQUAL(*firstDuplicateContainer(v),1);
	v.push_back(2);
	ASSERT_EQUAL(*firstDuplicateContainer(v),1);
	v.push_back(2);
	ASSERT_EQUAL(*firstDuplicateContainer(v),1);

END_UNIT

UNIT(first_duplicate_test2_C)
	std::vector<int> v;
	v.push_back(2);
	v.push_back(2);
	v.push_back(1);
	ASSERT_EQUAL(*firstDuplicateContainer(v),2);
END_UNIT

TEST_SUITE(Hash Tests)
	TEST(first_unique_test_random)
	TEST(first_unique_test1)
	TEST(first_unique_test2)

	TEST(first_unique_test_random_C)
	TEST(first_unique_test1_C)
	TEST(first_unique_test2_C)

	TEST(first_duplicate_test_random)
	TEST(first_duplicate_test1)
	TEST(first_duplicate_test2)
	
	TEST(first_duplicate_test_random_C)
	TEST(first_duplicate_test1_C)
	TEST(first_duplicate_test2_C)	
END_SUITE
