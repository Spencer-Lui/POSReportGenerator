#include "ExportService.h"

#include <fstream>

bool ExportService::ExportStoreSummary(
    const std::vector<StoreInfo>& stores,
    const std::string& filePath)
{
    std::ofstream file(filePath);

    if (!file.is_open())
    {
        return false;
    }

    file << "Store No,"
        << "Store Name,"
        << "Status,"
        << "POS,"
        << "Updated,"
        << "Rate,"
        << "Open Date"
        << "\n";

    for (const auto& store : stores)
    {
        file << store.GetStoreNo() << ","
            << store.GetStoreName() << ","
            << store.GetUpdateStatus() << ","
            << store.GetPosCount() << ","
            << store.GetUpdatedPos() << ","
            << store.GetUpdateRate() << ","
            << store.GetOpenDate()
            << "\n";
    }

    return true;
}
