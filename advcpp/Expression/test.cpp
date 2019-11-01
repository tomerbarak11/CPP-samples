#include "mu_test.h"
#include <cstring>
#include <fstream>
#include <iostream>
#include "Number.h"
#include "BiFunc.h"
#include <iostream>
#include <fstream>
#include <stack>
#include <stdlib.h>     /* strtod */
#include <sstream>
#include <string>     // std::string, std::stod
UNIT(Expression_test)
	Number* l=new Number(52);
	Number* r=new Number(5);
	Expression* e1=new Add(l,r);
	Expression* e2=new Sub(l,r);
	Expression* e3=new Mul(l,r);
	Expression* e4=new Div(l,r);

	Expression* e5=new Mul(new Sub(new Number(42),new Number(5)),new Add(new Number(7),new Number(3)));

	ASSERT_THAT(e1->value()==57);
	ASSERT_THAT(e2->value()==47);
	ASSERT_THAT(e3->value()==260);
	ASSERT_THAT(e4->value()==10.4);

	ASSERT_THAT(e5->value()==370);
	delete l;
	delete r;
	delete e1;
	delete e2;
	delete e3;
	delete e4;
	delete e5;


END_UNIT



UNIT(Expression_file_test)

	std:: ifstream f("Equation.txt");
	std:: string str;
	if(f)
	{
		std::  ostringstream ss;
		ss << f.rdbuf();
		str = ss.str();
	}

	std:: ifstream f2("Equation.txt");

	std::cout<<str;
	std::stack<std::string> s;
	for (size_t i = 0; i <str.size(); ++i)
	{
		std::string s1;
		std::string s2;
		std::string s3;

		getline (f2, s1,' ');
		getline (f2, s2,' ');
		getline (f2, s3,' ');


	std::istringstream iss1 (s1);
	double d1;
	iss1 >> d1;
	std::cout<<"d1 = " <<d1<<"\n";


    //strcpy(char_array, s1); 

	std::istringstream iss2 (s2);
	double d2;
	iss2 >> d2;
	std::cout<<"d2 = " <<d2<<"\n";

	std::istringstream iss3 (s3);
	char d3;
	iss3 >> d3;
	std::cout<<"d3 = " <<d3<<"\n";	

/*
		std::cout<<s1;
		std::cout<<" ";
		std::cout<<s2;
		std::cout<<" ";
		std::cout<<s3;	
		std::cout<<"\n";
*/	

	std::cout<<"\n";	

	}

END_UNIT

TEST_SUITE(Expression)
	TEST(Expression_test)
	TEST(Expression_file_test)

END_SUITE
