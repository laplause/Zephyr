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
	Renderer::Renderer() : mScreenWidth(800), mScreeHeight(600), mIsFullScreen(false), mRenderList(50)
	{

	}

	Renderer::Renderer(unsigned int renderListSize) : mScreenWidth(800), mScreeHeight(600), mIsFullScreen(false), mRenderList(renderListSize)
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

	void Renderer::CreateRenderable(const std::string& meshName, const std::string& materialName)
	{
		unsigned int index = GetNextUnusedRenderable();
		Renderable& newRenderable = mRenderList[index];
		newRenderable.Assign();
		newRenderable.SetId(index);
		newRenderable.Initialize(meshName, materialName);
	}

	const unsigned int Renderer::GetNextUnusedRenderable()
	{
		std::vector<Renderable>::iterator it;
		unsigned int count = 0;
		for (it = mRenderList.begin(); it != mRenderList.end(); it++, count++)
		{
			if (!(*it).IsAssigned())
				return count;
		}

		return count;
	}
}