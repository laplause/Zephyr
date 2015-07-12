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
	{
		ID3D11Resource* res = nullptr;
		ID3D11Texture2D* texture2d = nullptr;
		D3D11_TEXTURE2D_DESC desc;

		mTexture->GetResource(&res);
		res->QueryInterface(&texture2d);
		texture2d->GetDesc(&desc);
		mTextureDimensions.x = (float)desc.Width;
		mTextureDimensions.y = (float)desc.Height;

		ZEPHYR_RELEASEOBJECT(res);
		ZEPHYR_RELEASEOBJECT(texture2d);

		return true;
	}

	return false;
}

ID3D11ShaderResourceView* Texture::GetTextureResource() const
{
	ZEPHYR_ASSERT(mTexture != nullptr, "The texture resource requested has not been loaded.");
	return mTexture;
}

const ZMath::Vec2& Texture::GetTextureDimensions() const
{
	return mTextureDimensions;
}