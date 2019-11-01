#ifndef COUNTER_H
#define COUNTER_H
#include <cstddef>

class Counter{
public:
    Counter(size_t a_numOfRef);
    Counter& operator++();
    Counter& operator--();
    size_t getValue() const;
    void setValue(size_t a_value);
    operator size_t();
private:
   size_t m_value;
};

Counter::Counter(size_t a_numOfRef)
: m_value(a_numOfRef)
{
}

Counter& Counter::operator++()
{
    ++m_value;
    return *this;
}

Counter& Counter::operator--()
{
    --m_value;
    return *this;}

size_t Counter::getValue() const
{
    return m_value;
}

void Counter::setValue(size_t a_value)
{
    m_value=a_value;
}

Counter::operator size_t()
{
    return m_value;
}

#endif
