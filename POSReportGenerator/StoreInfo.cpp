#include "StoreInfo.h"

StoreInfo::StoreInfo()
    : m_posCount(0),
    m_updatedPos(0),
    m_updateRate(0)
{
}

//-----------------------------------------
// Getter
//-----------------------------------------

const std::string& StoreInfo::GetStoreNo() const
{
    return m_storeNo;
}

const std::string& StoreInfo::GetStoreName() const
{
    return m_storeName;
}

const std::string& StoreInfo::GetUpdateStatus() const
{
    return m_updateStatus;
}

int StoreInfo::GetPosCount() const
{
    return m_posCount;
}

int StoreInfo::GetUpdatedPos() const
{
    return m_updatedPos;
}

int StoreInfo::GetUpdateRate() const
{
    return m_updateRate;
}

const std::string& StoreInfo::GetOpenDate() const
{
    return m_openDate;
}

//-----------------------------------------
// Setter
//-----------------------------------------

void StoreInfo::SetStoreNo(const std::string& storeNo)
{
    m_storeNo = storeNo;
}

void StoreInfo::SetStoreName(const std::string& storeName)
{
    m_storeName = storeName;
}

void StoreInfo::SetUpdateStatus(const std::string& updateStatus)
{
    m_updateStatus = updateStatus;
}

void StoreInfo::SetPosCount(int posCount)
{
    m_posCount = posCount;
}

void StoreInfo::SetUpdatedPos(int updatedPos)
{
    m_updatedPos = updatedPos;
}

void StoreInfo::SetUpdateRate(int updateRate)
{
    m_updateRate = updateRate;
}

void StoreInfo::SetOpenDate(const std::string& openDate)
{
    m_openDate = openDate;
}