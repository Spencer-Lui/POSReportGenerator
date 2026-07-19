#pragma once
#include <vector>
#include "StoreInfo.h"
#include "SQLiteHelper.h"

class PosRepository
{
public:

    std::vector<StoreInfo>
        GetSummary();

    bool Import(
        const std::vector<StoreInfo>& stores);

private:

    bool InsertStore(
        const StoreInfo& store);

    SQLiteHelper m_database;
};

