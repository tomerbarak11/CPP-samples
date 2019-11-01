#include "CDR.h"
CDR::CDR(std::string a_IMSI,
size_t a_MSISDN,
std::string a_IMEI,
std::string a_brandName,
size_t a_MCCMNC,
std::string a_callType,
std::string a_callDate,
std::string a_callTime,
size_t a_duration,
size_t a_download,
size_t a_upload,
std::string a_partyMSISDN,
std::string a_partyOperator)
: m_IMSI(a_IMSI)
, m_MSISDN(a_MSISDN)
, m_IMEI(a_IMEI)
, m_brandName(a_brandName)
, m_MCCMNC(a_MCCMNC)
, m_callType(a_callType)
, m_callDate(a_callDate)
, m_callTime(a_callTime)
, m_duration(a_duration)
, m_download(a_download)
, m_upload(a_upload)
, m_partyMSISDN(a_partyMSISDN)
, m_partyOperator(a_partyOperator)
{
}

size_t CDR::getMCCMNC() const
{
    return m_MCCMNC;
}

size_t CDR::getMSISDN() const
{
    return m_MSISDN;
}

std::string CDR::getBrandName() const
{
    return m_brandName;
}

std::string CDR::getType() const
{
    return m_callType;
}

size_t CDR::getDownload() const
{
    return m_download;
}

size_t CDR::getUpload() const
{
    return m_upload;
}

size_t CDR::getDuration() const
{
    return m_duration;
}

std::string CDR::getPartyOperator() const
{
    return m_partyOperator;
}