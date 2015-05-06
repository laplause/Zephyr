#include "Texture.h"
#include "ZAssert.h"
#include "Common.h"
#include <WICTextureLoader.h>
using namespace RenderCore;

Texture::Texture() : mTexture(nullptr)
{

}

Texture::~Texture()
{
	ZEPHYR_RELEASEOBJECT(mTexture);
}

bool Texture::LoadTexture(const std::wstring& fileName, ID3D11Device* device)
{
	DirectX::CreateWICTextureFromFile(device, fileName.c_str(), nullptr, &mTexture);

	if (mTexture != nullptr)
		return true;

	return false;
}

ID3D11ShaderResourceView* Texture::GetTextureResource() const
{
	ZEPHYR_ASSERT(mTexture != nullptr, "The texture resource requested has not been loaded.");
	return mTexture;
}