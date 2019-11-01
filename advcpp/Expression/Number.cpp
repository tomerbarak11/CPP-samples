#include "Number.h"
Number::Number(double a_value)
: m_value(a_value)
{
}

double const Number:: value() const
{
    return m_value;
}
