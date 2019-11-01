#ifndef _IPARSER_H_
#define _IPARSER_H_

#include <vector>
#include <fstream>

class IParser
{
	public:
		virtual std::vector<std::string> parse(std::string a_string)=0;
};

#endif
