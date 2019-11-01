#include "Loader.h"
#include "ParserBook.h"
#include "Datastore.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

bool Loader::load(const char* a_fileName)
{
	std::string line;
	std::ifstream in(a_fileName);
	ParserBook pb;
	if(!in)
	{
		std::cout << "Cannot open input file.\n";
		return false;
	}
	std::vector<std::string> res;

	while(getline(in,line))
	{
		res=pb.parse(line);
		std::cout<<"\n";
	}
	Datastore ds.
	std::cout<<"\n";
	return true;
}
