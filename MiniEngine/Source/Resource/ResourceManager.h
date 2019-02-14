#pragma once

namespace Engine
{
	template<class Type, class TypeID>
	class TResourceManager
	{
	public:
		TResourceManager()
		{

		}

	private:
		std::map<TypeID, std::unique_ptr<Type>> m_ResourceMap;
	};
}