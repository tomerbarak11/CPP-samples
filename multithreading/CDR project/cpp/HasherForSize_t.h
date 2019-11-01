#ifndef HASHERFORSIZET_H
#define HASHERFORSIZET_H
#include <cstddef>
class HasherForSize_t
{
public:
	size_t operator()(int a_key)
	{
		return a_key;
	}
};
#endif