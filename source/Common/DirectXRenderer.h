///////////////////////////////////////////////////////////////////////////////////////////////////
//	Author: Christopher Sosa																	 //
//																								 //
//	This is a base renderer that use the DirectX API. Derive from this to create a custom		 //
//  DX renderer that uses forward rendering. A deffered renderer could be made from this base    //
//                                                                                               //
// Majority of implemetation inspired by Realt Time 3D Rendering with DIRECTX and HLSL           //
// Paul VArcholik                                                                                //
//                                                                                               //
///////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef DIRECTXRENDERER_H
#define DIRECTXRENDERER_H

#include <string>
#include <d3d11_1.h>
#include "Renderer.h"
#include "ZMath.h"

using namespace ZMath;

namespace RenderCore
{
	// Concrete DirectXrendering class
	class DirectXRenderer : public Renderer
	{
	public:
		DirectXRenderer(HINSTANCE instance, const std::wstring& windowClass, const std::wstring& windowTitle, int showCommand);
		virtual ~DirectXRenderer();

		virtual void Initialize();
		virtual void Shutdown();
		virtual void Update();
		virtual void Draw();

		ID3D11Device1* Direct3DDevice() const;
		ID3D11DeviceContext1* Direct3DDeviceContext() const;
		bool DepthBufferEnabled() const;
		bool IsFullScreen() const;
		const D3D11_TEXTURE2D_DESC& BackBufferDesc() const;
		const D3D11_VIEWPORT& Viewport() const;

	protected:
		virtual void InitializeDirectX();

		D3D_FEATURE_LEVEL mFeatureLevel;
		ID3D11Device* mDirect3DDevice;
		ID3D11DeviceContext* mDirect3DDeviceContext;
		IDXGISwapChain1* mSwapChain;

		ID3D11Texture2D* mDepthStencilBuffer;
		D3D11_TEXTURE2D_DESC mBackBufferDesc;
		ID3D11RenderTargetView* mRenderTargertView;
		ID3D11DepthStencilView* mDepthStencilView;
		D3D11_VIEWPORT mViewport;

		unsigned int mFrameRate;
		unsigned int mMultiSamplingCount;
		unsigned int mMultiSamplingQualityLevels;
		bool mDepthStencilBufferEnabled;
		bool mMultiSamplingEnabled;
		ZMath::Vec4 mBackGroundColor;

	private:
		DirectXRenderer(const DirectXRenderer& rhs);
		DirectXRenderer& operator=(const DirectXRenderer& rhs);
	};
}
#endif