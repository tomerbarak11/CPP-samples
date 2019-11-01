#ifndef PARSER_H
#define PARSER_H
#include <string>
#include <vector>
#include "expression.h"
#include "TokensEnum.h"
#include <tr1/unordered_map>
#include <stack>
#include <map>

typedef Expression*(*fp)(std::string a_string,std::stack<Expression*>& s);

class Parser {
public:
    Parser();
    const Expression* parse(std::vector<std::string> const& tokens);
private:
    void BuildMap(std::map<TokenT,fp>& a_map);
    std::map<TokenT,fp> m_map;
};

#endif