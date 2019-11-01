#ifndef _STREAMSTRINGLOADER_H_
#define _STREAMSTRINGLOADER_H_

#include "IStringLoader.h"
#include <iostream>
#include <sstream>
#include <fstream>

class StreamStringLoader:public IStringLoader
{
	public:
		StreamStringLoader(std::istream& a_filePointer);
		std::string load();
	private:
		std::istream& m_filePointer;
};

#endif
