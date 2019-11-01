#ifndef _AUTHORS_H
#define _AUTHORS_H
#include <fstream>
#include <set>
#include "Author.h"

class Authors
{
	public:
		Author* insertAuthorPointer(std::string a_author);
	private:
		std::set <Author> m_authorsSet;
};

#endif
