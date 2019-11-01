#ifndef CAT_H
#define CAT_H
#include <string>
#include "Singleton.h"
#include "StructForCat.h"

class Cat:private Singleton<Cat>
{
public:
    Cat();
    Cat(CatData a_data);
    void meow() const;
    using Singleton::getOne;
    using Singleton::getAtomicCounter;
    using Singleton::setAtomicCounter;
    using Singleton::instance;
private:
    std::string m_catName;
    int m_age;
};

#endif