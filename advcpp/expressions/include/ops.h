#ifndef OPS_H
#define OPS_H

#include "expression.h"


class BiFunc : public Expression{
public:
    BiFunc(const Expression *arg1, const Expression *arg2);
    virtual double value() const;
    std::ostream& printExpression(const Expression* l,const Expression* r,std::ostream& a_os = std::cout) const;

    const Expression * left() const { return arg1;}
    const Expression * right() const { return arg2;}
    std::ostream& printExpression(std::ostream& a_os = std::cout) const;

private:
    virtual double op(double x, double y) const = 0;
    virtual std::ostream& oprint(const Expression* l,const Expression* r,std::ostream& a_os = std::cout) const=0;
private:
    const Expression *arg1, *arg2;
};


class Add : public BiFunc 
{
public:
    Add(const Expression *arg1, const Expression *arg2);
    virtual double op(double x, double y) const;
    std::ostream& oprint(const Expression* l,const Expression* r,std::ostream& a_os = std::cout) const;
private:
};

class Sub : public BiFunc 
{
public:
    Sub(const Expression *arg1, const Expression *arg2);
    virtual double op(double x, double y) const;
    std::ostream& oprint(const Expression* l,const Expression* r,std::ostream& a_os = std::cout) const;
private:
};

class Mul : public BiFunc 
{
public:
    Mul(const Expression *arg1, const Expression *arg2);
    virtual double op(double x, double y) const;
    std::ostream& oprint(const Expression* l,const Expression* r,std::ostream& a_os = std::cout) const;
private:
};

class Div : public BiFunc 
{
public:
    Div(const Expression *arg1, const Expression *arg2);
    virtual double op(double x, double y) const;
    std::ostream& oprint(const Expression* l,const Expression* r,std::ostream& a_os = std::cout) const;
private:
};

inline Add* add(const Expression *arg1, const Expression *arg2){
    return new Add(arg1,arg2);
}

inline Sub* sub(const Expression *arg1, const Expression *arg2){
    return new Sub(arg1,arg2);
}

inline Mul* mul(const Expression *arg1, const Expression *arg2){
    return new Mul(arg1,arg2);
}

inline Div* div(const Expression *arg1, const Expression *arg2){
    return new Div(arg1,arg2);
}

#endif