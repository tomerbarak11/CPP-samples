#ifndef _IQUERY_H_
#define _IQUERY_H_
#include <vector>
#include <fstream>
#include "Book.h"

class IQuery
{
	public:
		virtual std::vector<Book*> findBookByISBN(std::string a_ISBN)=0;
	private:
};

#endif
