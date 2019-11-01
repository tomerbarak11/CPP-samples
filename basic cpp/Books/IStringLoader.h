#ifndef _ISTRINGLOADER_H_
#define _ISTRINGLOADER_H_

#include <fstream>

class IStringLoader
{
	public:
		virtual std::string load()=0;
};

#endif
