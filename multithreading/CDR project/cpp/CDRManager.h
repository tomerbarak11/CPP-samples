#ifndef CDRMANAGER_H
#define CDRMANAGER_H
#include "CDR.h"
#include <map>
#include <vector>
#include "SafeHash.h"
#include <iostream>
#include "Subscriber.h"
#include "Operator.h"
#include "HasherForSize_t.h"

template<typename K,typename V1,typename V2,typename H>
class CDRManager
{
public:
    CDRManager(SafeHash<K,V1,H>& a_ou,SafeHash<K,V2,H>& a_su,HasherForSize_t a_func);
    void addCDRsOfVector(std::vector<CDR*> a_cdrVector);
private:
    SafeHash<size_t,Operator,HasherForSize_t>& m_ou;
    SafeHash<size_t,Subscriber,HasherForSize_t>& m_su;
    HasherForSize_t m_func;
};

template<typename K,typename V1,typename V2,typename H>
CDRManager<K,V1,V2,H>::CDRManager(SafeHash<K,V1,H>& a_ou,SafeHash<K,V2,H>& a_su,HasherForSize_t a_func)
: m_ou(a_ou)
, m_su(a_su)
, m_func(a_func)
{  
}


template<typename K,typename V1,typename V2,typename H>
void CDRManager<K,V1,V2,H>::addCDRsOfVector(std::vector<CDR*> a_cdrVector)
{
    size_t size=a_cdrVector.size();
    for(size_t i=0;i<size;++i)
    {
        Subscriber* newSub=new Subscriber(a_cdrVector[i]);
        m_su.updateIf(newSub->getMSISDN(),*newSub);
    }
}

#endif