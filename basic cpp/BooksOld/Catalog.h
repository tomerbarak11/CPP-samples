#ifndef _CATALOG_H_
#define _CATALOG_H_

#include "Book.h"
#include "Author.h"
#include "Publisher.h"
#include "Loader.h"
#include <vector>
#include <map>
#include <fstream>

class Catalog
{
	public:
		Catalog(const char* a_fileName);
		
	private:
	
		Datastore m_ds;
		
		std::vector<Book> booksVector;
		std::vector<Author> authorVector;
		std::vector<Publisher> publisherVector;
		
		std::map<int,Book> mapISBN;
		std::map<std::string,std::vector<Book*> > mapTitle;
};

#endif
