#include "Detector.h"

Detector::Detector()
{
    m_map["number"]=NUMBER;
    m_map["+"]=ADDITION;
    m_map["-"]=SUBSTRACT;
    m_map["*"]=MULTIPLY;
    m_map["/"]=DIVISION;

}

TokenT Detector::detect( std::string const& a_string)
{
    if(isdigit(a_string[0]))
    {
        return m_map["number"];
    }
    return m_map[a_string];
}
