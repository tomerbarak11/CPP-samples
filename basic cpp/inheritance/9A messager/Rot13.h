#ifndef _ROT13_H_
#define _ROT13_H_
#include <string>
#include "Encoder.h"

class Rot13: public Encoder
{
public:
	bool row13maker(std::string& a_str);
};
#endif
