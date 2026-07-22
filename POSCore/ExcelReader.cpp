#include "ExcelReader.h"

#include <fstream>
#include <sstream>
#include <iostream>
#include <filesystem>

std::vector<StoreInfo>
ExcelReader::ReadStoreSummary(
    const std::string& filePath)
{
    std::vector<StoreInfo> stores;

    std::ifstream file(
        filePath,
        std::ios::binary);

    std::cout << "Current Path = "
        << std::filesystem::current_path()
        << std::endl;

    std::cout << "Open File = "
        << filePath
        << std::endl;

    std::cout << "Exists = "
        << std::filesystem::exists(filePath)
        << std::endl;

    if (!file.is_open())
    {
        std::cout << "Open Failed!" << std::endl;
        return stores;
    }

    std::string line;
    bool isFirstLine = true;
    int count = 0;

    while (std::getline(file, line))
    {
        std::cout << line << std::endl;

        try
        {
            if (!line.empty() &&
                (unsigned char)line[0] == 0xEF)
            {
                line.erase(0, 3);
            }

            if (isFirstLine)
            {
                isFirstLine = false;
                continue;
            }

            std::stringstream ss(line);

            std::string cell;

            //-----------------------------------
            // 建立一筆 StoreInfo
            //-----------------------------------

            StoreInfo store;

            //-----------------------------------
            // StoreNo
            //-----------------------------------

            std::getline(
                ss,
                cell,
                ',');

            store.SetStoreNo(cell);

            //-----------------------------------
            // StoreName
            //-----------------------------------

            std::getline(
                ss,
                cell,
                ',');

            store.SetStoreName(cell);

            //-----------------------------------
            // UpdateStatus
            //-----------------------------------

            std::getline(
                ss,
                cell,
                ',');

            store.SetUpdateStatus(cell);

            //-----------------------------------
            // PosCount
            //-----------------------------------

            std::getline(
                ss,
                cell,
                ',');

            store.SetPosCount(
                std::stoi(cell));

            //-----------------------------------
            // UpdatedPos
            //-----------------------------------

            std::getline(
                ss,
                cell,
                ',');

            store.SetUpdatedPos(
                std::stoi(cell));

            //-----------------------------------
            // UpdateRate
            //-----------------------------------

            std::getline(
                ss,
                cell,
                ',');

            store.SetUpdateRate(
                std::stoi(cell));

            //-----------------------------------
            // OpenDate
            //-----------------------------------

            std::getline(
                ss,
                cell,
                ',');

            store.SetOpenDate(cell);

            stores.push_back(store);

            if (count < 10)
            {
                std::cout
                    << store.GetStoreNo()
                    << " "
                    << store.GetStoreName()
                    << std::endl;
            }

            ++count;

        }
        catch (const std::exception& ex)
        {
            std::cout
                << ex.what()
                << std::endl;
        }
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

    std::cout
        << "Total Stores = "
        << stores.size()
        << std::endl;

    return stores;
}


