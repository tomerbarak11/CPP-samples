#include "Datastore.h"
#include <string>

class dsFunction
{
public:
	dsFunction(Datastore a_what)
	: m_ds(a_what)
	{}

	void operator()(std::string a_ISBN,std::string a_author,std::string a_publisher,int a_year)
	{
		//m_ds.newBook(a_ISBN,a_author,a_publisher,a_year);
	}

private:
	Datastore m_ds;
};

