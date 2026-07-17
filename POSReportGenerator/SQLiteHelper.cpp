#include <vector>
#include "SQLiteHelper.h"


static int QueryCallback(
    void* data,
    int columnCount,
    char** values,
    char** columnNames)
{
    auto* rows =
        static_cast<
        std::vector<
        std::vector<std::string>>*>(data);

    std::vector<std::string> row;

    for (int i = 0; i < columnCount; ++i)
    {
        if (values[i] != nullptr)
        {
            row.push_back(values[i]);
        }
        else
        {
            row.push_back("");
        }
    }

    rows->push_back(row);

    return 0;
}
SQLiteHelper::SQLiteHelper()
    : m_db(nullptr)
{
}
SQLiteHelper::~SQLiteHelper()
{
    Close();
}
bool SQLiteHelper::Open(
    const std::string& dbPath)
{
    int result =
        sqlite3_open(
            dbPath.c_str(),
            &m_db);

    if (result != SQLITE_OK)
    {
        Close();

        return false;
    }

    return true;
}
void SQLiteHelper::Close()
{
    if (m_db != nullptr)
    {
        sqlite3_close(m_db);

        m_db = nullptr;
    }
}
bool SQLiteHelper::ExecuteNonQuery(
    const std::string& sql)
{
    char* errorMessage = nullptr;

    int result =
        sqlite3_exec(
            m_db,
            sql.c_str(),
            nullptr,
            nullptr,
            &errorMessage);

    if (result != SQLITE_OK)
    {
        if (errorMessage != nullptr)
        {
            sqlite3_free(errorMessage);
        }

        return false;
    }

    return true;
}
std::vector<std::vector<std::string>>
SQLiteHelper::ExecuteQuery(
    const std::string& sql)
{
    std::vector<std::vector<std::string>> rows;

    char* errorMessage = nullptr;

    int result =
        sqlite3_exec(
            m_db,
            sql.c_str(),
            QueryCallback,
            &rows,
            &errorMessage);

    if (result != SQLITE_OK)
    {
        if (errorMessage != nullptr)
        {
            sqlite3_free(errorMessage);
        }

        return {};
    }

    return rows;
}