#include <iostream>
#include <vector>
#include <utility>
#include <stack>
void RNGT(std::vector<int>& a_vec);
void minus1(std::stack<std::pair<int,size_t> > temp,std::vector<int>& a_vec);
void checkPairsOfStack(std::stack<std::pair<int,size_t> >& a_temp,std::pair<int,size_t> a_pair, std::vector<int>& a_vec);
int main()
{
	std::vector<int> v;
	v.push_back(35);
	v.push_back(30);
	v.push_back(7);
	v.push_back(5);
	v.push_back(3);			
	v.push_back(4);
	v.push_back(12);
	v.push_back(42);
	std::cout<<"Before\n";
	for(size_t i=0;i<v.size();++i)
	{
		std::cout<<"Vector["<<i<<"]"<<" = "<<v[i]<<"\n";
	}
	std::cout<<"\n";
	std::cout<<"After\n";
	RNGT(v);
	for(size_t i=0;i<v.size();++i)
	{
		std::cout<<"Vector["<<i<<"]"<<" = "<<v[i]<<"\n";
	}
}

void RNGT(std::vector<int>& a_vec)
{
	std::stack<std::pair<int,size_t> >temp;
	size_t vectorSize=a_vec.size();
	for(size_t i = 0;i<vectorSize;++i)
	{
		checkPairsOfStack(temp,std::make_pair(a_vec[i],i),a_vec);
	}
	minus1(temp,a_vec);
}

void minus1(std::stack<std::pair<int,size_t> > a_temp,std::vector<int>& a_vec)
{
	while(!a_temp.empty())
	{
		std::pair<int,size_t> pop = a_temp.top();
		a_temp.pop();
		a_vec[pop.second] =-1;
	}
}

void checkPairsOfStack(std::stack<std::pair<int,size_t> >& a_temp,std::pair<int,size_t> a_pair, std::vector<int>& a_vec)
{
	if(a_temp.empty())
	{
		a_temp.push(a_pair);
	}
	else
	{
		std::pair<int,size_t> top=a_temp.top();
		if(top.first>=a_pair.first)
		{
			a_temp.push(a_pair);
			return;
		}
		while((!a_temp.empty())&&a_temp.top().first<=a_pair.first)
		{
			std::pair<int,size_t> pop = a_temp.top();
			a_temp.pop();
			a_vec[pop.second]=a_pair.first;	
		}
		a_temp.push(a_pair);
		return;
	}
	return;
}
