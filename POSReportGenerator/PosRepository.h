#pragma once
#include <vector>
#include "StoreInfo.h"
#include "SQLiteHelper.h"

class PosRepository
{
public:

    std::vector<StoreInfo>
        GetSummary() const;

    bool Import(
        const std::vector<StoreInfo>& stores);

private:

    SQLiteHelper m_database;
};

