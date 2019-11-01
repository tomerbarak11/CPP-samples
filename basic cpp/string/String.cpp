#include <cstddef>
#include <iostream>
#include <cstring>
#include "String.h"

String::String(const char* a_source)
{
	int len=strlen(a_source);
	m_chars = new char[len+1];
	strcpy(m_chars,a_source);
}

String::String(const String& a_source)
{
	strcpy(m_chars,a_source.get());
}

String::~String()
{
}

String& String::operator=(const String& a_source)
{
	String* res=0;
	//if(length()>strlen(a_source))
	{
		strcpy(m_chars,a_source.get());
	}
	return *res;
	
}

size_t String::length() const
{
	size_t len;
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

void String::print(std::ostream& a_os) const
{
	a_os<<get();
}

int compare(const String& a_first, const String& a_second)
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
