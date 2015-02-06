#include "Camera.h"
using namespace RenderCore;

const float Camera::DefaultFieldOfView = ZMath::PIOVERFOUR;
const float Camera::DefaultNearPlaneDistance = 0.01f;
const float Camera::DefaultFarPlaneDistance = 100.0f;

Camera::Camera() : mFieldOfView(DefaultFieldOfView), mNearPlaneDistance(DefaultFarPlaneDistance), mFarPlaneDistance(DefaultFarPlaneDistance),
mViewMatrix(), mProjectionMatrix()
{

}

Camera::Camera(float fieldOfView, float aspectRatio, float nearPlaneDistance, float FarPlaneDistance)
: mFieldOfView(fieldOfView), mAspectRatio(aspectRatio), mNearPlaneDistance(nearPlaneDistance), mFarPlaneDistance(FarPlaneDistance),
mViewMatrix(), mProjectionMatrix()
{

}

Camera::~Camera()
{

}

const ZMath::Mat4x4& Camera::ViewProjectionMatrix() const
{
	return mViewMatrix * mProjectionMatrix;
}

const ZMath::Mat4x4& Camera::ViewMatrix() const
{
	return mViewMatrix;
}

const ZMath::Mat4x4& Camera::ProjectionMatrix() const
{
	return mProjectionMatrix;
}

void Camera::Reset()
{
	mTransform = ZMath::CreateIdentity4x4();
	UpdateViewMatrix();
}

void Camera::Initialize()
{
	UpdateProjectionMatrix();
	Reset();
}

void Camera::Update()
{
	UpdateViewMatrix();
}

void Camera::UpdateViewMatrix()
{
	ZMath::Vec3 position = ZMath::Vec3(mTransform.row3.x, mTransform.row3.y, mTransform.row3.z);
	ZMath::Vec3 direction = ZMath::Vec3(mTransform.row2.x, mTransform.row2.y, mTransform.row2.z);
	ZMath::Vec3 up = ZMath::Vec3(mTransform.row1.x, mTransform.row1.y, mTransform.row1.z);

	mViewMatrix = ZMath::DirectXViewMatrix(position, direction, up);
}

void Camera::UpdateProjectionMatrix()
{
	mProjectionMatrix = ZMath::DirectXPerspectiveMatrix(mFieldOfView, mAspectRatio, mNearPlaneDistance, mFarPlaneDistance);
}

void Camera::SetPosition(float x, float y, float z)
{
	mTransform.row3.x = x;
	mTransform.row3.z = y;
	mTransform.row3.z = z;

	UpdateViewMatrix();
}

void Camera::SetPosition(ZMath::Vec3& position)
{
	mTransform.row3 = ZMath::Vec4(position, 1.0f);
}

void Camera::SetAspectRatio(float aspectRatio)
{
	mAspectRatio = aspectRatio;
}