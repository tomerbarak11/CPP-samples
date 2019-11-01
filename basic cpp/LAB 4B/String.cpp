#include <cstddef>
#include <iostream>
#include <cstring>
#include "String.h"
#include <cassert>
#include <stdio.h>

bool String:: s_caseSensitivity=false;
size_t String::STRING_ALLOC_ALIGNMENT=STRING_ALLOC_ALIGNMENT_DEFAULT;
const size_t String::STRING_ALLOC_ALIGNMENT_DEFAULT;

String::String(const char* a_source)
:m_capacity(STRING_ALLOC_ALIGNMENT_DEFAULT)
{
	if(0!=a_source)
	{	
		m_size=(strlen(a_source));
	}
	else
	{	
		m_size=0;
	}
	bool res = stringInit(a_source);
	assert(res==true);
}

String::String(const String& a_source)
:m_size(strlen(a_source.get()))
,m_capacity(STRING_ALLOC_ALIGNMENT_DEFAULT)
{
	bool res = stringInit(a_source.get());
	set(a_source.get());
	assert(res==true);
}

String::~String()
{
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
	return m_size;
}

size_t String::capacity() const
{
	return m_capacity;
}

const char* String::get() const
{
	return m_chars;
}

void String::set(const char* a_source)
{
	if(strlen(a_source)>m_size)
	{
		delete [] m_chars;
		size_t newSize=m_size;
		while(newSize<=strlen(a_source))
		{
			newSize=newSize+STRING_ALLOC_ALIGNMENT;
		}
		m_chars = new char[newSize+1];
		m_size=strlen(m_chars);
	}
	strcpy(m_chars,a_source);
}

String& String::operator+=(const char* a_rhs)
{
	size_t newSize=m_size;
	while(newSize<=strlen(a_rhs))
	{
		m_chars = new char[newSize+1];
		newSize=newSize+STRING_ALLOC_ALIGNMENT;
	}
	m_size=strlen(m_chars);
	strcat(m_chars,a_rhs);
	return *this;
}

String& String::operator+=(String const& a_rhs)
{
	size_t newSize=m_size;
	while(newSize<=strlen(a_rhs.get()))
	{
		newSize=newSize+STRING_ALLOC_ALIGNMENT;
	}
	char* temp = new char[newSize];
	strcpy(temp,m_chars);
	m_chars = new char[newSize+1];
	m_size=newSize+1;
	strcpy(m_chars,temp);
	strcat(m_chars,a_rhs.get());
	return *this;
}

char String::operator[](size_t a_pos) const
{
	return m_chars[a_pos];
}

char& String::operator[](size_t a_pos)
{
	return m_chars[a_pos];
}


String String::operator()(size_t a_start, size_t a_leng) const
{
	size_t i;
	/*if((a_start+a_leng)>m_size)
	{
		return 0;
	}*/
	char* newString= new char[a_leng+1];
	for(i=0;i<a_leng;i++)
	{
		newString[i]=m_chars[a_start+i];
	}
	newString[i]='\0';
	String res(newString);
	return res;
}

bool String::contains(String const& a_what, bool a_caseSense) const
{
	if(a_caseSense==true)
	{
		if(strstr(m_chars,a_what.get()))
		{
			return true;
		}
	}
	else
	{
		if(strcasestr(m_chars,a_what.get()))
		{
			return true;
		}
	}
	return false;
}

int String::findFirst(char a_what) const
{
	size_t i;
	for(i=0;i<m_size;i++)
	{
		if(m_chars[i]==a_what)
		{
			return i;
		}
	}
	return -1;
}

int String::findLast(char a_what) const
{
	for(int i=m_size-1;i>=0;i--)
	{
		if(m_chars[i]==a_what)
		{
			return i;
		}
	}
	return -1;
}

char String::findFirstDuplicate() const
{
	size_t i;
	int chars256[256];
	for(i=0;i<256;i++)
	{
		chars256[i]=0;
	}
	for(i=0;i<m_size;i++)
	{
		chars256[(int)m_chars[i]]++;
		if(chars256[(int)m_chars[i]]==2)
		{
			return m_chars[i];
		}
	}
	return 0;
}

size_t String::alignment()
{
	return STRING_ALLOC_ALIGNMENT_DEFAULT;
}

void String::alignment(size_t a_block)
{
	STRING_ALLOC_ALIGNMENT=a_block;
}

void String::print(std::ostream& a_os) const
{
	a_os<<get();
}

bool String::isCaseSensitive()
{
	return s_caseSensitivity;
	return false;
}

void String::setCaseSensitive(bool a_sensitive)
{
	s_caseSensitivity=a_sensitive;
	return;
}

/*int compare(const String& a_first) const
{
	if(String::isCaseSensitive()==true)
	{
		if(strcmp(m_chars,a_first.get())==0)
		{
			return 0;
		}
		if(strcmp(m_chars,a_first.get())==-1)
		{
			return -1;
		}
		return 1;
	}	
	else
	{
		if(strcasecmp(m_chars,a_first.get())==0)
		{
			return 0;
		}
		if(strcasecmp(m_chars,a_first.get())==-1)
		{
			return -1;
		}
		return 1;
	}
	return 0;
}*/

std::ostream& operator<<(std::ostream& a_os, String const& a_rhs)
{
	a_rhs.print(a_os);
	return a_os;
}

String const operator+(String const& a_lhs, String const& a_rhs)
{
	char* newWord= new char[strlen(a_lhs.get())+strlen(a_rhs.get())+1];
	strcpy(newWord,a_lhs.get());
	strcat(newWord,a_rhs.get());
	String const newString(newWord);

	return newString;
}

/*{
 * String String::operator()(size_t a_start, size_t a_leng) const

	size_t i;
	if((a_start+a_leng)<m_size)
	{
		return 0;
	}
	char* newString= new char[a_leng+1];
	for(i=0;i<a_leng;i++)
	{
		newString[i]=m_chars[a_leng+i];
	}
	newString[i]='\0';
	String res(newString);
	return res;
	* */


String const operator+(String const& a_lhs, const char* a_rhs)
{
	char* newWord= new char[strlen(a_lhs.get())+strlen(a_rhs)+1];
	strcpy(newWord,a_lhs.get());
	strcat(newWord,a_rhs);
	String const newString(newWord);

	return newString;
}

String const operator+(const char* a_lhs, String const& a_rhs)
{
	char* newWord= new char[strlen(a_lhs)+strlen(a_rhs.get())+1];
	strcpy(newWord,a_lhs);
	strcat(newWord,a_rhs.get());
	String const newString(newWord);

	return newString;
}

bool operator==(String const& a_first, String const& a_second)
{
	if(strcmp(a_first.get(),a_second.get())==0)
	{
		return true;
	}
	return false;
}

bool operator!=(String const& a_first, String const& a_second)
{
	if(strcmp(a_first.get(),a_second.get())!=0)
	{
		return true;
	}
	return false;
}

bool operator<(String const& a_first, String const& a_second)
{
	if(strcmp(a_first.get(),a_second.get())<0)
	{
		return true;
	}
	return false;
}

bool operator>(String const& a_first, String const& a_second)
{
	if(strcmp(a_first.get(),a_second.get())>0)
	{
		return true;
	}
	return false;
}

bool operator<=(String const& a_first, String const& a_second)
{
	if(strcmp(a_first.get(),a_second.get())<=0)
	{
		return true;
	}
	return false;
}

bool operator>=(String const& a_first, String const& a_second)
{
	if(strcmp(a_first.get(),a_second.get())>=0)
	{
		return true;
	}
	return false;
}

