#include "FirstFlag.h"
FirstFlag::FirstFlag()
{
    first=false;
}

//a_a==false
//a_b==true
bool FirstFlag::flip(bool a_a,bool a_b)
{
    return __sync_bool_compare_and_swap(&first,a_a,a_b);
}