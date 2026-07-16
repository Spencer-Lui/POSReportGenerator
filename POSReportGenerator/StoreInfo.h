#pragma once

#include <string>

class StoreInfo
{
public:

    StoreInfo();

    //-----------------------------------------
    // Getter
    //-----------------------------------------

    const std::string& GetStoreNo() const;

    const std::string& GetStoreName() const;

    const std::string& GetUpdateStatus() const;

    int GetPosCount() const;

    int GetUpdatedPos() const;

    int GetUpdateRate() const;

    const std::string& GetOpenDate() const;

    //-----------------------------------------
    // Setter
    //-----------------------------------------

    void SetStoreNo(const std::string& storeNo);

    void SetStoreName(const std::string& storeName);

    void SetUpdateStatus(const std::string& updateStatus);

    void SetPosCount(int posCount);

    void SetUpdatedPos(int updatedPos);

    void SetUpdateRate(int updateRate);

    void SetOpenDate(const std::string& openDate);

private:

    //-----------------------------------------
    // Member Variable
    //-----------------------------------------

    std::string m_storeNo;

    std::string m_storeName;

    std::string m_updateStatus;

    int m_posCount;

    int m_updatedPos;

    int m_updateRate;

    std::string m_openDate;
};