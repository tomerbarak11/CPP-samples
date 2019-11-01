#include "BookFactor.h"
#include "Book.h"
#include "Record.h"
#include "Author.h"
#include "Authors.h"

BookFactor::BookFactor()
{
}

Book* BookFactor::CreateBook(const Record a_record)
{
	Book* b=new Book();
	b->setISBN(a_record[0]);
	b->setTitle(a_record[1]);
		
	Author* ap;
	ap=m_authors->insertAuthorPointer(a_record[2]);
	b->setAuthor(ap);

	Publisher* pp=0;
	pp=m_publishers->insertPublisherPointer(a_record[3]);
	b->setPublisher(pp);

	return b;
}
