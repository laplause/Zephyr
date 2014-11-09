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
using namespace Core;

namespace RenderCore
{
	//Abstract base class that defines the essentials of a renderer.
	class Renderer : public System
	{
	public:
		Renderer();
		virtual ~Renderer();

		virtual void Initialize();
		virtual void Shutdown();
		virtual void Update();
		virtual void Draw() = 0;

	protected:
		unsigned int mScreenWidth;
		unsigned int mScreeHeight;
		bool mIsFullScreen;
		SystemWindow* mWindow;
	};
}
#endif