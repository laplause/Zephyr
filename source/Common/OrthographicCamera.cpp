#include "OrthographicCamera.h"
using namespace RenderCore;

const float OrthoGraphicCamera::DefaultNearPlaneDistance = 0;
const float OrthoGraphicCamera::DefaultFarPlaneDistance = 1.0f;

OrthoGraphicCamera::OrthoGraphicCamera(float screenWidth, float screenHeight)
: Camera(), mWidth(screenWidth), mHeight(screenHeight), mNearPlaneDistance(DefaultNearPlaneDistance), mFarPlaneDistance(DefaultFarPlaneDistance),
mViewMatrix(), mProjectionMatrix()
{

}

OrthoGraphicCamera::OrthoGraphicCamera(float screenWidth, float screenHeight, float near, float far)
: Camera(), mWidth(screenWidth), mHeight(screenHeight), mNearPlaneDistance(near), mFarPlaneDistance(far),
mViewMatrix(), mProjectionMatrix()
{

}

OrthoGraphicCamera::~OrthoGraphicCamera()
{

}

void OrthoGraphicCamera::Initialize()
{
	UpdateProjectionMatrix();
	Reset();
}

void OrthoGraphicCamera::Update()
{
	UpdateViewMatrix();
}

void OrthoGraphicCamera::Reset()
{
	Camera::Reset();
	UpdateViewMatrix();
}

void OrthoGraphicCamera::UpdateViewMatrix()
{
	mViewMatrix = ZMath::Mat4x4(1, 0, 0, mTransform.row3.x,
								0, 1, 0, mTransform.row3.y,
								0, 0, 1, 0,
								0, 0, 0, 1);
}

void OrthoGraphicCamera::UpdateProjectionMatrix()
{
	mProjectionMatrix = ZMath::DirectXOrthoMatrix(mWidth, mHeight, mNearPlaneDistance, mFarPlaneDistance);
}

void OrthoGraphicCamera::SetPosition(float x, float y, float z)
{
	Camera::SetPosition(x, y, z);
}

void OrthoGraphicCamera::SetPosition(ZMath::Vec3& position)
{
	Camera::SetPosition(position);
}

const ZMath::Mat4x4& OrthoGraphicCamera::ViewMatrix() const
{
	return mViewMatrix;
}

const ZMath::Mat4x4& OrthoGraphicCamera::ProjectionMatrix() const
{
	return mProjectionMatrix;
}

const ZMath::Mat4x4& OrthoGraphicCamera::ViewProjectionMatrix() const
{
	return mViewMatrix * mProjectionMatrix;
}