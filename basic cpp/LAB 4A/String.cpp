#include <cstddef>
#include <iostream>
#include <cstring>
#include "String.h"
#include <cassert>
bool String::s_caseSensitivity=false;
size_t String::s_numberOfObjects=0;

String::String(const char* a_source)
{
	bool res = stringInit(a_source);
	s_numberOfObjects++;
	assert(res==true);
}

String::String(const String& a_source)
{
	bool res = stringInit(a_source.get());
	set(a_source.get());
	s_numberOfObjects++;
	assert(res==true);
}

String::~String()
{
	s_numberOfObjects--;
}

bool String::stringInit(const char* a_source)
{
	int len;
	if(0==a_source)
	{
		len=0;
	}
	else
	{
		len=strlen(a_source);
	}
	m_chars = new char[len+1];	
	if(!m_chars)
	{
		return false;
	}
	if(len!=0)
	{
		set(a_source);
	}

	return true;
}

String& String::operator=(const String& a_source)
{
	String* res=0;
	{
		set(a_source.get());
	}
	return *res;
}

size_t String::length() const
{
	size_t len=0;
	const char* p;
	p=get();
	while(*p)
	{
		len++;
		p++;
	}
	return len;
}

const char* String::get() const
{
	return m_chars;
}

void String::set(const char* a_source)
{
	if(strlen(a_source)>length())
	{
		delete [] m_chars;
		m_chars = new char[strlen(a_source)+1];
	}
	strcpy(m_chars,a_source);
}

void String::print(std::ostream& a_os) const
{
	a_os<<get();
}

bool String::isCaseSensitive()
{
	return s_caseSensitivity;
}

void String::setCaseSensitive(bool a_sensitive)
{
	s_caseSensitivity=a_sensitive;
}

size_t String::objectCount()
{
	return String::s_numberOfObjects;
}

int compare(const String& a_first, const String& a_second)
{
	if(String::isCaseSensitive()==true)
	{
		if(strcmp(a_first.get(),a_second.get())==0)
		{
			return 0;
		}
		if(strcmp(a_first.get(),a_second.get())==-1)
		{
			return -1;
		}
		return 1;
	}	
	else
	{
		if(strcmp(a_first.get(),a_second.get())==0)
		{
			return 0;
		}
		if(strcmp(a_first.get(),a_second.get())==-1)
		{
			return -1;
		}
		return 1;
	}
	//const String* p1;
	//const String* p2;
	
	/*p1=a_first;
	p2=a_second;
	
	if(0==p1&&0==p2)
	{
		return 0;
	}
	else if(0==p1)
	{
		return -1;
	}
	
	else if(0==p2)
	{
		return 1;
	}
	
	while(p1&&p2)
	{
		if(*p1>*p2)
		{
			return 1;			
		}
		else if(*p1<*p2)
		{
			return -1;			
		}		
	}
	return 0;*/
}

std::ostream& operator<<(std::ostream& a_os, String const& a_rhs)
{
	a_rhs.print(a_os);
	return a_os;
}
