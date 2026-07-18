#include "StoreService.h"

std::vector<StoreInfo>
StoreService::GetSummary()
{
    return
        m_repository.GetSummary();
}
