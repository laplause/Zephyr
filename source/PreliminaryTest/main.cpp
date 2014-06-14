#include "ZMath.h"
using namespace ZMath;

int main()
{
	Vec2 x2(5.0f), y2(1.0f);
	Vec3 x3(5.0f), y3(1.0f);
	Vec4 x(5.0f), y(1.0f);

	x = Add(x, y);
	x = Sub(x, y);

	Vector<float, 5> x5, y5;
	x5[0] = 5.0f;
	x5[1] = 5.0f;
	x5[2] = 5.0f;
	x5[3] = 5.0f;
	x5[4] = 5.0f;
	y5[0] = 1.0f;
	y5[1] = 1.0f;
	y5[2] = 1.0f;
	y5[3] = 1.0f;
	y5[4] = 1.0f;

	x5 += y5;
	x5 = x5 + y5;

	x2 = Add(x2, y2);
	x2 = Sub(x2, y2);

	x3 = Add(x3, y3);
	x3 = Sub(x3, y3);

	return 0;
}