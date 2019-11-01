#ifndef _UPPERCASE_H_
#define _UPPERCASE_H_
#include <string>
#include "Encoder.h"

class Uppercase: public Encoder
{
public:
	virtual bool encode(std::string& a_str);
};



#endif
