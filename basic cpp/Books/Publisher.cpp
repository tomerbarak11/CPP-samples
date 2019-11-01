#include "Publisher.h"
#include <fstream>

Publisher::Publisher(std::string a_publisher)
:m_publisher(a_publisher)
{
}

std::string Publisher::getPublisher() const
{
	return m_publisher;
}

bool Publisher::operator<(Publisher const& a_publisher) const
{
	if (m_publisher.compare(a_publisher.getPublisher())<0)
	{
		return false;
	}
	return true;
}
