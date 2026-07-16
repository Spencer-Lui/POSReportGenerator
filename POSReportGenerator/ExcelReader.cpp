#include "ExcelReader.h"

#include <fstream>
#include <sstream>
#include <iostream>

std::vector<StoreInfo>
ExcelReader::ReadStoreSummary(
    const std::string& filePath)
{
    std::vector<StoreInfo> stores;

    std::ifstream file(filePath);

    if (!file.is_open())
    {
        return stores;
    }

    std::string line;
    bool isFirstLine = true;

    while (std::getline(file, line))
    {
        if (isFirstLine)
        {
            isFirstLine = false;
            continue;
        }

        std::cout << line << std::endl;

        std::stringstream ss(line);

        std::string cell;
    }

    /*
    公司 SQL（保留）
    ----------------
    SELECT
        storeid,
        storename,
        ...
    FROM POS_List
    */

    return stores;
}


