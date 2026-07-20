#pragma once
#include <vector>
#include "Toolbar.h"
#include "StoreInfo.h"
#include "StoreService.h"


class MainWindow
{
public:

    void Draw();

private:

    Toolbar m_toolbar;

    void DrawStoreTable();

    //std::vector<StoreInfo> m_storeList;
    StoreService m_storeService;
};

