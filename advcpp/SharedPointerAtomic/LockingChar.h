#ifndef LOCKINGCHAR_H
#define LOCKINGCHAR_H

class LockingChar
{

public:
    LockingChar(char a_char=0);
    char& getChar() const;
private:
    char &m_lock;
};

#endif


