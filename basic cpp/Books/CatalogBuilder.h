#ifndef _CATALOGBUILDER_H_
#define _CATALOGBUILDER_H_

#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include "IParser.h"
#include "RecordFactory.h"
#include "Books.h"
#include "Record.h"

class CatalogBuilder
{
	public:
		CatalogBuilder(RecordFactory a_rf);
		void CatalogCreator(RecordFactory a_rf);

	private:
		RecordFactory m_rf;
		Books* m_books;
};

#endif
