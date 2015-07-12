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
#include "Texture.h"
using namespace RenderCore;

namespace Core
{
	class Sprite : public Core::GameObject
	{
	private:

		class SpriteQuad : public RenderCore::Mesh
		{
		public:
			SpriteQuad(const std::string& meshName, Sprite* parent);
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

			Sprite* mParent;
		};

		friend class SpriteQuad;

	public:
		Sprite(int id, const std::string& objectName);
		virtual ~Sprite();

		virtual void Initialize(RenderCore::DirectXRenderer* renderer, const std::string& materialName, Texture* spriteTexture);
		virtual void Update();

		void SetPosition(float x, float y);

		static enum AnchorPoint
		{
			TOP_LEFT = 0,
			CENTER,
			ANCHOR_POINT_MAX
		};

	private:
		float mTextureWidth;
		float mTextureHeight;
		ZMath::Vec2 mPosition;
		AnchorPoint mAnchorPoint;
		SpriteQuad mQuad;
	};
}
#endif