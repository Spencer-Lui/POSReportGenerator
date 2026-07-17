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


