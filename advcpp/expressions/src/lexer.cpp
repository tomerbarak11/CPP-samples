#include "lexer.h"

Lexer::Lexer(std::istream& is, char delim)
: m_is(is)
, m_delim(delim)
{
}

std::vector<std::string> Lexer::lex()
{
    std::vector<std::string> tokens;

    std::string token;
    while(std::getline(m_is, token, m_delim)){
        tokens.push_back(token);
    }
    return tokens;
}