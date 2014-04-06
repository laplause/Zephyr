#include "ZMath.h"

int main()
{
	ZMath::Vec4 x = ZMath::Load(40.0f, -6.0f, 2.0f, 0.0f);
	ZMath::Vec4 y = ZMath::Load(58.0f, 9.0f, 1.0f, 0.0f);

	//x = ZMath::Dot(x, y);
	//x = ZMath::Load(1.0f, 0.0f, 0.0f, 0.0f);
	x = ZMath::Cross(x, y);
}