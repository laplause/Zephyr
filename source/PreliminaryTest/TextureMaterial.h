///////////////////////////////////////////////////////////////////////////////////////////////////
//	Author: Christopher Sosa																	 //
//																								 //
//	This is a base class for a material. A material is object which defines the look of a mesh.  //
//  It contains at least a vertex and pixel shader as well as a texture and in the case of       //
//  directx it contains the input layout that is necessary to define the vertex attributes.      //
//                                                                                               //
///////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef TEXTUREMATERIAL_H
#define TEXTUREMATERIAL_H

#include "Material.h"

class DirectXRenderer;

class TextureMaterial : public RenderCore::Material
{
private:
	struct MatrixBuffer
	{
		ZMath::Mat4x4 world;
		ZMath::Mat4x4 view;
		ZMath::Mat4x4 projection;
	};

public:
	TextureMaterial(const std::string& materialName);
	virtual ~TextureMaterial();

	virtual void Initialize(const std::string& vsFileName, const std::string& psFileName, RenderCore::DirectXRenderer* renderer);
	virtual void SetActiveShader(ID3D11DeviceContext* deviceContext);
	virtual void SetShaderBuffers(ID3D11DeviceContext* deviceContext, RenderCore::Camera* camera);

private:
	ID3D11Buffer* mpMatrixBuffer;
	ID3D11SamplerState* mpSamplerState;
	ID3D11ShaderResourceView* mTexture;
};
#endif