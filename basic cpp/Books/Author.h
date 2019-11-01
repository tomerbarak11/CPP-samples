#ifndef _AUTHOR_H
#define _AUTHOR_H
#include <fstream>

class Author
{
	public:
		Author(std::string a_author);
		std::string getAuthor() const;
		bool operator<(Author const& a_author) const;

	private:
		std::string m_author;
};

#endif
