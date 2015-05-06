#include "TextureManager.h"
using namespace RenderCore;

TextureManager* TextureManager::m_sInstance = nullptr;

TextureManager::TextureManager() : mTextureTable(), mTextureLoadInfoList()
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
		mTextureTable[textureName] = texture;
	}
}

void TextureManager::AddTextureData(const std::string& textureName, const std::string& texturePath)
{
	mTextureLoadInfoList.push_back(TextureLoadInfo(textureName, texturePath));
}

void TextureManager::LoadTexturesFromData(ID3D11Device* device)
{
	if (mTextureLoadInfoList.empty())
		return;

	for (std::vector<TextureLoadInfo>::iterator it = mTextureLoadInfoList.begin(); it != mTextureLoadInfoList.end(); it++)
	{
		Texture* tex = new Texture();
		TextureLoadInfo tli = *it;

		tex->LoadTexture(std::wstring(tli.second.begin(), tli.second.end()), device);
		AddTexture(tli.first, tex);
	}
}

Texture* TextureManager::GetTexture(const std::string& textureName)
{
	if (mTextureTable.find(textureName) != mTextureTable.end() && mTextureTable.find(textureName)->second != nullptr)
	{
		return mTextureTable[textureName];
	}
	else
	{
		return nullptr;
	}
}