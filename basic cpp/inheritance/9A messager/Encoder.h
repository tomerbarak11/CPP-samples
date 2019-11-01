#ifndef _ENCODER_H_
#define _ENCODER_H_
#include <string> 

class Encoder
{
public:
	virtual ~Encoder(){}
	virtual bool encode(std::string& m_text) =0;
};


#endif
