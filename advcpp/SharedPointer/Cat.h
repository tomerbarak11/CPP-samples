#ifndef CAT_H
#define CAT_H
#include <string>
class Cat
{
public:
    Cat(std::string a_name);
    std::string getName() const;
    void eat(){
        m_name += "@";
    }
private:
    std::string m_name;
};

#endif