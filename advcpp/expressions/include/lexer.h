#ifndef LEXER_H
#define LEXER_H
#include <istream>
#include <vector>
#include <string>

class Lexer {
public:
    Lexer(std::istream& is, char delim = ' ');
    std::vector<std::string> lex();
private:
    std::istream& m_is;
    char m_delim;
};

#endif