#include "Subscriber.h"
#include <sstream>
Subscriber::Subscriber()
{
}

Subscriber::Subscriber(CDR* a_cdr)
: m_msisdn(a_cdr->getMSISDN())
, m_outgoingInOpDuration(0)
, m_mbDown(a_cdr->getDownload())
, m_mbUp(a_cdr->getUpload())
{
    if(a_cdr->getType()== "MOC")
    {
        if(a_cdr->getBrandName()==a_cdr->getPartyOperator())
        {
            m_outgoingInOpDuration+=a_cdr->getDuration();
        }
    }
}

size_t Subscriber::getMSISDN() const
{
    return m_msisdn;
}

size_t Subscriber::getOutgoingInOpDurationMSISDN() const
{
    return m_outgoingInOpDuration;
}

void Subscriber::operator+=(Subscriber a_other)
{
    m_outgoingInOpDuration+=a_other.getOutgoingInOpDurationMSISDN();
}
