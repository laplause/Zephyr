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
		virtual ~Camera();

		virtual void Initialize() = 0;
		virtual void Update() = 0;

		virtual void Reset() = 0;

		virtual void SetPosition(float x, float y, float z);
		virtual void SetPosition(ZMath::Vec3& position);

		const ZMath::Vec4& GetPosition() const;
		const ZMath::Vec4& GetForward() const;
		const ZMath::Vec4& GetUp() const;
		const ZMath::Vec4& GetRight() const;

	private:
		Camera(const Camera& rhs);
		Camera& operator=(const Camera& rhs);
	};
}
#endif