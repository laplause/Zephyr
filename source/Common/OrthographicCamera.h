///////////////////////////////////////////////////////////////////////////////////////////////////
//	Author: Christopher Sosa																	 //
//																								 //
//	This is the base class for the Zephyr component it contains an Id and an assigned bool.      //
//                                                                                               //
///////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef ORTHOGRAPHICCAMERA_H
#define ORTHOGRAPHICCAMERA_H

#include "Camera.h"

namespace RenderCore
{
	class OrthoGraphicCamera : public RenderCore::Camera
	{
		OrthoGraphicCamera(float screenWidth, float screenHeight);
		OrthoGraphicCamera(float screenWidth, float screenHeight, float near, float far);
		virtual ~OrthoGraphicCamera();

		virtual void Initialize();
		virtual void Update();
		virtual void Reset();

		virtual void UpdateViewMatrix();
		virtual void UpdateProjectionMatrix();

		virtual void SetPosition(float x, float y, float z);
		virtual void SetPosition(ZMath::Vec3& position);

		const ZMath::Mat4x4& ViewMatrix() const;
		const ZMath::Mat4x4& ProjectionMatrix() const;
		const ZMath::Mat4x4& ViewProjectionMatrix() const;

		static const float DefaultNearPlaneDistance;
		static const float DefaultFarPlaneDistance;

	protected:
		float mWidth;
		float mHeight;
		float mNearPlaneDistance;
		float mFarPlaneDistance;

		ZMath::Mat4x4 mViewMatrix;
		ZMath::Mat4x4 mProjectionMatrix;
	};
}
#endif