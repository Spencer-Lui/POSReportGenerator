#pragma once

#include <vector>

#include "StoreInfo.h"
#include "PosRepository.h"

class StoreService
{
public:

    std::vector<StoreInfo>
        GetSummary();

private:

    PosRepository m_repository;
};

