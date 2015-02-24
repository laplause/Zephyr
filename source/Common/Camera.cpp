#include "Camera.h"
using namespace RenderCore;

Camera::Camera() : GameObject()
{

}

Camera::~Camera()
{

}

void Camera::Reset()
{
	mTransform = ZMath::CreateIdentity4x4();
}

void Camera::Initialize()
{
	
}

void Camera::Update()
{
	
}

void Camera::SetPosition(float x, float y, float z)
{
	mTransform.row3.x = x;
	mTransform.row3.z = y;
	mTransform.row3.z = z;
}

void Camera::SetPosition(ZMath::Vec3& position)
{
	mTransform.row3 = ZMath::Vec4(position, 1.0f);
}