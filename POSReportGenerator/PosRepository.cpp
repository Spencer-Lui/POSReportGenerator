#include "PosRepository.h"
#include "SQLiteHelper.h"

std::vector<StoreInfo>
PosRepository::GetSummary() const
{
    std::vector<StoreInfo> stores;

    StoreInfo store;

    store.SetStoreNo("0001");
    store.SetStoreName("Taipei");
    store.SetPosCount(35);

    stores.push_back(store);

    return {};
}
bool PosRepository::Import(
    const std::vector<StoreInfo>& stores)
{
    if (!m_database.Open(
        "Resources/POSReport.db"))
    {
        return false;
    }

    //-----------------------------------
    // 清空舊資料
    //-----------------------------------

    if (!m_database.ExecuteNonQuery(
        "DELETE FROM StoreSummary;"))
    {
        m_database.Close();

        return false;
    }

    m_database.Close();

    return true;
}