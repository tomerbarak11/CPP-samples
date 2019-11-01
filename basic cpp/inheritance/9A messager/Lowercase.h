#ifndef _LOWERCASE_H_
#define _LOWERCASE_H_
#include <string>
#include "Encoder.h"

class Lowercase: public Encoder
{
public:
	virtual bool encode(std::string& a_str);
};
#endif
