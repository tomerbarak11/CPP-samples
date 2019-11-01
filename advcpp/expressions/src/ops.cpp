#include "ops.h"
#include "Detector.h"
BiFunc::BiFunc(const Expression *arg1, const Expression *arg2)
: arg1(arg1)
, arg2(arg2)
{    
}

std::ostream& BiFunc::printExpression(std::ostream& a_os) const
{
    return oprint(left(),right(),a_os);
}

double BiFunc::value() const
{
    return op(left()->value() , right()->value());
}

Add::Add(const Expression *arg1, const Expression *arg2)
: BiFunc(arg1, arg2)
{    
}

double Add::op(double x, double y) const
{
    return  x + y;
}

std::ostream& Add::oprint(const Expression* l,const Expression* r,std::ostream& a_os) const
{
    a_os<<"( ";
    l->printExpression(a_os);
    a_os<<" "<<"+"<<" ";
    r->printExpression(a_os);
    a_os<<")";
    return a_os;
}

Sub::Sub(const Expression *arg1, const Expression *arg2)
: BiFunc(arg1, arg2)
{    
}

double Sub::op(double x, double y) const
{
    return  x - y;
}

std::ostream& Sub::oprint(const Expression* l,const Expression* r,std::ostream& a_os) const
{
    a_os<<"( " <<l->value()<<" "<<"-"<<" "<<r->value()<<")";
    return a_os;
}

Mul::Mul(const Expression *arg1, const Expression *arg2)
: BiFunc(arg1, arg2)
{    
}

double Mul::op(double x, double y) const
{
    return  x * y;
}

std::ostream& Mul::oprint(const Expression* l,const Expression* r,std::ostream& a_os) const
{
    a_os<<"( " <<l->value()<<" "<<"*"<<" "<<r->value()<<")";
    return a_os;
}

Div::Div(const Expression *arg1, const Expression *arg2)
: BiFunc(arg1, arg2)
{    
}

double Div::op(double x, double y) const
{
    return  x / y;
}

std::ostream& Div::oprint(const Expression* l,const Expression* r,std::ostream& a_os) const
{
    a_os<<"( " <<l->value()<<" "<<"/"<<" "<<r->value()<<")";
    return a_os;
}