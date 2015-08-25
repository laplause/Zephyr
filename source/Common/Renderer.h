///////////////////////////////////////////////////////////////////////////////////////////////////
//	Author: Christopher Sosa																	 //
//																								 //
//	This is the abstract base class for the Zephyr graphics engine						         //
//																	                             //
//	Majority of implementation inspired by Paul Varcholik's book Real time						 //
//	3D rendering with DirectX and HLSL	                                                         //
///////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef RENDERER_H
#define RENDERER_H

#include "SystemWindow.h"
#include "System.h"
#include "Renderable.h"
#include <vector>
#include <string>
using namespace Core;

namespace RenderCore
{
	//Abstract base class that defines the essentials of a renderer.
	class Renderer : public System
	{
	public:
		Renderer();
		Renderer(unsigned int renderListSize);
		virtual ~Renderer();

		virtual void Initialize();
		virtual void Shutdown();
		virtual void Update(const GameTime& gameTime);
		virtual void Draw(const GameTime& gameTime) = 0;

		unsigned int CreateRenderable(const std::string& meshName, const std::string& materialName, const int objectHandle);
		void AddRenderable(Renderable& renderable);

		const SystemWindow* GetWindow() const;

	protected:
		const unsigned int GetNextUnusedRenderable();

		unsigned int mScreenWidth;
		unsigned int mScreeHeight;
		bool mIsFullScreen;
		std::vector<Renderable> mRenderList;
		SystemWindow* mWindow;
	};
}
#endif