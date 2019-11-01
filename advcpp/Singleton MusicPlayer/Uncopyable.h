#ifndef UNCOPYABLE_H
#define UNCOPYABLE_H

class Uncopyable
{
public:
protected:
    Uncopyable();
private:
    Uncopyable(Uncopyable const& a_other);
    Uncopyable& operator=(Uncopyable const& a_other);
};

#endif