///////////////////////////////////////////////////////////////////////////////////////////////////
//	Author: Christopher Sosa																	 //
//																								 //
//	These values control much of how the engine behaves. Some data oriented approach must be     //
//  implemented eventually.                                                                      //
//                                                                                               //
///////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <string>
#include <map>
#include <vector>
#include "Texture.h"

namespace RenderCore
{
	class TextureManager
	{
	public:
		~TextureManager();
		static TextureManager* CreateInstance();
		static TextureManager* GetTextureManager();
		void Shutdown();
		void AddTexture(const std::string& textureName, Texture* texture);
		void AddTextureData(const std::string& textureName, const std::string& texturePath);
		void LoadTexturesFromData(ID3D11Device* device);
		Texture* GetTexture(const std::string& textureName);

		typedef std::pair<std::string, std::string> TextureLoadInfo;

	private:
		//Hide constructors since this is a singleton
		TextureManager();
		TextureManager(const TextureManager& rhs);
		TextureManager& operator=(const TextureManager& rhs);

		std::map<std::string, Texture*> mTextureTable;
		std::vector<TextureLoadInfo> mTextureLoadInfoList;
		static TextureManager* m_sInstance;
	};
}
#endif