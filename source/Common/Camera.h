///////////////////////////////////////////////////////////////////////////////////////////////////
//	Author: Christopher Sosa																	 //
//																								 //
//	This is the base class for the Zephyr component it contains an Id and an assigned bool.      //
//                                                                                               //
///////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef CAMERA_H
#define CAMERA_H

#include "Renderable.h"
#include "ZMath.h"

namespace RenderCore
{
	class Camera : public Renderable
	{
	public:
		Camera();
		Camera(float fieldOfView, float aspectRatio, float nearPlaneDistance, float FarPlaneDistance);
		~Camera();

		virtual void Initialize();
		virtual void Update();
		virtual void Draw(ID3D11DeviceContext* deviceContext);

		virtual void Reset();
		virtual void UpdateViewMatrix();
		virtual void UpdateProjectionMatrix();

		virtual void SetPosition(float x, float y, float z);
		virtual void SetPosition(ZMath::Vec3& position);

		void SetAspectRatio(float aspectRatio);

		const ZMath::Mat4x4 ViewMatrix() const;
		const ZMath::Mat4x4 ProjectionMatrix() const;
		const ZMath::Mat4x4 ViewProjectionMatrix() const;

		static const float DefaultFieldOfView;
		static const float DefaultAspectRatio;
		static const float DefaultNearPlaneDistance;
		static const float DefaultFarPlaneDistance;

	protected:
		float mFieldOfView;
		float mAspectRatio;
		float mNearPlaneDistance;
		float mFarPlaneDistance;

		ZMath::Vec3 mPosition;
		ZMath::Vec3 mDirection;
		ZMath::Vec3 mUp;
		ZMath::Vec3 mRight;

		ZMath::Mat4x4 mViewMatrix;
		ZMath::Mat4x4 mProjectionMatrix;

	private:
		Camera(const Camera& rhs);
		Camera& operator=(const Camera& rhs);
	};
}
#endif