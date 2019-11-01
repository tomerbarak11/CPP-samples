#include "parser.h"

#include "ops.h"
#include "numbers.h"
#include <iostream>
#include <stack>
#include "TokensEnum.h"
#include <tr1/unordered_map>
#include "numbers.h"
#include "TokensEnum.h"
#include <sstream>
#include <map>
#include "Detector.h"
#include "expression.h"

Expression* CreateAdd(std::string a_string,std::stack<Expression*>& s)
{
    if(s.size()<2)
    {
        return 0;
    }
    Expression* e2=s.top();
    s.pop();
    Expression* e1=s.top();
    s.pop();
    return add(e1,e2);
}

Expression* CreateSub(std::string a_string,std::stack<Expression*>& s)
{ 
    if(s.size()<2)
    {
        return 0;
    }  
    Expression* e2=s.top();
    s.pop();
    Expression* e1=s.top();
    s.pop();    
    return sub(e1,e2);
}

Expression* CreateMul(std::string a_string,std::stack<Expression*>& s)
{
    if(s.size()<2)
    {
        return 0;
    }   
    Expression* e2=s.top();
    s.pop();
    Expression* e1=s.top();
    s.pop();    
    return mul(e1,e2);
}

Expression* CreateDiv(std::string a_string,std::stack<Expression*>& s)
{
    if(s.size()<2)
    {
        return 0;
    }   
    Expression* e2=s.top();
    s.pop();
    Expression* e1=s.top();
    s.pop();    
    return div(e1,e2);
}

Expression* CreateNumber(std::string a_string,std::stack<Expression*>& s)
{
    std::istringstream iss1 (a_string);
    double d;
    iss1 >> d;
    return number(d);
}

Parser::Parser()
{
    BuildMap(m_map);
}

Expression const* Parser::parse(std::vector<std::string> const& tokens)
{
    std::stack <Expression*> s;
    Detector d;
    BuildMap(m_map);
    size_t size=tokens.size();
    if(size<2)
    {
        return 0;
    }
    for(size_t i=0;i<size;++i)
    {
        TokenT et = d.detect(tokens[i]);
        Expression* e=m_map[et](tokens[i],s);
        s.push(e);
    }

    Expression* top=s.top();
    s.pop();
    return top;
}

void Parser::BuildMap(std::map<TokenT,fp>& a_map)
{
    a_map[NUMBER]=CreateNumber;
    a_map[ADDITION]=CreateAdd;
    a_map[SUBSTRACT]=CreateSub;
    a_map[MULTIPLY]=CreateMul;
    a_map[DIVISION]=CreateDiv;
}
