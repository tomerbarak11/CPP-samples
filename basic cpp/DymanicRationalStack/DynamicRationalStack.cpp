#include <iostream>
#include "Rational.h"
#include "DynamicRationalStack.h"
#include <stdio.h>
#include <cassert>

DynamicRationalStack::DynamicRationalStack(size_t a_initialCapacity,float a_growFactor)
:m_capacity(a_initialCapacity)
,m_growFactor(a_growFactor)
,m_top(0)

{
	assert(m_capacity>0);
	m_items=new Rational[m_capacity];
}

DynamicRationalStack::DynamicRationalStack(DynamicRationalStack const& a_other)
:m_capacity(a_other.m_capacity)
,m_top(a_other.m_top)
,m_items(new Rational[m_capacity])
{
	for(size_t i=0;i<a_other.m_top;i++)
	{
		m_items[i]=a_other.m_items[i];
	}
}

DynamicRationalStack::~DynamicRationalStack()
{
	delete [] m_items;
}

bool DynamicRationalStack::push(Rational const& a_rational)
{
	size_t size=s_DEFAULT_STACK_GROWTH_FACTOR*m_top;
	if(isFull()==true)
	{
		Rational* newItems= new Rational[size];
		if(0==newItems)
		{
			return false;
		}
		delete m_items;
		m_items=newItems;
		m_capacity=size;
	}
	m_items[m_top]=a_rational;
	m_top++;
	return true;
}

size_t DynamicRationalStack::push(Rational a_rationals[], size_t a_size)
{
	size_t count=0;
	for(size_t i=0;i<a_size;i++)
	{
		if(isFull()==true||m_capacity-a_size<m_top)
		{
			return count;
		}
		m_items[i+m_top+1]=a_rationals[i];
		m_top++;
	}
	return count;
}

bool DynamicRationalStack::pop(Rational& a_item)
{
	if(isEmpty()==1)
	{
		return false;
	}
	m_top--;
	a_item=m_items[m_top];
	return true;
}

bool DynamicRationalStack::top(Rational& a_item) const
{
	if(isEmpty()==1)
	{
		return false;
	}
	a_item=m_items[m_top-1];
	return true;
}

size_t DynamicRationalStack::size() const
{
	return m_top;
}

size_t DynamicRationalStack::capacity() const
{
	return m_capacity;
}

bool DynamicRationalStack::isFull() const
{
	if(m_top==m_capacity)
	{
		return true;
	}
	return false;
}

bool DynamicRationalStack::isEmpty() const
{
	if(m_top==0)
	{
		return true;
	}
	return false;
}

void DynamicRationalStack::print(std::ostream& a_os) const
{
	dump(a_os,"Print\n",m_top);
}

void DynamicRationalStack::trace(std::ostream& a_os) const
{
	dump(a_os,"Trace\n",m_capacity);
}

void DynamicRationalStack::dump(std::ostream& a_os, const char* a_header, size_t a_n) const
{
	a_os<<a_header;
	for(size_t i=0;i<a_n;i++)
	{
		m_items[i].print();
		a_os<<"\n";
	}
	a_os<<"\n";
}

size_t DynamicRationalStack::drain(DynamicRationalStack& a_into)
{
	size_t count=0;
	Rational popped;
	for(int i=m_top-1;i>=0;i--)
	{
		if(isEmpty()==true)
		{
			break;
		}
		pop(popped);
		push(popped);
		count++;
	}
	return count;
}

/*DynamicRationalStack& DynamicRationalStack::operator= (const DynamicRationalStack &item)
{
	
}*/

