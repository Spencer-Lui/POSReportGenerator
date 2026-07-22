#include <filesystem>
#include <iostream>
#include "PosRepository.h"
#include "SQLiteHelper.h"

namespace
{
    constexpr const char* DATABASE_PATH =
        "Resources/POSReport.db";

    constexpr const char* SELECT_STORE_SUMMARY =
        "SELECT * FROM StoreSummary;";

    constexpr const char* DELETE_STORE_SUMMARY =
        "DELETE FROM StoreSummary;";
}

static int ToInt(
    const std::string& value)
{
    try
    {
        return std::stoi(value);
    }
    catch (...)
    {
        return 0;
    }
}

std::vector<StoreInfo>
PosRepository::GetSummary()
{
    std::vector<StoreInfo> stores;

    std::cout
        << "Database Current Path = "
        << std::filesystem::current_path()
        << std::endl;

    std::cout
        << "Database File = "
        << DATABASE_PATH
        << std::endl;

    std::cout
        << "Database Exists = "
        << std::filesystem::exists(DATABASE_PATH)
        << std::endl;

    if (!m_database.Open(DATABASE_PATH))
    {
        std::cout << "Open Database Failed!" << std::endl;

        return stores;
    }

    auto rows =
        m_database.ExecuteQuery(
            SELECT_STORE_SUMMARY);

    std::cout
        << "SQLite Rows = "
        << rows.size()
        << std::endl;

    std::cout
        << "Row Count = "
        << rows.size()
        << std::endl;

    for (const auto& row : rows)
    {
        if (row.size() < 7)
        {
            continue;
        }

        StoreInfo store;

        store.SetStoreNo(row[0]);

        store.SetStoreName(row[1]);

        store.SetUpdateStatus(row[2]);

        store.SetPosCount(
            ToInt(row[3]));

        store.SetUpdatedPos(
            ToInt(row[4]));

        store.SetUpdateRate(
            ToInt(row[5]));

        store.SetOpenDate(
            row[6]);

        stores.push_back(store);

        static int printCount = 0;

        if (printCount < 10)
        {
            std::cout
                << store.GetStoreNo()
                << " "
                << store.GetStoreName()
                << std::endl;

            ++printCount;
        }
    }

    m_database.Close();

    return stores;
}
bool PosRepository::Import(
    const std::vector<StoreInfo>& stores)
{
    if (!m_database.Open(
        DATABASE_PATH))
    {
        return false;
    }

    //-----------------------------------
    // 清空舊資料
    //-----------------------------------

    if (!m_database.ExecuteNonQuery(
        DELETE_STORE_SUMMARY))
    {
        m_database.Close();

        return false;
    }

    //-----------------------------------
    // 匯入所有門市
    //-----------------------------------

    int insertCount = 0;

    for (const auto& store : stores)
    {
        if (!InsertStore(store))
        {
            std::cout
                << "Insert Failed : "
                << store.GetStoreNo()
                << std::endl;

            m_database.Close();

            return false;
        }

        insertCount++;
    }

    std::cout
        << "Insert Count = "
        << insertCount
        << std::endl;

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