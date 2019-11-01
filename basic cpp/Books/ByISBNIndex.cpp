#include "ByISBNIndex.h"
#include "Book.h"
#include <map>
#include <vector>
#include <fstream>
#include <iostream>

void ByISBNIndex::addBook(Book* a_book)
{	
	std::vector<Book*> vec;
	vec.push_back(a_book);
	m_ISBNMap.insert(std::pair<std::string,std::vector<Book*> >(a_book->getISBN(),vec));
}

std::vector<Book*> ByISBNIndex::findBookByISBN(std::string a_ISBN)
{
	//return (m_ISBNMap[a_ISBN[.find(a_ISBN)->second);
	return m_ISBNMap[a_ISBN];
}

