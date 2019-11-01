#include "mu_test.h"
#include "StreamStringLoader.h"
#include "IParser.h"
#include "RecordParser.h"
#include "RecordFactory.h"
#include "CatalogBuilder.h"
#include "Book.h"
#include "ByISBNIndex.h"

#include <iostream>
#include <vector>

UNIT(load_test)
	const char* fileName="books-tiny.txt";

	std::filebuf fb;
	std::istream is(&fb);	
	if (!fb.open (fileName,std::ios::in))
	{
		std::cout<<"open fail\n";
		while (is)
		{
			std::cout << char(is.get());
		}
		fb.close();
	}
	
	StreamStringLoader ssl(is);
	RecordParser rp('|');
	RecordFactory rf(&ssl,&rp);
	//CatalogBuilder cb(rf);
END_UNIT

UNIT(book_test)
	Book b1;
	ByISBNIndex bi;
	std::string ISBN1="1";
	std::string title1="Classical Mythology";
	std::string author1="Mark P. O. Morford";
	std::string year1="2002";
	std::string publisher1="Oxford University Press";
	b1.setISBN(ISBN1);
	bi.addBook(&b1);
	
	Book b2;
	std::string ISBN2="2";
	std::string title2="Submarine : A Guided Tour Inside a Nuclear Warship";
	std::string author2="Tom Clancy";
	std::string year2="2002";
	std::string publisher2="Berkley Publishing Group";
	b1.setISBN(ISBN2);
	bi.addBook(&b2);
		
	std::vector<Book*> vb;
	std::cout<<vb.size();
	vb=bi.findBookByISBN("1");
	std::cout<<vb.size();

	
END_UNIT

TEST_SUITE(Text Manipulator)
	TEST(load_test)
	TEST(book_test)
END_SUITE
