#pragma once
#include <string>
class StoreInfo
{
public:
	StoreInfo();

	const std::string& GetStoreNo() const;

	const std::string& GetStoreName() const;

	int GetTotal() const;

	void SetStoreNo(const std::string& storeNo);

	void SetStoreName(const std::string& storeName);

	void SetTotal(int total);

private:
	std::string m_storeNo;

	std::string m_storeName;

	int m_total;
};

