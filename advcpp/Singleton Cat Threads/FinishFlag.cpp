#include "FinishFlag.h"
FinishFlag::FinishFlag()
{
    finish=false;
}

void FinishFlag::set()
{
    __sync_bool_compare_and_swap(&finish,false,true);
}

bool FinishFlag::isSet()
{
    return __sync_bool_compare_and_swap(&finish,true,true);
}

