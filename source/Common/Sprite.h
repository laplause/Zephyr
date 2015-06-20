///////////////////////////////////////////////////////////////////////////////////////////////////
//	Author: Christopher Sosa																	 //
//																								 //
//	This is the base class for the Zephyr game object it contains an array of component handles. //
//                                                                                               //
///////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef SPRITE_H
#define SPIRTE_H

#include "GameObject.h"
#include "Mesh.h"
#include "ZMath.h"
#include "DirectXRenderer.h"
using namespace RenderCore;

namespace Core
{
	class Sprite : public Core::GameObject
	{
	private:

		class SpriteQuad : public RenderCore::Mesh
		{
		public:
			SpriteQuad(const std::string& meshName);
			virtual ~SpriteQuad();

			virtual void Initialize(ID3D11Device* device, ID3D11DeviceContext* deviceContext);
			virtual void Update();
			virtual void Draw(ID3D11DeviceContext* deviceContext);

		private:
			struct Vertex
			{
				ZMath::Vec3 position;
				ZMath::Vec2 textureCoordinates;
			};
		};

	public:
		Sprite(const std::string& objectName);
		virtual ~Sprite();

		virtual void Initialize(RenderCore::DirectXRenderer* renderer, const std::string& materialName);
		virtual void Update();

	private:
		SpriteQuad mQuad;
		std::string mName;
	};
}
#endif