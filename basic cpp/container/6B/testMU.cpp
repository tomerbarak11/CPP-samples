#include "mu_test.h"

#include <cstddef>
#include <algorithm>
#include <vector>
#include "map.h"
UNIT(test_ctor)

	Map<std::string, int> myMap;
	ASSERT_EQUAL_INT (0,myMap.size() );
	
	ASSERT_EQUAL_INT (0,myMap.size() );
	ASSERT_THAT (myMap.isEmpty());
	
		
END_UNIT



UNIT(test_insert)
	
	Map<std::string, int> myMap;
	
	std::string str1 = "apple";
	std::string str2 = "box";
	int num1 = 5;
	int num2 = 10;
	
	ASSERT_THAT (myMap.myInsert (str1,num1)==true);
	ASSERT_THAT (!myMap.isEmpty());
	
	ASSERT_THAT (myMap.myInsert (str1,num1)==false);
	ASSERT_THAT (myMap.myInsert (str2,num1)==false);
	ASSERT_THAT (myMap.myInsert (str1,num2)==false);
	ASSERT_EQUAL_INT (1,myMap.size() );	
	
	ASSERT_THAT (myMap.myInsert (str2,num2)==true);
	ASSERT_EQUAL_INT (2,myMap.size() );	
	
	
END_UNIT




//	bool remove(K a_key);
UNIT(test_remove)
	
	Map<std::string, int> myMap;
	
	std::string str1 = "apple";
	std::string str2 = "box";
	int num1 = 5;
	int num2 = 10;
	
	ASSERT_THAT (myMap.myRemove (str1)==false);
	myMap.myInsert (str1,num1);
	ASSERT_EQUAL_INT (1,myMap.size() );	
 	ASSERT_THAT (myMap.myRemove (str2)==false);
	myMap.myInsert (str2,num2);
	ASSERT_THAT(myMap.atKey(str1,num1)==true) ;
 	ASSERT_THAT (myMap.myRemove (str1)==true);
	ASSERT_EQUAL_INT (1,myMap.size() );	
	ASSERT_THAT(myMap.atKey(str1,num1)==false) ;
 	ASSERT_THAT (myMap.myRemove (str2)==true);
	ASSERT_THAT (myMap.isEmpty());
	ASSERT_EQUAL_INT (0,myMap.size() );	
		
END_UNIT





UNIT(test_atKey)
	
	Map<std::string, int> myMap;

	std::string str1 = "apple";
	std::string str2 = "box";
	std::string str3 = "cake";
	int num1 = 5;
	int num2 = 10;
	
	int returnNum = 0;
	
	myMap.myInsert (str1,num1);
	myMap.myInsert (str2,num2);
	
	ASSERT_THAT(myMap.atKey(str1,returnNum)) ;
	ASSERT_EQUAL(returnNum,5 );
	ASSERT_THAT(myMap.atKey(str2,returnNum)) ;
	ASSERT_EQUAL(returnNum,10 );
	ASSERT_EQUAL_INT (myMap.size(),2 );
	
	ASSERT_THAT(myMap.atKey(str3,num2)==false) ;
	ASSERT_EQUAL(num2,10 );
	ASSERT_THAT (!myMap.isEmpty());
	
	
END_UNIT




//bool Map<K,V>:: atValue(K& a_key , V const& a_value) const
UNIT(test_atValue)
	
	Map<std::string, int> myMap;
	
	std::string str1 = "apple";
	std::string str2 = "box";
	std::string str3 = "cake";
	int num1 = 5;
	int num2 = 10;
	int num3 = 15;

	std::string returnStr ;
	
	myMap.myInsert (str1,num1);
	myMap.myInsert (str2,num2);
	
	ASSERT_THAT(myMap.atValue(num1,returnStr)) ;
	ASSERT_THAT(returnStr=="apple" );
	ASSERT_THAT(myMap.atValue(num2,returnStr)) ;
	ASSERT_THAT(returnStr=="box" );
	
	ASSERT_THAT(myMap.atValue(num3,returnStr)==false) ;
	ASSERT_EQUAL(returnStr,"box" );
	
	ASSERT_EQUAL_INT (myMap.size(),2 );
	ASSERT_THAT (!myMap.isEmpty());
	
	
END_UNIT



TEST_SUITE(Map Unit Test)

	TEST(test_ctor) 
	TEST(test_insert) 
	TEST(test_remove) 
	TEST(test_atKey) 
	TEST(test_atValue) 

		
END_SUITE
