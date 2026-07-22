#include <cassert>
#include <iostream>
#include <filesystem>
#include "ImportService.h"
#include "ExcelReader.h"
#include "PosRepository.h"

bool ImportService::ImportStoreSummary()
{
    ExcelReader reader;

    auto stores =
        reader.ReadStoreSummary(
            "Resources/071301.csv");

    assert(!stores.empty());

    PosRepository repository;

    bool success =
        repository.Import(stores);

    std::cout
        << "Import Success = "
        << success
        << std::endl;

    return true;
}