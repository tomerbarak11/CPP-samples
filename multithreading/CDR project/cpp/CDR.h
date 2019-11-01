#ifndef CDR_H
#define CDR_H
#include <string>
class CDR
{
public:
    CDR(std::string a_IMSI,
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
    std::string a_partyOperator);

    size_t getMSISDN() const;

    size_t getMCCMNC() const;
    std::string getBrandName() const;

    size_t getDownload() const;
    size_t getUpload() const;
    std::string getType() const;
    size_t getDuration() const;
    std::string getPartyOperator() const;



private:
    std::string m_IMSI;
    size_t m_MSISDN;
    std::string m_IMEI;
    std::string m_brandName;
    size_t m_MCCMNC;
    std::string m_callType;
    std::string m_callDate;
    std::string m_callTime;
    size_t m_duration;
    size_t m_download;
    size_t m_upload;
    std::string m_partyMSISDN;
    std::string m_partyOperator;
};


#endif