#include <iostream>
#include "foo.h"

int main(void)
{
    std::cout<<"This is a shared library test...\n";
    foo();
    return 0;
}
