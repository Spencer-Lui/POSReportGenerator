#include "ImportService.h"

#include "ExcelReader.h"

#include "PosRepository.h"

bool ImportService::ImportStoreSummary()
{
    ExcelReader reader;

    auto stores =
        reader.ReadStoreSummary(
            "Resources/071301.xlsx");

    PosRepository repository;

    repository.Import(stores);

    return true;
}