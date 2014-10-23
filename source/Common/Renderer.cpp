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
	Renderer::Renderer() : mScreenWidth(800),
	mScreeHeight(600), mIsFullScreen(false)
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