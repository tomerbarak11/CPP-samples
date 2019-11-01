#include "ParserBook.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

std::vector<std::string> ParserBook::parse(std::string a_string)
{
	std::vector<std::string> res;
	std::string member;
	std::istringstream istr(a_string);
	while(getline(istr,member,'|'))
	{
		std::cout<<member.data()<<"\n";
		res.push_back(member);
	}
	std::cout<<res[0];
	std::cout<<"\n";
	return res;
}
