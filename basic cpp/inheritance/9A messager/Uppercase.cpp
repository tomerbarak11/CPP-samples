#include "Encoder.h"
#include <string>
#include "Uppercase.h"
#include <algorithm>

bool Uppercase::encode(std::string& a_str)
{
	std::transform(a_str.begin(), a_str.end(), a_str.begin(), ::toupper);
	return true;
}
