#ifndef DETECTOR_H
#define DETECTOR_H
#include "TokensEnum.h"
#include <string>
#include <map>
#include <stack>

class Detector
{
public:
    Detector();
    TokenT detect( std::string const& a_string);
private:
    std::map<std::string,TokenT> m_map;
};

#endif