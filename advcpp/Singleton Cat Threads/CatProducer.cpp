#include "CatProducer.h"
#include <iostream>
CatProducer::CatProducer(CatData a_data)
: m_data(a_data)
{
}

void CatProducer::run()
{
    Cat& c1=Cat::instance(m_data);
    c1.meow();
}