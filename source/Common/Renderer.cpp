///////////////////////////////////////////////////////////////////////////////////////////////////
//	Author: Christopher Sosa																	 //
//																								 //
//	This is the abstract base class for the Zephyr graphics engine						         //
//																	                             //
//	Majority of implementation inspired by Paul Varcholik's book Real time						 //
//	3D rendering with DirectX and HLSL	                                                         //
///////////////////////////////////////////////////////////////////////////////////////////////////

#include "Renderer.h"

namespace RenderCore
{
	Renderer::Renderer(unsigned int screenWidth, unsigned int screenHeight, bool fullScreen) : mScreenWidth(screenWidth),
	mScreenHeight(screenHeight), mFullScreen(fullScreen)
	{

	}

	Renderer::~Renderer()
	{

	}

	void Renderer::Initialize()
	{

	}

	void Renderer::Shutdown()
	{

	}

	void Renderer::Update()
	{

	}

	void Renderer::Draw()
	{

	}
}