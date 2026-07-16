#include "SQLiteHelper.h"

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