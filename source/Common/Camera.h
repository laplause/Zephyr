///////////////////////////////////////////////////////////////////////////////////////////////////
//	Author: Christopher Sosa																	 //
//																								 //
//	This is the base class for the Zephyr component it contains an Id and an assigned bool.      //
//                                                                                               //
///////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef CAMERA_H
#define CAMERA_H

#include "GameObject.h"
#include "ZMath.h"

namespace RenderCore
{
	class Camera : public Core::GameObject
	{
	public:
		Camera();
		Camera(float fieldOfView, float aspectRatio, float nearPlaneDistance, float FarPlaneDistance);
		~Camera();

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

		const ZMath::Vec4& GetPosition() const;
		const ZMath::Vec4& GetForward() const;
		const ZMath::Vec4& GetUp() const;
		const ZMath::Vec4& GetRight() const;

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

	private:
		Camera(const Camera& rhs);
		Camera& operator=(const Camera& rhs);
	};
}
#endif