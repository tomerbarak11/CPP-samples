#ifndef _RECORDPARSER_H_
#define _RECORDPARSER_H_

#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include "IParser.h"

class RecordParser: public IParser
{
	public:
		RecordParser(char a_char);
		std::vector<std::string> parse(std::string a_string);

	private:
		char m_delim;
};

#endif
