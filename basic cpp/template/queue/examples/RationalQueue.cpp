#include <iostream>
#include "RationalQueue.h"
#include <stdio.h>
#include <cassert>

RationalQueue::RationalQueue(size_t a_initialCapacity)
:m_enStack(a_initialCapacity,s_DEFAULT_STACK_GROWTH_FACTOR)
,m_deStack(a_initialCapacity,s_DEFAULT_STACK_GROWTH_FACTOR)
{
	assert(a_initialCapacity>0);
}

/*RationalQueue::~RationalQueue()

{
	assert(a_initialCapacity>0);
}*/

bool RationalQueue::enqueue(const Rational& a_rational)
{
	return m_enStack.push(a_rational);
}

size_t RationalQueue::enqueue(Rational a_rationals[], size_t a_size)
{
	return m_enStack.push(a_rationals,a_size);
}

bool RationalQueue::dequeue(Rational& a_rational)
{
	if(m_deStack.isEmpty()==false)
	{
		return m_deStack.pop(a_rational);
	}
	m_enStack.drain(m_deStack);
	
	return m_deStack.pop(a_rational);
}

size_t RationalQueue::dequeue(Rational a_rationals[], size_t a_size)
{
	size_t count;
	
	m_enStack.drain(m_deStack);
	for(size_t i=0;i<a_size;i++)
	{
		if(m_deStack.pop(a_rationals[i]))
		{
			count++;
		}
		else
		{
			break;
		}
	}
	return count;
}

bool RationalQueue::isFull() const
{
	if(m_enStack.capacity() || m_deStack.capacity()==size())
	{
		return true;
	}
	return false;
}

bool RationalQueue::isEmpty() const
{
	return(m_enStack.capacity()==0 && m_deStack.capacity()==0);
}

size_t RationalQueue::size() const
{
	return m_enStack.size()+m_deStack.size();
}

size_t RationalQueue::capacity() const
{
	return m_enStack.capacity();
}

void RationalQueue::print() const
{
	dump("Print\n",m_deStack.size());
	dump("Print\n",m_enStack.size());
}

void RationalQueue::trace() const
{
	dump("Print\n",m_deStack.capacity());
	dump("Print\n",m_enStack.capacity());
}

void RationalQueue::dump(const char* a_header, size_t a_n) const
{
	std::cout<<a_header;
	for(size_t i=0;i<a_n;i++)
	{
		m_deStack.print();
		std::cout<<"\n";
	}
	std::cout<<"\n";
}
