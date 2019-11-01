#ifndef _BOOKFACTOR_H
#define _BOOKFACTOR_H
#include "CatalogBuilder.h"
#include "Record.h"
#include "Authors.h"
#include "Publishers.h"
#include "Book.h"

class BookFactor
{
	public:
		BookFactor();
		void setTitle();
		Book* CreateBook(const Record a_record);
		
	private:
		Record m_record;
		Authors* m_authors;
		Publishers* m_publishers;	
};

#endif
