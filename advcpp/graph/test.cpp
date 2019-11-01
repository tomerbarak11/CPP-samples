#include "mu_test.h"
#include "graph.h"
#include <cstring>
#include <fstream>
#include <iostream>

class City
{
public:
    City(std::string a_name);
	std::string getName() const;
    void printName() const;
	int operator==(City const& a_other) const;
	
private:
    std::string m_name;
};

City::City(std::string a_name)
: m_name(a_name)
{
}

std::string City::getName() const
{
	return m_name;
}

void City::printName() const
{
	std::cout<<m_name<<"\n";
}

int City::operator==(City const& a_other) const
{
	return m_name==a_other.getName();
}

UNIT(graph)
	Graph<City> g;

	std::string s1="Tel Aviv";
	City c1(s1);
	
	g.addIf(c1);

	std::string s2="Haifa";
	City c2(s2);
	g.addIf(c2);

	g.addIf(c1,c2,1);
	
	std::string s3="Jerusalem";
	City c3(s3);
	g.addIf(c3);

	g.addIf(c1,c3,2);

	std::string s4="Eilat";
	City c4(s4);
	g.addIf(c4);
	
	g.addIf(c1,c4,3);
	g.addIf(c3,c4,4);

	ASSERT_THAT(g.isConnectedBFS(c1,c2));
	ASSERT_THAT(g.isConnectedBFS(c1,c3));
	ASSERT_THAT(g.isConnectedBFS(c1,c4));
	ASSERT_THAT(g.isConnectedBFS(c3,c4));


	//Graph<City> KruskalGraph=g.KruskalCreate(g);
	//int x =g.KruskalCreate(g);

END_UNIT

TEST_SUITE(Hash Tests)
	TEST(graph)
END_SUITE
