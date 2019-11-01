#include "Encoder.h"
#include <string>
#include <algorithm>
#include "Lowercase.h"

bool Lowercase::encode(std::string& a_str)
{
	std::transform(a_str.begin(), a_str.end(), a_str.begin(), ::tolower);
	return true;
}
