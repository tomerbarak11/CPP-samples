#include "mu_test.h" 
#include "hash_table.h"

class HasherForInt
{
public:
	size_t operator()(int a_key)
	{
		return a_key;
	}
};

UNIT(crt_test)
	HashTable<int,int,HasherForInt> hashTable = HashTable<int,int,HasherForInt> (16);
	ASSERT_THAT (0 == hashTable.size());
	ASSERT_THAT (17 == hashTable.capacity());
END_UNIT

UNIT(non_find_in_empty_list_test)
	HashTable<int,int,HasherForInt> hashTable = HashTable<int,int,HasherForInt> (17);
	int res=0;
	int num = 42;
	ASSERT_THAT (false == hashTable.find(num, res));
END_UNIT

UNIT(find_in_none_empty_list_when_exist_test)
	HashTable<int,int,HasherForInt> hashTable = HashTable<int,int,HasherForInt>();
	int ret=100;
	int key = 42;
	int val = 24;
	hashTable.insert (key,val);
	ASSERT_THAT (hashTable.find(key, ret));
	ASSERT_EQUAL_INT (ret , val);	
END_UNIT

UNIT(find_in_none_empty_list_when_doesnt_exist_test)
	HashTable<int,int,HasherForInt> hashTable = HashTable<int,int,HasherForInt>();
	int ret=0;
	int key =  88;
	int val =  99;
	int toFind =100;
	hashTable.insert (key,val);
	ASSERT_THAT (false == hashTable.find(toFind, ret));
END_UNIT

UNIT(remove_test)
	HashTable<int,int,HasherForInt> hashTable = HashTable<int,int,HasherForInt>();
	
	int ret=0;
	int key =  88;
	int val =  99;
	hashTable.insert (key,val);
	ASSERT_THAT (true == hashTable.remove(key, ret));
	ASSERT_THAT (false == hashTable.remove(key+1, ret));

END_UNIT

UNIT(factor)
	HashTable<int,int,HasherForInt> hashTable = HashTable<int,int,HasherForInt>();
	for(size_t i=0;i<997;i++)
	{
		hashTable.insert(i,i);
	}
END_UNIT

UNIT(contains)
	HashTable<int,int,HasherForInt> hashTable = HashTable<int,int,HasherForInt>();
	for(size_t i=0;i<900;i++)
	{
		hashTable.insert(i,i);
	}
	int k42=42;
	ASSERT_THAT(hashTable.contains(k42));

	ASSERT_THAT(!hashTable.contains(901));

END_UNIT

TEST_SUITE(Hash Tests)
	TEST(crt_test) 
	TEST(non_find_in_empty_list_test)
	TEST(find_in_none_empty_list_when_exist_test)
	TEST(find_in_none_empty_list_when_doesnt_exist_test)
	TEST(remove_test)
	TEST(factor)
	TEST(contains)	
END_SUITE
