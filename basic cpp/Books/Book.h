#ifndef _BOOK_H_
#define _BOOK_H_
#include <fstream>
#include "Author.h"
#include "Publisher.h"
#include "Publishers.h"

class Book
{
	public:
		friend class BookFactor;
		std::string getISBN();
		
		void setISBN(std::string a_ISBN);
		void setTitle(std::string a_title);
		void setAuthor(Author* a_Author);
		void setPublisher(Publisher* a_Publisher);
		void setYear(std::string a_year);

	private:
		std::string m_ISBN;
		std::string m_title;
		std::string m_year;
		Author* m_author;
		Publisher* m_publisher;
};

#endif
