#ifndef NUMBER_H
#define NUMBER_H
#include "Expression.h"

class Number: public Expression
{
public:
    Number(double a_value);
    double const value() const;
private:
    double const m_value;
};
#endif