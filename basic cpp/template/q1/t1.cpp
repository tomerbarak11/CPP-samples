#include <iostream>

template <typename T>
T const& mini(T const& a, T const& b)
{
	return (a<b)? a:b;
}

template <typename T>
T const& get(T* arr, size_t i)
{
	return arr[i];
}

int main()
{
	int a=1,b=2;
	std::cout <<"int "<<mini(a,b)<<"\n";
	
	size_t c=3,d=4;
	std::cout <<"size_t "<<mini(c,d)<<"\n";
	
	float e=1.5,f=2.5;
	std::cout <<"float "<<mini(e,f)<<"\n";
	
	const char* s1="aa";
	const char* s2="bb";
	std::cout <<"string "<<mini(s1,s2)<<"\n";
	int intA[]={0,1,2,3,4,5,6};
	std::cout <<"string "<< get (intA,6) <<"\n";

	return 0;
}
