#pragma once
#include <vector>
#include "StoreInfo.h"
class PosRepository
{
public:

    std::vector<StoreInfo>
        GetSummary() const;

    bool Import(
        const std::vector<StoreInfo>& stores);
};

