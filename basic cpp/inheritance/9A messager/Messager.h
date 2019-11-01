#ifndef _MESSAGER_H_
#define _MESSAGER_H_
#include<bits/stdc++.h> 
#include "Encoder.h"
#include <string>

class Messager
{
public:
	Messager(std::string a_text);
	const void set(std::string a_str);
	const char* get();
	bool transform(Encoder* a_pEncoder);

private:
	std::string m_text;

};


#endif
