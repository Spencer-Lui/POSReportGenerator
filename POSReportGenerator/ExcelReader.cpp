#include "ExcelReader.h"

std::vector<StoreInfo>
ExcelReader::ReadSummary(
    const std::string& fileName)
{
    /*
    公司 SQL（保留）
    ----------------
    SELECT
        storeid,
        storename,
        ...
    FROM POS_List
    */

    ExcelReader reader;

    return reader.ReadSummary("071301.xlsx");
}
