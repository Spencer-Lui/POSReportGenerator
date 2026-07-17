#pragma once

#include <string>
#include <vector>

#include "sqlite3.h"

class SQLiteHelper
{
public:

    SQLiteHelper();

    ~SQLiteHelper();

    bool Open(const std::string& dbPath);

    void Close();

    bool ExecuteNonQuery(
        const std::string& sql);

    std::vector<std::vector<std::string>>
        ExecuteQuery(
            const std::string& sql);

private:

    sqlite3* m_db;
};

