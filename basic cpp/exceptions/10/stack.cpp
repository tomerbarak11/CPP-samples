#include <iostream>
#include "Stack64.h"

Stack64::Stack64()
:m_top(0)
,m_capacity(STACK_CAPACITY)
{
	for(size_t i=0;i<STACK_CAPACITY;i++)
	{
		m_items[i]=0;
	}
	
	std::cout<<"CTOR\n";
}

bool Stack64::push(int a_value)
{
	if(isFull()==true)
	{
		throw std::overflow_error("Overflaw\n");
		return false;
	}
	m_items[m_top+1]=a_value;
	m_top++;
	return true;
}

bool Stack64::pop(int* a_value)
{
	if(isEmpty()==true)
	{
		throw std::underflow_error("Underflaw\n");
		return false;
	}
	*a_value=m_items[m_top];
	m_top--;
	return true;
}

bool Stack64::isFull() const
{
	if(m_top==m_capacity)
	{
		return true;
	}
	return false;
}

bool Stack64::isEmpty() const
{
	if(m_top==0)
	{
		return true;
	}
	return false;
}

bool Stack64::top(int* a_pValue) const
{
	if(isEmpty()==true)
	{
		return false;
	}
	*a_pValue=m_items[m_capacity];
	return true;
}

size_t Stack64::size() const
{
	return m_top;
}

size_t Stack64::capacity() const
{
	return STACK_CAPACITY;
}
