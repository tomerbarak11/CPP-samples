#include "Authors.h"
#include "Author.h"
#include <fstream>
#include <set>

Author* Authors::insertAuthorPointer(std::string a_author)
{
	Author *ptr(0);
	Author auth(a_author);
	std::set<Author>::iterator it;
	std::pair<std::set<Author>::iterator,bool> ret;
	ret=m_authorsSet.insert(auth);
	it=ret.first;
	ptr=(Author*)&(it);
	return ptr;
}
