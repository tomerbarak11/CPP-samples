#include "Messager.h"
#include <string>

Messager::Messager(std::string a_text)
:m_text(a_text)
{
}

bool Messager::transform(Encoder* a_encoder)
{
	if(0==a_encoder)
	{
		return false;
	}
	a_encoder->encode(m_text);
	return true;
}

const char* Messager::get()
{
	return m_text.data();
}

const void Messager::set(std::string a_str)
{
	m_text=a_str;
}
