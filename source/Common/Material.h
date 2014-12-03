///////////////////////////////////////////////////////////////////////////////////////////////////
//	Author: Christopher Sosa																	 //
//																								 //
//	This is a base class for a material. A material is object which defines the look of a mesh.  //
//  It contains at least a vertex and pixel shader as well as a texture and in the case of       //
//  directx it contains the input layout that is necessary to define the vertex attributes.      //
//                                                                                               //
///////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef MATERIAL_H
#define MATERIAL_H

#include <d3d11_1.h>
#include <string>
#include "DirectXRenderer.h"

namespace RenderCore
{
	//Class that defines the look of a mesh.
	class Material
	{
	public:
		Material(const std::string& materialName);
		virtual ~Material();

		virtual void Initialize(const std::string& vsFileName, const std::string& psFileName, DirectXRenderer* renderer) = 0;
		ID3D11InputLayout* GetInputLayout() const;

	protected:

		struct ShaderBlob
		{
			char* shaderData;
			unsigned int fileSize;
			ShaderBlob();
			~ShaderBlob();
		};

		ID3D11VertexShader* mpVertexShader;
		ID3D11PixelShader* mpPixelShader;
		ShaderBlob* mpVertexShaderBlob;
		ShaderBlob* mpPixelShaderBlob;
		ID3D11InputLayout* mpInputLayout;
		std::string mName;
	};
}
#endif