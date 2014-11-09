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
#include "ZMath.h"

using namespace ZMath;

namespace RenderCore
{
	//Mesh class that defines the geometry and attributes of a renderable mesh.
	class Mesh
	{
	public:
		struct Vertex
		{
			Vec4 position;
			Vec4 normal;
			Vec2 textureCoordinates;
			Vec4 color;
		};

		Mesh(const std::string& meshName);
		virtual ~Mesh();

		virtual void Initialize();
		const ID3D11Buffer* GetVertexBuffer() const;

	protected:
		enum VertexAttributes
		{
			POSITION,
			NORMAL,
			TEXTURECOORDINATES,
			COLOR,
			VERTEXATTRIBUTESSIZE
		};

		Vertex *mpVertices;
		unsigned int* mpIndices;
		bool mAttributeExists[VertexAttributes::VERTEXATTRIBUTESSIZE];
		std::string mName;
		ID3D11Buffer* mpVertexBuffer;

		void CreateVertexBuffers();
	};
}
#endif