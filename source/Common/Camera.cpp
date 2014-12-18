#include "Camera.h"
using namespace RenderCore;

const float Camera::DefaultFieldOfView = ZMath::PIOVERFOUR;
const float Camera::DefaultNearPlaneDistance = 0.01f;
const float Camera::DefaultFarPlaneDistance = 100.0f;

Camera::Camera() : mFieldOfView(DefaultFieldOfView), mNearPlaneDistance(DefaultFarPlaneDistance), mFarPlaneDistance(DefaultFarPlaneDistance),
mPosition(), mUp(), mRight(), mDirection(), mViewMatrix(), mProjectionMatrix()
{

}

Camera::Camera(float fieldOfView, float aspectRatio, float nearPlaneDistance, float FarPlaneDistance)
: mFieldOfView(fieldOfView), mAspectRatio(aspectRatio), mNearPlaneDistance(nearPlaneDistance), mFarPlaneDistance(FarPlaneDistance),
mPosition(), mUp(), mRight(), mDirection(), mViewMatrix(), mProjectionMatrix()
{

}

Camera::~Camera()
{

}

const ZMath::Mat4x4 Camera::ViewProjectionMatrix() const
{
	return mViewMatrix * mProjectionMatrix;
}

const ZMath::Mat4x4 Camera::ViewMatrix() const
{
	return mViewMatrix;
}

const ZMath::Mat4x4 Camera::ProjectionMatrix() const
{
	return mProjectionMatrix;
}

void Camera::Reset()
{
	mPosition = ZMath::Zero;
	mDirection = ZMath::Forward;
	mUp = ZMath::Up;
	mRight = ZMath::Right;

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
	mViewMatrix = ZMath::DirectXViewMatrix(mPosition, mDirection, mUp);
}

void Camera::UpdateProjectionMatrix()
{
	mProjectionMatrix = ZMath::DirectXPerspectiveMatrix(mFieldOfView, mAspectRatio, mNearPlaneDistance, mFarPlaneDistance);
}

void Camera::SetPosition(float x, float y, float z)
{
	mPosition.x = x;
	mPosition.y = y;
	mPosition.z = z;

	UpdateViewMatrix();
}

void Camera::SetPosition(ZMath::Vec3& position)
{
	mPosition = position;
}

void Camera::SetAspectRatio(float aspectRatio)
{
	mAspectRatio = aspectRatio;
}

void Camera::Draw(ID3D11DeviceContext* deviceContext)
{

}