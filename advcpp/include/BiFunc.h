#ifndef BIFUNC_H
#define BIFUNC_H
#include "Expression.h"
class BiFunc: public Expression
{
public:
    BiFunc(Expression const* a_arg1,Expression const* a_arg2);
    virtual double const value()const=0;

protected:
    Expression const* m_arg1;
    Expression const* m_arg2;
};

class Add: public BiFunc
{
public:
    Add(Expression const* a_arg1,Expression const* a_arg2);
    double const value() const;
private:
};

class Sub: public BiFunc
{
public:
    Sub(Expression const* a_arg1,Expression const* a_arg2);
    double const value() const;
private:
};

class Mul: public BiFunc
{
public:
    Mul(Expression const* a_arg1,Expression const* a_arg2);
    double const value() const;
private:
};

class Div: public BiFunc
{
public:
    Div(Expression const* a_arg1,Expression const* a_arg2);
    double const value() const;
private:
};

#endif
