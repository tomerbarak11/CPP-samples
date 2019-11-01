#ifndef EXPRESSION_H
#define EXPRESSION_H
class Expression
{
public:
    virtual double const value()const=0;
    virtual ~Expression(){}
};
#endif