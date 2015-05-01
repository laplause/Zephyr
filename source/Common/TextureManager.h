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

namespace RenderCore
{
	class Texture;

	class TextureManager
	{
	public:
		~TextureManager();
		static TextureManager* CreateInstance();
		static TextureManager* GetTextureManager();
		void Shutdown();
		void AddTexture(const std::string& textureName, Texture* texture);
		Texture* GetTexture(const std::string& textureName);

	private:
		//Hide constructors since this is a singleton
		TextureManager();
		TextureManager(const TextureManager& rhs);
		TextureManager& operator=(const TextureManager& rhs);

		std::map<std::string, Texture*> textureTable;
		static TextureManager* m_sInstance;
	};
}
#endif