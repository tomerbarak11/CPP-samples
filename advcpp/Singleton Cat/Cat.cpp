#include "Cat.h"
#include <iostream>

Cat::Cat(CatData a_data)
: m_catName(a_data.m_catName)
, m_age(a_data.m_age)
{
}


void Cat::meow() const
{
    std::cout<<"Mewo!\n";
}

