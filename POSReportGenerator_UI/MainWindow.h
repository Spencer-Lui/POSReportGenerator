#pragma once
#include <vector>
#include "Toolbar.h"
#include "StoreInfo.h"
#include "StoreService.h"
#include "ExportService.h"


class MainWindow
{
public:

    void Draw();

private:

    Toolbar m_toolbar;

    void DrawStoreTable();

    void DrawStoreRow(const StoreInfo& store);
    //std::vector<StoreInfo> m_storeList;
    void DrawUpdateStatus(const StoreInfo& store);

    StoreService m_storeService;

    ExportService m_exportService;

    std::string m_lastExportPath;

    std::string m_statusMessage;

    bool m_exportSuccess = true;

private:

    std::string CreateExportFilePath();
};

