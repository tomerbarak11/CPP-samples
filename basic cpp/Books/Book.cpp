#include "Book.h"
#include "Author.h"
#include "Publisher.h"
#include <fstream>
#include <iostream>

std::string Book::getISBN()
{
	return m_ISBN;
}


void Book::setISBN(std::string a_ISBN)
{
	m_ISBN=a_ISBN;
}

void Book::setTitle(std::string a_title)
{
	m_title=a_title;
}

void Book::setAuthor(Author* a_author)
{
	m_author=a_author;
}

void Book::setPublisher(Publisher* a_publisher)
{
	m_publisher=a_publisher;
}

void Book::setYear(std::string a_year)
{
	m_year=a_year;
}
