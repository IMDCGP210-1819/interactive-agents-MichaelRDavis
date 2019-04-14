#pragma once

template<class Asset, class AssetID>
class TAssetManager
{
public:
	TAssetManager()
	{

	}

	void Load(AssetID ID, const std::string FileName)
	{

	}

	Asset& Get(AssetID ID)
	{

	}

	const Asset& Get(AssetID ID) const
	{

	}

private:
	void Insert(AssetID ID, std::unique_ptr<Asset> InAsset)
	{

	}

private:
	std::map<AssetID, std::unique_ptr<Asset>> m_AsseteMap;
};
