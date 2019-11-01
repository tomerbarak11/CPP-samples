#ifndef PARSER_H
#define PARSER_H
#include <string>
#include <vector>
#include "CDR.h"
#include "Thread.h"

class Parser: public Thread
{
public:
    Parser(std::string a_fileName);
    std::vector<CDR*> parse();
    void run();
private:
    std::string m_fileName;

};
#endif