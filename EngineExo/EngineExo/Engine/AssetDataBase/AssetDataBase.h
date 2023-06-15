#pragma once
#include "../Object/Object.h"

namespace Engine
{
	//Créer des assets
	class AssetDataBase : public Object
	{
		DECLARE_CLASS_INFO(AssetDataBase, Object)
#pragma region f/p
	private:
		static  std::vector<Object*> AllObjectPath = std::vector<Object*>();
#pragma endregion
#pragma region methods
	public:
		static void CreateAsset(Object* _asset, PrimaryType::String _path);
		static std::vector<Engine::Object*> LoadAllAssets();
		std::string GetAssetPath(Object* _obj);
#pragma endregion

	};
}
