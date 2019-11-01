#include "LockingChar.h"

LockingChar::LockingChar(char a_char)
: m_lock(a_char)
{
}

char& LockingChar::getChar() const
{
    return m_lock;
}
