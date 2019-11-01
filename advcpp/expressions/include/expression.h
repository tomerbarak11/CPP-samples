#ifndef EXPRESSION_H
#define EXPRESSION_H
#include <iostream>

class Expression {
public:
    virtual ~Expression();
    virtual double value() const = 0;
    virtual std::ostream& printExpression(std::ostream& a_os = std::cout) const = 0;
};

#endif