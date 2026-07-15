#include "PosRepository.h"

std::vector<StoreInfo>
PosRepository::GetSummary() const
{
    std::vector<StoreInfo> stores;

    StoreInfo store;

    store.SetStoreNo("0001");
    store.SetStoreName("Taipei");
    store.SetTotal(35);

    stores.push_back(store);

    return stores;
}