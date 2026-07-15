#pragma once

#include <string>

#include "sqlite3.h"

class SQLiteHelper
{
public:

    SQLiteHelper();

    ~SQLiteHelper();

    bool Open(const std::string& dbPath);

    void Close();

private:

    sqlite3* m_db;
};
