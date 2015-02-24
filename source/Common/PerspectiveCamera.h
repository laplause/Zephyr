///////////////////////////////////////////////////////////////////////////////////////////////////
//	Author: Christopher Sosa																	 //
//																								 //
//	This is the base class for the Zephyr component it contains an Id and an assigned bool.      //
//                                                                                               //
///////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef PERSPECTIVECAMERA_H
#define PERSPECTIVECAMERA_H

#include "Camera.h"

namespace RenderCore
{
	class PerspectiveCamera : public RenderCore::Camera
	{
	public:
		PerspectiveCamera();
		PerspectiveCamera(float fieldOfView, float aspectRatio, float nearPlaneDistance, float farPlaneDistance);
		virtual ~PerspectiveCamera();

		virtual void Initialize();
		virtual void Update();
		virtual void Reset();

		virtual void UpdateViewMatrix();
		virtual void UpdateProjectionMatrix();

		virtual void SetPosition(float x, float y, float z);
		virtual void SetPosition(ZMath::Vec3& position);
		void SetAspectRatio(float aspectRatio);

		const ZMath::Mat4x4& ViewMatrix() const;
		const ZMath::Mat4x4& ProjectionMatrix() const;
		const ZMath::Mat4x4& ViewProjectionMatrix() const;

		static const float DefaultFieldOfView;
		static const float DefaultAspectRatio;
		static const float DefaultNearPlaneDistance;
		static const float DefaultFarPlaneDistance;

	protected:
		float mFieldOfView;
		float mAspectRatio;
		float mNearPlaneDistance;
		float mFarPlaneDistance;

		ZMath::Mat4x4 mViewMatrix;
		ZMath::Mat4x4 mProjectionMatrix;
	};
}
#endif