#ifndef NUMBERS_H
#define NUMBERS_H

#include "expression.h"

class Number : public Expression {
public:
    Number(double v);
    double value() const;
    std::ostream& printExpression(std::ostream& a_os = std::cout) const;

private:
    double m_value;
};

inline Number* number(double d){
    return new Number(d);
}
#endif