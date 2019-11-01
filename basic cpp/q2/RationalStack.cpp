#include <iostream>
#include <stdio.h>
#include "RationalStack.h"

RationalStack::RationalStack()
:m_top(0)
{
	for(size_t i=0;i<RATIONAL_STACK_SIZE;i++)
	{
		m_items[i]=0;
	}
}

bool RationalStack::push(Rational a_item)
{
	if(isFull()==true)
	{
		return false;
	}
	m_items[m_top]=a_item;
	m_top++;
	return true;
}

size_t RationalStack::push(Rational a_items[], size_t a_size)
{
	if(isFull()==true||RATIONAL_STACK_SIZE-a_size<m_top)
	{
		return false;
	}
	for(size_t i=0;i<a_size;i++)
	{
		m_items[i+m_top+1]=a_items[i];
		m_top++;
	}
	return true;
}

Rational RationalStack::pop()
{
	Rational r;
	if(isEmpty()==1)
	{
		return false;
	}
	r=m_items[--m_top];
	return r;
}

Rational RationalStack::top() const
{
	/*if(isEmpty()==1)
	{
		return false;
	}*/
	return m_items[m_top-1];
}

bool RationalStack::isFull() const
{
	if(m_top==RATIONAL_STACK_SIZE)
	{
		return true;
	}
	return false;
}

bool RationalStack::isEmpty() const
{
	if(m_top==0)
	{
		return true;
	}
	return false;
}

size_t RationalStack::size() const
{
	return m_top;
}

void RationalStack::print() const
{
	for(size_t i=0;i<m_top;i++)
	{
		std::cout<<"Rational number number "
					<<i
					<<" = "
					<<m_items[i].numerator()
					<<"/"
					<<m_items[i].denominator()
					<<"\n";	;					
	}
}

void RationalStack::trace() const
{
	for(size_t i=0;i<RATIONAL_STACK_SIZE;i++)
	{
		std::cout<<"Rational number number "
					<<i
					<<" = "
					<<m_items[i].numerator()
					<<"/"
					<<m_items[i].denominator()
					<<"\n";					
	}
}
