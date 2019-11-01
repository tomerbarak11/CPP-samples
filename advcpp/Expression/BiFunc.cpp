#include "BiFunc.h"
BiFunc::BiFunc(Expression const* a_arg1,Expression const* a_arg2)
: m_arg1(a_arg1)
, m_arg2(a_arg2)
{
}

Add::Add(Expression const* a_arg1,Expression const* a_arg2)
: BiFunc(a_arg1,a_arg2)
{
}

double const Add::value() const
{
    return (m_arg1->value())+(m_arg2->value());
}

Sub::Sub(Expression const* a_arg1,Expression const* a_arg2)
: BiFunc(a_arg1,a_arg2)
{
}

double const Sub::value() const
{
    return (m_arg1->value())-(m_arg2->value());
}

Mul::Mul(Expression const* a_arg1,Expression const* a_arg2)
: BiFunc(a_arg1,a_arg2)
{
}

double const Mul::value() const
{
    return (m_arg1->value())*(m_arg2->value());
}

Div::Div(Expression const* a_arg1,Expression const* a_arg2)
: BiFunc(a_arg1,a_arg2)
{
}

double const Div::value() const
{
    return (m_arg1->value())/(m_arg2->value());
}
