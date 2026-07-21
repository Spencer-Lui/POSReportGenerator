#pragma once

#include <string>
#include <vector>

#include "StoreInfo.h"

class ExportService
{
public:

    bool ExportStoreSummary(
        const std::vector<StoreInfo>& stores,
        const std::string& filePath);
};

