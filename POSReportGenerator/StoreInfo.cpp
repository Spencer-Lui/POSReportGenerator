#include "StoreInfo.h"

StoreInfo::StoreInfo()
    : m_total(0)
{
    
}

const std::string&
StoreInfo::GetStoreNo() const
{
    return m_storeNo;
}

const std::string&
StoreInfo::GetStoreName() const
{
    return m_storeName;
}

int
StoreInfo::GetTotal() const
{
    return m_total;
}

void
StoreInfo::SetStoreNo(
    const std::string& storeNo)
{
    m_storeNo = storeNo;
}

void
StoreInfo::SetStoreName(
    const std::string& storeName)
{
    m_storeName = storeName;
}

void
StoreInfo::SetTotal(
    int total)
{
    m_total = total;
}
