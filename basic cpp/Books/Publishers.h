#ifndef _PUBLISHERS_H
#define _PUBLISHERS_H
#include <fstream>
#include <set>
#include "Publisher.h"

class Publishers
{
	public:
		Publisher* insertPublisherPointer(std::string a_publisher);
	private:
		std::set <Publisher> m_publishersSet;
};

#endif
