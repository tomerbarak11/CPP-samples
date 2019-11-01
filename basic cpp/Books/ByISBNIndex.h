#ifndef _BYISBNINDEX_H_
#define _BYISBNINDEX_H_
#include "Book.h"
#include <fstream>
#include <map>
#include <vector>
#include "IQuery.h"

class ByISBNIndex
{
	public:
		void addBook(Book* a_book);
		std::vector<Book*> findBookByISBN(std::string a_ISBN);
	private:
		std::map <std::string,std::vector<Book*> > m_ISBNMap;
};

#endif
