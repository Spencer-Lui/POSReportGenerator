#pragma once

#include <string>
#include <vector>

#include "StoreInfo.h"

class ExcelReader
{
public:

    std::vector<StoreInfo>
        ReadSummary(const std::string& fileName);
};

