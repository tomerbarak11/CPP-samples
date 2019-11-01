#ifndef _PUBLISHER_H
#define _PUBLISHER_H
#include <fstream>

class Publisher
{
	public:
		Publisher(std::string a_publisher);
		std::string getPublisher() const;
		bool operator<(Publisher const& a_author) const;
	private:
		std::string m_publisher;
};

#endif
