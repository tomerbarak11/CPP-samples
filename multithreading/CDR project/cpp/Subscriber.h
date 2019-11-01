#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H
#include "CDR.h"
class Subscriber
{
public:
    Subscriber();

    Subscriber(CDR* a_cdr);
    size_t getMSISDN() const;
    size_t getOutgoingInOpDurationMSISDN() const;

    void operator+=(Subscriber a_other);
private:
    size_t m_msisdn;

    size_t m_outgoingInOpDuration;
    size_t m_ingoingInOpDuration;
    size_t m_ingoingOutDuration;
    size_t m_ingoingInDuration;

    size_t m_smsSentIn;
    size_t m_smsRecIn;
    size_t m_smsSentOut;
    size_t m_smsRecOut;

    size_t m_mbDown;
    size_t m_mbUp;

};

#endif