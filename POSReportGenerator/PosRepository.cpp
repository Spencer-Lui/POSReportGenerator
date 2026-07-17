#include "PosRepository.h"
#include "SQLiteHelper.h"

std::vector<StoreInfo>
PosRepository::GetSummary()
{
    std::vector<StoreInfo> stores;

    if (!m_database.Open(
        "Resources/POSReport.db"))
    {
        return stores;
    }

    auto rows =
        m_database.ExecuteQuery(
            "SELECT * FROM StoreSummary;");

    m_database.Close();

    return stores;
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

    //-----------------------------------
    // 匯入所有門市
    //-----------------------------------

    for (const auto& store : stores)
    {
        if (!InsertStore(store))
        {
            m_database.Close();

            return false;
        }
    }


    m_database.Close();

    return true;
}
bool PosRepository::InsertStore(
    const StoreInfo& store)
{
    std::string sql;

    sql =
        "INSERT INTO StoreSummary ";

    sql +=
        "("
        "StoreNo,"
        "StoreName,"
        "UpdateStatus,"
        "PosCount,"
        "UpdatedPos,"
        "UpdateRate,"
        "OpenDate"
        ")";

    sql +=
        " VALUES (";

    sql +=
        "'" +
        store.GetStoreNo() +
        "',";

    sql +=
        "'" +
        store.GetStoreName() +
        "',";

    sql +=
        "'" +
        store.GetUpdateStatus() +
        "',";

    sql +=
        std::to_string(
            store.GetPosCount())
        + ",";

    sql +=
        std::to_string(
            store.GetUpdatedPos())
        + ",";

    sql +=
        std::to_string(
            store.GetUpdateRate())
        + ",";

    sql +=
        "'" +
        store.GetOpenDate() +
        "'";

    sql += ");";

    return m_database.ExecuteNonQuery(sql);
}