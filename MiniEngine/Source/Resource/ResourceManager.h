#pragma once

///**
// * 
// */
//template<class AssetType, class AssetID>
//class TAssetManager
//{
//public:
//	/** Default constructor. */
//	TAssetManager()
//	{
//
//	}
//
//	/** Load asset into the asset map. */
//	void Load(AssetID ID, const std::string FileName)
//	{
//		std::unique_ptr<AssetType> Asset(new AssetType());
//		if (!Asset->loadFromFile(FileName))
//		{
//			std::cout << "Failed to load asset " << FileName << std::endl;
//		}
//
//		Insert(ID, std::move(Asset));
//	}
//
//	/** Returns an asset from the map via its ID. */
//	AssetType& Get(AssetID ID)
//	{
//		auto Found = m_AsseteMap.find(ID);
//		assert(Found != m_AsseteMap.end());
//		return *Found->second;
//	}
//
//	/** Returns an asset from the map via its ID, const version. */
//	const AssetType& Get(AssetID ID) const
//	{
//		auto Found = m_AsseteMap.find(ID);
//		assert(Found != m_AsseteMap.end());
//		return *Found->second;
//	}
//
//private:
//	/** Insert asset into the asset map. */
//	void Insert(AssetID ID, std::unique_ptr<AssetType> InAsset)
//	{
//		auto Asset = m_AsseteMap.insert(std::make_pair(ID, std::move(InAsset)));
//		assert(Asset.second);
//	}
//
//private:
//	/** Asset map for storing assets keyed with a unique ID. */
//	std::map<AssetID, std::unique_ptr<AssetType>> m_AsseteMap;
//};
