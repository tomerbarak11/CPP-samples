#include <iostream>
#include "DynStack.h"
#include <stdio.h>
#include <cassert>
DynStack::DynStack(size_t a_capacity)
:m_capacity(a_capacity)
,m_top(0)
{
	assert(m_capacity>0);
	m_items=new int[m_capacity];
}

DynStack::DynStack(DynStack const& a_other)
:m_capacity(a_other.m_capacity)
,m_top(a_other.m_top)
,m_items(new int[m_capacity])
{
	for(size_t i=0;i<a_other.m_top;i++)
	{
		m_items[i]=a_other.m_items[i];
	}
}

DynStack::~DynStack()

{
	delete [] m_items;
}

bool DynStack::push(int a_item)
{
	if(isFull()==true)
	{
		return false;
	}
	m_items[m_top]=a_item;
	m_top++;
	return true;
}

bool DynStack::pop(int& a_item)
{
	if(isEmpty()==1)
	{
		return false;
	}
	m_top--;
	a_item=m_items[m_top];
	return true;
}

bool DynStack::top(int& a_item) const
{
	if(isEmpty()==1)
	{
		return false;
	}
	a_item=m_items[m_top-1];
	return true;
}

void DynStack::print(std::ostream& a_os) const
{
	for(size_t i=0;i<m_top;i++)
	{
		a_os<<"Number "
					<<i
					<<" = "
					<<m_items[i]
					<<"\n";	;					
	}
}

void DynStack::trace(std::ostream& a_os) const
{
	for(size_t i=0;i<m_capacity;i++)
	{
		a_os<<"Number "
					<<i
					<<" = "
					<<m_items[i]
					<<"\n";					
	}
}


