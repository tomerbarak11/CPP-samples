#include "StreamStringLoader.h"
#include <iostream>
#include <sstream>
#include <fstream>

StreamStringLoader::StreamStringLoader(std::istream& a_filePointer)
:m_filePointer(a_filePointer)
{
}

std::string StreamStringLoader::load()
{
	return "fdfd";
}

