#include "FinishFlag.h"
FinishFlag::FinishFlag()
{
    finish=false;
}
//false
//true
void FinishFlag::set()
{
    __sync_bool_compare_and_swap(&finish,false,true);
}

bool FinishFlag::isSet()
{
    return __sync_bool_compare_and_swap(&finish,true,true);
}

