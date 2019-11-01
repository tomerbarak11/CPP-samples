#include <cstdio>
#include <iostream>
int main(int argc,char *argv[])
{
	int i;
	std::cout << "hello world"<<'\n';
	for(i=0;i<argc;i++)
	{
		std::cout << "argv["<<i<<"]"<<"="<<argv[i]<<"\n";
	}
}
