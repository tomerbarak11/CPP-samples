#include "Publisher.h"
#include "Publishers.h"
#include <fstream>
#include <set>

Publisher* Publishers::insertPublisherPointer(std::string a_publisher)
{
	Publisher *ptr(0);
	Publisher pub(a_publisher);
	std::set<Publisher>::iterator it;
	std::pair<std::set<Publisher>::iterator,bool> ret;
	ret=m_publishersSet.insert(pub);
	it=ret.first;
	ptr=(Publisher*)&(it);
	return ptr;
}
