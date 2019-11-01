#include "Author.h"
#include <fstream>

Author::Author(std::string a_author)
:m_author(a_author)
{
}

std::string Author::getAuthor() const
{
	return m_author;
}

bool Author::operator<(Author const& a_author) const
{
	if (m_author.compare(a_author.getAuthor())<0)
	{
		return false;
	}
	return true;
}
