#include "TextureManager.h"
using namespace RenderCore;

TextureManager* TextureManager::m_sInstance = nullptr;

TextureManager::TextureManager()
{

}

TextureManager::~TextureManager()
{

}

TextureManager* TextureManager::CreateInstance()
{
	if (m_sInstance != nullptr)
	{
		return m_sInstance;
	}
	else
	{
		m_sInstance = new TextureManager();
	}

	return m_sInstance;
}

TextureManager* TextureManager::GetTextureManager()
{
	if (m_sInstance != nullptr)
	{
		return m_sInstance;
	}
	else
	{
		return CreateInstance();
	}
}

void TextureManager::AddTexture(const std::string& textureName, Texture* texture)
{
	if (texture != nullptr)
	{
		textureTable[textureName] = texture;
	}
}

Texture* TextureManager::GetTexture(const std::string& textureName)
{
	if (textureTable.find(textureName) != textureTable.end() && textureTable.find(textureName)->second != nullptr)
	{
		return textureTable[textureName];
	}
	else
	{
		return nullptr;
	}
}