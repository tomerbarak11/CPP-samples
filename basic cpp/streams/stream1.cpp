#include <iostream>
#include <fstream>
#include <climits>

int main()
{
	bool ok=false;
	int val;
	do{
		ok=true;
		std::cout<<"Number ";
		std::cin>>val;
		if(!std::cin.good())
		{
			std::cout<<"Bad number"<<"\n";
			ok=false;
			std::cin.clear();
			std::cin.ignore(INT_MAX,'\n');
		}
	}while(!ok);
	std::cout<<"The number "<<val<<"\n";
}
