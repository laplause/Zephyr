///////////////////////////////////////////////////////////////////////////////////////////////////
//	Author: Christopher Sosa																	 //
//																								 //
//	This is a Mesh class for holding attribute data that makes up geometry.                      //
//                                                                                               //
///////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef MESH_H
#define MESH_H

#include <string>
#include <d3d11_1.h>

namespace RenderCore
{
	//Mesh class that defines the geometry and attributes of a renderable mesh.
	class Mesh
	{
	public:
		Mesh(const std::string& meshName);
		virtual ~Mesh();

		virtual void Initialize(ID3D11Device* device, ID3D11DeviceContext* deviceContext);
		virtual void Update();
		virtual void Draw(ID3D11DeviceContext* deviceContext);
		const ID3D11Buffer* GetVertexBuffer() const;

	protected:
		std::string mName;
		ID3D11Buffer* mpVertexBuffer;

		void CreateVertexBuffers();
	};
}
#endif