#include "Parser.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstring>

Parser::Parser(std::string a_fileName)
: m_fileName(a_fileName)
{
}


std::vector<CDR*> Parser::parse()
{
    std::vector<CDR*> vector;
    std::ifstream f;
    char * cstr = new char [m_fileName.length()+1];
    std::strcpy (cstr, m_fileName.c_str());    
    f.open(cstr);
    if (!f)
    {
        std::cerr << "Unable to open file testfile.txt";
    }
    while(!f.eof())
    {
        std::string imsi;
        std::string msisdn;
        std::string imei;
        std::string brandName;
        std::string mcc;
        std::string mnc;
        std::string mccmnc;
        std::string callType;
        std::string callDate;
        std::string callTime;
        std::string duration;
        std::string download;
        std::string upload;
        std::string partyMSISDN;
        std::string partyOperator;


       	getline(f, imsi,'|');
       	getline(f, msisdn,'|');
       	getline(f, imei,'|');
       	getline(f, brandName,'|');
        
        for(size_t i=0;i<3;i++)
        {
            char c;
            f.get(c);
            mcc.push_back(c);
        }
        getline(f, mnc,'|');
        mccmnc=mcc+mnc;
       	getline(f, callType,'|');
       	getline(f, callDate,'|');
       	getline(f, callTime,'|');
       	getline(f, duration,'|');
       	getline(f, download,'|');
       	getline(f, upload,'|');
       	getline(f, partyMSISDN,'|');
       	getline(f, partyOperator,'\n');

        size_t dMsisdn;
        std::istringstream iss0(msisdn);
        iss0>>dMsisdn;

        size_t dDuration;
        std::istringstream iss1(duration);
        iss1>>dDuration;

        size_t dDownload;
        std::istringstream iss2(download);
        iss2>>dDownload;        

        size_t dUpload;
        std::istringstream iss3(upload);
        iss3>>dUpload;

        size_t dMccmnc;
        std::istringstream iss4(mccmnc);
        iss4>>dMccmnc; 
        CDR* newCDR=new CDR(imsi,dMsisdn,imei,brandName,dMccmnc,callType,callDate,callTime,
        dDuration,dDownload,dUpload,partyMSISDN,partyOperator);
        vector.push_back(newCDR);
    }
    f.close();
    return vector;
}

void Parser::run()
{
    parse();
}

