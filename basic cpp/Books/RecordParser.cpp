#include "RecordParser.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

RecordParser::RecordParser(char a_char)
:m_delim(a_char)
{
}

std::vector<std::string> RecordParser::parse(std::string a_string)
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
