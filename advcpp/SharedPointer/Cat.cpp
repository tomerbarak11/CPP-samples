#include "Cat.h"
#include <iostream>

Cat::Cat (std::string a_name)
: m_name(a_name)
{
}

std::string Cat::getName() const
{
    std::cout<<m_name<<"\n";
    return m_name;
}

