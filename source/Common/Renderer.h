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

namespace RenderCore
{
	//Abstract base class that defines the essentials of a renderer.
	class Renderer
	{
	public:
		Renderer(unsigned int screenWidth, unsigned int screenHeight, bool fullScreen);
		virtual ~Renderer();

		virtual void Initialize() = 0;
		virtual void Shutdown() = 0;
		virtual void Update() = 0;
		virtual void Draw() = 0;

	protected:
		unsigned int mScreenWidth;
		unsigned int mScreenHeight;
		bool mFullScreen;
	};
}
#endif