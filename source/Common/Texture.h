///////////////////////////////////////////////////////////////////////////////////////////////////
//	Author: Christopher Sosa																	 //
//																								 //
//	This class defines a texture to be used by the engine and managed by the TextureManager.     //
//                                                                                               //
///////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef TEXTURE_H
#define TEXTURE_H

#include <d3d11.h>
#include <string>

namespace RenderCore
{
	//Class that defines a Texture being used by the engine
	class Texture
	{
	public:
		Texture();
		~Texture();

		bool LoadTexture(const std::wstring& fileName, ID3D11Device* device);
		ID3D11ShaderResourceView* GetTextureResource() const;

	private:
		ID3D11ShaderResourceView* mTexture;
	};
}
#endif