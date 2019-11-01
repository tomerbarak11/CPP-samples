#include "numbers.h"

Number::Number(double v)
: m_value(v)
{
}

double Number::value() const 
{ 
    return m_value;
}

std::ostream& Number::printExpression(std::ostream& a_os) const
{
    a_os<<m_value;
    return a_os;
}
