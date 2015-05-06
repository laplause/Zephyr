///////////////////////////////////////////////////////////////////////////////////////////////////
//	Author: Christopher Sosa																	 //
//																								 //
//	This is a triangle class that inherits from mesh. Mostly an example object.                  //
//                                                                                               //
///////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Mesh.h"
#include "ZMath.h"

using namespace RenderCore;
using namespace ZMath;

class Triangle : public Mesh
{
public:
	Triangle(const std::string& meshName);
	virtual ~Triangle();

	virtual void Initialize(ID3D11Device* device, ID3D11DeviceContext* deviceContext);
	virtual void Update();
	virtual void Draw(ID3D11DeviceContext* deviceContext);

private:
	struct Vertex
	{
		Vec3 position;
		Vec2 textureCoordinates;
	};
};
#endif