#ifndef FINISHFLAG_H
#define FINISHFLAG_H
extern int finish;

class FinishFlag
{
public:
    FinishFlag();
    void set();
    bool isSet();

private:
};

#endif