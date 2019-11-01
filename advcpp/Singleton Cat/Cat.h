#ifndef CAT_H
#define CAT_H
#include <string>
#include "Singleton.h"

typedef struct CatData
{
    std::string m_catName;
    int m_age;
}CatData;

class Cat:private Singleton<Cat>
{
public:
    Cat(CatData a_data);
    void meow() const;
    using Singleton::getOne;
    using Singleton::getAtomicCounter;
    using Singleton::setAtomicCounter;
private:
    std::string m_catName;
    int m_age;
};

#endif