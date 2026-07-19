#include "DatabaseInitializer.h"
#include "SQLiteHelper.h"
#include <string>

SQLiteHelper m_database;

bool DatabaseInitializer::Initialize()
{
    if (!m_database.Open("Resources/POSReport.db"))
    {
        return false;
    }

    if (!CreateStoreSummaryTable())
    {
        m_database.Close();

        return false;
    }

    m_database.Close();

    return true;
}
bool DatabaseInitializer::CreateStoreSummaryTable()
{
    std::string sql =
        R"(

-- Store summary table

CREATE TABLE IF NOT EXISTS StoreSummary
(
    StoreNo TEXT PRIMARY KEY,

    StoreName TEXT NOT NULL,

    UpdateStatus TEXT,

    PosCount INTEGER,

    UpdatedPos INTEGER,

    UpdateRate INTEGER,

    OpenDate TEXT
);

)";

    return m_database.ExecuteNonQuery(sql);
}
